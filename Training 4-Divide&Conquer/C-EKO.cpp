/*
Lumberjack Mirko needs to chop down M metres of wood.
It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire.
However, Mirko is only allowed to cut a single row of trees.
Mirko's machine works as follows: Mirko sets a height parameter H (in metres), 
and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact).
Mirko then takes the parts that were cut off. 
(For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres,
the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively,
while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).)
Mirko is ecologically minded, so he doesn't want to cut off more wood than necessary. 
That's why he wants to se his sawblade as high as possible.
===Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.
**Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1≤N≤1000000) and M (Mirko's required wood amount, 1≤M≤2000000000).
The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres)-- 
--.The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.
**Output
The first and only line of output must contain the required height setting.
TEST
5 20
4 42 40 26 46
=>36
--------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6+5;

int N;
long long M;
long long H[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    long long l = 0, r = *max_element(H+1, H+N+1);
    long long m;
    long long minDif = 1e10;
    long long ans;
    while (r - l > 1) {
        m = (l+r)/2;
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            if (H[i] > m) sum += H[i] - m;
        }
        if (sum == M) {
            ans = m; break;
        }
        if (sum > M) {
            l = m;
            if (sum - M < minDif) ans = m;
        }
        else r = m;
    }
    cout << ans;
}