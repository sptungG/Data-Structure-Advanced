/*
Cho 2 số nguyên dương n,m.
=> Đưa ra chuỗi tổ hợp chập m của n phần tử trong tập {1,2,…n} thứ k trong thứ tự từ điển.
**Input
  Dòng đầu ghi 3 số nguyên dương n,m,k cách nhau bởi dấu cách, n,m≤10^4;k≤10^9.
**Output
  Ghi ra chuỗi tổ hợp chập m của n phần tử thứ k trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách. 
  Nếu không tồn tại thì ghi ra -1.
TEST
4 3 6
=> -1
---------------------------------------------------
*/  
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int cnt = 0;
int x[10001];
bool mark[10001];

void print(){
    cnt++;
    if (cnt == k){
        for (int i = 1; i <= m; i++) cout << x[i] << ' ';
        exit(0);
    }
}

void TRY(int k){
    for (int v = x[k - 1] + 1; v <= n - m + k; v++){
        if (!mark[v]){
            x[k] = v;
            //mark[v] = true;
            if (k == m) print();
            else TRY(k + 1);
            //mark[v] = false;
        }
    }
}


int main(){
    cin >> n >> m >> k;
    x[0] = 0;
    TRY(1);
    if (cnt < k) cout << -1 << endl;
}