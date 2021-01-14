 //  Created by NPT
#include <iostream>
 
using namespace std;
 
int n, a[200007], b[200007], mod = 1000000007;
unsigned long long p = 1000000007;
 
long long addMod(long long a, long long b){
    if (a<=0) {
        a+=p;
    }
    if (b<=0) {
        b+=p;
    }
    a=a%p;
    b=b%p;
    long long tmp = p - a;
    if (tmp>b) {
        return a+b;
    }
    return b-tmp;
}
 
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n-1; i++) {
        cin >> b[i];
    }
    long long ans = 0;
    for (int i=1; i<=n-1; i++) {
        if (b[i] == 2) {
            int j = i-1;
            long long k = a[i];
            while (b[i] == 2) {
                k = (k * a[i+1])%mod;
                i++;
            }
            if (b[j]==1 || j == 0) {
                ans = addMod(ans, k);
            } else {
                ans = addMod(ans, -k);
            }
            //ans %= mod;
        }
    }
    b[n] = 3;
    if (b[1]!=2) {
        ans = addMod(ans, a[1]);
    }
    for (int i=1; i<=n-1; i++) {
        if (b[i]==0 && b[i+1]!=2) {
            //ans -= a[i+1];
            ans = addMod(ans, -a[i+1]);
        } else if (b[i]==1 && b[i+1]!=2){
            //ans += a[i+1];
            ans = addMod(ans, a[i+1]);
        }
        //ans %= mod;
    }
    cout << ans;
    return 0;
}
