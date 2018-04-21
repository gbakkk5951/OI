using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
namespace OI {
map<long long, int> rem;
const int MXN = 4010;
struct _Main {
	int pow(int base, int pow) {
		int ret = 1;
		for (int i = 1; i <= pow; i++) {
			ret *= base;
		}
		return ret;
	}
	int n[MXN], k[MXN];
	int p[MXN], pcnt, vis[35000];
	void sieve(int mx) {
		int t;
		for (int i = 2; i <= mx; i++) {
			if (!vis[i]) {
				p[pcnt++] = i;
			}
			for (int j = 0; j < pcnt && (t = i * p[j]) <= mx; j++) {
				vis[t] = 1;
				if (i % p[j] == 0) {
					break;
				}
			}
		}
	}
	int s[20], c[20], d[20], cnt;
	void div(int n) {
		cnt = 0;
		for (int i = 0; i < pcnt && p[i] * p[i] <= n; i++) {
			if (n % p[i] == 0) {
				d[cnt] = p[i]; 
				c[cnt] = 0;
				do {
					c[cnt]++;
					n /= p[i];
				} while (n % p[i] == 0);
				cnt++;
			}
		}
		if (n > 1) {
			c[cnt] = 1;
			d[cnt] = n;
			cnt++;
		}
		s[cnt] = 1;
		for (int i = cnt - 1; i >= 0; i--) {
			s[i] = s[i + 1] * pow(p[i], c[i]); 
		}
	}
	int ans;
	int need;
	void dfs(int nd, int mx, int cnt, int now) {
		ans = max(ans, cnt + 1);
		if (ans >= need) {
			return;
		}
		if (nd == this->cnt) {
			int tmp[20];
			memcpy(tmp, s, 20 * sizeof(int));
			for (int i = this->cnt - 1; i >= 0; i--) { // cnt 没加this-> 与参数冲突 
				s[i] = s[i + 1] * pow(p[i], c[i]); 
			}
			if (s[0] > now && cnt + 1 + log(s[0]) / log(now) + 1e-6  >= need) {
				dfs(0, now, cnt + 1, 1);
			}
			memcpy(s, tmp, 20 * sizeof(int));
			return;
		}
		int t = 1;
		for (int i = 0; i <= c[nd]; i++) {
			if (now * t * s[nd + 1] > mx) {
				c[nd] -= i;
				dfs(nd + 1, mx, cnt, now * t);
				if (ans >= need) return;
				c[nd] += i;
			}
			t *= p[nd];
		}
	}
	_Main() {
		int Qn;
		int mx = 2;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(n[Q]); read(k[Q]);
			mx = max(mx, (int)ceil(sqrt(n[Q])) + 20);
		}
		sieve(mx);
		for (int Q = 1; Q <= Qn; Q++) {
			if (rem.count(n[Q] * 100 + k[Q])) {
				if (rem[n[Q] * 100 + k[Q]] >= k[Q]) {
					printf("TAK\n");
				} else {
					printf("NIE\n");
				}
				continue;
			}
			div(n[Q]); 
			need = k[Q];
			ans = cnt + 1;
			if (n[Q] != 1) dfs(0, 1, 1, 1);
			rem[n[Q] * 100 + k[Q]] = ans;
			if (ans >= k[Q]) {
				printf("TAK\n");
			} else {
				printf("NIE\n");
			}
		}
		
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}bzoj3733;
}
