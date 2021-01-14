/*
R-MAX SUPSEQENCE
Given an integers sequence a=(a1,a2,…,an).
A subsequence of a is defined to be ai,ai+1,…,aj.
The weight of a subsequence is the sum of its elements.
===>>Find the subsequence having the highest weight.
**Input
  Line 1 contains n (1≤n≤106)
  Line 2 contains a1,…,an (−500≤ai≤500)
**Output
  Write the weight of the highest subsequence found.
TEST
10
3 -1 -3 5 2 5 0 -1 5 4
=>20
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n,a[1000007],f[1000007];

int max(int a, int b){
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        f[i] = a[i];
    }
    for (int i=2; i<=n; i++) {
        f[i] = max(f[i], f[i-1]+a[i]);
    }
    int ans = -999999999;
    for (int i=1; i<=n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}
//non DP
// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// maxSubseq(int a[],int n){
// 	int res;
// 	int s[1000000];
// s[1] = a[1];
// res = s[1];
// for(int i=2;i<n;++i){
//  if (s[i-1] > 0){
//     s[i] = s[i-1] + a[i];
// }
// else{
//     s[i] = a[i];
// }
// if(s[i] > res ) res = s[i];
// }
// return res;
// }

// int main(){
// int n;
// cin>> n;
// int *a= new int[n];
// for(int i = 0;i < n;i++){
// 	cin>> a[i];
// }
// cout<< maxSubseq(a,n);
// delete[] a;//xoa mang a

// return 0;
// }
