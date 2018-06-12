using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
#include <queue>
namespace OI {
typedef long long lld;
const lld MOD = 1e9 + 7;
struct Node {
	Node *s[2], *fail;
	char end;
}pool[3050];
int pidx;
inline Node *new_() {
	return &pool[pidx++];
}
struct AC {
	Node *root;
	AC() {
		root = new_();
	}
	void insert(char str[]) {
		Node *nd = root;
		for (int i = 0; str[i]; i++) {
			if (!nd->s[str[i] - '0']) {
				nd->s[str[i] - '0'] = new_();
			}
			nd = nd->s[str[i] - '0'];
		}
		nd->end = 1;
	}
	void build() {
		queue<Node *>q;
		Node *nd = root;
		for (int i = 0; i < 2; i++) {
			if (nd->s[i]) {
				q.push(nd->s[i]);
				nd->s[i]->fail = nd;
			} else {
				nd->s[i] = nd;
			}
		}
		while (!q.empty()) {
			nd = q.front();
			q.pop();
			nd->end |= nd->fail->end;
			for (int i = 0; i < 2; i++) {
				if (nd->s[i]) {
					q.push(nd->s[i]);
					nd->s[i]->fail = nd->fail->s[i];
				} else {
					nd->s[i] = nd->fail->s[i];
				}
			}
		}
	}
	int query(char str[], int len) {
		int ret = 0;
		Node *nd = root;
		for (int i = 0; i < len; i++) {
			nd = nd->s[str[i]];
			if (nd->end) {
				++ret;
				nd = root;
			}
		}
		return ret;
	}
}ac;

struct _Main {
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? base * ret % MOD : ret;
			base = (base & 1) ? base * base % MOD : base;
		}
		return ret;
	}
	int n, S;
	char str[35];
	char ask[55];
	_Main() {
		read(n); read(S);
		if (S == 0) {
			printf("%lld", fastpower(2, n + 1 >> 1));
			return;
		}
		if (n > 50) {
			cout << 0 << endl;
			fclose(stdout);
			return;
		}
		int dst = 1 << (n + 1 >> 1);
		for (int i = 1; i <= S; i++) {
			scanf("%s", str);
			ac.insert(str);
		}
		ac.build();
		int ans = 0;
		for (int I = 0; I < dst; I++) {
			for (int i = 0; i <= (n - 1) >> 1; i++) {
				str[n - 1 - i] = str[i] = I >> i & 1;
			}
			ans += ac.query(str, n) < 2;
		}
		printf("%d", ans);
		fclose(stdout);
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
}std;
}
