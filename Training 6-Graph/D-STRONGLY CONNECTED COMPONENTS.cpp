/*
Given a directed graph G=(V,E) where V={1, …, N} is the number of nodes and the set E has M arcs.
 Compute number of strongly connected components of G

Input
Line 1: two positive integers N and M (1≤ N ≤ 10e5, 1 ≤ M ≤ 10e6)
Line i+1 (i=1,…,M): contains two positive integers u and v 
                    which are endpoints of ith arc

Output
 Write the number of strongly connected components of G

Example
 input
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
 output
3
*/
//  Created by NPT
#include <stdio.h>
 
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
const int N = 100005;
const int oo = 0x3c3c3c3c;
 
int n, m, Num[N], Low[N], cnt = 0;
vector<int> a[N];
stack<int> st;
int Count = 0;
 
void visit(int u) {
    Low[u] = Num[u] = ++cnt;
    st.push(u);
 
    for (int v : a[u])
        if (Num[v])
            Low[u] = min(Low[u], Num[v]);
        else {
            visit(v);
            Low[u] = min(Low[u], Low[v]);
        }
 
    if (Num[u] == Low[u]) {  // found one
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            Num[v] = Low[v] = oo;  // remove v from graph
        } while (v != u);
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
 
    for (int i = 1; i <= n; i++)
        if (!Num[i]) visit(i);
 
    cout << Count << endl;
}