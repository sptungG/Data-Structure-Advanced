/*
2
5 7
1 2
1 3
2 3
2 4
2 5
3 4
4 5
3 1 3 4
5 7
1 2
1 3
2 3
2 4
2 5
3 4
4 5
4 1 3 5 4
-->  1    
    0
*/
//Created by NTN NPT
#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
vector <int> a[MAX];
int b[MAX];
int T;
int n,m;
int u,v,k;
int ans=0;
void input(){
    cin >> n >> m;
        for (int j=1; j<=m; j++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cin >> k;
        for (int i=1; i<=k; i++) {
            cin >> b[i];
        } 
}
void solve(){
     for (int i=2; i<=k; i++) {
         ans=0;
        for (int j=0; j<a[b[i-1]].size(); j++) {
            if (a[b[i-1]][j] == b[i]) {
                ans = 1;
                break;
            }
        }
        if (ans == 0) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1<< endl;
}
int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        input();
        solve(); 
    }
return 0;
}