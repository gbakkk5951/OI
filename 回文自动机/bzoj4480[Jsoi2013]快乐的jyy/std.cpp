using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 5e4 + 17;
lld ans;
struct Node {
	Node *s[26], *fail;
	int len, cnt;
	lld sum;
}pool[MXN];
int pidx;
Node *new_(int len) {
	Node *nd = &pool[pidx++];
	memset(nd, 0, sizeof(Node));
	nd->len = len;
	return nd;
}//AC
struct PalinTree {
	Node *r1, *r0, *lst;
	Node *node[MXN];
	int str[MXN], n, ndn;
	PalinTree() {
		clear();
	}//AC
	void clear() {
		n = ndn = pidx = 0;
		r1 = new_(-1);
		r1->fail = r1;
		r0 = new_(0);
		r0->fail = r1;
		str[n = 0] = -1;
		lst = r0;
	}//AC
	void insert(int val) {
		Node *nd = lst, *up;
		str[++n] = val;
		while (str[n - nd->len - 1] != val) nd = nd->fail;
		if (!nd->s[val]) {
			node[++ndn] = new_(nd->len + 2);
			for (up = nd->fail; str[n - up->len - 1] != val; up = up->fail);
			node[ndn]->fail = up->s[val] ? up->s[val] : r0;
			nd->s[val] = node[ndn];
		}
		lst = nd->s[val];
		++lst->cnt;
	}//AC
	void build() {
		Node *nd;
		for (int i = ndn; i >= 1; i--) {
			nd = node[i];
			nd->fail->cnt += nd->cnt;
		}
		for (int i = 1; i <= ndn; i++) {
			nd = node[i];
			nd->sum = nd->cnt + nd->fail->sum;
		}
		n = 0;
		lst = r1;
	}//AC
	lld go(int val) {
		str[++n] = val;
		Node *nd = lst;
		while (str[n - nd->len - 1] != val || (nd->s[val] == 0 && nd != r1)) nd = nd->fail;
		if (nd->s[val]) {
			nd = nd->s[val];
			lst = nd;
			return nd->sum;
		} else {
			lst = nd;
			return 0;
		}
	}//AC
}tree;

struct _Main {
	char sa[MXN], sb[MXN];
	_Main() {
		int la, lb;
		ans = 0;
		scanf("%s", sa + 1);
		scanf("%s", sb + 1);
		la = strlen(sa + 1);//这个没算
		lb = strlen(sb + 1);//这个没算
		for (int i = 1; i <= la; i++) {
			tree.insert(sa[i] - 'A');
		}
		tree.build();
		for (int i = 1; i <= lb; i++) {
			ans += tree.go(sb[i] - 'A');
		}
		printf("%lld\n", ans);
	}//Ac
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
