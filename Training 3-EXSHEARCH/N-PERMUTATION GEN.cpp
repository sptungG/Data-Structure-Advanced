/*
Cho 1 một hoán vị H độ dài n với các thành phần nằm trong tập {1,2,…,n}. 
=>> Tìm hoán vị kế tiếp của hoán vị H trong thứ tự từ điển.
**Input
  Dòng đầu ghi 1 số nguyên dương n≤10^4.
  Dòng thứ 2 ghi n số nguyên dương ≤n cách nhau bởi dấu cách là hoán vị H.
**Output
  Ghi ra hoán vị H trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách.
          Nếu không tồn tại thì ghi ra -1.
TEST
5
3 2 1 5 4
=> 3 2 4 1 5 
------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
/*
---tao hoan vi ke tiep
tim tu R qua L hoan vi
*/
const int N=10010;
int a[N];
int n;
int main(){
cin>>n;
for(int i=1;i<=n;++i) cin>>a[i];
if(next_permutation(a+1,a+n+1)){
	for(int i=1;i<=n;++i){
		cout<<a[i]<<' ';
	}
}else cout<<-1;
return 0;

/*int j=n-1;
while(a[j]>a[j+1]){
	--j;
	if(j==0) break;
}
if(j==0) cout<<-1;
else{
int k=n;
while(a[j]>a[k]) --k;
swap(a[j],a[k]);
int l=j+1,r=n;
while(l<r) swap(a[l++],a[--r]);
for(int i=1;i<=n;++i) cout<<a[i]<<' ';
return 0;
}*/
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, k;
// int cnt = 0;
// int x[10001];
// bool mark[10001];

// void print(){
//     cnt++;
//     if (cnt == k){
//         for (int i = 1; i <= n; i++) cout << x[i] << ' ';
//         exit(0);
//     }
// }

// void TRY(int k){
//     for (int v = 1; v <= n; v++){
//         if (!mark[v]){
//             x[k] = v;
//             mark[v] = true;
//             if (k == n) print();
//             else TRY(k + 1);
//             mark[v] = false;
//         }
//     }
// }


// int main(){
//     cin >> n >> k;
//     TRY(1);
//     if (cnt < k) cout << -1 << endl;
// }