/*
Given a sequence of n integers a0,…,an−1.
We denote rmq(i,j) the minimum element of the sequence ai,ai+1,…,aj. 
Given m pairs (i1,j1),…,(im,jm),
=>>>>>>>>compute the sum Q=∑mk=1rmq(ik,jk)
**Input
  Line 1: n (1≤n≤106)
  Line 2: a0,…,an−1 (1≤ai≤106)
  line 3: m (1≤m≤106)
  Line k+3 (k=1,…,m): ik,jk (0≤ik<jk<n)
**Output
  Write the value Q
*Scoring: 50% tests with 1≤n≤5000
TEST
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10
=>>6
--------------------------------
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n,a[1000007],m,d[4000007];

int min(int a, int b){
    return a < b ? a : b;
}

void build(int node,int L,int R){
    if (L==R)
    {
        d[node]=a[L];
        return;
    };
    int mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=min(d[node*2],d[node*2+1]);
}

int get(int id,int L,int R,int u,int v){
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 100000000;
    int mid=(L+R) /2 ;
    int x1=get(id*2,L,mid,u,v);
    int x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    cin >> m;
    build(1, 1, n);
    int ans = 0;
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        ans += get(1,1,n,u+1,v+1);
    }
    cout << ans;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// const int MAX = 1e6+5;
// const int K = 20;

// int n, m;
// int a[MAX];
// int s, t;
// int dp[MAX][K];
// int lg[MAX];
// long long res = 0;

// int main() {
//     ios::sync_with_stdio(false); cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     cin >> m;
//     for (int i = 0; i < n; i++) {
//         dp[i][0] = a[i];
//     }
//     lg[1] = 0;
//     for (int i = 2; i <= MAX; i++) {
//         lg[i] = lg[i/2] + 1;
//     }
//     for (int j = 1; j <= K; j++) {
//         for (int i = 0; i + (1 << j) <= n; i++) {
//             dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j - 1))][j - 1]);
//         }
//     }
//     for (int i = 1; i <= m; i++) {
//         cin >> s >> t;
//         int j = lg[t - s + 1];
//         res += min(dp[s][j], dp[t - (1 << j) + 1][j]);
//     }
   
//     cout << res;
//     return 0;
//     for (int j = 1; j <= K; j++) {
//         for (int i = 0; i + (1 << j) <= n; i++) {
//             cout << "dp[" << i << "]["  << j << "] = " << dp[i][j] << endl;
//         }
//     }
// }