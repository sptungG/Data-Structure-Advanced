/*
Given a sequence of positive integers a1,…,aN (0<ai≤1e9+7).
 You are required to compute the product S=a1×⋯×aN. In order to avoid overflow (if any),
 You should report the value S modulo 109+7.

Input
The input consists of following lines:
 The first line contains N (1≤N≤1e6).
 Line 2 contains N positive integers a1,…,aN which are less than or equal to 1000.
Output
Write S modulo 1e9+7.

Example
 input
4
3 1 2 3
 output
18
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n, m = 1000000007;

unsigned long long addMod(unsigned long long a, unsigned long long b, unsigned long long p){
    a=a%p;
    b=b%p;
    unsigned long long tmp = p - a;
    if (tmp>b) {
        return a+b;
    }
    return b-tmp;
}
 
unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long p){
    if (a==0 || b==0) {
        return 0;
    }
    if (a==1) {
        return b%p;
    }
    if (b==1) {
        return a%p;
    }
    if (a>b) {
        unsigned long long tmp = a; a=b; b=tmp;
    }
    unsigned long long c = mulmod(a/2, b, p);
    c = addMod(c, c, p);
    if (a%2==0) {
        return c;
    } else {
        return addMod(c, b, p);
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    long long ans = 1;
    for (int i=1; i<=n; i++) {
        long long a;
        cin >> a;
        ans = (ans * (a%m)) % m;
    }
    cout << ans;
    return 0;
}
