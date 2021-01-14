/*
Q-longestCommonsub
A subsequence of a given sequence S=S1,…,Sn is obtained by removing some elements from S.
Given two sequence of integers X=(X1,…,Xn) and Y=(Y1,…,Ym).
Find the longest common subsequence of X and Y.
**Input
  Line 1 contains n and m (1≤n,m≤104)
  Line 2 contains X1,…,Xn
  Line 3 contains Y1,…,Ym
**Output
  Write the length of the longest subsequence of the given sequences
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
=>>5
-----------------------------------------
*/
//  Created by NPT
#include <iostream>
#include <stack>
 
using namespace std;
 
int n,m,x[10007],y[10007],s[10007][10007];
char trace[10007][10007];
 
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> y[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (x[i] == y[j]) {
                s[i][j] = s[i-1][j-1] + 1;
                trace[i][j] = 'D';
            } else {
                if (s[i-1][j] < s[i][j-1]) {
                    s[i][j] = s[i][j-1];
                    trace[i][j] = 'L';
                } else {
                    s[i][j] = s[i-1][j];
                    trace[i][j] = 'U';
                }
            }
        }
    }
    cout << s[n][m] << endl;

    return 0;
}
// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #define MAX 10002
 
// using namespace std;
 
// int X[MAX], Y[MAX], n,m;
// int L[MAX][MAX];
 
// int LCS(int a, int b){
//     for (int i = 0; i <= a; i++)
//     {
//         for (int j = 0; j <= b; j++)
//         {
//             if (i == 0 || j == 0)
//                 L[i][j] = 0;
            
//             else if (X[i - 1] == Y[j - 1])
//                 L[i][j] = L[i - 1][j - 1] + 1;
            
//             else
//                 L[i][j] = max(L[i - 1][j], L[i][j - 1]);
//         }
//     }
//     return L[a][b];
// }
 
// int main(){
//     cin >> n >> m;
//     for(int i =0; i<n;i++){
//         cin >> X[i];
//     }
//     for(int i =0; i<m;i++){
//         cin >> Y[i];
//     }
//     cout << LCS(n,m);
//     return 0;
// }