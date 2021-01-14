
#include <stdio.h>

#define MAX 1000000
#define ll long long

int n;
int i, j;
ll a[MAX];
ll res;  //result
ll sum;

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}
	res = a[0];
	sum = a[0];
	
	for (i = 1; i < n; i++) {
		if (sum > 0) {
			sum = sum + a[i];
		} else {
			sum = a[i];
		}
		if (sum > res) {
			res = sum;
		}
	}
	
	printf("%I64d", res);
}
