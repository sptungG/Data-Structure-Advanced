/*
Given a undirected graph G=(V,E) where V={1,…,N} is the number of nodes and the set E has M edges.
 Compute number of connected components of G.

Input
 Line 1: two positive integers N and M (1 ≤ N ≤ 105, 1 ≤ M ≤ 105)
 Line i+1 (i = 1, …, M): contains two positive integers u and v which are endpoints of ith edge

Output
 Write the number of connected components of G.

Example
input
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8
output
3
*/
//  Created by NPT
#include <iostream>
#include <vector>

using namespace std;

const int N=1e5+1;

vector<int> A[N] ;
int n,m;
char color[N];
int icc[N];
int ncc=0;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int k=1; k<=m ; k++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void DFS(int u){
    color[u]='G';
    icc[u]=ncc;
    for (int i =0; i<A[u].size(); i++) {
        int v= A[u][i];
        if(color[v]=='W'){
            DFS(v);
        }
    }
}
void DFS(){
    for(int v=1; v<=n; v++){
        color[v]='W';
    }
    ncc=0;
     for(int v=1; v<=n; v++){
         if(color[v]=='W'){
             ncc++;
             DFS(v);
         }
     }
    cout << ncc;
}
void solve(){
    DFS();
}

int main(int argc, const char * argv[]) {
    input();
    solve();
}
