//  Created by NPT
#include <iostream>
 
using namespace std;
 
int n, a[1007];
 
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (a[i]<a[j]) {
                ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}