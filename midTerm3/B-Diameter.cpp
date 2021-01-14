// input
// 6 10
// 1 2 2
// 1 5 6
// 1 6 1
// 2 3 8
// 2 6 4
// 3 4 7
// 3 6 2
// 4 5 3
// 4 6 5
// 5 6 4
// 3
// 1 3 4
// output
// 7
//  Created by NPT
#include <bits/stdc++.h>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef pair <int,int> ii;
vector <ii> a[200007];
int n,m,k,s[107],d[10007];
 
void dijkstra(int bg)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[bg]=0;
    pq.push(ii(0,bg));
 
    int u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first;
            int wv=a[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                pq.push(ii(-d[v],v));
            }
        }
    }
}
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int u,v,w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> s[i];
    }
    int ans = -1;
    for (int i=1; i<=k; i++) {
        dijkstra(s[i]);
        for (int j=i+1; j<=k; j++) {
            ans = max(ans,d[s[j]]);
        }
    }
    cout << ans;
    return 0;
}