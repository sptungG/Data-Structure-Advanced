// input
// 5 7 3 6
// 1 2 1 2
// 1 4 2 2
// 1 5 3 6
// 2 3 3 2
// 2 4 4 4
// 3 4 5 1
// 4 5 4 7
// output
// 6
//  Created by NPT
#include <iostream>
#include <vector>
 
using namespace std;
vector <int> a[60];
int n,m,k,q,x[60],dd[60],a1[60][60],a2[60][60],ans=999999999,sum1=0,sum2=0,mina1=999999999,mina2=999999999;
 
bool check(int i, int v){
    if (dd[v]==1) {
        return false;
    }
//    if (sum1+a2[x[i-1]][v]>q) {
//        return false;
//    }
    if (sum1+a2[x[i-1]][v]+mina1*(k+1-i)>q) {
        return false;
    }
    if (sum2+a1[x[i-1]][v]>ans) {
        return false;
    }
    return true;
}
 
void tryy(int i){
    for (int j=0; j<a[x[i-1]].size(); j++) {
        int v = a[x[i-1]][j];
        if (check(i, v)) {
            x[i]=v;
            dd[v]=1;
            sum1+=a2[x[i-1]][x[i]];
            sum2+=a1[x[i-1]][x[i]];
            if (i==k+1) {
                ans = ans < sum2 ? ans : sum2;
            } else {
                if (sum2+(k+1-i)*mina1<ans) tryy(i+1);
            }
            dd[v]=0;
            sum1-=a2[x[i-1]][x[i]];
            sum2-=a1[x[i-1]][x[i]];
        }
    }
}
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    int u,v,w1,w2;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w1 >> w2;
        a[u].push_back(v);
        a[v].push_back(u);
        mina1 = mina1 < w1 ? mina1 : w1;
        mina2 = mina2 < w2 ? mina2 : w2;
        a1[u][v] = w1;
        a1[v][u] = w1;
        a2[u][v] = w2;
        a2[v][u] = w2;
    }
    for (int i=1; i<=n; i++) {
        x[1] = i;
        dd[i] = 1;
        tryy(2);
        dd[i] = 0;
    }
    if (ans == 999999999) cout << -1;
    else cout << ans;
    return 0;
}