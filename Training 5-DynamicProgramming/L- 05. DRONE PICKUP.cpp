//
//  main.cpp
//  Training5_DRONE PICKUP
/*
A Drone is planned to fly from point 1 to point N in which it can stop at some points among 1,2,…,N.
These points are located on a line, point i has coordinate i. Each point i is associated with
  ci: amount of good
  ai: amount of energy
When the drone stops at point i, it takes the amount ci of good and the amount ai of energy.
After that, it can fly farthest to point i+ai (it can stops at some point among i+1,i+2,…,i+ai).
  Due to technical constraints, the Drone can only stop at at most K+1 point.
==>>Compute the route (sequence of points at which the drone stops to take goods and energy) starting from point 1 and terminating at point N 
                      such that the total amount of goods is maximal (points 1 and N are considered as points that the Drone stop).
**Input
  Line 1: N and K (1≤N≤3000,1≤K≤100)
  Line 2: N positive integers c1,c2,…,cN (1≤ci≤20,∀i=1,…,N)
  Line 3: N positive integers a1,a2,…,aN (1≤ai≤50,∀i=1,…,N)
**Output
  Total amount of goods that the Drone takes during the route, or value -1 if no route exists.
TEST
6 3
3 1 4 2 2 2
2 3 1 1 3 1
=>8
-------------------------------------------------
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n,k,c[3007],a[3007],s[3007][107];

int main() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    s[1][1] = c[1];
    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (j+a[j] >= i) {
                for (int u=1; u<=k+1; u++) {
                    if (s[j][u-1] != 0) s[i][u] = s[i][u] < c[i] + s[j][u-1] ? c[i] + s[j][u-1] : s[i][u];
                }
            }
        }
    }
    int ans = -1;
//    for (int j=1; j<=n; j++) {
//        for (int i=1; i<=k+1; i++) {
//            cout << s[j][i] << " ";
//        }
//        cout << endl;
//    }
    for (int i=1; i<=k+1; i++) {
        ans = ans < s[n][i] ? s[n][i] : ans;
    }
    cout << ans;
    return 0;
}
// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// using namespace std;
// #define MAXN 3002
// #define MAXK 102
 
// int n, k;
// int a[MAXN], c[MAXN];
// int L[MAXK][MAXN];
  
// void Solve(){
//     L[1][1] = c[1];
//     for(int i = 2; i<=n; i++){
//         if ( i <= 1 + a[1])
//             L[1][i] = c[1] + c[i];
//     }
    
//     for(int i =2; i<=k; i++){
//         for(int j =2; j<=n; j++){
            
//             int max = 0;
//             for(int p=1; p<j;p++){
//                 if (a[p] + p >= j && L[i-1][p] !=0){
//                     if (max < L[i-1][p] + c[j]){
//                         max = L[i-1][p] + c[j];
//                     }
//                 }
//             }
//             L[i][j] = max;
//         }
//     }
    
//     /*for(int i =1; i<=k;i++){
//         for(int j =1; j<=n;j++){
//             cout << L[i][j] << " ";
//         }
//         cout << endl;
//     }*/
//     cout << L[k][n];
    
// }
 
// void Input(){
//     cin >> n >> k;
//     for(int i = 1; i<=n; i++){
//         cin >> c[i];
//     }
//     for(int i = 1; i<=n; i++){
//         cin >> a[i];
//     }
// }
 
// int main() {
//     Input();
//     Solve();
    
//     return 0;
// }