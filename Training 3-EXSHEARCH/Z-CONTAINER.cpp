/*
There is a container having horizontal size W and vertical size H. 
There are N rectangle items 1, 2, ..., N in which item i has horizontal size wi and vertical size hi.
=>> Find the way to place these N items into the container such that
     The sides of items are packed in parallel with the sides of the container
     The items cannot rotated
     No two items overlap.
**Input
 The input consists of following lines
  Line 1: contains two integer H and W (1≤H,W≤30)
  Line 2: contains N (1≤N≤12)
  Line i+2 (∀i=1,…,N): contains two integers hi and wi
**Output
 The output contains a unique number 0 (if we cannot place items) or 1 (if we can place items)
TEST
6 4
3
2 3
6 1
4 3
=> 1
------------------------------------------
*/
#include <iostream>
using namespace std;

int n, k, cnt = 0;
int a[10002];

void solution(){
    cnt++;
    if (cnt == k) {
        for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
        exit(0) ;
    }
}

int main(){
    cin >> n >> k;
    if (n == 0) {
        cout << -1 << '\n';
        exit(0);
    }
    for (int i = 1; i <= n; i++) a[i] = i;

    int i = n;
    do{
        solution();
        i = n - 1;
        while ( i > 0 && a[i] > a[i + 1]) i--;
        if (i > 0){
            int k = n;
            while (a[k] < a[i]) k--;
            swap(a[k], a[i]);

            int p = i + 1, q = n;
            while (p < q){
                swap(a[p], a[q]);
                p++;
                q--;
            }
        }
    } while (i > 0);
    cout << -1 << '\n';
}