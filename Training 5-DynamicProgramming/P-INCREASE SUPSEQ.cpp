/*
Given a sequence of integers a1,…,an.
 Compute the longest subsequence (elements are not necessarily continuous) 
   i                        n which elements are in an increasing orders.

Input
 Line 1 contains an integer n (1≤n≤1e4)
 Line 2 contains n integers a1,…,an
Output
 Write the length of the longest subsequence found.

Example
 input
10
7 2 3 7 5 4 2 1 9 6
 output
4
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n,k,a[10007],s[10007];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    s[1]=1;
    int ans = 1;
    for(int i=2; i<=n; i++) {
        s[i] = 1;
        for (int j=1; j<i; j++) {
            if (a[i]>a[j]) {
                s[i] = s[i] > (s[j] + 1) ? s[i] : (s[j]+1);
            }
        }
        ans = ans < s[i] ? s[i] : ans;
    }
    cout << ans;
    return 0;
}
