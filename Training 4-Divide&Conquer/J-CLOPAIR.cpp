/*
Cho N điểm trên mặt phẳng, hãy tìm một cặp điểm với khoảng cách | euclid | nhỏ nhất giữa chúng. 
Biết rằng không có hai điểm nào trùng nhau và có duy nhất một cặt có khoảng cách nhỏ nhất.
**Input
Dòng đầu tiên chứa một số nguyên N (2≤N≤50000).
N dòng tiếp theo mỗi dòng chứa hai số nguyên là tọa độ X và Y của một điểm.
  Giá trị tuyệt đối của X, Y không vượt quá 10^6.
**Output
Ghi ra 3 số a b c, trong đó a,b (a<b) là các chỉ số của cặp điểm tìm được trong dữ liệu vào (chỉ số bắt đầu từ 0) 
và c là khoảng cách giữa chúng(Làm tròn c đến 6 chữ số sau dấu phẩy động).
    TEST
5
0 0
-4 1
-7 -2
4 5
1 1
=>0 4 1.414214
---------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 50000;

int N;
int a, b;
typedef struct point {
    int id;
    int x;
    int y;
} point;
point p[MAX];

class pointPair {
    public :
    point a;
    point b;
    double dist;
};

double findDist(point a, point b) {
    return sqrt((a.x - b.x) *  (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


bool sortByX(point a, point b) {
    return a.x < b.x;
}

bool sortByY(point a, point b) {
    return a.y < b.y;
}

pointPair findMinDist(int l, int r) {
    if (r - l == 1) {
        pointPair tmp;
        tmp.a = p[l];
        tmp.b = p[r];
        return tmp;
    }
    int m = (l + r)/2;
    if (r - l == 2) {
        pointPair pp1, pp2, pp3;
        pp1.a = p[l];
        pp1.b = p[r];
        pp1.dist = findDist(p[l], p[r]);
        pp2.a = p[l];
        pp2.b = p[m];
        pp2.dist = findDist(p[l], p[m]);
        pp3.a = p[r];
        pp3.b = p[m];
        pp3.dist = findDist(p[r], p[m]);
        return pp1.dist < pp2.dist ? pp1.dist < pp2.dist ? pp1 : pp3 : pp2.dist < pp3.dist ? pp2 : pp3;
    }
    pointPair L = findMinDist(l, m);
    pointPair R = findMinDist(m+1, r);
    return findDist(L.a, L.b) < findDist(R.a, R.b) ? L : R;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N;
    int Id = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        p[i].x = a;
        p[i].y = b;
        p[i].id = Id++;
    }
    sort(p, p+N, sortByX);
//    cout << "point array : " << endl;
//    for (int i = 0; i < N; i++) {
//        cout << p[i].x << " " << p[i].y << endl;
//    }

    pointPair cloPair = findMinDist(0, N-1);
    double d = cloPair.dist;
 //   cout << "d = " << d << endl;
    int m = (N-1)/2;
    point strip[N];
    int id = 0;
    for (int i = 0; i < N; i++) {
        if (abs(p[i].x - p[m].x) <= d) strip[id++] = p[i];
    }
    sort(strip, strip+id, sortByY);
//    cout << "strip array : " << endl;
//    for (int i = 0; i < id; i++) {
//        cout << strip[i].id << endl;
//    }
    double minStrip = 1000000;
    pointPair tmp;
    pointPair stripAns;
    for (int i = 0; i < id; i++) {
        for (int j = 1; j <= 7 && j < id - i; j++) {
            tmp.a = strip[i]; tmp.b = strip[i+j];
            tmp.dist = findDist(tmp.a, tmp.b);
            if (tmp.dist < minStrip) {
                minStrip = tmp.dist;
                stripAns = tmp;
            }
        }
    }
    pointPair res = minStrip < d ? stripAns : cloPair;
    double resDist = min(minStrip, d);
    if (res.a.id > res.b.id) {
        int tmp = res.a.id;
        res.a.id = res.b.id;
        res.b.id = tmp;
    }
    printf("%d %d %0.6f\n", res.a.id, res.b.id, resDist);
}



// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// struct point {
//     double x, y;
// };

// bool cmp_x(const point &a, const point &b) {
//     return a.x < b.x;
// }

// bool cmp_y(const point &a, const point &b) {
//     return a.y < b.y;
// }

// #define MAXN 100000
// point a[MAXN];
// double mindist; // bi?n luu k?t qu? bài toán

// // tính kho?ng cách gi?a a và b r?i update k?t qu?
// void upd_ans(const point &a, const point &b) {
//     double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
//     if (dist < mindist) mindist = dist;
// }

// void find(int l, int r) {
//     if (r <= l) return;
//     // do?n [l,r] có 2 ph?n t?
//     if (r == l + 1) {
//         upd_ans(a[l], a[r]);
//         // s?p các ph?n t? l?i theo y
//         if (!cmp_y(a[l], a[r])) swap(a[l], a[r]);
//         return;
//     }

//     int m = (l + r) / 2;
//     double midx = a[m].x;
//     find(l, m);
//     find(m+1, r);

//     static point t[MAXN];
//     // tr?n a[l,m] và a[m+1,r] l?i, luu vào m?ng t?m t
//     merge(a+l, a+m+1, a+m+1, a+r+1, t, cmp_y);
//     // copy t? t v? l?i a
//     copy(t, t+r-l+1, a+l);

//     // m?ng t ? dây luu các ph?n t? th?a |x_i - midx| < mindist,
//     // v?i s? lu?ng ph?n t? là tm
//     // do dã sort nên các ph?n t? s? có y tang d?n
//     int tm = 0;
//     for (int i=l; i<=r; i++) if (abs(a[i].x-midx) < mindist) {
//         for (int j=tm-1; j>=0 && t[j].y > a[i].y-mindist; j--)
//             upd_ans(a[i], t[j]);
//         t[tm++] = a[i];
//     }
// }

// int main() {
//     ios::sync_with_stdio(false); cin.tie(0);

//     int n; cin >> n;
//     for (int i=0; i<n; i++) cin >> a[i].x >> a[i].y;

//     mindist = 1E20;
//     sort(a, a+n, cmp_x);
//     find(0, n-1);

//     printf("%.6lf", mindist);
//     return 0;
// }

//  Created by NPT
// #include<iostream>
// #include<algorithm>
// #include<cmath>
// #include<map>
// #define MAX_SIZE 100006
 
// using namespace std;
// float ret_min = __FLT_MAX__;
// int N;
// int indx1, indx2;
// typedef struct Point {
//     float x;
//     float y;
//     int ind;
// } point;
// point p[MAX_SIZE];
 
// int compareX(const void*a, const void*b) {
//     Point* p1 = (Point*)a;
//     Point* p2 = (Point*)b;
//     return (p1->x - p2->x);
// }
 
// int compareY(const void*a, const void*b) {
//     Point* p1 = (Point*)a;
//     Point* p2 = (Point*)b;
//     return (p1->y - p2->y);
// }
 
// float dis(Point p1, Point p2) {
//     return sqrt((p1.x - p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
// }
 
// float minDisArr(Point P[], int n) // n is size 
// {
//     float min_d = __FLT_MAX__;
//     for(int i = 0; i< n; i++) {
//         for(int j = i+1; j<n ; j++ ) {
//             if(dis(P[i], P[j]) <= ret_min) {
//                 ret_min = dis(P[i], P[j]);
//                 indx1 = P[i].ind;
//                 indx2 = P[j].ind;
//             }
//         }
//     }
//     return ret_min;
// }
 
// float min(float x, float y)  
// {  
//     return (x < y)? x : y;  
// } 
 
// float minDisMiddle(Point strip[], int size_arr, float d) {
//     float min_d = d;
//     qsort(strip, size_arr, sizeof(point), compareY);
//     for(int i = 0; i< size_arr; i++) {
//         for(int j = i+1; j< size_arr && (strip[j].y - strip[i].y) <= ret_min; j++)
//         if(dis(strip[j], strip[i]) <= ret_min) {
//             ret_min = dis(strip[j], strip[i]);
//             indx1 = strip[i].ind;
//             indx2 = strip[j].ind;
//         }
//     }
//     return ret_min;
// }
 
// float solve(Point P[], int n) {
//     if(n<= 3)
//         return minDisArr(P, n);
//     int mid = n/2;
//     Point midPoint = P[mid];
//     float ml = solve(P,mid);
//     float mr = solve(P+mid, n-mid);
 
//     ret_min = min(ml, mr);
//     Point strip[n];
//     int j = 0;
//     for(int i = 0; i< n; i++) {
//         if (abs(P[i].x - midPoint.x) <= ret_min)
//             strip[j] = P[i], j++;
//     }
//     return min(ret_min, minDisMiddle(strip, j, ret_min));
// }
 
// int main() {
//     cin >> N;
//     for(int i = 0; i< N; i++) {
//         cin >> p[i].x >> p[i].y;
//         p[i].ind = i;
//     }
//     qsort(p, N, sizeof(point), compareX);
//     float ret = solve(p,N);
//     if (indx1 > indx2) {
//         int tmp = indx1;
//         indx1 = indx2;
//         indx2 = tmp;
//     }
//     printf("%d %d %.6f", indx1, indx2, ret);
// }