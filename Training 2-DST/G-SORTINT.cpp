/*
Cho mảng các số nguyên a. Hãy sắp xếp mảng A theo thứ tự tăng dần
**Input
  Dòng đầu chứa một số nguyên là số phần tử của mảng n≤10^6.
  Dòng thứ hai chứa n số nguyên.
**Output
  In ra trên một dòng mảng a theo thứ tự tăng dần.
TEST
5
7 4 1 2 3
=> 1 2 3 4 7 
--------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

void merge(int a[], int l, int m, int r){
	int n1 =m-l+1;
	int n2 =r-m;
	int *L = new int[n1];
	int *R = new int[n2];
	for(int i =0;i<n1;++i){
		L[i]= a[l+i];
	}
	for(int i =0;i<n2;++i){
		R[i]= a[m+i+1];
		}
		//so  sanh L R de cho vao mang
		int i=0, j=0,k=l;
		while(i<n1 && j<n2){
			if(L[i]<R[j]){
				a[k]= L[i];
				++i;
			}else{
				a[k]= R[j];
				++j;
			}
			++k;
		}
		while(i<n1){
			a[k++]= L[i++];			
		}
		while(j<n2){
			a[k++]=R[j++];
		}
}
void mergeSort(int a[], int l, int r){
	if(l<r){
		int m =(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}
int main(){
	int n;
	cin>>n;
	int *a= new int[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
		mergeSort(a,0,n-1);
	for(int i=0;i<n;++i){
		cout<< a[i] <<' ';
	}
	return 0;
}



/*
int main(){
int n;
cin>>n;
int *a = new int[n];
for(int i=0;i<n;++i){
	cin>> a[i];
}
sort(a,a+n);
for(int i=0;i<n;++i){
	cout << a[i] << ' ';
}
return 0;
}
*/
