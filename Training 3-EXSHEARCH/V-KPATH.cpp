/*
A k-path on a given undirected graph is a path having exactly k edges and containing no repeated nodes.
=> Given an undirected graph G and an integral value k, count how many k-paths on G.
**Input
 The input consists of following lines
  Line 1: contains two integer n and k (1≤n≤30, 1≤k≤10) in which n is the number of nodes of the graph G (nodes are numbered 1,2,...,n)
  Line 2: contains an integer m (1≤m≤60) which is the number of edges of G
  Line i+2: contains two integers u and v representing two end points of the ith edge of G (∀i=1,…,m)
**Output
  The output contains the number of k-paths of  G
TEST
4 3
5
1 2
1 3
1 4
2 3
3 4
=> 6
----------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 35

int n, K;
int m;
int G[MAX][MAX];
int a, b;
int res;
int x[MAX];
bool visited[MAX][MAX];
bool node[MAX];

bool check(int v, int k) {
    if (node[v]) return false;
    if (visited[x[k-1]][v]) return false;
    if (k > 1 && G[x[k-1]][v] == 0) return false;
    return true;
}

int backTrack(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            node[v] = true;
            visited[x[k-1]][v] = true;
            visited[v][x[k-1]] = true;
            if (k == K+1) res++;
            else backTrack(k+1);
            node[v] = false;
            visited[x[k-1]][v] = false;
            visited[v][x[k-1]] = false;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n >> K;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    res = 0;
    cout << backTrack(1)/2;
}