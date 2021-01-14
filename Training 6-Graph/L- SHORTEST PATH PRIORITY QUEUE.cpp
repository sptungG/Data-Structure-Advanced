/*
Given a directed graph G=(V,A) where V={1,…,n} is the set of nodes. 
Each arc (u,v)∈A has weight w(u,v). 
Given s, t ∈ V, compute the shortest path from s to t.

Input
Line 1: n and m (1≤ n ≤1e5,1≤ m ≤1e6)
Line i+1 (i=1,…,m): positive integers u, v, and w in which w is the weight of arc (u,v)
Line m+2: s, t

Output
Write the weight of the shortest path found 
        or -1 if no path from s to t exists.

Example
 input
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5
 output
97
*/
//  Created by NPT
#include <bits/stdc++.h>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef pair <int,int> ii;
vector <ii> a[100007];
long n,m,d[100007];
 
void dijkstra(int s)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[s]=0;
    pq.push(ii(0,s));
 
    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                pq.push(ii(-d[v],v));
            }
        }
    }
}
int main() {
    cin>>n>>m;
    long u,v,w;
    for (long i=1;i<=m;i++)
    {
        cin >>u>>v>>w;
        a[u].push_back(ii(v,w));
    }
    int s,t;
    cin >> s >> t;
    dijkstra(s);
    if (d[t] == 0) cout << -1;
    else cout<<d[t]<<endl;
}