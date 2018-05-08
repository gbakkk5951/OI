using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
int s[MXN], sa[MXN], rk[MXN], h[MXN];
int sum[MXN], xofy[MXN], a[MXN], b[MXN];//神TM MXN写成了MXM
inline int cmp(int xrank[], int a, int b, int step, int len) { //是否不相等
	if (xrank[a] == xrank[b]) {
		if (max(a, b) + step < len) {
			return xrank[a + step] != xrank[b + step];
		} else {
			return min(a, b) + step < len;
		}
	}
	return 1;
}
void getsa(int len, int s[], int sa[]) {
	int *xrank = a, *ypos = b, *oldxrank, m = 0;
	for (int i = 0; i < len; i++) ++sum[xrank[i] = s[i]], m = max(m, s[i] + 1);
	for (int i = 1; i < m; i++) sum[i] += sum[i - 1]; // < 不是 <= 
	for (int i = len - 1; i >= 0; i--) sa[--sum[s[i]]] = i;
	memset(sum, 0, m * sizeof(int));
	for (int step = 1; ; step <<= 1) {
		int p = 0;
		for (int i = len; i < len + step; i++) ypos[p++] = i;
		for (int i = 0; i < len; i++) ypos[p++] = sa[i], p -= sa[i] < step;
		for (int i = 0; i < len; i++) xofy[i] = xrank[ypos[i] - step];
		for (int i = 0; i < len; i++) sum[xofy[i]]++;
		for (int i = 1; i < m; i++) sum[i] += sum[i - 1];// < m 不是 <= m
		for (int i = len - 1; i >= 0; i--) sa[--sum[xofy[i]]] = ypos[i] - step;
		memset(sum, 0, m * sizeof(int));
		oldxrank = xrank;
		xrank = ypos;
		m = 0; 
		xrank[sa[0]] = m; //神TM oldxrank
		for (int i = 1; i < len; i++) {
			xrank[sa[i]] = m += cmp(oldxrank, sa[i], sa[i - 1], step, len);
		}
		if (++m == len) break;
		ypos = oldxrank;
	}
}
void getrk(int len, int sa[], int rk[]) {
	for (int i = 0; i < len; i++) {
		rk[sa[i]] = i;
	}
}
void geth(int len, int sa[], int rk[], int h[]) {
	for (int i = 0, j, k = 0; i < len; i++) {
		if (rk[i]) {
			j = sa[rk[i] - 1];
			for (k -= k != 0; s[j + k] == s[i + k]; k++);
			h[rk[i]] = k;
		} 
		//不必else k = 0 因为else时必然k <= 1
	}
}

struct _Main {
	_Main() {
		int len = 0, t;
		while (!isalpha(t = getchar()));
		do {
			s[len++] = t;
		} while ( isalpha(t = getchar()));
		getsa(len, s, sa);
		for (int i = 0; i < len; i++) {
			printf("%d ", sa[i] + 1);
		}
		printf("\n");
		getrk(len, sa, rk);
		geth(len, sa, rk, h);
		for (int i = 1; i < len; i++) {
			printf("%d ", h[i]);
		}
	}
}cdvs1500;	
}
