/*
Một người du lịch xuất phát từ thành phố thứ nhất muốn đi thăm quan tất cả n−1 thành phố khác. 
mỗi thành phố đúng một lần, rồi quay trở lại thành phố xuất phát.
=>>Yêu cầu: Cho biết chi phí đi lại giữa các thành phố, hãy giúp người du lịch tìm hành trình với tổng chi phí là nhỏ nhất.
**Input
  Dòng đầu tiên chứa hai số nguyên dương n,m cách nhau bởi dấu cách (n≤20,m<400).
  m dòng tiếp theo mỗi dòng chứa ba số nguyên dương i,j,c (i,j≤n,c≤106) biểu thị chi phí đi trực tiếp từ thành phố i đến thành phố j là c.
 Lưu ý: nếu từ thành phố i đến thành phố j nào không mô tả chi phí đi lại thì có nghĩa là không có đường đi trực tiếp từ i đến j.
**Output
Ghi ra duy nhất một số là tổng chi phí hành trình nhỏ nhất tìm được.
TEST
2 2
1 2 3
2 1 2
=>5
------------------------------------------
*/
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int a[MAX][MAX] = {0}, visited[MAX] = {0}, m, n, ans =999999999, f = 0, minz = 999999999, x[MAX], b[MAX][MAX] = {0};

void input(){
	cin  >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			a[i][j] = 999999999;
		}
	}
	while(m--){
		int i, j, c;
		cin >> i >> j >> c;
		a[i][j] = c;
		b[i][j] = 1;
	}
}

bool check(int v, int k){
	if(visited[v]) return false;
	if(b[x[k-1]][v] == 0) return false;
	return true;
}

void solution(){
	ans = min(ans, f+a[x[n]][1]);
}

void TRY(int k){
	for(int v = 2; v<=n; v++){
		if(check(v, k)){
			x[k] = v;
			f+= a[x[k-1]][x[k]];
			visited[v] = 1;
			if(k==n) solution();
			else{
				if(f+ (n-k+1)* minz < ans) TRY(k+1);
			}
			f-= a[x[k-1]][x[k]];
			visited[v] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	x[1] = 1;
	for(int i=1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			minz = min(minz, a[i][j]);
		}
	}
	TRY(2);
	cout << ans;
}