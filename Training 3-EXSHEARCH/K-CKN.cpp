/*
Cho hai số nguyên dương n,k và một số nguyên tố m sao cho k<n,m. 
=>>>>> Tính giá trị Ckn mod m.
**Input
  Dòng đầu tiên chứa số test T.
  T dòng tiếp theo, mỗi dòng chứa ba số nguyên n,k,m.
**Output
  Gồm T dòng, mỗi dòng chứa một số nguyên duy nhất là kết quả phép toán Ckn mod m.
TEST
2
7 3 7
5 2 7
=> 0
   3
Note:   
Số test T<=10
Subtask 1 (30%) : n,k<=100.
Subtask 2 (30%) : n∗k<=10^5.
Subtask 3 (20%) : m<=10^9+7, k<=10^5
Subtask 4 (20%) : m,n<=10^18 ,  k<=10^5
------------------------------
*/
#include <stdio.h>

int k, n;

void input() {
    scanf("%d %d", &k, &n);
}
int kToN(int k, int n) {
}

int main() {
    input();
    int cKn = 1;
    cKn = kToN(k,n);
    for(int i = 1; i <= n-k; i++) {
        cKn = cKn/i;
    }
    printf("%d", cKn);
    return 0;
}
