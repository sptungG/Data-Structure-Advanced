/* HARD
The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2, ..., n.
The warehouse i has amount of ai (ai is non-negative integer) and is located at coordinate i (∀i=1,…,n).
The King of ALPHA opens a competition for hunters who are responsible to find 
  a subset of gold warehouses having largest total amount of golds with respect to the condition 
  that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.

**Input
The input consists of the following lines:
  *Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n).
  Line 2 contains n integers a1,a2,…,an
**Output
 Contains only one single integer denoting the total amount of golds of selected warehouses.
TEST
6 2 3
3 5 9 6 7 4
=>19
------------------------------------------------
*/

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N =1000001;
int a[N],S[N];
int n,L1,L2,ans;

int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); //read faster
cin>>n>>L1>>L2;
for(int i=1;i<=n;i++) cin>>a[i];
ans=0;

//use deque
deque<int>Q;
for(int i=1;i<=n;i++){
	while(!Q.empty()&&Q.front()<i-L2) Q.pop_front();
	if(i-L1>=1){
		while(!Q.empty()&&S[Q.back()]<S[i-L1]) Q.pop_back();
		Q.push_back(i-L1);
	}
	S[i]=(Q.empty()?0:S[Q.front()])+a[i];
	ans=max(ans,S[i]);
}

/*
for(int i=1;i<=n;i++){
	S[i]=a[i];
	for(int j=i-L2;j<=i-L1;j++) if(j>=1 && S[i]<S[j]+a[i])
	S[i]=S[j]+a[i];
	ans= max(ans,S[i]);
}*/
cout<<ans;
return 0;
}
