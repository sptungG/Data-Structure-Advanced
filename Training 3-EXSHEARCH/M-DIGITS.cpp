/*
Write C program that reads an integer value N from stdin,
prints to stdout the number Q ways to assign values 1, 2, …, 9 to characters I,C,T,H,U,S,K 
         (characters are assigned with different values) such that: ICT−K62+HUST=N
**Input
  Unique line contains an integer N (1≤N≤105)
**Output
  Write the value Q
TEST
2000
=> 28
----------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[8];
int cnt = 0;
bool b[10];

bool check(int i, int k) {
	if(b[i]) return true;
	return false;
}

void Try(int k) {
	for(int i = 1; i <= 9; i++)
	if(check(i,k))
	{
		a[k] = i;
		b[i] = false;
		if(k == 7) {
			if((a[1]*100 + a[2] *10 + a[3]) - (a[4]*100 + 62) + (a[5]*1000 + a[6]*100 + a[7]*10 + a[3]) == n) {
				cnt++;
			//	for(int j = 1; j <= 7; j++) cout << a[j] << " ";
			//	cout << "\n";
			}
		}
		else Try(k + 1);
		b[i] = true;
	}
}


int main() {
	cin >> n;
	for(int i = 0; i < 10; i++) b[i] = true;
	Try(1);
	cout << cnt << "\n";
}