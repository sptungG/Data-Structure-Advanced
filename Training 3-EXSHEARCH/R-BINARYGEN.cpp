/*
Cho 1 một xâu nhị phân S độ dài n.
=> Tìm xâu nhị phân kế tiếp của xâu S trong thứ tự từ điển.
**Input
  Dòng đầu 1 số nguyên dương n≤10^4.
  Dòng thứ 2 ghi n số 0 hoặc 1 liên tiếp nhau.
**Output
 Ghi ra xâu nhị phân kế tiếp của xâu S trên một dòng duy nhất. 
 Nếu không tồn tại thì ghi ra -1.
TEST
5
00100
=> 00101
--------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            s[i] = '1';
            break;
        }
    }
    if (i == -1) cout << -1;
    else {
        for (int j = i+1; j < n; j++) s[j] = '0';
        cout << s;
    }
}