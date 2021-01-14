/*
Lỗ Ban là một vị thợ mộc nổi tiếng bậc nhất thời Tống của Trung Quốc với đôi bàn tay cực kỳ tài hoa khéo léo.
Ngưỡng mộ tài năng của Lỗ Ban, Vua Tống mời Lỗ Ban vào triều làm quan chuyên quản lý việc thiết kế cung điện và chế tác vật dụng tinh xảo. 
Vua Tống trong một chuyến du ngoạn ở núi Ngũ Nhạc tình cờ phát hiện một phiến đá ngũ sắc tuyệt đẹp,
 Vua Tống nảy ra ý định đem phiến đá này về cung để chế tác thành một bàn cờ. Nhưng Vua Tống nhanh chóng phát hiện ra rằng,
 phiến đá này có hình dạng kỳ lạ rất khó để có thể cắt ra phần diện tích vuông vắn đủ lớn cho bàn cờ. Vậy là Vua Tống triệu Lỗ Ban vào triều để thương lượng:
Bề mặt phiến đá có thể được mô tả như là một hình đa giác được ghép thành từ nhiều phiến đá nhỏ hình chữ nhật có chung nhau một mép,
có các chiều dài khác nay nhưng giống nhau về chiều rộng và bằng 1 đơn vị.
(Trong hình vẽ dưới đây, phiến đá đa giác gồm các hình chữ nhật có chiều cao lần lượt từ trái qua phải là 2,1,4,5,1,3,3 và chiều rộng đều bằng 1.)
=>> Yêu cầu: Bạn cần giúp Lỗ Ban tìm ra hình chữ nhật chung mép với các hình chữ nhật nhỏ và có diện tích lớn nhất nằm trong phiến đá đa giác nói trên.
   (Ở hình vẽ dưới, hình chữ nhật lớn nhất là hình được gạch chéo.)
**Input
  Chứa một hoặc nhiều test. 
  Mỗi test mô tả một đa giác bắt đầu bằng số nguyên n (1≤n≤1000000) là số lượng hình chữ nhật nhỏ cấu thành đa giác.
  Tiếp theo sau là n số nguyên l1,l2,…,ln với 0≤li≤100000000 lần lượt từ trái sang phải biểu thị chiều dài của các hình chữ nhật.
  Chiều rộng của các hình chữ nhật bằng nhau và bằng 1.
  File kết thúc với dòng ghi duy nhất một số 0.
**Output
  Với mỗi test ghi trên một dòng diện tích của hình chữ nhật nằm trong đa giác thỏa mãn điều kiện đề bài.
TEST
2 0 0
3 0 0 0
4 0 1 0 1
5 1 0 1 0 1
6 2 0 1 0 1 0
0
=>
0
0
1
1
2
-------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int N =1000010;
int n;
int a[N];

long long hist(int l, int r){
	if(l==r) return a[l];
	int m=(l+r)/2;
	int h=a[m];
	int indexL=m, indexR=m;
	long long mid =a[m];
	while(indexL>l || indexR<r){
		while(indexL>l && a[indexL-1]>=h) indexL--;
		while(indexR<r && a[indexR+1]>=h) indexR++;
		mid =max(mid,(long long)(indexR-indexL+1)*h);
		
		if(indexL>l){
			if(indexR<r) h=max(a[indexL-1],a[indexR+1]);
			else h=a[indexL-1];
		}else{
			if(indexR<r) h=a[indexR+1];
			else h=0;
		}
	}
long long left=hist(l,m);
long long right=hist(m+1,r);
return max(mid,max(left,right));
}

int main(){
cin>>n;
while(n!=0){
	for(int i=1;i<=n;++i)
		cin>>a[i];
		cout<<hist(1,n)<<endl;
		cin>>n;
}

return 0;
}
