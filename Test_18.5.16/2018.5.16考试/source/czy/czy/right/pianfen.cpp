#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, q, p, a[N];

int main() {
	scanf("%d%d%d", &n, &q, &p);
	for(int i = 1 ; i <= n ; ++ i) scanf("%d", &a[i]);
	for(int i = 1, t, l, r, x ; i <= q ; ++ i) {
		scanf("%d%d%d", &t, &l, &r); if(!t) scanf("%d", &x);
		if(t) {
			int xsum = 0;
			for(int j = l ; j <= r ; ++ j) xsum ^= a[j];
			printf("%d\n", xsum & 1);
		} else {
			for(int j = l ; j <= r ; ++ j) a[j] += x;
		}
	}
}