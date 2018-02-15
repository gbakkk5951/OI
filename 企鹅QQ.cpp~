using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
namespace OI {
typedef long long lld;
typedef double lf;
const int 
	MAXN = 30010,
	LEN = 210,
	INF = 0x3f3f3f3f,
	MOD = 60013
;
lld mod[2] = {(479 << 21) + 1, 19260817};
int base[2] = {71, 73};
int map[2][255];
int head[205][MOD];
int nxt[30000 * 200 + 100];
int val[30000 * 200 + 100];
int lidx;

lld fastpower(lld base, lld pow, lld mod) {
	lld ret = 1;
	while (pow) {
		if (pow & 1) {
			ret = ret * base % mod;
		}
		pow >>= 1;
		base = base * base % mod;
	}
	return ret;
}

struct Hash {
	int hash[2];
	bool operator == (const Hash &b) const {
		return memcmp(this, &b, sizeof(Hash)) == 0;
	}

	void operator <<= (int pow) {
		int i;
		for (i = 0; i < 2; i++) {
			hash[i] = hash[i] * fastpower(base[i], pow, mod[i]) % mod[i];
		}
	}
	void operator += (char a) {
		int i;
		for (i = 0; i < 2; i++) {
			hash[i] = (hash[i] + map[i][a]) % mod[i];
		}
	}
};

struct Str {
	Hash pre, su;
	int cnt;
	bool operator == (const Str &b) const {
		return pre == b.pre && su == b.su; 
	}
}pool[30000 * 200 + 100];

int ans;

void add(int pos, int idx) {
	int are = (pool[idx].pre.hash[0] + pool[idx].su.hash[0]) % MOD;
	int i, t;
	for (i = head[pos][are]; i; i = nxt[i]) {
		t = val[i];
		if (pool[t] == pool[idx]) {
			ans += pool[t].cnt;
			pool[t].cnt++;
			return;
		}
	}
	lidx++;
	val[lidx] = idx;
	nxt[lidx] = head[pos][are];
	head[pos][are] = lidx;
	pool[idx].cnt = 1;
}

struct _Main {
char buf[205];
Hash pre[205], su[205];
char id[64];
_Main() {

	srand(6690);
	int n;
	int i, j, k;
	int Q, Qn;
	int idx;
	scanf("%d%d%*d", &Qn, &n);
	for (i = 0; i < 64; i++) {
		id[i] = i + 1;	
	}
	for (i = 0; i < 2; i++) {
		for (j = 1; j < 64; j++) {
			swap(id[j], id[rand() % (j + 1)]);
		}
		k = 0;
		for (j = '0'; j <= '9'; j++) {
			map[i][j] = id[k++];
		}
		for (j = 'a'; j <= 'z'; j++) {
			map[i][j] = id[k++];
		}	
		for (j = 'A'; j <= 'Z'; j++) {
			map[i][j] = id[k++];
		}	
		map[i]['_'] = id[k++];
		map[i]['@'] = id[k++];
	}

	for (Q = 1; Q <= Qn; Q++) {
		scanf("%s", buf);
		for (i = 1; i <= n; i++) {
			pre[i] = pre[i - 1];
			pre[i] <<= 1;
			pre[i] += buf[i - 1];
		}
		for (i = n; i >= 1; i--) {
			su[i] = su[i + 1];
			su[i] <<= 1;
			su[i] += buf[i - 1];	
		}

//		cerr << "hash = " <<pre[n].hash[0] <<" "<<pre[n].hash[1]<<endl;
		for (i = 1; i <= n; i++) {
			idx = (Q - 1) * n + i;
			pool[idx].su = su[i + 1];
			pool[idx].pre = pre[i - 1];
			add(i, idx);
		}
	}
	printf("%d\n", ans);
}

}penguin;

}


