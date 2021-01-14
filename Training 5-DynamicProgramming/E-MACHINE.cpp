//
//  main.cpp
//  Training5_Machine
//
//  Created by Nguyễn Trường on 11/12/20.
//
/*
An engineer needs to schedule a machine to run on some given periods 1,…,n to produce a chemical product C.
Each period i is represented by a starting time point si and terminating time point ti (si<ti). 
Due to a technical constraint, the machine must run on exactly two periods that are not overlap (two periods i and j are not overlap if ti<sj or tj<si).
 If the machine is runned on the period i, then the amount of C it will produce is equal to the duration of the period i (which is equal to ti−si).
=>>Help the engineer to select two not-overlap periods to run the machine =>such that the amount of C produced is maximal.
**Input
 Line 1: contains the positive integer n (2≤n≤2⋅106)
 Line i+1: contains two positive integer si and ti (1≤si<ti≤2⋅106)
**Output
 The output consists of only one single integer which is the amount of product C the machine will produce in the two selected periods.
 In case there is no solution (there does not exist two periods that are not overlap), the output contains the value -1.
TEST
5
8 12
6 11
3 9
2 5
1 4
=>>8
--------------------------------
*/
//  Created by NPT
#include <bits/stdc++.h>

using namespace std;

typedef struct periodT{
    int s, t;
} period;

int n, maxDur[2000007], st[2000007], flag = 0, ans = -1;
period p[2000007];

bool compareS(period a, period b){
    return a.s < b.s;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> p[i].s >> p[i].t;
    }
    sort(p+1, p+n+1, compareS);
    maxDur[n] = p[n].t-p[n].s;
    st[n] = p[n].s;
    for (int i=n-1; i>=1; i--) {
        maxDur[i] = p[i].t-p[i].s < maxDur[i+1] ? maxDur[i+1] : p[i].t-p[i].s;
        st[i] = p[i].s;
    }
    for (int i=1; i<=n; i++) {
        long up = upper_bound(st+1, st+n+1, p[i].t) - st;
        if (up <= n) {
            flag = 1;
            int tmp = p[i].t-p[i].s + maxDur[up];
            ans = ans < tmp ? tmp : ans;
        }
    }
    if (flag == 0) cout << -1;
    else cout << ans;
    return 0;
}
// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N = 1<<20;
// int s[N], t[N], ls[N], lt[N];
 
// int main() {
//     ios::sync_with_stdio(false);
 
//     int n;
//     cin >> n;
 
//     for (int i = 0; i < n; i++) {
//         cin >> s[i] >> t[i];
//         lt[t[i]] = max(lt[t[i]], t[i]-s[i]);
//         ls[s[i]] = max(ls[s[i]], t[i]-s[i]);
//     }
 
//     for (int i = 1; i <= (int) 1e6; i++) {
//         lt[i] = max(lt[i], lt[i-1]);
//     }
 
//     for (int i = (int) 1e6; i >= 1; i--) {
//         ls[i] = max(ls[i], ls[i+1]);
//     }
 
//     int res = 0;
 
//     for (int i = 1; i <= (int) 1e6; i++) {
//         res = max(res, lt[i-1] + ls[i]);
//     }
 
//     cout << res << endl;
 
//     return 0;
// }