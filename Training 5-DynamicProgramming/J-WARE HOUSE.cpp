/*
A truck is planned to arrive at some stations among N stations 1,2,...,N located on a line. 
Station i (i=1,…,N) has coordinate i and has following information
    ai: amount of goods 
    ti: pickup time duration for taking goods
The route of the truck is a sequence of stations x1<x2<...<xk (1≤xj≤N,j=1,…,k).
Due to technical constraints, the distance between two consecutive stations that
 the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T.
=>>Find a route for the truck such that total amount of goods picked up is maximal.
**Input
  Line 1: N,T,D (1≤N≤1000,1≤T≤100,1≤D≤10)
  Line 2: a1,…,aN(1≤ai≤10)
  Line 3: t1,…,tN(1≤ti≤10)
**Output
Write the total amount of goods that the truck picks up in the route.
TEST
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
=>24
--------------------------------------
*/
//  Created by NPT
#include <iostream>
#include <deque>

using namespace std;

int N,T,D,a[1007],t[1007],S[1007][1007],ans=0,rs;

void solve(){
    for (int k = 1;k<=T;k++){
      if (k != t[0]) S[0][k] = 0;
      else S[0][k] = a[0];
    }
    for (int i = 1; i<=N;i++){
        for (int k = 0;k<=T;k++){
            if(k!=t[i]) S[i][k] = 0;
            else S[i][k] = a[i];
 
            for (int d=1;d<=D;d++){
                int j = i-d;
                if(j>=0 && k>=t[i] && S[j][k-t[i]] > 0){
                    if(S[i][k] < S[j][k-t[i]] + a[i])
                        S[i][k] = S[j][k-t[i]] + a[i];
                }
            }
        }
    }
    rs = 0;
    for (int i = 0;i<N;i++){
        for (int k = 0;k<=T;k++){
            if(S[i][k]>rs) rs = S[i][k];
        }
    }
    cout << rs;
}
 
int main()
{
    cin >>N>>T>>D;
    for (int i = 1;i<=N;i++){
        cin >> a[i];
    }
    for (int i = 1;i<=N;i++){
        cin >> t[i];
    }
    solve();
    return 0;
}

//#include <iostream> // 40 diem ko biet sao sai
//
//using namespace std;
//
//typedef struct routeT{
//    int aa,tt;
//} route;
//
//int n,t,d,a[1007],ti[1007];
//route dd[1007][1007];
//int cou[1007];
//
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(0);
//    cin >> n >> t >> d;
//    for (int i=1; i<=n; i++) {
//        cin >> a[i];
//        cou[i] = 1;
//        dd[i][1].aa = a[i];
//    }
//    for (int i=1; i<=n; i++) {
//        cin >> ti[i];
//        dd[i][1].tt = ti[i];
//    }
//    for (int i=2; i<=n; i++) {
//        int ii = 1 < (i-d) ? (i-d) : 1;
//        for (int j=ii; j<=i-1; j++) {
//            for (int k=1; k<=cou[j]; k++) {
//                if (dd[j][k].tt + ti[i] <= t) {
//                    cou[i]++;
//                    dd[i][cou[i]].aa = dd[j][k].aa + a[i];
//                    dd[i][cou[i]].tt = dd[j][k].tt + ti[i];
//                }
//            }
//        }
//    }
//    int ans = -1;
//    for (int i=1; i<=n; i++) {
//        for (int j=1; j<=cou[i]; j++) {
//            ans = ans < dd[i][j].aa ? dd[i][j].aa : ans;
//        }
//    }
//    cout << ans;
//    return 0;
//}

// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #define MAXN 1002
// #define MAXT 102
// using namespace std;
 
// int N, T, D;
// int a[MAXN], t[MAXN];
// int W[MAXT][MAXN];
 
// void Solve(){
//     for(int i =1; i<=T; i++){
//         for(int j =1; j<=N; j++){
//             int p = i - t[j];
//             if (p>=0) {
//                 int max = 0;
//                 for (int k = 1; k<=D; k++) {
//                     if (j-k>0 && max < W[p][j-k]) {
//                         max = W[p][j-k];
//                     }
//                 }
//                 W[i][j] = max + a[j];
//             } else {
//                 W[i][j] = 0;
//             }
//         }
//     }
    
// //    for(int i =1; i<=T;i++){
// //        for(int j =1; j<=N;j++){
// //            cout << W[i][j] << " ";
// //        }
// //        cout << endl;
// //    }
// int max = 0;
// for (int i = 1; i <= N; i++) {
//         if (max < W[T][i]) {
//             max = W[T][i];
//         }
//     }
//     cout << max;
// }

//  void Input(){
//     cin >> N >> T >> D;
//     for(int i = 1; i<=N; i++){
//         cin >> a[i];
//     }
//     for(int i = 1; i<=N; i++){
//         cin >> t[i];
//     }
// }
 
// int main() {
//     Input();
//     Solve();
    
//     return 0;
// }