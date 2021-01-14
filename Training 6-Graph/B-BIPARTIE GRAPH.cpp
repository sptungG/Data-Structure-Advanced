/*
Given a undirected graph G = (V, E) in which V={1, …, N} is the set of nodes and | E | = M.
 You are required to write a program to check if G is a bipartie graph.

Input
 Line 1 N and M (1≤N,M≤105)
 Line i+1 (i=1,…,M): u and v which are endpoints of the ith edge
Output
 Write 1 if G is a bipartie graph and 0, otherwise.

Example
input
6 6
1 2
1 3
2 5
2 6
4 5
4 6
output
1
*/
//  Created by NPT
#include <bits/stdc++.h>
#include <vector>
#include <queue>
 
using namespace std;
 
int n,m,dd[100007],flag = true;
vector <int> a[100007];
 
void dfs(long u) {
    for (int i=0; i<a[u].size(); i++) {
        int v = a[u][i];
        if (dd[v] == dd[u]) {
            flag = false;
            return;
        }
        if (dd[v] == -1) {
            dd[v] = 1 - dd[u];
            dfs(v);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(dd,-1,sizeof(dd));
    for (int i=1; i<=n; i++) {
        if (dd[i] == -1) {
            dd[i] = 0;
            dfs(i);
        }
    }
    if (flag == true) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}