/*
The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced .
There are N courses 1,2,…,N that must be assigned to M periods 1,2,…,M. 
Each courses i has credit ci and has some courses as prerequisites. 
The load of a period is defined to be the sum of credits of courses assigned to that period.
 The prerequisites information is represented by a matrix A[N×N] in which Ai,j = 1 
  indicates that courses i must be assigned to a period before the period to which the course j is assigned.
=>>>>>Compute the assignment such that the maximum load for all periods is minimal.
**Input
 Line 1 contains N and M (2≤N≤16,2≤M≤5)
 Line 2 contains c1,c2,…,cN
 Line i+2(i=1,…,N) contains the ith line of the matrix A
**Output
 Unique line contains that maximum load for all periods of the solution found
TEST
6 2
4 4 4 4 2 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
1 0 0 0 0 0
=> 12
-------------------------------------------------------
*/
#include <iostream>

using namespace std;

#define MAX 30

int N, b; // number of courses, and semesters
int credits[MAX];
int A[MAX][MAX]; // A[i][j] = 1 means that course i must be taken before course j

int X[MAX]; // X[i] is the semester to which course i is assigned
int load[MAX]; // load[j] = number of credits assigned to semester j
int f_best; // optimal objective value

void input() {
    cin >> N >> b;
    for (int i = 1; i <= N; i++) {
        cin >> credits[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
}

bool check(int v, int k) {
    for (int i = 1; i <= k-1; i++) {
        if (A[i][k] == 1) {
            if (X[i] >= v) return false;
        }
        if (A[k][i] == 1) {
            if (X[i] <= v) return false;
        }
    }
    return true;
}

void solution() {
    int max_load = 0;
    for (int j = 1; j <= b; j++) {
        if (max_load < load[j])
            max_load = load[j];
    }
    if (max_load < f_best)
        f_best = max_load;
}

void TRY(int k) {
    for (int v = 1; v <= b; v++) {
        if (check(v, k)) {
            X[k] = v; // assign course k to semester v
            load[v] += credits[k]; // update load
            if (k == N) solution();
            else {
                TRY(k+1);
            }
            load[v] = load[v] - credits[k]; // recover
        }
    }
}

int main() {
    input();
    f_best = 100000000;
    for (int j = 1; j <= b; j++)   
        load[j] = 0;
    TRY(1); // loop 
    cout << f_best;
}