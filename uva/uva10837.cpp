using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <set>
namespace OI {
typedef long long lld;
const int MAXN = 2e8 + 1;
struct _Main {
int pcnt;
int prime[1700];
int vis[15000];
void getprime(int mx) {
	int i, j;
	lld t;
	for (i = 2; i <= mx; i++) {
		if (!vis[i]) {
			prime[pcnt++] = i;
		}
		for (int j = 0; j < pcnt && (t = (lld)prime[j] * i) <= mx; j++) {
			vis[t] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
int p[1700], pn;
lld ans;
void getp(lld phi) {
	pn = 0;
	for (int i = 0; i < pcnt && prime[i] <= phi + 1; i++) {
		if (phi % (prime[i] - 1) == 0) {
			p[pn++] = prime[i];
		}
	}
}
set<int> tree;
void dfs(int nd, lld rem, lld now) {
	if (rem == 1) {
		ans = min(ans, now);
		return;
	}
	if (now * (rem + 1) >= ans) {
		return;
	}
	if (nd == pn) {
		if (tree.find(rem + 1) != tree.end());
		int i;
		for (i = 0; i < pcnt; i++) {
			if ((rem + 1) % prime[i] == 0) {
				break;
			}
		}
		if (i == pcnt) ans = min(ans, now * (rem + 1));
		return;
	}
	dfs(nd + 1, rem, now);
	lld ph = p[nd] - 1, pm = p[nd];
	tree.insert(p[nd]);
	if (nd == 0) ph *= 2, pm *= 2;
	for (int i = (nd ? 1 : 2); rem % ph == 0; pm *= p[nd], ph *= p[nd]) {
		dfs(nd + 1, rem / ph, now * pm);
	}
	tree.erase(prime[nd]);
}
lld getAns(lld phi) {
	ans = MAXN;
	tree.clear();
	ans = MAXN - 1;
	getp(phi);
	dfs(0, phi, 1);
	return ans;
}


_Main() {
	getprime(sqrt(MAXN) + 1);
	int idx = 0, phi;
	while (~scanf("%d", &phi)) {
		if (phi == 0) break;
		printf("Case %d: %d %lld\n", ++idx, phi, getAns(phi));
	}
}

}uva10837;


}

