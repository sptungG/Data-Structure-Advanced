/*
Cho 1 số nguyên dương n. 
=> Đưa ra xâu nhị phân độ dài n thứ k trong thứ tự từ điển mà không có i số 0 liên tiếp.
**Input
  Dòng đầu ghi 3 số nguyên dương n,k,i trong đó n,i≤10^4,k≤10^9 cách nhau bởi dấu cách
**Output
  Ghi ra xâu nhị phân độ dài n thứ k mà không có i số 0 liên tiếp trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách.
  Nếu không tồn tại thì ghi ra -1.
TEST
2 3 10
=> 1 0
6 4 2
=> 0 1 1 0 1 0 
--------------------------------------------------------
*/  
#include <bits/stdc++.h>
using namespace std;

int n, k, i;
int cnt = 0;
vector<int> x;

void print(){
    cnt++;
    if (cnt == k){
        for (int i = 0; i < n; i++) cout << x[i] << ' ';
        exit(0);
    }
}

void solve(int index, int cnt0, int i){

    if (index == n) print();
    else if (cnt0 == i - 1){
        x[index] = 1;
        solve(index + 1, 0, i);
        }
        else {
            x[index] = 0;
            solve(index + 1, cnt0 + 1, i);
            x[index] = 1;
            solve(index + 1, 0, i);
        }
}


int main(){
    cin >> n >> k >> i;
    x.resize(n + 1);
    solve(0, 0, i);
    if (cnt < k) cout << -1 << endl;
}