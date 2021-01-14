/*
The network administrator of a company have to analyze the current state of their communication network all over the world.
 The communication network consists of servers and cable links between these servers, each link has a cost.
 A k-route is a sequence of k+1 different servers in which two consecutive servers are connected by a cable link.
 A cycle is a k-route (for any k>1) such that the beginning and the terminating servers are connected by a cable link.
 The communication network contains no cycle. The cost of a k-route is the sum of cost of links between two consecutive servers of the k-route. 
 One of the indicators of the analysis is the k-route having minimal cost of the network for a given value of k.
Given the communication network G and an integral value k, help the network administrator to find the k-route having minimal cost of G.

Input
The input consists of following lines
 Line 1: contains two integer n and k (1≤n≤10000, 1≤k≤2000) in which n is the number of servers of
                                       the communication network G (servers are numbered 1,2,...,n)
 Line 2: contains an integer m (1 ≤ m ≤ 10000) which is the number of cable links between servers of G
 Line i+2: contains three integers u, v, and w: u and v are two end points of the ith link of G (∀i=1,…,m),
                                                w is the cost of this link.
Output
 The output contains the cost of the k-route found.

Example
 input
6 2
5
1 2 4
1 4 1
1 5 3
1 6 2
2 3 1
 output
3

*/
//  Created by NPT
#include <bits/stdc++.h>
#include <vector>
#include <queue>
 
#define nmax 10007

using namespace std;
 
typedef pair <int, int> ii;
 
vector <ii> adj[nmax];
int n,k,m,h[nmax],par[nmax][20],h0,cl[nmax],cur[nmax],dd[nmax],s[nmax],leng[nmax];

void dfs(int xp) {
    //tinh h(chieu cao) cua tung nut, va par[u][i] la nut cha 2^i cua u
    for (int i=1; i<=n; i++) dd[i]=cur[i]=0;
    int sn=0;
    dd[xp]=1;
    s[++sn]=xp;
    h[xp]=0;
    par[xp][0]=0;
    leng[xp] = 0;
    while (sn) {
        int u=s[sn];
        if (cur[u]<adj[u].size()) {
            int v = adj[u][cur[u]].first;
            if (dd[v] == 0) {
                leng[v] = leng[u] + adj[u][cur[u]].second;
                dd[v] = 1;
                s[++sn] = v;
                h[v] = h[u] + 1;
                par[v][0] = u;
            }
            cur[u]++;
        } else sn--;
    }
    for (int k=1; k<=h0; k++)//h0 la log(10000)
      for (int u=1; u<=n; u++)
        par[u][k]=par[par[u][k-1]][k-1];
}

int LCAs(int u, int v)
{
    //nhay 2 nut ve cun do cao
    if (h[u]<h[v]) swap(u,v);
    int del=h[u]-h[v];
    for (int i=0; i<=h0; i++)
        if ((del >> i )& 1) u=par[u][i];
    if (u==v) return u;

    //nhay len dan,neu gap 2 nut cung nhau thi ko nhay, khac nhau moi nhay
    for (int i=h0; i>=0 ; i--)
      if (par[u][i]!=par[v][i])
        {
          u=par[u][i];
          v=par[v][i];
        }
    return par[u][0];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(v,w));
        adj[v].push_back(ii(u,w));
    }
    h0 = log(n);
    dfs(1);
    int ans = 999999999;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int cc = LCAs(i, j);
            if (h[j]+h[i]-2*h[cc]+1 == k+1) {
                ans = min(ans, leng[i]+leng[j]-2*leng[cc]);
            }
        }
    }
    cout << ans;
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
 
// using namespace std;
 
// typedef pair <int, int> ii;
 
// vector <ii> g[10007];
// int n,k,m,d[10007],cou[10007];
 
// void bfs(int uu) {
//     for (int i=1; i<=n; i++) {
//         d[i] = 0;
//         cou[i] = 0;
//     }
//     queue <int> qu;
//     qu.push(uu);
//     d[uu] = 1;
//     cou[uu] = 1;
 
//     while (qu.size()) {
//         int u = qu.front();
//         qu.pop();
 
//         for (int i = 0; i < g[u].size(); i++) {
//             int v = g[u][i].first;
//             if (cou[u] == k+1) {
//                 continue;
//             }
//             if (d[v] == 0) {
//                 d[v] = d[u] + g[u][i].second;
//                 cou[v] = cou[u] + 1;
//                 qu.push(v);
//             }
//         }
//     }
// }
 
// int main(int argc, const char * argv[]) {
//     ios_base::sync_with_stdio(0);
//     cin >> n >> k >> m;
//     for (int i=1; i<=m; i++) {
//         int u,v,w;
//         cin >> u >> v >> w;
//         g[u].push_back(ii(v,w));
//         g[v].push_back(ii(u,w));
//     }
//     int ans = 999999999;
//     for (int i=1; i<=n; i++) {
//         bfs(i);
//         for (int j=1; j<=n; j++) {
//             if (i!=j && cou[j]==k+1) {
//                 ans = ans < d[j] ? ans : d[j];
//             }
//         }
//     }
//     cout << ans-1;
//     return 0;
// }
