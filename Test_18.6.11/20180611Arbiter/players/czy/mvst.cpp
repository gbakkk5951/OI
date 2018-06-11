#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 65535 + 10;

struct E {
	int u, v, w;
} e[N];

int fa[N], n, m, vis[N];

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

struct fs {
	double val;
	ll up, down;
} ans;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

void upd() {
	for(int i = 1 ; i <= n ; ++ i) fa[i] = i;
	ll sumw = 0;
	for(int i = 1 ; i <= m ; ++ i) {
		vis[i] = 0;
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(get(u) != get(v)) {
			sumw += w;
			fa[get(u)] = get(v);
			vis[i] = 1;
		}
	}
	double wba = (double) sumw / (n - 1);
	double tot = (double) wba * wba;
	ll up = (ll) (n - 1) * wba * wba, down = n - 1;
	for(int i = 1 ; i <= m ; ++ i) {
		if(vis[i]) {
			int w = e[i].w;
			tot += (double) w * w / (n - 1) - 2.0 * wba * w / (n - 1);
			up += (ll) w * w - 2ll * wba * w;
		}
	}
	if(tot < ans.val) {
		ans.val = tot;
		ll d = gcd(up, down);
		ans.up = up / d, ans.down = down / d;
	}
}

namespace luangao {
	bool le(E a, E b) { return a.w < b.w; }
	bool ge(E a, E b) { return a.w > b.w; }
	bool sile(E a, E b) { return sin(a.w) < sin(b.w); }
	bool sige(E a, E b) { return sin(a.w) > sin(b.w); }
	bool cole(E a, E b) { return cos(a.w) < cos(b.w); }
	bool coge(E a, E b) { return cos(a.w) > cos(b.w); }
	void sol() {
		sort(e + 1, e + 1 + m, le), upd();
		sort(e + 1, e + 1 + m, ge), upd();
		sort(e + 1, e + 1 + m, sile), upd();
		sort(e + 1, e + 1 + m, sige), upd();
		sort(e + 1, e + 1 + m, cole), upd();
		sort(e + 1, e + 1 + m, coge), upd();
		int T = 100000000 / (n + 2 * m);
		for(int i = 1 ; i <= T ; ++ i) random_shuffle(e + 1, e + 1 + m), upd();
	}
}

int main() {
	srand((unsigned long long) new char);
	freopen("mvst.in", "r", stdin);
	freopen("mvst.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= m ; ++ i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w), ans.val += e[i].w;
	// n = m = 65535;
	// for(int i = 1 ; i <= m ; ++ i) e[i].u = i, e[i].v = (i + 1 <= n ? i + 1 : 1), e[i].w = rand() % n + 1, ans.val += e[i].w;

	if(n == 1) return puts("0"), 0;

	luangao :: sol();

	printf("%lld/%lld\n", ans.up, ans.down);
}