/*
Farmer John has built a new long barn, with N (2≤N≤100,000) stalls.
  The stalls are located along a straight line at positions x1,…,xN (0≤xi≤1,000,000,000).
His C (2≤C≤N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible.
===What is the largest minimum distance?
**Input
t – the number of test cases, then t test cases follows.
Line 1: Two space-separated integers: N and C
Lines 2…N+1: Line i+1 contains an integer stall location, xi
**Output
For each test case output one integer: the largest minimum distance.
   TEST
1
5 3
1
2
8
4
9
==>>3
NOTED: FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
---------------------------------------
*/
#include <bits/stdc++.h>  
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int N, C, T;
int X[MAX + 1];

bool caculate(int lamda){
    int cnt = 1;
    int first = 2;
    int pre  = X[1];

    while (first <= N){
        if (X[first] - pre >= lamda){
            cnt++;
            pre = X[first];
            first++;
        }
        else first++;

        if (cnt >= C) return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> N >> C;
        int d_max = -1;
        for (int i = 1; i <= N; i++){
            cin >> X[i];
            d_max = max(d_max, X[i]);
        }
        sort(X + 1, X + N + 1);

        int res = 0;
        int d_min = 1;
        while (d_min <= d_max){
            int d = (d_min + d_max) / 2;
            if (caculate(d)){
                res = max(res, d);
                d_min = d + 1;
            }
            else d_max = d - 1;
        }

        cout << res <<endl;
    }
}
//  Created by NPT
// #include <bits/stdc++.h>
 
// using namespace std;
 
// int n, c, x[100007], ans;
 
// bool check(int m){
//     int tmpC = c-1;
//     int last = 1;
//     for (int i=2; i<=n; i++) {
//         if (x[i] - x[last] >= m) {
//             tmpC--;
//             last = i;
//         }
//         if (tmpC == 0) {
//             return true;
//         }
//     }
//     return false;
// }
 
// int main() {
//     ios_base::sync_with_stdio(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         int xmax = -1;
//         cin >> n >> c;
//         for (int i=1; i<=n; i++) {
//             cin >> x[i];
//             if (xmax < x[i]) {
//                 xmax = x[i];
//             }
//         }
//         sort(x+1, x+n+1);
//         int l = 0, r = xmax+1, mid;
//         while (r-l>1) {
//             mid = (l+r)/2;
//             if (check(mid)) {
//                 ans = mid;
//                 l = mid;
//             } else {
//                 r = mid;
//             }
//         }
//         if (check(r)) ans = r;
//         cout << ans << endl;
//     }
    
//     return 0;
// }