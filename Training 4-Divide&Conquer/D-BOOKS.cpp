/*
Before the invention of book-printing, it was very hard to make a copy of a book.
All the contents had to be re-written by hand by so called scribers.
The scriber had been given a book and after several months he finished its copy.
One of the most famous scribers lived in the 15th century and his name was Xaverius Endricus Remius Ontius Xendrianus (Xerox).
Anyway, the work was very annoying and boring. And the only way to speed it up was to hire more scribers.
Once upon a time, there was a theater ensemble that wanted to play famous Antique Tragedies.
The scripts of these plays were divided into many books and actors needed more copies of them, of course.
So they hired many scribers to make copies of these books. 
Imagine you have m books (numbered 1,2,…,m) that may have different number of pages (p1,p2,…,pm) 
 and you want to make one copy of each of them. 
  Your task is to divide these books among k scribes, k≤m. 
   Each book can be assigned to a single scriber only, and every scriber must get a continuous sequence of books.
   That means, there exists an increasing succession of numbers 0=b0<b1<b2,…<bk−1≤bk=m
  such that i-th scriber gets a sequence of books with numbers between bi−1+1 and bi.
The time needed to make a copy of all the books is determined by the scriber who was assigned the most work.
===Therefore, our goal is to minimize the maximum number of pages assigned to a single scriber.
   Your task is to find the optimal assignment.
**Input
The input consists of N cases (equal to about 200).The first line of the input contains only positive integer N. 
Then follow the cases. Each case consists of exactly two lines.
  At the first line, there are two integers m and k, 1≤k≤m≤500. 
  At the second line, there are integers p1,p2,…,pm separated by spaces.
All these values are positive and less than 10000000.
**Output
For each case, print exactly one line. The line must contain the input succession p1,p2,…,pm divided into exactly k parts 
     such that the maximum sum of a single part should be as small as possible. 
Use the slash character ('/') to separate the parts.
   There must be exactly one space character between any two successive numbers and between the number and the slash.
If there is more than one solution, print the one that minimizes the work assigned to the first scriber,  
then to the second scriber etc. 
  But each scriber must be assigned at least one book.
    TEST
2
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100
==>
100 200 300 400 500  / 600 700  / 800 900 
100  / 100  / 100  / 100 100 
----------------------------------------
*/
#include <bits/stdc++.h>
#define MAX 500
using namespace std;

int B, S; /// B: the number of books
          /// S: the number of scribes
long long l, r, m;
long long p[MAX]; /// p[i]: the number of pages of book i
long long first[MAX]; /// first[i]: the indexes of the first books in each part
long long most_valid_first[MAX]; /// the most valid first[]

void update(long long max_val) {
    long long sum = 0, tmp = first[max_val];

    for(long long i = first[max_val+1] - 1; i >= tmp; i--) {
        sum += p[i];

        if(sum == m) {
            first[max_val] = i;
            break;
        } else if(sum > m) {
            first[max_val] = i+1;
            break;
        }
    }
}

bool check() {
    for (int i = 0; i < S; i++)
        first[i] = i;
    first[S] = B;

    for (int i = S-1; i >= 0; i--) {
        update(i);
    }

    if (first[0] > 0) return false;
    return true;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> B >> S;
        long long sum_page = 0;
        for (int i = 0; i < B; i++) {
            cin >> p[i];
            sum_page += p[i];
        }
        l = *max_element(p, p+B), r = sum_page;
        while (l < r) {
            m = (l+r)/2;
            if (check()) {
                r = m;
                for (int i = 0; i < S; i++) {
                    most_valid_first[i] = first[i];
                }
            } else {
                l = m+1;
            }
        }

        /// Print the books assigned to scribe 0 -> S-1
        for (int i = 0; i < S-1; i++) {
            for (int j = most_valid_first[i]; j < most_valid_first[i+1]; j++)
                cout << p[j] << " ";
            cout << " / ";
        }

        /// Print the books assigned to scribe S
        for (int i = most_valid_first[S-1]; i < B; i++) {
            cout << p[i];
            if (i == B-1) break;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}

//  Created by NPT
// #include <iostream>
 
// using namespace std;
 
// int k,m,p[507];
// long long ans;
 
// bool check(long long mid){
//     long long sum = 0;
//     int dem = 1;
//     for (int i=1; i<=m; i++) {
//         if (p[i]>mid) {
//             return false;
//         }
//         if (sum + p[i] > mid) {
//             sum = p[i];
//             dem++;
//         } else {
//             sum+=p[i];
//         }
//     }
//     if (dem > k) {
//         return false;
//     }
//     return true;
// }
 
// void sol(long long ans){
//     int kq[1007];
//     int ckq = 0;
//     long long sum = 0;
//     int dem = 1;
//     for (int i=m; i>=1; i--) {
//         if (k-dem == i) {
//             for (int j=i; j>=1; j--) {
//                 kq[++ckq] = -1;
//                 kq[++ckq] = p[j];
//             }
//             break;
//         }
//         if (sum + p[i] > ans) {
//             kq[++ckq] = -1;
//             sum = p[i];
//             dem++;
//             kq[++ckq] = p[i];
//         } else {
//             kq[++ckq] = p[i];
//             sum+=p[i];
//         }
//     }
//     for (int i=ckq; i>=1; i--) {
//         if (kq[i] == -1) {
//             cout << " / ";
//         } else {
//             cout << kq[i] << " ";
//         }
//     }
//     cout << endl;
// }
 
// int main() {
//     ios_base::sync_with_stdio(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         cin >> m >> k;
//         long long sump = 0;
//         for (int i=1; i<=m; i++) {
//             cin >> p[i];
//             sump+=p[i];
//         }
//         long long l = 0, r = sump+1, mid;// chu y de kieu long long moi FULL diem
//         while (r-l>1) {
//             mid = (l+r)/2;
//             if (check(mid)) {
//                 ans = mid;
//                 r = mid;
//             } else {
//                 l = mid;
//             }
//         }
//         sol(ans);
//     }
//     return 0;
// }