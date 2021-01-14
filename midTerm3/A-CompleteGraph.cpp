// input
// 4
// 0 1 1 1
// 1 0 1 1
// 1 1 0 1
// 1 1 1 0
// output
// 1
//  Created by NPT
#include <iostream>
 
using namespace std;
 
int n, a[1007][1007];
 
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    int check = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j && a[i][j]!=1) {
                check = 0;
            }
        }
    }
    cout << check;
    return 0;
}