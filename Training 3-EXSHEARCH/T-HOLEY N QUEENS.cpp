/*
The N-queens problem is the problem of placing N queens on
 a N × N chessboard so that no queen shares a row, column or a diagonal with any other queen.
Essentially, we are trying to place the queens without any queen threatening another.
(For example, the first image below (without holes in the board) is a solution to the 8-queens problem.)
For this problem, consider the problem we'll call the 'holey N-queens problem'.
Instead of having an everyday chessboard (of arbitrary size), 
 your chessboard is like the second image above (without queens): it has holes through some of the squares.
 You can't place a queen on a square that has a hole, but a queen can threaten another even if there is a hole on the path between them.
=>> Given a holey chessboard, you must find placements for the N queens so that no queen threatens another.
 (The third image above (with holes and queens) shows one such solution.)
**Input
  Input consists of up to 1000 board descriptions.
  Each description starts with a line containing a pair of integers, 3 ≤ N ≤ 12 and 0 ≤ M ≤ N2,
            indicating respectively the size of one side of the board, and the number of holes. 
  The next M lines each describe the location of a unique hole in the board. 
        A hole is described by its row and column, each in the range [1, N].
  The end of input is marked by values of zero for N and M.
**Output
  For each problem description, print out the number of unique N-queens solutions that are possible.
  Two solutions are considered different if any space is occupied by a queen in one solution but not in the other
TEST
8 0
8 3
1 4
6 5
4 8
0 0
=> 92
   50
--------------------------------------
*/
#include <iostream>
#include <string.h> // thu vien chua ham memset
#define MAX 24
using namespace std;

int n, m, cnt;
int x[12];
bool mark[12][12], markColumn[12], markCheo1[MAX], markCheo2[MAX];

bool check(int v, int k){
    return !mark[k][v] && !markColumn[v] && !markCheo1[k + v] && !markCheo2[k - v + n];
}

void TRY(int k){
    for (int v = 0; v <= n; v++){
        if (check(v, k)){
            x[k] = v;
            //cout << k << " === " << v << '\n';
            markColumn[v] = markCheo1[v + k] = markCheo2[k - v + n] = true;
            if (k == n) cnt++;
            else TRY(k + 1);
            markColumn[v] = markCheo1[v + k] = markCheo2[k - v + n] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(true){
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        memset(mark, 0, sizeof(mark));
        memset(markColumn, 0, sizeof(markColumn));
        memset(markCheo1, 0, sizeof(markCheo1));
        memset(markCheo2, 0, sizeof(markCheo2));
        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            mark[--x][--y] = true;
        }
        n--;
        cnt = 0;
        TRY(0);
        cout << cnt << '\n';
    }
}
