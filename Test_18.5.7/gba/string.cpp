using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e6 + 10;
const int MXP = 20;
const int ORG = 0, REV = 1;

int sum[MXN], xofy[MXN], a1[MXN << 1], a2[MXN << 1];
void getsa(int len, int s[], int sa[]) {
	int *xrk = a1, *ypo = a2, *ork;
	int m = 0, p;
	memset(a1 + len, -1, len * sizeof(int));
	memset(a2 + len, -1, len * sizeof(int));
	for (int i = 0; i < len; i++) sum[xrk[i] = s[i]]++, m = max(m, s[i] + 1);
	for (int i = 1; i < m; i++) sum[i] += sum[i - 1];
	for (int i = len - 1; i >= 0; i--) sa[--sum[s[i]]] = i;
	memset(sum, 0, m * sizeof(int));
	for (int stp = 1; stp < len; stp <<= 1) {
		p = 0;
		for (int i = len - stp; i < len; i++) ypo[p++] = i;
		for (int i = 0; i < len; i++) ypo[p++] = sa[i] - stp, p -= sa[i] < stp;
		for (int i = 0; i < len; i++) sum[xofy[i] = xrk[ypo[i]]]++;
		for (int i = 1; i < m; i++) sum[i] += sum[i - 1];
		for (int i = len - 1; i >= 0; i--) sa[--sum[xofy[i]]] = ypo[i];
		memset(sum, 0, m * sizeof(int)); //忘了清空
		ork = xrk;
		xrk = ypo;
		xrk[sa[0]] = m = 0;
		for (int i = 1; i < len; i++) {//!= 写成了 == 
			xrk[sa[i]] = m += ork[sa[i]] != ork[sa[i - 1]] 
						   || ork[sa[i] + stp] != ork[sa[i - 1] + stp];
		}
		if (++m == len) break;
		ypo = ork;
	}
}
void getrk(int len, int sa[], int rk[]) {
	for (int i = 0; i < len; i++) {
		rk[sa[i]] = i;
	}
}
void geth(int len, int s[], int sa[], int rk[], int h[]) {
	for (int i = 0, j, k = 0; i < len; i++) {
		if (rk[i]) {
			j = sa[rk[i] - 1];
			for (k -= k != 0; s[i + k] == s[j + k]; ++k);
			h[rk[i]] = k;
		}
	}
}
int log[MXN];
void getlog(int mxn) {
	for (int i = 1; i <= mxn; i++) {
		log[i] = log[i - 1] + (i == 1 << log[i - 1] + 1);
		//printf("log %d = %d\n", i, log[i]);
	}
}
void getst(int len, int st[][MXN], int src[]) {
	memmove(st[0], src, len * sizeof(int));
	for (int I = 1; I <= log[len]; I++) {
		for (int i = 0; i + (1 << I) - 1 < len; i++) {
			st[I][i] = min(st[I - 1][i], st[I - 1][i + (1 << I - 1)]);
		}
	}
}
int getmin(int st[][MXN], int l, int r) {
	int lg = log[r - l + 1];
	return min(st[lg][l], st[lg][r - (1 << lg) + 1]);
}


struct _Main {
	int s[2][MXN], sa[2][MXN], rk[2][MXN], h[2][MXN];
	int st[2][MXP][MXN];
	int calc(int len, int i, int sublen) {
		int a = rk[ORG][i], b = rk[ORG][i + sublen];
		int r = getmin(st[ORG], min(a, b) + 1, max(a, b));
		if (r >= sublen) return 1;
		if (i) {
			//没有将正坐标映射为反坐标
			a = rk[REV][len - (i + sublen - 1) - 1]; 
			b = rk[REV][len - (i - 1) - 1];
			r += getmin(st[REV], min(a, b) + 1, max(a, b));
		}
		//printf("calc(%d, %d, %d) = %d\n", len, i, sublen, r);
		return r >= sublen;
	}
	
	_Main() {
		freopen("string.in", "r", stdin);
		freopen("string.out", "w", stdout);
		int len = 0;
		int ans = 0;
		char t;
		while (!isalpha(t = getchar()));
		do {
			s[ORG][len++] = t;
		} while ( isalpha(t = getchar()));
		memmove(s[REV], s[ORG], len * sizeof(int));
		for (int i = 0; i < len >> 1; i++) {
			swap(s[REV][i], s[REV][len - i - 1]);
		}
		getlog(len);
		for (int I = 0; I < 2; I++) {
	//		printf("BEG %d\n", I);
			getsa(len, s[I], sa[I]);
			getrk(len, sa[I], rk[I]);
			geth(len, s[I], sa[I], rk[I], h[I]);
			getst(len, st[I], h[I]);
			/*
			for (int i = 0; i < len; i++) {
				for (int j = sa[I][i]; j < len; j++) {
					printf("%d ", s[I][j]);
				}
				printf("\n%d\n", h[I][i]);
			}
			*/
		}
		for (int sublen = len >> 1; sublen >= 1; sublen--) {
			for (int i = 0; i + sublen < len; i += sublen) {
				if (calc(len, i, sublen)) {
					ans = sublen << 1;
					break;
				}
			}
			if (ans) {
				break;
			}
		}
		printf("%d\n", ans);
		fclose(stdout);
	}
	
}string;
}
