/*
Superior Island is a very picturesque island and only bicycles are allowed on the island.
Therefore, there are many one-way bicycle roads connecting the different best photo-shooting spots on the island.
To help the visitors plan their trip to the island, the tourism commission wants to designate r different bicycle routes
    that go through some of the best photo-shooting spots on the island. Given a map of all the bicycle roads on the island 
    and a list of the best photo-shooting spots to be included on each of the three planned routes (non-listed spots must not be included in the route),
=>>> please write a program to plan each of the r routes so that the distance on each route is minimal.
     Note that each best photo-shooting spot may only appear at most once on the route.
**Input
There are two parts to the input.
 The first part of input gives the information of the bicycle roads on the island.
   The first line contains two integer n and r , n≤100 and r≤10 , indicating that there are n best photo-shooting spots on the island and there are r routes to be planned.
   The next n lines (line 2 through line n+1) contains n×n integers (n lines with n integers on each line), 
    where the j -th integer on line i denotes the distance from best photo-shooting spot i−1 to best photo-shooting spot j ;
    the distances are all between 0 and 10, where 0 indicates that there is no one-way road going from best photo-shooting spot i−1 to spot j.
 The second part of input has r lines, denoting the r sightseeing routes to be planed.
   Each line lists the best photo-shooting stops to be included in that route.
   The integers on each line denote the recommended photo-shooting stops on that particular sightseeing route.
   The first integer on the line is the starting point of the route and the last integer is the last stop on the route.
   However, the stops in between can be visited in any order.
**Output
 Output r integers on r lines (one integer per line) indicating the distance of each of the r planned routes.
 ( If a route is not possible, output '0'.)
TEST
6 3
0 1 2 0 1 1
1 0 1 1 1 0
0 2 0 1 3 0
4 3 1 0 0 0
0 0 1 1 0 0
1 0 0 0 0 0
1 3 5
6 3 2 5
6 1 2 3 4 5
=>
5
0
7
--------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 105

int n, route, last; /// n: number of photo-shooting spots, route: number of planned routes, last: length of each route
int c[MAX][MAX];    /// c[i][j]: cost from spot i to spot j
int r[MAX];         /// r[i]: spot i in a route
int x[MAX];
int cost;           /// total cost of route so far
int minCost;        /// minimal cost
bool visited[MAX];
int res[15];

bool check(int v, int k) {
    if (visited[v]) return false;
    if (c[x[k-1]][r[v]] == 0) return false;
    return true;
}

int backTrack(int k) {
    for (int v = 2; v < last; v++) {
        if (check(v, k)) {
            x[k] = r[v];
            cost += c[x[k-1]][x[k]];
            visited[v] = true;
            if (k == last - 1) {
                minCost = c[x[k]][x[last]] == 0 ? minCost : min(cost + c[x[k]][x[last]], minCost);
            }
            else backTrack(k+1);
            cost -= c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
    if (minCost == 2000) return 0;
    return minCost;
}

void input() {
    char arr[30];
    gets(arr);
    last = 0;
    for (int i = 0; i < strlen(arr); i+=2) {
        r[++last] =  (int)arr[i] - 48;
    }
    x[1] = r[1]; x[last] = r[last];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    scanf("%d %d\n", &n, &route);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) scanf("%d ", &c[i][j]);
        scanf("\n");
    }

    for (int i = 1; i <= route; i++) {
        input();
        cost = 0; minCost = 2000;
        cout << backTrack(2) << endl;
    }
    return 0;
    for (int i = 1; i < route; i++) {
        cout << res[i] << endl;
    }
    cout << res[route];
}