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
  	if(tmp < b){
  		return b - tmp;
	  }
	  return a+b;
}
 
int main(){
ll a,b;
cin >> a>> b;
cout<< addMod(a,b,P);
return 0;
}
