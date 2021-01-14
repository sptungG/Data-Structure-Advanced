/*
Given a undirected connected graph G=(V,E) where V={1,…,N}.
 Each edge (u,v)∈E has weight w(u,v).
 Compute minimum spanning tree of G.

Input
Line 1: N and M (1 ≤ N,M ≤ 1e5) in which N is the number of nodes 
                                and M is the number of edges.
Line i+1 (i=1,…,M): contains 3 positive integers u, v, 
                    and w where w is the weight of edge (u,v)
Output
 Write the weight of the minimum spanning tree found.

Example
 input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
 output
7
*/
//  Created by NPT
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
 
struct dt
{
    int u, v, w;
};
 
int n, m, cou = 0;
long long ans;
dt a[100007], kq[100007];
int root[100007];
 
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
}
 
bool comp(dt p, dt q)
{
    return p.w < q.w;
}
 
int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}
 
void Kruskal()
{
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        ans += a[i].w;
        kq[++cou] = a[i];
        //kq.push_back(a[i]);
    }
}
 
bool compareU(dt a, dt b){
    if (a.u != b.u) {
        return a.u < b.u;
    } else {
        return a.v < b.v;
    }
}
 
void Ghikq()
{
    cout << ans << endl;
  
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    nhap();
    Kruskal();
    Ghikq();
    return 0;
}