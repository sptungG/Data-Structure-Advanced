/*
There are n passengers 1,2,…,n. 
The passenger i want to travel from point i to point i+n(i=1,2,…,n). 
There is a bus located at point 0 and has k places for transporting the passengers 
                 (it means at any time, there are at most k passengers on the bus).
 You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n).
=>>>Compute the shortest route for the bus, serving n passengers and coming back to point 0 without visiting any point more than once (except for the point 0).
**Input
 Line 1 contains n and k(1≤n≤11,1≤k≤10).
 Line i+1(i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
**Output
  Unique line contains the length of the shortest route.
TEST
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
=>> 25
----------------------------------------
*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int NMAX = 11;
int n;
int q;
ll res;
ll tmp;
ll bound;
ll c[2*NMAX+1][2*NMAX+1];
int load;
bool flag[2*NMAX+1];
bool fin[NMAX+1];
ll y;
int nrc = 0;


void solve(int x, int p) {
	nrc++;
	if (x == 0) {
		res = min(res, tmp + c[p][0]);
		return;
	}
	
	if ((1 <= p) && (p <= n)) {
		load += 1;
		flag[p] = true;
	} else if (p > n) {
		if (!flag[p-n]) {
			return;
		}
		load -= 1;
		flag[p] = true;
		x--;
	}
	
	if (x > 0 && 0 <= load && load <= q) {
		for (int i = 1; i <= 2*n; i++) {
			if (!flag[i]) {
				flag[i] = true;
				tmp += c[p][i];
				y--;
				
				if (tmp + y*bound < res) {
					solve(x, i);
				}
				
				y++;
				tmp -= c[p][i];
				flag[i] = false;
			}
		}	
	} else if (x == 0) {
		res = min(res, tmp + c[p][0]);
	}
	
	if ((1 <= p) && (p <= n)) {
		load -= 1;
		flag[p] = false;
	} else if (p > n) {
		load += 1;
		flag[p] = false;
		x++;
	}
}

int main() {
	cin >> n >> q;
	res = 0;
	bound = 100000000;
	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j <= 2*n; j++) {
			cin >> c[i][j];
			res += c[i][j];
			if (i != j) bound = min(bound, c[i][j]);
		}
	}
	
	load = 0;
	tmp = 0;
	memset(flag, 0, sizeof(flag));
	
	y = 2*n + 1;
	solve(n, 0);
	
	cout << res << endl;
//	cout << nrc << endl;
	return 0;
}