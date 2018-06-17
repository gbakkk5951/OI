using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 19930726;
const int MXN = 1e6 + 17;
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base; 
	}
	return ret;
}//AC
struct Node {
	Node *s[26], *fail;
	int len, cnt;
}pool[MXN];
int pidx;
Node *new_(int len) {
	Node *nd = &pool[pidx++];
	nd->len = len;
	return nd;
}//AC 怎么检查的，都没ret，（而且cnt 应该在insert里面加，但当时没想到不算问题）

struct PalinTree {
	Node *r1, *r0, *lst;
	Node *node[MXN];
	int str[MXN];
	int cnt[MXN];
	int n;
	PalinTree() {
		r1 = new_(-1);
		r1->fail = r1;
		r0 = new_(0);
		r0->fail = r1;
		str[0] = -1;
		lst = r1;
	}//AC
	void insert(int val) {
		Node *nd = lst;
		str[++n] = val;
		while (str[n - 1 - nd->len] != val) nd = nd->fail;
		if (!nd->s[val]) {
			node[n] = new_(nd->len + 2);
			Node *up = nd->fail;
			while (str[n - 1 - up->len] != val) up = up->fail;
			node[n]->fail = up->s[val] ? up->s[val] : r0;
			nd->s[val] = node[n];
		}
		lst = nd->s[val];
		++lst->cnt;
	}//AC
	void calc() {
		Node *nd;
		for (int i = n; i >= 1; i--) {
			if (nd = node[i]) {//节点不一定满
				cnt[nd->len] += nd->cnt;
				nd->fail->cnt += nd->cnt;
			}
		}
	}//AC
	
}tree;


struct _Main {
	char str[MXN];
	int cnt[MXN];
	lld sum;
	_Main() {
		int n;
		lld tot;
		lld ans = 1;
		read(n); read(tot);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++) {
			tree.insert(str[i] - 'a');
		}
		tree.calc();
		memcpy(cnt, tree.cnt, (n + 1) * sizeof(int));
		for (int i = 1; i <= n; i += 2) {
			sum += cnt[i];
		}
		if (tot > sum) {
			printf("-1");
			return;
		}
		for (int i = n - (~n & 1); i >= 1; i -= 2) {
			if (cnt[i] >= tot) {
				ans = ans * fastpower(i, tot) % MOD;
				break;
			} else {
				ans = ans * fastpower(i, cnt[i]) % MOD;
				tot -= cnt[i];
			}
		}
		printf("%lld", ans);
	}//AC
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}//AC
}std;
}
