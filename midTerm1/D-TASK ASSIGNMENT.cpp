 /*
 In a company, there are N tasks 1,…,N and M staffs 1,…,M.
  The cost that the company has to pay if the staff i performs the task j is c(i,j),∀i=1,…,M,j=1,…,N.
  Given a value K, find the way to assign tasks to staffs such that each task is performed by only one staff 
  and each staff cannot perform more than K tasks,
  and the total cost is minimal.

Input
The input consists of following lines:
 Line 1 contains N, M, K (1≤N≤30,1≤M≤20,1≤K≤30).
 Line i+1 (i=1,…,M) contains the ith line of the matrix c.
Output
 Write the minimal total cost of the solution found.

Example
 input
6 2 3
2 5 7 7 2 9
9 8 9 4 8 5
 output
27
 */
//  Created by NPT
#include <iostream>
 
using namespace std;
 
int n,m,k,c[40][40],cmin = 999999999, ctask[40], tcost = 0, ans = 999999999;
 
bool check(int i, int v){
    if (ctask[v]+1>k) {
        return false;
    }
//    if (ctask[v] + (n-i)/m > k) {
//        return false;
//    }
    return true;
}
 
void tryy(int i){
    for (int v=1; v<=m; v++) {
        if (check(i,v)) {
            ctask[v]++;
            tcost += c[v][i];
            if (i==n) {
                ans = ans < tcost ? ans : tcost;
            } else {
                if (tcost+cmin*(n-i) < ans){
                    tryy(i+1);
                }
            }
            ctask[v]--;
            tcost -= c[v][i];
        }
    }
}
 
int main(int argc, const char * argv[]) {
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c[i][j];
            cmin = cmin > c[i][j] ? c[i][j] : cmin;
        }
    }
    tryy(1);
    cout << ans;
    return 0;
}