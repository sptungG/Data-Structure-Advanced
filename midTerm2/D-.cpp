//  Created by NPT
#include <iostream>
 
using namespace std;
 
int n,b,a[37], ans = 0, s[37], sum = 0;
 
void tryy(int i){
    for (int v=0; v<=1; v++) {
        if (v == 0) {
            sum += a[i+1];
        } else {
            sum -= a[i+1];
        }
        if (i==n-1) {
            if (sum == b) {
                ans = (ans+1) % 1000000007;
            }
        } else {
            if (sum>b) {
                if (sum - s[i+2] <=b) {
                    tryy(i+1);
                }
            } else {
                if (sum + s[i+2] >=b) {
                    tryy(i+1);
                }
            }
        }
        if (v == 0) {
            sum -= a[i+1];
        } else {
            sum += a[i+1];
        }
    }
}
 
int main() {
    cin >> n >> b;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=n; i>=1; i--) {
        s[i] = s[i+1]+a[i];
    }
    sum = a[1];
    tryy(1);
    cout << ans;
    return 0;
}