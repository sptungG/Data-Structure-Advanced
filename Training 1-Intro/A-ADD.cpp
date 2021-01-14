#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
 unsigned long long a,b,c,d;
 cin>>a>>b;
 c=a%10+b%10;
 d=a/10+b/10+c/10;
//1+1 c=2 d=0 xxxx
if(d!=0){
	cout<<d;
}
cout<< c%10;
return 0;
}
