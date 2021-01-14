/*
The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N. 
Due to the policy of the hospital, each nurse cannot work all the days 1,..., N.
Instead, there must be days off in which the nurse need to take a rest.
A working plan is a sequence of disjoint working periods.
A working period of a nurse is defined to be a sequence of consecutive days 
on which the nurse must work and the length of the working period is the number of consecutive days of that working period.
The hospital imposes two constraints:
 Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
 The length of each working period must be greater or equal to K1 and less than or equal to K2 (2)
=>>The director of the hospital want to know how many possible working plans satisfying above constraint?
**Input
The input consists of one line which contains 3 positive integers N,K1,K2(N≤1000,K1<K2≤400)
**Output
The output consists of only one single integer M modulo 10^9+7 where M is the total working plans satisfying the above constraints.
   TEST
6 2 3
=>4
------------------------------------------
*/
//  Created by NPT
#include <iostream>

using namespace std;

int n,k1,k2,f[1007];

int main() {
    cin >> n >> k1 >> k2;
    f[0] = 1; f[1] = 1;
    for (int i=1; i<=n+1; i++) {
        for (int j=k1; j<=k2; j++) {
            if (i-j-1>=0) f[i] += f[i-j-1];
        }
    }
    cout << f[n] + f[n+1];
    return 0;
}
// #include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// int result[1000];
// int N, K1, K2, series = 0;
// int cnt = 0;
// bool check(int i, int k){
//     if(k==1) return true;
//     if(i==1 && series<K2 || i==0 && series>=K1 && ((N-k)>=K1 || k == N)) return true;
//     return false;
// }

// void Try(int k){
//     for(int i = 0; i<=1; i++){
//         if(check(i, k)){

//             result[k] = i;
//             int tmp = series;
//             if(i==1){
//                 series++;
//             } else series =0;

//             if(k==N){
//                 cnt++;

//             } else {
//                 Try(k+1);
//             }

//             series = tmp;
//         }
//     }
// }
// int main(){
//     cin>>N>>K1>>K2;
//     Try(1);
//     int a = cnt% (int)(pow(10,9)+7);
//     cout<<a;
//     return 0;
// }