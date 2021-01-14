/*
Given a undirected tree G=(V,E) in which V={1,…,N} is the set of nodes.
 Each edge (u,v)∈E has weight w(u,v).
 The length of a path is defined to be the sum of weights of edges of this path.
Find the longest elementary path on G.

Input
Line 1: positive integer N (1≤ N ≤10e5)
Line i+1 (i=1,…,N−1):positive integers u,v,w 
                     in which w is the weight of edge (u,v) (1 ≤ w ≤ 100)
Output
 The weight of the longest path on the given tree

Example
 input
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
 output
10
*/
//  Created by NPT
#include <bits/stdc++.h>
#include <vector>
#include <queue>
 
using namespace std;
typedef pair <long,long> ii;

long n,d1[1000007],d2[1000007];
bool dd[1000007];
vector <ii> a[1000007];

void dfs(long u) {
    dd[u]=false;
    for (long i=0; i<a[u].size(); i++) {
        long v = a[u][i].first;
        if (dd[v]) {
           dfs(v);
           if (d1[u]<d1[v]+a[u][i].second) {
             d2[u]=d1[u];
             d1[u]=d1[v]+a[u][i].second;
           } else if (d2[u]<d1[v]+a[u][i].second) d2[u]=d1[v]+a[u][i].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long i=1; i<n; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    memset(dd,true,sizeof(dd));
    dfs(1);
    long ans=-1;
    for (long i=1; i<=n; i++)
       ans=max(ans,d1[i]+d2[i]);
       //cout << i << " "<< d1[i] << " " << d2[i] << endl;
    cout << ans;
}

// cach 2: dung dfs tim duong di dai nhat tu diem 1 den diem do (goi diem do la k), sau do dung dfs tim duong di dai nhat tu k den cac dinh con lai, do chinh la duong di dai nhat

//#include <bits/stdc++.h>
//
//using namespace std;
//typedef pair <long,long> ii;
//
//long n,d[1000007],vtmax;
//bool dd[1000007];
//vector <ii> a[1000007];
//
//void dfs(long u)
//{
//    dd[u]=false;
//    for (long i=0; i<a[u].size(); i++)
//    {
//        long v=a[u][i].first;
//        if (dd[v])
//         {
//            d[v]=d[u]+a[u][i].second;
//            dfs(v);
//         }
//    }
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    freopen("longest_path.inp","r",stdin);
//    freopen("longest_path.out","w",stdout);
//    cin >> n;
//    for (long i=1; i<n; i++)
//    {
//        long u,v,w;
//        cin >> u >> v >> w;
//        a[u].push_back(ii(v,w));
//        a[v].push_back(ii(u,w));
//    }
//    for (long i=1; i<=n; i++) dd[i]=true;
//
//    dfs(1);
//    for (long i=2; i<=n; i++)
//      if (d[i]>d[1])
//       {
//          d[1]=d[i];
//          vtmax=i;
//       }
//
//    for (long i=1; i<=n; i++) {d[i]=0; dd[i]=true;}
//    dfs(vtmax);
//    for (long i=1; i<=n; i++)
//      if (d[i]>d[vtmax]) d[vtmax]=d[i];
//
//    cout << d[vtmax];
//}
