/*
Cho 1 một số n.
=> Đưa ra hoán vị độ dài n thứ k trong thứ tự từ điển.
**Input
 Dòng đầu ghi 2 số nguyên dương n,k (n≤104^,k≤10^9) cách nhau bởi dấu cách.
**Output
  Ghi ra hoán vị thứ k trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách.
   Nếu không tồn tại thì ghi ra -1.
TEST
3 4
=> 2 3 1  
-----------------------------------
*/
#include <iostream>
using namespace std;

int n, k, cnt = 0;
int a[10002];

void solution(){
    cnt++;
    if (cnt == k) {
        for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
        exit(0) ;
    }
}

int main(){
    cin >> n >> k;
    if (n == 0) {
        cout << -1 << '\n';
        exit(0);
    }
    for (int i = 1; i <= n; i++) a[i] = i;

    int i = n;
    do{
        solution();
        i = n - 1;
        while ( i > 0 && a[i] > a[i + 1]) i--;
        if (i > 0){
            int k = n;
            while (a[k] < a[i]) k--;
            swap(a[k], a[i]);

            int p = i + 1, q = n;
            while (p < q){
                swap(a[p], a[q]);
                p++;
                q--;
            }
        }
    } while (i > 0);
    cout << -1 << '\n';
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, k;
// int cnt = 0;
// int x[10001];
// bool mark[10001];

// void print(){
//     cnt++;
//     if (cnt == k){
//         for (int i = 1; i <= n; i++) cout << x[i] << ' ';
//         exit(0);
//     }
// }

// void TRY(int k){
//     for (int v = 1; v <= n; v++){
//         if (!mark[v]){
//             x[k] = v;
//             mark[v] = true;
//             if (k == n) print();
//             else TRY(k + 1);
//             mark[v] = false;
//         }
//     }
// }


// int main(){
//     cin >> n >> k;
//     TRY(1);
//     if (cnt < k) cout << -1 << endl;
// }