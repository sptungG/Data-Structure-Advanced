/*
At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way.
The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}.
Each teacher t∈T has a preference list which is a list of courses 
             he/she can teach depending on his/her specialization.
We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as 
 these courses have been already scheduled in the same slot of the timetable.
The load of a teacher is the number of courses assigned to her/him.
=>>How to assign n courses to m teacher such that each course assigned to a teacher is in his/her preference list,
          no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
**Input
  The input consists of following lines
   Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
   Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
   Line m+2: contains an integer k
   Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
**Output
The output contains a unique number which is the maximal load of the teachers in the solution found
    and the value -1 if not solution found
TEST
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12
=>>>> 3
----------------------------------
*/
#include <bits/stdc++.h>
#define MAX 31
using namespace std;

int m, n; /// m: the number of teachers, n: the number of courses
int k; /// k: the number of paired conflicting courses
int conflict[MAX][MAX]; /// conflict[i][j]: course i conflict to course j
int load[MAX]; /// load[i]: the number of courses assigned to teacher i
int teach[MAX][MAX]; /// teach[i][j]: mark that teacher i can teach course j
int taught[MAX][MAX]; /// taught[i][j] dánh d?u gv i dã d?y môn j
bool cant_assign;
int ans = 30;

bool cmp(int p, int q) {
    return load[p] < load[q];
}

int get_ans() {
    return *max_element(load + 1, load + n + 1);
}

void arrange(int i) { /// arrange(i): phân công môn i cho 1 giáo viên nào dó
    if (get_ans() >= ans) return; ///n?u có 1 gv d?y nhi?u hon k?t qu? dã ghi nh?n thì thoát
    if (i > n) { /// n?u dã phân công h?t các môn thì c?p nh?t k?t qu?
        ans = min(ans, get_ans()); ///update minimal load
        return;
    }
    vector < int > index; /// the set of teachers can teach course i

    for (int j = 1; j <= m; j++) {/// duy?t t?t c? các giáo viên
        for (int k = 1; k < i; k++) { /// duy?t các môn k tru?c môn i
            if (conflict[k][i] && taught[j][k]) { /// n?u môn k conflict v?i môn i và môn k dã du?c d?y b?i gv j
                ///gán cant_assign = 1 dánh d?u giáo viên j không th? d?y môn i
                cant_assign = true;
                break;
            }
        }
        if (teach[j][i] == 1 && !cant_assign) {
            index.push_back(j); /// dua giáo viên j vào danh sách các gv có th? d?y môn i
        }
        cant_assign = false;
    }

    ///sort the teachers can teach course i according to the load of them
    sort(index.begin(), index.end(), cmp); /// tìm giáo viên có s? môn ít nh?t d? giao cho môn i
    for (int j : index) {
        load[j] = load[j] + 1;
        taught[j][i] = 1;
        arrange(i+1);
        load[j] = load[j] - 1;
        taught[j][i] = 0;
    }
}

int main() {
    cin >> m >> n;
    for (int j = 1; j <= m; j++) {
        int x; /// x: the number courses teacher j can teach
        cin >> x;
        while (x--) {
            int p;
            cin >> p;
            teach[j][p] = 1;
        }
    }
    cin >> k;
    while (k--) {
        int p1, p2; /// p1 and p2 is two courses conflict
        cin >> p1 >> p2;
        if (p1 > p2) {
            swap(p1, p2);
        }
        conflict[p1][p2] = 1;
    }
    ans = MAX;
    arrange(1);
    for (int i = 1; i <= n; i++) {
        int check = 0;
        for (int j = 1; j <= m; j++) {
            if (teach[j][i] == 1) {
                check = 1;
                break;
            }
        }
        if (check == 0) {
            cout << -1;
            return 0;
        }
    }
    cout << ans << endl;
}