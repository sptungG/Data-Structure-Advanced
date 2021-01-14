/*
A distribution company distribute goods to M retail outlets 1,2,…,M. It has N branches 1,2,...,N.
   Each branch i has ai salesman.
The company have to assign M retail outlets to N branches: 
   each branch is responsible to distribute goods to some retail outlets,
   each retail outlet is distributed by one branch.
 In order to balance among salesman, the number of retail outlets assigned to each branch i must be positive and divisible by ai.
=>> Compute the total number Q of ways of such assignment.
(Example, N = 2, M = 20, a1 = 3, a2 = 2. There are 3 ways:
Branch 1 is assigned to 6 retail outlets, branch 2 is assigned to 14 retail outlets
Branch 1 is assigned to 12 retail outlets, branch 2 is assigned to 8 retail outlets
Branch 1 is assigned to 18 retail outlets, branch 2 is assigned to 2 retail outlets)
**Input
  Line 1: N and M (1≤N≤100,1≤M≤500)
  Line 2: N positive integers a1,…,aN (1≤ai≤10,i=1,…,N)
**Output
  Write the value Q modulo (10^9+7)
TEST
2 20
3 2
=> 3
-----------------------------------------
*/
//  Created by NPT
#include <iostream>

using  namespace std;

int n,m,a[107],s[107][1007], q=1000000007;

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=m/a[1]+1; i++) {
        s[1][a[1]*i] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int k=1; k<=m/a[i]+1; k++) {
                if (s[i-1][j-a[i]*k] != 0 && j-a[i]*k>0)
                  s[i][j] = (s[i][j]+s[i-1][j-a[i]*k])%q;
            }
        }
    }
    cout << s[n][m];
    return 0;
}
// #include <iostream>
// #define MAXN 102
// #define MAXM 502
// #define MOD 1000000007
// using namespace std;
 
// int N, M;
// int a[MAXN];
// int F[MAXN][MAXM];
 
 
// void Solve(){
//     //f[n,M] = f[n-1,M-a[n]] + f[n-1 , M-2a[n]]  +  ...
//     for (int i = 1; i <= N; i++) {
//         F[i][0] = 1;
//         for (int j = 1; j <= M; j++) {
//         int x = (j - a[i] >= 0) ? F[i][j - a[i]] : 0;
//             F[i][j] = (x + F[i - 1][j]) % MOD;
//                         //cout<<F[i][j]<<" ";
//         }
//                 //cout<<"\n";
//     }
    
//     cout << F[N][M];
// }
 
// void Input(){
//     cin >> N >> M;
//     for(int i = 1; i<=N; i++){
//         cin >> a[i];
//         M -= a[i];
//     }
// }
 
// int main() {
//     Input();
//     Solve();
    
//     return 0;
// }