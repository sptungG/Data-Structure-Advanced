/*
Vanya walks late at night along a straight street of length l, lit by n lanterns.
Consider the coordinate system with the beginning of the street corresponding to the point 0, and its end corresponding to the point l.
Then the i-th lantern is at the point a_i(ai).
The lantern lights all points of the street that are at the distance of at most d from it,
where d is some positive number, common for all lanterns.
==>>Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?
**Input
The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 10^9) — the number of lanterns and the length of the street respectively.
The next line contains n integers ai (0 ≤ ai ≤ l). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.
**Output
Print the minimum light radius d, needed to light the whole street.
 (The answer will be considered correct if its absolute or relative error doesn't exceed 10^-9.)
   TEST
7 15
15 5 3 7 9 14 0
=>2.5000000000
2 5
2 5
=>2.0000000000
NOTE:
Consider the second sample.
At d = 2 the first lantern will light the segment [0, 4] of the street,
and the second lantern will light segment [3, 5]. Thus, the whole street will be lit.
-------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int N;
long long L;
long long a[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+N+1);
    double maxDis = 0;
    a[0] = -a[1];
    for (int i = 1; i <= N; i++) {
        maxDis = max(maxDis, (double)(a[i] - a[i-1])/2);
    }
    if (a[N] < L) maxDis = max(maxDis, (double)(L - a[N]));
    printf("%0.9f\n", maxDis);
}