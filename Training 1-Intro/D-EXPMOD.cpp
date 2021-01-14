#include <iostream>
 
unsigned long long addMod(unsigned long long a, unsigned long long b, unsigned long long p){
    a=a%p;
    b=b%p;
//    unsigned long long tmp = p - a;
//    if (tmp>b) {
//        return a+b;
//    }
//    return b-tmp;
    return (a+b)%p;
}
 
unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long p){
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
 
unsigned long long XmuN(unsigned long long x, unsigned long long n, unsigned long long p){
    if (n==1) {
        return x%p;
    }
    unsigned long long a = XmuN(x, n/2,p);
    a = mulmod(a, a, p);
    if (n%2==0) {
        return a;
    } else {
        return mulmod(a, x, p);
    }
}
 
int main(){
    unsigned long long a,b;// de y phai la unsigned moi full diem
    long m = 1000000007;
    std::cin >> a >> b;
    if (a==0) {
        std::cout << 0;
    } else if(b==0){
        std::cout << 1;
    } else {
        std::cout << XmuN(a, b,m);
    }
    return 0;
}