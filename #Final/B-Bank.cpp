/*
2
4 4
1000 1
2000 2
500 2
1200 0
3 4
1000 0
2000 1
500 1

 4200  (7200)
3000

*/
//Created by NTD NPT
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,r,d[10001][10001],ans;
struct struc{
    int a;
    int t;
};
struc custom[10001];
bool check(struc a,struc b){
    return a.t < b.t;
}

void solution(){
   cin >> n >> r;
        for (int i=1; i<=n; i++)
          cin >> custom[i].a >> custom[i].t;
        sort(custom+1,custom+n+1,check);
        for (int i=1; i<=n; i++)
          for (int j=0; j<=custom[i].t; j++)
            d[i][j]=max(d[i][j],max(d[i-1][j],d[i-1][j-1]+custom[i].a));

        ans=-1;
        for (int i=1; i<=n; i++)
           for (int j=0; j<=r; j++)
             ans=max(ans,d[i][j]);
        cout << ans << endl;
         for (int i = 0;i<=n;i++){
        for (int j = 0;j<=n;j++){
            d[i][j] = 0;
        }
     }
}
void solve(){
   int number;
   cin >> number;
   for (int i=1;i<=number;i++){
       solution();
   }
}
int main(){
    solve();
    return 0;
}