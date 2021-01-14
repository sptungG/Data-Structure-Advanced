/*
Phong là một nhà điêu khắc, ông có một tấm đá cẩm thạch hình chữ nhật kích thước W×H. 
Ông ta muốn cắt tấm đá thành các miếng hình chữ nhật kích thước W1×H1,W2×H2,…,WN×HN. 
Ông ta muốn cắt đến tối đa các mẫu kích thước có thể. 
Tấm đá có những vân đá cho nên không thể xoay khi sử dụng, có nghĩa là không thể cắt ra miếng B×A thay cho miếng A×B trừ khi A=B. 
Các miếng phải được cắt tại các điểm nguyên trên hàng cột và mỗi nhát cắt phải cắt đến hết hàng hoặc hết cột. 
Sau khi cắt sẽ còn lại những mẩu đá còn thừa bỏ đi, nghĩa là những mẩu đá không thể cắt thành miếng kích thước cho trước nào.
=>Yêu cầu: Hãy tìm cách cắt sao cho còn ít nhất diện tích đá thừa bỏ đi.
  Hình dưới minh họa cách cắt các phiến đá trong ví dụ với diện tích thừa ít nhất tìm được là 10.
(
Famous sculptor Phong is making preparations to build a marvelous monument.
For this purpose he needs rectangular marble plates of sizes W1×H1,W2×H2,…,WN×HN.
Recently, Phong has received a large rectangular marble slab. He wants to cut the slab to obtain plates of the desired sizes.
Any piece of marble (the slab or the plates cut from it) can be cut either horizontally or vertically into two rectangular plates with integral widths and heights,
 cutting completely through that piece.
This is the only way to cut pieces and pieces cannot be joined together. 
Since the marble has a pattern on it, the plates cannot be rotated: 
 if Phong cuts a plate of size A×B then it cannot be used as a plate of size B×A unless A=B. 
He can make zero or more plates of each desired size.
A marble plate is wasted if it is not of any of the desired sizes after all cuts are completed.
Phong wonders how to cut the initial slab so that as little of it as possible will be wasted.
As an example, assume that in the figure below the width of the original slab is 21 and the height of the original slab is 11,
 and the desired plate sizes are 10×4,6×2,7×5, and 15×10. 
=> The minimum possible area wasted is 10, and the figure shows one sequence of cuts with total waste area of size 10.)
Your task is to write a program that, given the size of the original slab and the desired plate sizes, 
calculates the minimum total area of the original slab that must be wasted.
**Input
 Dòng đầu tiên chứa hai số nguyên: W và H.
 Dòng thứ hai chứa một số nguyên N. 
 N dòng tiếp theo mỗi dòng chứa hai số nguyên Wi và Hi.
 
 (The first line of input contains two integers: first W, the width of the original slab, and then H, the height of the original slab;
 The second line contains one integer N: the number of desired plate sizes. 
 The following N lines contain the desired plate sizes.
   Each of these lines contains two integers: first the width Wi and then the height Hi of that desired plate size (1≤i≤N).)
**Output
 Kết quả ghi ra duy nhất một số nguyên là tổng diện tích nhỏ nhất các miếng thừa bỏ đi.
 (For each dataset, write in one line a single integer: the minimum total area of the original slab that must be wasted.)
*Scoring
  1≤W≤600,1≤H≤600,0<N≤200,1≤Wi≤W, and 1≤Hi≤H.
  Có 50% số test ứng với W≤20,H≤20 và N≤5.
   TEST
21 11
4
10 4
6 2
7 5
15 10
=>10
----------------------------------
*/
//  Created by NPT
#include <iostream>

using namespace std;
 
//solution: https://www.iarcs.org.in/inoi/online-study-material/problems/phidias-soln.php

int n, m, k, s[602][602], c[602][602];
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    int x,y;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        c[x][y] = 1;
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (c[x][y]) continue;
            s[x][y] = x * y;
            for (int x1 = 1; x1 <= x/2; x1++) s[x][y] = min( s[x][y], s[x1][y] + s[x - x1][y] );
            for (int y1 = 1; y1 <= y/2; y1++) s[x][y] = min( s[x][y], s[x][y1] + s[x][y - y1] );
        }
    }
    cout << s[n][m] << "\n";
    return 0;
}
//--------------------------------------------------------------
// #include <algorithm>
// #include <iostream>
// #define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
// using namespace std;

// int n, m;
// int DP[602][602];
// int C[602][602];
// int k, x, y;

// int main(){

// 	optimizar_io
// 	cin >> n >> m >> k;
// 	for( int i = 1; i <= k; i++ ){
// 		cin >> x >> y;
// 		C[x][y] = 1;
// 	}
	
// 	int x, y, x1, y1, lim;
// 	for( x = 1; x <= n; x++ ){
// 		for(  y = 1;  y <= m; y++ ){
			
// 			if( C[x][y] ) continue;
// 			DP[x][y] = x * y;
			
// 			lim = x / 2;
// 			for( x1 = 1; x1 <= lim; x1++ )
// 				DP[x][y] = min( DP[x][y], DP[x1][y] + DP[x - x1][y] );
			
// 			lim = y / 2;
// 			for( y1 = 1; y1 <= lim; y1++ )
// 				DP[x][y] = min( DP[x][y], DP[x][y1] + DP[x][y - y1] );
 			
// 		}
// 	}
// 	cout << DP[n][m] << "\n";
	
// 	return 0;

// }
//--------------------------------------------------------------
// #include <bits/stdc++.h>

// using namespace std;

// int w, h;
// int table[601][601];

// void init() {
//     for (int i=1; i<=h; i++) {
//         for (int j=1; j<=w; j++) {
//             table[i][j] = i*j;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie();

//     int m;
//     cin >> w >> h;
//     cin >> m;
//     init();
//     for (int i=0; i<m; i++) {
//         int tmp1, tmp2;
//         cin >> tmp1 >> tmp2;
//         table[tmp2][tmp1] = 0;
//     }

//     //dp
//     for (int i=1; i<=h; i++) {
//         for (int j=1; j<=w; j++) {
//             int minWaste = table[i][j];
//             // horizonal cut
//             for(int k=1; k<=i; k++) {
//                 minWaste = min(minWaste, table[k][j] + table[i-k][j]);
//             }
//             // vertical cut
//             for (int k=1; k<=j; k++) {
//                 minWaste = min(minWaste, table[i][k] + table[i][j-k]);
//             }
//             table[i][j] = minWaste;
//         }
//     }

//     cout << table[h][w] << endl;
// }