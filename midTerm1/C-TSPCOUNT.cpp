/*
There are N cities. The distance between city i and city j is c(i,j),∀i,j∈{1,…,N}.
 A tour is define to be a permutation x1,x2,…,xN of 1, 2,...,N (in which x1 is always fixed by 1) 
 and its length is defined to be c(x1,x2)+c(x2,x3)+⋯+c(xN−1,xN)+c(xN,x1). Given a positive integer M.
Compute how many tours whose length is less than or equal to M.

Input
The input consists of following lines:
 Line 1 contains N và M (1≤N≤15,1≤M≤1000000).
 Line i+1(∀i=1,…,N) contains ith of the matrix c
Output
 Write the number of tours whose length is less than or equal to M.

Example
 input
4 10
0 1 2 6
1 0 5 4
2 5 0 3
6 4 3 0
 output
2
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n, m, c[20][20], tt[20], mark[20], ans = 0, kc = 0, cmin = 999999999;

void tryy(int i){
    for (int v=2; v<=n; v++) {
        if (!mark[v]) {
            tt[i] = v;
            mark[v] = 1;
            if (i==1) {
                kc += c[1][v];
            } else {
                kc += c[tt[i-1]][v];
            }
            if (i==n-1) {
                if (kc + c[v][1] <= m) {
                    ans++;
//                    for (int j=1; j<=n-1; j++){
//                        cout << tt[j] << " ";
//                    }
//                    cout << c[v][1] << " ";
//                    cout << ":" << kc+c[v][1];
//                    cout << endl;
                }
            } else {
                if (kc + cmin*(n-i) <= m) {
                    tryy(i+1);
                }
            }
            mark[v] = 0;
            if (i==1) {
                kc -= c[1][v];
            } else {
                kc -= c[tt[i-1]][v];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c[i][j];
            if (i!=j) {
                cmin = cmin < c[i][j] ? cmin : c[i][j];
            }
        }
    }
    tryy(1);
    cout << ans;
    return 0;
}
