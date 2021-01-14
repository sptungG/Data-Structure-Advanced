/*
Cho 1 một chuỗi tổ hợp C độ dài m với các thành phần nằm trong tập {1,2,…,n}. 
=>  Tìm chuỗi tổ hợp kế tiếp của chuỗi C trong thứ tự từ điển.
**Input
  Dòng đầu 2 số nguyên dương n,m≤10^4.
  Dòng thứ 2 ghi m số nguyên dương ≤n cách nhau bởi dấu cách.
**Output
  Ghi ra chuỗi C trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách.
       Nếu không tồn tại thì ghi ra -1
TEST
5 3
2 3 5
=> 2 4 5
--------------------------------------------
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;

int n, m, a[MAX];

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	
	int l = n;
	int i = m-1;
	while (a[i] == l) {
		i--;
		l--;
	}
	if (i == -1) {
		cout << -1 << endl;
		return 0;
	}
	a[i]++;
	for(int j = i+1; j < m; j++) {
		a[j] = a[j-1] + 1;
	}
	
	for (int i = 0; i < m; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	
	return 0;
}