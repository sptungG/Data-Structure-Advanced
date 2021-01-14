/*
 Country SS consists of N towns indexed from 1 to N, and each town i has its own inter city bus (IC Bus for short) system i. There is K roads between towns, each road connects two different towns.
 The bus can move freely in both directions on the road.

 Quang is living in the town 1 in the country, and decided to go to the grandmother's house 
 in the town N by some inter city buses. There are some special rules in this country:

 *If the passenger want to use the IC Bus of the town i, he has to only ride at the town i.
 *The bus fares of the IC Bus system i is Ci regardless of the distance that the passenger used.
 *The IC Bus system i allows to pass maximum Di towns per trip. If the trip has to pass more than Di towns, 
  the passenger has to change to another IC Bus system.
 *The passenger will not be able ride to or down from the bus at a middle point different than the town.

Your task is to to find the minimum value of
 the sum of the fare needed for Quang to reach the town N from the town 1.

Input
 The input consists of 1 + N + K lines.

The first line contains two positive integers N and K (2 ≤ N ≤ 5000; N−1 ≤ K ≤ 10000).

i-th line in the N following lines contains 2 positive integers Ci and Di (1≤ Ci ≤ 10000; 1 ≤ Di ≤ N) 
               which are the taxi fare and the maximum number of passing towns of the IC Bus system i.

Each line in the K following lines contains two positive integers i and j (1≤i<j≤N) 
                      which means these two towns has a direct road connecting them.

Output
 You should output on a single line an unique integer that is the minimum value of the sum of the fare necessary for Quang to go to the town N from the town 1.

Note: Quang uses the IC Bus of the town 1 and then of the town 5.

Example
inputCopy
6 6
400 2
200 1
500 3
900 1
400 4
200 5
1 2
1 5
2 3
2 4
3 6
4 6
 output
800
*/
//  Created by NPT
#include <bits/stdc++.h>
using namespace std;
const int N  = 5001;
vector<int> A[N];
int c[N],d[N];
int n,K;
int dis[N][N];
int minCost[N];// minCost[v] is the minCost for reaching node v from source node s
bool used[N];// used[v] = true means that node v has been fixed (found minCost to v)
void input(){
    cin >> n >> K;
    for(int v = 1; v <= n; v++)
        cin >> c[v] >> d[v];
    for(int i = 1; i <= K; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
int solve(){
    // compute distance from each node to other nodes
    for(int s = 1; s <= n; s++){
        queue<int> Q;
        for(int v = 1; v <= n; v++) dis[s][v] = n+1;
        dis[s][s] = 0;
        Q.push(s);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            for(int i = 0; i < A[u].size(); i++){
                int v =A[u][i];
                if(dis[s][v] == n+1){// not visited
                    dis[s][v] = dis[s][u] + 1;
                    Q.push(v);
                }
            }
        }
    }
    // dijkstra not using priority queue
    for(int v= 1; v <= n; v++) minCost[v] = 1e9;
    minCost[1] = 0;
    memset(used,false,sizeof(used));
    for(int i = 1; i <= n; i++){
        int minId = -1;// luu dinh co minCost nho nhat ma chua duoc fixed (used = false)
        int minValue = 1e9;
        for(int v = 1; v <= n; v++) if(!used[v]){
            if(minCost[v] < minValue){
                minValue = minCost[v]; minId = v;
            }
        }
        used[minId] = true;
        if(minId == n){
            cout << minCost[minId]; return 0;
        }
        // update minCost of other not used nodes
        for(int v = 1; v <= n; v++) if(!used[v] && dis[minId][v] <= d[minId]){
            minCost[v] = min(minCost[v],minCost[minId] + c[minId]);
            //cout << "update minCost[" << v << "] = " << minCost[v] << endl;
        }
    }
}
int main(){
    input();
    solve();
}
