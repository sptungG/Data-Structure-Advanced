/*
There are n passengers 1,2,…,n.
The passenger i want to travel from point i to point i+n(i=1,2,…,n).
There is a taxi located at point 0 for transporting the passengers. 
 Given the distance matrix c(2n+1)∗(2n+1) in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n) 
=>>Compute the shortest route for the taxi, serving n passengers and coming back to point 0 such that at any moment,
                  there are no more than one passenger in the taxi, and no point is visited more than once 
                  (except for point 0, which can be visited up to twice).
**Input
  Line 1 contains n(1≤n≤11). 
  Line i+1(i=1,2,…,2n+1) contains the ith line of the matrix c.
**Output
 Unique line contains the length of the shortest route.
TEST
2
0 8 5 1 10
5 0 9 3 5
6 6 0 8 2
2 6 3 0 7
2 5 3 4 0
=> 17
---------------------------------------------
*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int NMAX = 11;
int n;
ll res;
ll tmp;
ll bound;
ll c[2*NMAX+1][2*NMAX+1];
bool flag[NMAX+1];


void solve(int x, int p) {
	if (x > n) {
		res = min(res, tmp + c[p][0]);
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			tmp += (c[p][i] + c[i][i+n]);
			flag[i] = true;
			bound -= c[i][i+n];
			if (tmp + bound < res) {
				solve(x+1, i+n);	
			}
			bound += c[i][i+n];
			flag[i] = false;
			tmp -= (c[p][i] + c[i][i+n]);
		}
	}
}

int main() {
	cin >> n;
	res = 0;
	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j <= 2*n; j++) {
			cin >> c[i][j];
			res += c[i][j];
		}
	}
	bound = 0;
	for (int i = 1; i <= n; i++) {
		bound += c[i][i+n];
	}
	tmp = 0;
	memset(flag, 0, sizeof(flag));
	solve(1, 0);
	cout << res << endl;
	return 0;
}