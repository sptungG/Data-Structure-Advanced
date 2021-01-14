//  Created by NPT
#include <iostream>
 
using namespace std;
 
int n, a[100007], f[100007][3],f2[100007][3];
 
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        f[i][0] = -999999999;
        f[i][1] = -999999999;
        cin >> a[i];
        if (a[i]%2 == 0) {
            f[i][0] = a[i];
            f2[i][0] = 1;
        } else {
            f[i][1] = a[i];
            f2[i][1] = 1;
        }
    }
    for (int i=2; i<=n; i++) {
        int j=i-1;
        if (a[i]%2 == 0) {
            if (f2[j][0]!=0) {
                f[i][0] = max(f[j][0]+a[i], f[i][0]);
                f2[i][0] = 1;
            }
            if (f2[j][1]!=0) {
                f[i][1] = max(f[j][1]+a[i], f[i][1]);
                f2[i][1] = 1;
            }
        } else {
            if (f2[j][1]!=0) {
                f[i][0] = max(f[j][1]+a[i], f[i][0]);
                f2[i][0] = 1;
            }
            if (f2[j][0]!=0) {
                f[i][1] = max(f[j][0]+a[i], f[i][1]);
                f2[i][1] = 1;
            }
        }
    }
    int ans = -999999999;
    for (int i=1; i<=n; i++) {
        ans = max(ans, f[i][0]);
    }
    cout << ans;
    return 0;
}