/*
Một thiết bị cảm biến có nhiệm vụ thu nhận dữ liệu về các đối tượng trong 1 khu vực để truyền về cho trung tâm xử lý. 
  Mỗi đối tượng sẽ được biểu diễn bởi 1 dãy số nguyên dương. Như vậy, cảm biến sẽ truyền các dãy số về cho trung tâm xử lý.
  Tuy nhiên, do các đối tượng ở gần nhau và có tín hiệu nhiễu nên một dãy số gửi về cho trung tâm có thể là dữ liệu của 2 đối tượng.
Dãy a1,...,an sẽ là dữ liệu của 2 đối tượng nếu có 1 vị trí i (1<i<n) sao cho max{a1,..,ai−1}−ai≥b 
    và max{ai+1,..,an}−ai≥b với b là hằng số cho trước (xem minh hoạ trong Hình 1). 
Khi phát hiện một dãy số a1,...,an là dữ liệu của 2 đối tượng thì cần phải tiến hành cắt dãy số đó thành 2 dãy,
    mỗi dãy là dữ liệu của một đối tượng. Khi đó vị trí cắt sẽ là vị trí i 
    sao cho max{a1,..,ai−1}−ai+max{ai+1,..,an}−ai đạt giá trị lớn nhất (giá trị đó gọi là độ đo cắt tín hiệu).
(Ví dụ: với giá trị b = 5 thì dãy số 3, 5, 4, 7, 2, 5, 4, 6, 9, 8 là dữ liệu của 2 đối tượng
   vì tìm thấy vị trí i=5 tại đó max{3,5,4,7}−2≥5 và max{5,4,6,9,8}−2≥5 và vị trí i=5 cũng chính là vị trí cắt.)
=>> Yêu cầu: cho trước giá trị n,b và dãy số nguyên dương a1,...,an.
  Hãy lập trình kiểm tra xem dãy số a1,...,an có phải là dữ liệu biểu diễn 2 đối tượng hay không 
  và tính độ đo cắt tín hiệu nếu câu trả lời là có.
**Input
 Dữ liệu đầu vào bao gồm các dòng sau:
  Dòng thứ nhất chứa 2 số nguyên dương n và b (3≤n≤200000,1≤b≤50)
  Dòng thứ 2 chứa n tự nhiên a1,...,an
**Output
 Ghi ra độ đo cắt tín hiệu nếu dãy đầu vào là dữ liệu biểu diễn 2 đối tượng 
 và giá trị -1 nếu ngược lại.
TEST
10 5
3 5 4 7 2 5 4 6 9 8
=> 12
--------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b;
    cin>>n>>b;
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++) cin>>a[i];
    int f[n];
    f[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        f[i]=max(a[i],f[i+1]);
    }
    int ans=0;
    int maxs=0;
    for(int i=1;i<n-1;i++){
        maxs=max(maxs,a[i-1]);
        if(maxs-a[i]>=b && f[i+1]-a[i]>=b){
            ans=max(ans,maxs+f[i+1]-2*a[i]);
            cnt++;
        }
    }
    if(cnt) cout<<ans<<endl;
    else cout<<-1<<endl;
}