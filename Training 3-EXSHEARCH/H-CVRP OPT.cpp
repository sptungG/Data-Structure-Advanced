/*
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. 
   Each client i requests d[i] packages. 
   The distance from location i to location j is c[i,j], 0≤i,j≤n.. 
A delivery solution is a set of routes: 
 each truck is associated with a route, starting from depot, 
 visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
  Each client is visited exactly by one route
 Total number of packages requested by clients of each truck cannot exceed its capacity
 Each truck must visit at least one client
=>>Goal
   Find a solution having minimal total travel distance
   Note that: the orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
**Input
  Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
  Line 2: d[1],...,d[n] (1≤d[i]≤10)
  Line i+3: the ith row of the distance matrix c(i=0,…,n) (1≤c[i,j]≤30)
**Output
 Minimal total travel distance
TEST
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0
=> 70
----------------------------------------------------------
*/  
#include <bits/stdc++.h>
#define MAX  30
using namespace std;

int N;  /// the number of customers
int K;  /// the number of trucks
int Q;  /// the capacity of each truck
int d[MAX]; /// d[i]:  the demand for load of customer i
int c[MAX][MAX]; /// c[i][j]: the cost travel from client i to client j
int cost; /// the total cost piles up during the departure of all trucks
int minCost;

int Y[MAX]; /// Y[k] is the first point of truck k
int X[MAX]; /// X[i] is the next point of point i
int segments; /// the number of segments
bool visited[MAX];
int load[MAX];/// load[k] is the total of load in truck k

void input() {
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) cin >> c[i][j];
    }
}

bool check_X(int v, int k) {
    if (v > 0) {
        if(visited[v]) return false;
        if(load[k] + d[v] > Q) return false; /// condition for load
    }
    return true;
}
void solution() {
    minCost = min(minCost, cost);
    return;
    for(int k = 1; k <= K; k++) {
        cout << "0";
        int u = Y[k]; /// the first point of departure of truck k
        while (u > 0) {
            cout <<  " - " << u;
            u = X[u];
        }
        cout << " - 0" << endl;
    }
    cout << "cost = " << cost << endl;
    cout << "--------------" <<endl;
}
void TRY_X(int s, int k) { /// try value for X[s], in the departure of truck k
    for (int v = 0; v <= N; v++) {
        if(check_X(v, k)) {
            X[s] = v; /// the next point of s is point v, in the departure of truck k
            visited[v] = true; segments++; load[k] += d[v]; cost += c[s][v];
            if(v == 0){/// truck k returned
                if(k==K){
                    if(segments == N+K) solution();
                } else {
                    TRY_X(Y[k+1], k+1);
                }
            } else {
                TRY_X(v,k);
            }
            visited[v] = false; segments--; load[k] -= d[v]; cost -= c[s][v];/// recover
        }
    }

}

bool check_Y(int v, int k) {
    if(visited[v]) return false;
    if(load[k]+d[v] > Q) return false;
    return true;
}

void TRY_Y(int k) {
    for (int v = Y[k-1]+1; v <= N; v++) {
        if (check_Y(v,k)) {
          Y[k] = v;
          visited[v] = true; segments++; load[k]+=d[v]; cost += c[0][v];
          if(k==K) { ///try for all first points of the trucks
            TRY_X(Y[1],1);
          } else {
            TRY_Y(k+1);
          }
          visited[v] = false; segments --; load[k]-=d[v]; cost -= c[0][v];
        }

    }
}

void solve() {
    minCost = 2e9;
    Y[0] = 0;
    segments = 0;
    for(int k = 1; k <= K; k++) load[k]=0;
    TRY_Y(1);
}
int main(){
    input();
    solve();
    cout << minCost;
}