/*
**Input
The input file consists of several datasets.
 The first line of the input file contains the number of datasets which is a positive integer T and is not greater than 1000. 
 Each of T following lines describes a parentheses expression including: '(',')','[',']','{','}'.
**Output
 For each dataset, write in one line 1 or 0 if the expression is correct or not, respectively.
TEST
2
([]())
()()()[}
=> 1
   0
---------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
/*
dung stack 
() (]
( cho vao stack, 
) lay stack so sanh cung cap thi pop ra  
--stack- rong ->1 || ko ->0 
( vao stack,
] so sanh, ko dung cap ->0
*/
int parentTheses(string s){
	stack<char> st;
	for(int i=0;i<s.length();++i){
		if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
		st.push(s[i]);
		}
		else if(st.empty() || s[i]==')'&& st.top() != '(' ) return 0;
		else if(st.empty()|| s[i]==']' && st.top()!='[' )	return 0;
		else if(st.empty()|| s[i]=='}' && st.top()!='{')  return 0;
		else st.pop();
	}
	if(st.empty()) return 1;
	return 0;
}

int main(){
int T;
cin >>T;
 string s;
 for(int t=0;t<T;++t){
 	cin>>s;
 	cout<< parentTheses(s) <<endl;
 }
return 0;
}
