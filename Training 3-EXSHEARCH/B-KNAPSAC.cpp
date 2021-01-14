/*
Một nhà thám hiểm cần đem theo một cái túi có trọng lượng không quá b.
Có n đồ vật có thể đem theo. Đồ vật thứ j có trọng lượng aj và giá trị sử dụng cj.
=>>Hỏi nhà thám hiểm cần đem theo những đồ vật nào để cho tổng giá trị sử dụng là lớn nhất 
           mà tổng trọng lượng đồ vật mang theo cái túi không vượt quá b?
**Input
   Dòng đầu tiên chứa hai số nguyên dương n,b (n≤30,b≤106).
   Dòng thứ j trong số n dòng tiếp theo mỗi dòng ghi ra hai số nguyên dương aj,cj≤106.
**Output
 Ghi ra duy nhất một số là tổng giá trị lớn nhất tìm được của các đồ vật cho vào túi.
TEST
2 6
4 2
3 2
=>2
-------------------------------------- 
*/  
#include <bits/stdc++.h>
using namespace std;
const int MAX = 35;
int n, b;   /// n: number of objects, b: the capacity of the knapsack
int w[MAX]; ///w[i]: weight of object i
int v[MAX]; ///v[i]: value of object i
int r[MAX][1000005]; ///r[i][j]: result of problem when we put the subset of the object from i to n into the knapsack of capacity j

int dp(int i, int c) {
    ///stop condition
    if (c < 0) return -2e9;
    if (i > n) return 0;
    ///check if r[i][c] has already been computed
    if (r[i][c] != 0) return r[i][c];
    ///base case
    r[i][c] = max(dp(i+1, c), v[i] + dp(i+1, c - w[i]));
    return r[i][c];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << dp(1, b);
}