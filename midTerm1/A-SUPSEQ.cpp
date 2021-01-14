/*
Given a sequence s of N positive integers a1,…,aN and a positive integer M.
 A subsequence of s from index i to index j is defined to be ai,ai+1,…,aj (∀1≤i≤j≤N).
  The weight of a sequence is defined to be the sum of all elements of the sequence.
   Compute the number of subsequences of s whose weight is less than or equal to M.

Input
The input consists of following lines:
 Line 1 contains N và M (1≤N≤1e5,1≤M≤1e5).
 Line 2 contains N positive integers a1,…,aN of the sequence s which are less than 30.
Output
 Write the number of subsequences of s whose weight is less than or equal to M.

Example
 input
5 5
2 3 4 1 5
 output
7
*/
//  Created by NPT
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,a[100007],f[100007];

int upper(int x) {
    int l=0, r=n+1;
    int mid=(l+r) / 2;
    while (r-l>1) {
        if (f[mid]>x) r=mid;
        else l=mid;
        mid=(l+r) / 2;
    }
    return r;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    f[1] = a[1];
    for (int i=2; i<=n; i++) {
        f[i] = f[i-1] + a[i];
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        //cout << upper(m+f[i-1]) << endl;
        ans += upper(m+f[i-1]) - i;
    }
    cout << ans;
    return 0;
}
