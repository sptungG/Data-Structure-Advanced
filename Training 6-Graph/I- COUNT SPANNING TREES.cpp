/*
Given a undirected connected graph G=(V,E) in which V={1,…,N} is the set of nodes and E is the set of M edges.
 Count the number of spanning trees of G.

Input
 Line 1: contains positive integers N and M (1≤ N ≤20,1≤ M ≤25)
 Line i+1 (i=1,…,M): contains u and v which are endpoints of the ith edge of G

Output
 Write the number of spanning trees of G

Example
 input
4 5
1 2
1 3
1 4
2 3
3 4
 output
8
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n,m,e[27],b[27],x[27],ans=0,r[27],p[27];

void link(int x, int y){
    if (r[x] > r[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (r[x] == r[y]) {
            r[y] = r[y] + 1;
        }
    }
}

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

int findSet(int x){
    if (x!=p[x]) {
        p[x] = findSet(p[x]);
    }
    return p[x];
}

bool checkNoCycle(int k, int v){
    for (int u=1; u<=n; u++) {
        makeSet(u);
    }
    for (int i=1; i<=k-1; i++) {
        int r1 = findSet(b[x[i]]);
        int r2 = findSet(e[x[i]]);
        link(r1,r2);
    }
    return findSet(b[v]) != findSet(e[v]);
}

void tryy(int k){
    for (int v=x[k-1]+1; v<=m; v++) {
        if (checkNoCycle(k,v)) {
            x[k] = v;
            if (k==n-1) {
                ans++;
            } else {
                tryy(k+1);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (long i=1; i<=m; i++) {
        cin >> b[i] >> e[i];
    }
    tryy(1);
    cout << ans;
    return 0;
}
