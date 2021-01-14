/*
Đường vành đai III của thành phố Naho nổi tiếng về chất lượng mặt đường tồi tệ.
 Lí do là đội ngũ sửa chữa đường của thành phố này quá tùy tiện.
 Đường vành đai III được chia nhỏ thành N đoạn kế tiếp nhau có cùng chiều dài đơn vị.
Mỗi lần sửa chữa đường họ tiến hành như sau:
  Một nhóm công nhân sẽ lựa chọn một đoạn đường nào đó và thay thế toàn bộ lớp nhựa phủ đường trên đoạn đó. 
  Loại nhựa đường được thay thế trên đoạn này có thể khác hẳn với loại nhựa đường trên các đoạn khác làm gây khó khăn cho việc đi lại trên đường.
Là cư dân thành phố Naho và là một lập trình viên giỏi, 
  Hải quyết định sử dụng hiểu biết của mình để giúp ích cho xã hội và làm thuận tiện cho cuộc sống của người dân thành phố khi phải đi qua đường vành đai III.
  Cụ thể là Hải quyết định tạo trang web chứa thông tin về độ gập ghềnh của đường.
  Hải đánh số các đoạn đường từ 1 đến N và thu thập thông tin về loại nhựa đường trên từng đoạn t1,t2,…,tN (ti là mã loại nhựa đường phủ trên đoạn đường thứ i ). 
  Hải định nghĩa một phần đường là một dãy liên tục các đoạn đường được phủ cùng loại nhựa phủ tk và 
  bên trái và bên phải phần đường đó là các đoạn đường (nếu tồn tại) được phủ loại nhựa khác.
  Cuối cùng, Hải xác định độ gập ghềnh của đường bằng tổng số lượng phần đường trên đường vành đai III. 
(Ví dụ đường phố chứa các đoạn đường được phủ bởi loại nhựa có mã lần lượt tương ứng với 1,1,0,1,1,1 sẽ có độ gập ghềnh bằng 3 vì nó chứa đúng 3 phần đường 11, 0 và 111.
Đường phố chứa các đoạn đường được phủ bởi loại nhựa có mã lần lượt tương ứng với 2,2,2,2 là lý tưởng vì nó chỉ chứa 1 phần đường và có độ gập ghềnh đúng bằng 1.)
Dân chúng sẽ hài lòng nếu Hải luôn có thể tính toán và cung cấp trên trang web độ gập ghềnh của đường tại thời điểm hiện tại.
 Đáng tiếc là mặt đường được thay đổi khá thường xuyên và Hải không muốn mỗi lần như vậy lại phải ra đường thu thập dữ liệu.
Vì vậy Hải yêu cầu đội ngũ sửa chữa đường mỗi lần sửa đường phải gửi một thông báo cho Hải.
 Mỗi thông báo bao gồm 2 số là số thứ tự đoạn đường được sửa và mã loại nhựa được phủ mới.
 =>> Nhiệm vụ của Hải là phải cập nhật độ gập ghềnh thực tế của đường sau mỗi thông báo như vậy.
**Input
 Dòng đầu tiên chứa số tự nhiên duy nhất N là số lượng đoạn đường (1≤N≤10^5).
 Dòng tiếp theo chứa N số nguyên t1,t2,…,tN là các loại nhựa đường ban đầu phủ trên các đoạn đường (|ti|≤10^9).
 Dòng thứ 3 chứa số nguyên duy nhất Q là số lượng thông báo từ dân chúng về việc sửa chữa mặt đường (1≤Q≤10^5).
 Mỗi dòng trong số Q dòng tiếp theo chứa lần lượt các thông báo. 
 Thông báo thứ i là cặp hai số nguyên pi, ci là số thứ tự của đoạn đường được sửa và mã loại nhựa đường mới được phủ lên trên đoạn đường này (1≤pi≤N, |ci|≤10^9).
 Đoạn đường được đánh số từ 1 đến N theo đúng thứ tự ghi loại nhựa đường trong dòng thứ 2 của dữ liệu vào.
**Output
 In ra Q dòng: dòng thứ i (1≤i≤Q) phải chứa đúng một số nguyên duy nhất là giá trị độ gập ghềnh của đường sau i thông báo sửa đường đầu tiên.
TEST
7
1 1 2 3 2 2 1
3
2 2
4 2
6 9
=> 5
   3 
   4
5
2 2 2 2 2
5
1 2
2 3
4 3
3 1
3 3
=> 1
   3
   5
   5
   3
-------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
int n,ans;
void solve(int a[])
{
    int x,c;
    cin>>x>>c;
    if(x==1) {
        int cnt=1;
        if(a[x] != a[x+1]) cnt++;
        ans -= cnt;
		ans++;
        a[x]=c;
        if(a[x]!=a[x+1]) ans++;
        return;
    }
    if(x==n){
        int cnt=1;
        if(a[x]!=a[x-1]) cnt++;
        ans-=cnt;ans++;
        a[x]=c;
        if(a[x]!=a[x-1]) ans++;
        return;
    }
    int cnt=1;
    for(int i=x;i<=x+1;i++) if(a[i]!=a[i-1]) cnt++;
    ans-=cnt;
    ans++;
    a[x]=c;
    for(int i=x;i<=x+1;i++){
        if(a[i]!=a[i-1]) ans++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=1;
    for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) ans++;
    int k;
    cin>>k;
    while(k--){
        solve(a);
        cout<<ans<<endl;
    }
}