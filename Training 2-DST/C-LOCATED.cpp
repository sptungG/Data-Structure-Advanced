/*
Hùng là tướng quân của một đội quân lớn, bộ phận thông tin đã chỉ ra rằng kẻ địch đã khởi động một loạt những máy bay chiến đấu nhỏ tiến sát tấn công quân của Hùng.
Chỉ còn rất ít thời gian để phát hiện ra vị trí chính xác của các chiến đấu cơ này để mà tiêu diệt chúng. 
Hùng đã điều chỉnh lên tối đa độ nhạy của rada để định vị các chiến đấu cơ này dù rằng kích thước của chúng rất nhỏ,
tuy nhiên điều đó cũng định vị luôn cả những chú chim đang bay gần đó.
Tuy vậy Hùng biết rằng tất cả các chiến đấu cơ dịch chuyển chính xác theo cùng một cách, điều đó hi vọng giúp Hùng định vị chính xác vị trí của đàn chiến đấu cơ. 
(Cho biết mô tả của 2 hình ảnh mà rada thu được cách nhau 1 phút, Hùng muốn định vị tập lớn nhất các điểm trên ảnh 1,
mà có thể tìm thấy nó trên ảnh 2 sau một khoảng di chuyển xác định. 
Biết rằng dàn chiến đấu cơ có thể không xuất hiện ở trên cả hai ảnh rada.)
**Input
  Dòng đầu tiên ghi ra một số nguyên T là số test. Với mỗi test:
  Dòng đầu tiên chứa 2 số nguyên L và C tương ứng là số dòng và số cột của 2 ảnh (1≤L,C≤1000).
  2∗L dòng tiếp theo mỗi dòng chứa C số nguyên 0 hoặc 1 cách nhau bởi dấu cách,
  trong đó L dòng đầu mô tả ảnh 1, L dòng sau mô tả ảnh 2.
  Ở 1 vị trí xác định, 1 tượng trưng cho có chiến đấu cơ hoặc chim ở đó còn 0 tượng trưng cho vị trí đó không có vật thể nào.
  Biết rằng số lượng số 1 trong một ảnh rada không quá 10000.
**Output
  Với mỗi test tương ứng, ghi duy nhất một số nguyên N là số điểm lớn nhất các đối tượng dịch chuyển theo cùng một cách thức.
1
10 8
0 1 1 0 0 0 0 0
0 1 1 1 0 0 0 0
0 0 0 0 0 1 0 0
0 1 1 1 1 0 0 0
0 0 1 1 1 0 0 0
0 0 0 1 1 0 0 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
1 1 0 1 1 1 1 0
1 1 0 0 1 1 1 0
1 0 0 0 0 1 1 0
0 0 0 1 0 0 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 1 0 0 1 0 0 0
0 0 0 0 0 0 0 0
=> 12
-------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
const int N=1010;
int l,c;
vector<pair<int, int> > a,b;
int d[2*N][2*N];


int main(){
int T;
cin>>T;
while(T--){
	int maxS=0;
	cin>>l>>c;
	int x;
	for(int i=0;i<l;++i)
	   for(int j=0;j<c;++j){ 
	   cin>>x;
	   if(x==1) a.push_back(make_pair(i,j));
	   }
	for(int i=0;i<l;++i)
	   for(int j=0;j<c;++j){
	   cin>>x;
	   if(x==1) b.push_back(make_pair(i,j));
	   }   
	   for(int i=0;i<a.size();++i){
	   	for(int j=0;j<b.size();++j){
	   		int u=a[i].first-b[j].first;
	   		int v=a[i].second-b[j].second;
	   		maxS=max(maxS,++d[u+N][v+N]);
		   }
	   }
/*	for(int x=-l;x<l;++x){
		for(int y=-c;y<c;++y){
			int sum=0;
			for(int i=0;i<l;++i){
				for(int j=0;j<c;++j){
					if(a[i][j]==1){
						if(i+x>=0&&i+x<l&&j+y>=0&&j+y<c&&b[i+x][j+y]==1) sum++;
					}
				}
			}
			maxS=max(maxS,sum);*/
	cout<<maxS<<endl;
	a.clear(),b.clear();
	memset(d,0,sizeof(d));
}

return 0;
}