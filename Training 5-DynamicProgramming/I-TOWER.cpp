/*
Perhaps you have heard of the legend of the Tower of Babylon.
Nowadays many details of this tale have been forgotten.
So now, in line with the educational nature of this contest, we will tell you the whole story:
The babylonians had n types of blocks, and an unlimited supply of blocks of each type.
 Each type-i block was a rectangular solid with linear dimensions (xi,yi,zi).
 A block could be reoriented so that any two of its three dimensions determined the dimensions of the base and the other dimension was the height.
 They wanted to construct the tallest tower possible by stacking blocks.
 The problem was that, in building a tower, one block could only be placed on top of another block as long 
 as the two base dimensions of the upper block were both strictly smaller than the corresponding base dimensions of the lower block.
(This meant, for example, that blocks oriented to have equal-sized bases couldn't be stacked.)
==>>Your job is to write a program that determines the height of the tallest tower the babylonians can build with a given set of blocks.
**Input
The input file will contain one or more test cases.
The first line of each test case contains an integer n, representing the number of different blocks in the following data set.
        The maximum value for n is 30. Each of the next n lines contains three integers representing the values xi,yi and zi.
Input is terminated by a value of zero (0) for n.
**Output
For each test case, print one line containing the case number (they are numbered sequentially starting from 1) 
               and the height of the tallest possible tower in the format "Case case: maximum height = height"
 TEST
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
==>
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342
------------------------------------------
*/
//  Created by NPT
#include <bits/stdc++.h>

using namespace std;

typedef struct blockT{
    int x,y,h;
} block;

int n, nn, d[1000], ans;
block b[1000];

bool compareX(block a, block b){
    if (a.x == b.x){
        if (a.y == b.y) return a.h < b.h;
        else return a.y > b.y;
    }
    return a.x > b.x;
}

int main(int argc, const char * argv[]) {
    int dem = 0;
    while (1<2){
        dem++;
        ans = -1;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        nn=0;
        for (int i=1; i<=n; i++) {
            int x,y,z;
            cin >> x >> y >> z;
            nn++;
            b[nn].x = x; b[nn].y = y; b[nn].h = z;
            nn++;
            b[nn].x = y; b[nn].y = x; b[nn].h = z;
            
            nn++;
            b[nn].x = z; b[nn].y = y; b[nn].h = x;
            nn++;
            b[nn].x = y; b[nn].y = z; b[nn].h = x;
            
            nn++;
            b[nn].x = x; b[nn].y = z; b[nn].h = y;
            nn++;
            b[nn].x = z; b[nn].y = x; b[nn].h = y;
        }
        sort(b+1, b+nn+1, compareX);
        for (int i=1; i<=nn; i++) {
            d[i] = b[i].h;
        }
        for (int i=1; i<=nn; i++) {
            for (int j=1; j<i; j++) {
                if (b[j].x > b[i].x && b[j].y > b[i].y) {
                    d[i] = d[i] < d[j] + b[i].h ? d[j] + b[i].h : d[i];
                }
            }
            ans = ans < d[i] ? d[i] : ans;
        }
        cout << "Case " << dem << ": maximum height = " << ans << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// typedef struct {
//     int x, y, z;
// } block;

// int n;
// block a[100];
// int maxh[100];

// void init(){
//     memset(a, 0, sizeof(a));
//     memset(maxh, 0, sizeof(maxh));
// }

// void input(){
//     cin >> n;
//     if (n == 0) exit(0);
//     int x, y, z;
//     for (int i = 1; i <= n; i++){
//         cin >> x >> y >> z;
//         a[3 * i - 2].x = x;
//         a[3 * i - 2].y = y;
//         a[3 * i - 2].z = z;
//         a[3 * i - 1].x = y;
//         a[3 * i - 1].y = z;
//         a[3 * i - 1].z = x;
//         a[3 * i].x = z;
//         a[3 * i].y = x;
//         a[3 * i].z = y;
//     }
// }

// int dp(int i){//Tim chieu cao cua toa thap voi dinh la vien i
//     if (maxh[i] != 0) return maxh[i];
//     maxh[i] = a[i].z;
//     for(int j = 1; j <= 3 * n; j++){
//         if (a[i].x < a[j].x && a[i].y < a[j].y ||
//             a[i].x < a[j].y && a[i].y < a[j].x){
//             maxh[i] = max (maxh[i], a[i].z + dp(j));
//         }
//     }
//     return maxh[i];
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     int cnt = 1;
//     while(1){
//         int res = 0;
//         init();
//         input();
//         for(int i = 1; i <= 3 * n; i++){
//             res = max(res, dp(i));
//         }
//         printf("Case %d: maximum height = %d\n", cnt++, res);
//     }
//     return 0;
// }