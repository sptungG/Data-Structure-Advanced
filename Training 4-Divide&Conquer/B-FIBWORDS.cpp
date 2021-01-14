/*
https://drive.google.com/file/d/1XQVyv4xLZpxC8vmkc_r5EaaBW6XNvh9M/view?usp=sharing
-----------------------------------
*/
#include <iostream>
using namespace std;

#define MAX 101
#define P_MAX 100000

long long count[MAX];
long long mid_count[MAX];
unsigned long long len[MAX];
string F[MAX];
int n, n_prep = 0;
string p;
int len_p;

void preprocessing() {
    // Gen words
    F[0] = "0"; len[0] = 1;
    F[1] = "1"; len[1] = 1;
    for (int i = 1; i < 3 || len[i - 3] < P_MAX; i++) {
        F[i + 1] = F[i] + F[i - 1];
        len[i + 1] = len[i] + len[i-1];
        n_prep = i+1;
    }
}

long long countShort(string s, string p) {
    long long c = 0;
    for (int i = 0; i < s.size() - len_p +1; i++) {
        //cout << "SubString = " << s.substr(i, len_p) << endl;
        if (p.compare(s.substr(i, len_p)) == 0)
            c++;
    }
    //cout << "Counting p = " << p << " in s = "<< s << ", result = " << c << endl;
    return c;

}

long long countLong(int n, string p) {
    if (count[n] < 0) {
        count[n] = countLong(n-1, p) + countLong(n-2, p) + mid_count[n%2];
    }
    return count[n];
}

long long solve(int n, string p) {
    if (n < n_prep && len[n] < len_p) {
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        count[i] = -1;
    }

    int k = 1;
    while (len[k - 1] < len_p) k++;
    count[k-1] = countShort(F[k-1], p);
    count[k] = countShort(F[k], p);

    string x = F[k].substr(0, len_p - 1);
    string a = F[k-1].substr(len[k-1] - len_p + 1);
    string b = F[k].substr(len[k] - len_p + 1);

    //cout << "a = " << a << ", b = " << b << ", x = " << x <<endl;

    //cout << "Couting for k = " << k << ", k % 2 = " << k % 2 << ", a + x = " << a+x << ", p = " << p << endl;
    mid_count[k % 2] = countShort(a+x, p);
    //cout << "Couting for k = " << k << ", k+1 % 2 = " << (k+1) % 2 << ", b + x = " << b+x << ", p = " << p << endl;
    mid_count[(k+1) % 2] = countShort(b+x, p);
    /*
    cout << countLong(n, p);
    for (int h = 0; h < n; h++) {
        printf("\ncount[%d] = %lld", h, count[h]);
        printf("\nmidcount[%d] = %lld", h, mid_count[h]);
    }
    */
    return countLong(n, p);
}

int main() {
    preprocessing();
    int noCase = 0;
    while (cin >> n) {
        noCase++;
        cin >> p;
        len_p = p.size();
        if (noCase > 1) cout << endl;
        cout << "Case " << noCase << ": " << solve(n, p);
    }
}