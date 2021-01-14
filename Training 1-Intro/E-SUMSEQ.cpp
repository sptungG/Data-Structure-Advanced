#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define P 1000000007
typedef unsigned long long ll;

ll addMod(ll a, ll b, ll p){
  a = a % p;
  b = b % p;
  ll tmp = p-a;
  	if(tmp < b){// p-a<b ->p<b+a (a+b)modp = b+a-p
  		return b - tmp;
	  }
	  return a+b;
}
 
int main(){
int n,a,ans =0;
cin >> n;
for(int i =0;i<n;++i){
	cin>>a;
	ans = addMod(ans,a,P);
}
cout << ans;
return 0;
}