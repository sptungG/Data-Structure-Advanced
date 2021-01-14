/*
Given a sequence of positive integers a=(a1,…,aN) 
and a positive integer K. 
Compute the number Q of triple (i,j,k) such that 1≤i<j<k≤N and ai+aj+ak=K.
**Input
The input consists of following lines:
  Line 1 contains N and K (1≤N≤5000,1≤K≤10^5).
  Line 2 contains a1,…,aN (1≤ai≤10^5)
**Output
Write the value Q.
    TEST
6 12
2 3 4 1 6 7
=>3
------------------------------------------
*/
//  Created by NPT
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
 
int n,k,a[5007],ans=0;
 
int bsearch(int a[], int d, int c, int kk){
    if (d>c) return 0;
    int g = (d+c) / 2;
    if (a[g]==kk) return 1+bsearch(a,d,g-1,kk)+bsearch(a,g+1,c,kk);
    else if (a[g]>kk) return bsearch(a,d,g-1,kk);
    else return bsearch(a,g+1,c,kk);
}
 
int main() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            ans += bsearch(a,j+1,n,k-a[i]-a[j]);
        }
    }
    cout << ans;
    return 0;
}





// #include<iostream>
// #include<algorithm>
// #include<bits/stdc++.h>
// using namespace std;
// long long n, k;
// long long a[100000];
// int q;
// int sum;
// int count;
// void input(){
//     q = 0;
//     sum = 0;
//     cin >> n >> k;
//     for(int i = 0;i<n;i++){
//         cin >> a[i];
//     }
//     sort(a, a+n);
// }
// int b_search(int l, int r, long long y){
//     if(l>r){
//         return 0;
//     }
//     else if(l == r){
//         if(a[l] == y){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     int m = (l+r)/2;
//     if(a[m] == y){
//         return 1 + b_search(l, m-1, y) + b_search(m+1, r, y);
//     }
//     else if(a[m] < y){
//         return b_search(m+1, r, y);
//     }
//     else{
//         return b_search(l, m-1, y);
//     }
// }
// void solve(){
//     int ans = 0;
//     for(int i = 0;i<n-3;i++){
//         for(int j = i+1;j<n-2;j++){
//             ans = ans + b_search(j+1, n-1, k - a[i] - a[j]);
//         }
//     }
//     cout << ans;
// }
// int main(){
//     input();
//     solve();
//     return 0;
// }