/*

 */
//  Created by NPT on 15/01/2021.
#include <iostream>
#include <vector>

using namespace std;

int n,m,a[1000],a1[1000],amax=0,ans,bag[1000];
vector <int> kq[507];

bool check(int mid){
    for (int i=1; i<=n; i++) {
        a1[i] = a[i];
        bag[i]=0;
    }
    for (int i=1; i<=n; i++) {
        int okk=0;
        for (int j=1; j<=m; j++) {
            if (bag[j]+a[i]<=mid) {
                bag[j]+=a[i];
                okk=1;
                break;
            }
        }
        if (okk==0) {
            return false;
        }
    }
    return true;
}

void sol(int ans){
    for (int i=1; i<=n; i++) {
        bag[i]=0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (bag[j]+a[i]<=ans) {
                bag[j]+=a[i];
                kq[j].push_back(i);
                break;
            }
        }
    }
    for (int i=1; i<=m; i++) {
        cout << kq[i].size() << " ";
        for (int j=0; j<kq[i].size(); j++) {
            cout << kq[i][j]-1 << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        amax=max(amax, a[i]);
    }
    //sort(a+1, a+n+1);
    int l = 0, r = 100000000, mid;
    while (r-l>1) {
        mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(r)) ans = r;
    cout << ans << endl;
    sol(ans);
    return 0;
}