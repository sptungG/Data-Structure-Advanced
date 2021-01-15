/*
1
10 20
1 9
5 2
7 18
2 8
15 3
7 11
3 10
16 4
5 13
4 6
6 4
7 19
4 8
10 5
6 13
5 7
7 5
8 2
5 9
2 6
5 1 9 5 2 6 
--->  7
     -1
     -1 
*/
//  Created by NPT on 15/01/2021.
#include <vector>
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct dt
{
    int u, v, w,w2;
};

int t,n,m,ans,cou=0,k,dd[100007],bac[100007],flag;
dt a[100007], kq[100007],s[100007];
int root[100007];
vector <int> adj[100007];

bool comp(dt p, dt q)
{
    return p.w < q.w;
}
 
int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}
 
void Kruskal(){
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    ans = 0;
    for (int i = 1; i <= m; i++) {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        ans += a[i].w2;
    }
}

bool compareU(dt a, dt b){
    if (a.u != b.u) {
        return a.u < b.u;
    } else {
        return a.v < b.v;
    }
}


int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        flag=0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            cin >> a[i].u >> a[i].v >> a[i].w;
            a[i].w2 = a[i].w;
        }
        for(int i=1;i<=n;i++){
            bac[i]=0;
        }
        cin >> k;
        for (int i=1; i<=k; i++) {
            cin >> s[i].u >> s[i].v;
            bac[s[i].u]++;
            bac[s[i].v]++;
            adj[s[i].u].push_back(s[i].v);
            adj[s[i].v].push_back(s[i].u);
            for (int j=1; j<=m; j++) {
                if ((s[i].u == a[j].u && s[i].v == a[j].v) ||  (s[i].u == a[j].v && s[i].v == a[j].u)){
                    s[i].w = a[j].w;
                    a[j].w = -1;
                    break;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            if (bac[i]%2==1) {
                flag=1;
            }
        }
        if (k+1!=n-1 || flag==0){
            cout << -1 << endl;
        } else {
            Kruskal();
            cout << ans << endl;
        }
    }
    return 0;
}