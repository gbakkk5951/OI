#pragma GCC optimize(0)
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
namespace OI {
const int MXN = 5e6 + 10;
int s[MXN], sa[MXN], rk[MXN], h[MXN];
int sum[MXN], xofy[MXN], a[MXN << 1], b[MXN << 1];//神TM MXN写成了MXM
void getsa(int len, int s[], int sa[]) {
	int *xrank = a, *ypos = b, *oldxrank, m = 0, p, lst, now;
	memset(a + len, -63, len * sizeof(int));
	memset(b + len, -63, len * sizeof(int));
	for (int i = 0; i < len; i++) ++sum[xrank[i] = s[i]], m = max(m, s[i] + 1);
	for (int i = 1; i < m; i++) sum[i] += sum[i - 1]; // < 不是 <= 
	for (int i = len - 1; i >= 0; i--) sa[--sum[s[i]]] = i;
	memset(sum, 0, m * sizeof(int));
	for (int step = 1; ; step <<= 1) {
		//printf("step = %d\n", step);
		p = 0;
		for (int i = len - step; i < len; i++) ypos[p++] = i;
		for (int i = 0; i < len; i++) ypos[p++] = sa[i] - step, p -= sa[i] < step;
		for (int i = 0; i < len; i++) sum[xofy[i] = xrank[ypos[i]]]++;
		for (int i = 1; i < m; i++) sum[i] += sum[i - 1];// < m 不是 <= m
		for (int i = len - 1; i >= 0; i--) sa[--sum[xofy[i]]] = ypos[i];
		memset(sum, 0, m * sizeof(int));
		oldxrank = xrank;
		xrank = ypos;
		m = 0; 
		xrank[lst = sa[0]] = m; //神TM oldxrank
		for (int i = 1; i < len; i++) {
		    xrank[sa[i]] = m += oldxrank[sa[i]] != oldxrank[sa[i - 1]] 
							 || oldxrank[sa[i] + step] != oldxrank[sa[i - 1] + step];
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
		int len = 0, t;/*
		while (!isalpha(t = getchar()));
		do {
			s[len++] = t;
		} while ( isalpha(t = getchar()));
		*/
		len = 5e6;
		for (int i = 0; i < len; i++) {
			s[i] = 1;
		}
		double t1 = clock();
		getsa(len, s, sa);
		double t2 = clock();
		printf("we uses %f ms\n", (t2 - t1) /  1000.0);
		/*
		for (int i = 0; i < len; i++) {
			printf("%d ", sa[i] + 1);
		}
		printf("\n");
		*/
		getrk(len, sa, rk);
		geth(len, sa, rk, h);
		/*for (int i = 1; i < len; i++) {
			printf("%d ", h[i]);
		}*/
	}
}cdvs1500;	
}
