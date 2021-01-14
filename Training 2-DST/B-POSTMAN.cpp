/*
Chuyển phát hàng là một công việc quan trọng trong thương mại điện tử là lĩnh vực phát triển bùng nổ trong thời gian hiện nay. 
Ta xét công việc của một nhân viên giao hàng của Công ty XYZ chuyên bán hàng trên mạng.
Nhân viên giao hàng cần phát các kiện hàng (được đóng gói trong các hộp cùng kích thước) đến các khách hàng có địa chỉ trên một đại lộ có dạng một đường thẳng.
Nhân viên giao hàng sẽ nhận các kiện hàng tại trụ sở công ty ở vị trí x=0, 
và cần chuyển phát hàng đến n khách hàng, được đánh số từ 1 đến n. 
Biết xi và mi là vị trí của khách hàng i và số lượng kiện hàng cần chuyển cho khách hàng này.
Do các kiện hàng là khá cồng kềnh nên mỗi lần đi chuyển phát nhân viên giao hàng chỉ có thể mang theo không quá k kiện hàng.
Nhân viên giao hàng xuất phát từ trụ sở, nhận một số (không quá k) kiện hàng và di chuyển theo đại lộ để chuyển phát cho một số khách hàng. 
Khi giao hết các kiện hàng mang theo, nhân viên giao hàng lại quay trở về trụ sở 
 và lặp lại công việc nói trên cho đến khi chuyển phát được tất cả các kiện hàng cho khách hàng.
Sau khi kết thúc công việc chuyển phát, nhân viên phải quay trở lại trụ sở công ty để nộp cho phòng kế toán tất cả các hóa đơn giao nhận có ký nhận của khách hàng.
   Giả thiết là: tốc độ di chuyển của nhân viên là 1 đơn vị khoảng cách trên một đơn vị thời gian.
   Thời gian nhận hàng ở trụ sở công ty và thời gian bàn giao hàng cho khách hàng được coi là bằng 0.
=>>Yêu cầu: Giả sử thời điểm mà nhân viên giao hàng bắt đầu công việc là 0. 
   Hãy giúp nhân viên giao hàng tìm cách hoàn thành công việc đã mô tả ở trên tại thời điểm sớm nhất.
**Input
  Dòng đầu tiên chứa hai số nguyên dương được ghi cách nhau bởi dấu cách n và k (n≤1000;k≤10^7).
  Dòng thứ i trong số n dòng tiếp theo chứa hai số nguyên được ghi cách nhau bởi dấu cách xi (|xi|≤10^7) và mi(1≤mi≤10^7)
**Output
  Ghi ra một số nguyên là thời điểm sớm nhất mà người giao hàng có thể hoàn thành nhiệm vụ của mình.
TEST
7 1
9400000 10000000
9500000 10000000
9600000 10000000
9700000 10000000
9800000 10000000
9900000 10000000
10000000 10000000
=> 1358000000000000
4 10
-7 5
-2 3
5 7
9 5
=> 42
-------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pair_ll;
const int maxN = 1e3 + 7;
int n ;
ll k , ans = 0;
pair_ll product_order[maxN];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    cin >> k;
    for(int i = 1 ; i <= n ; i++) cin >> product_order[i].first >> product_order[i].second;
    // sap xep theo quang duong di
    sort(product_order + 1 , product_order + n + 1);
	
	// truong hop khoang cach duong (> 0)
    while(product_order[n].first > 0)
    {
        if(product_order[n].second < 0)
        {
            if(product_order[n-1].first > 0) product_order[n-1].second += product_order[n].second;
            n-- ;
            continue;
        }
        // T: so luot chuyen cho nguoi o vi tri xa nhat ma chua duoc giao toan bo hang
        ll T = product_order[n].second / k;
        ll buff = 0;
        if(T * k != product_order[n].second)
        {
            ++T;
            // so hang con du sau luot chuyen cuoi cung
            buff = k - product_order[n].second % k; 
        }
        T = T * 2 * product_order[n].first;
        ans+= T;
        // neu so hang giao dot cuoi con du se chuyen cho nguoi gan nhat tren duong di ve
        if(product_order[n-1].first > 0) {product_order[n-1].second -= buff; }
        n--;
    }
    int pos = 1;
    // truong hop khoang cach am ( < 0)
    while(product_order[pos].first < 0)
    {
        if(product_order[pos].second < 0)
        {
            if(product_order[pos + 1].first < 0) product_order[pos + 1].second += product_order[pos].second;
            pos++;
            continue;
        }
        // T: so luot giao hang
        ll T = product_order[pos].second / k;
        ll buff = 0;
        if(T * k != product_order[pos].second)
        {
            ++T;
            // so hang con thua sau luot giao cuoi cung
            buff = k - product_order[pos].second % k;
        }
        // quang duong giao hang cho nguoi o vi tri pos
        T = T * 2 * abs(product_order[pos].first);
        ans+= T;
        if(product_order[pos + 1].first < 0)
        {
            product_order[pos + 1].second -=buff;
        }
        pos++;
    }
    cout << ans;
    return 0;
}