using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstdio>
namespace OI {
const int MXN = 1e5 + 13;
const int DST = 0, NXT = 1;
struct Node {
	Node *s[26], *fail;
	int len;
}pool[MXN << 1];
int pidx;
Node *new_(int len, int id) {
	Node *nd = &pool[pidx++];
	nd->len = len;
	return nd;
}
struct PalinTree {
	int str[MXN], val; 
	int len[MXN];
	int n;
	Node *r1, *r0, *lst;
	PalinTree () {
		r1 = new_(-1, 1);
		r1->fail = r1;
		r0 = new_(0, 0);
		r0->fail = r1;
		str[0] = -1;
		lst = r1;
	}
	void insert(int val) {
		Node *nd = lst, *s, *up;
		str[++n] = val;
		while (str[n - 1 - nd->len] != val) nd = nd->fail;
		if (!nd->s[val]) {
			s = new_(nd->len + 2, n + 1);
			up = nd->fail;
			while (str[n - 1 - up->len] != val) up = up->fail;
			s->fail = up->s[val] ? up->s[val] : r0;
			nd->s[val] = s;
		}
		lst = nd->s[val];
		len[n] = lst->len;
	}
}org, rev;
struct _Main {
	char str[MXN];
	_Main() {
		int ans = 0;
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			org.insert(str[i] - 'a');
		}
		for (int i = len - 1; i >= 0; i--) {
			rev.insert(str[i] - 'a');
		}
		for (int i = 1; i < len; i++) {
			ans = max(ans, org.len[i] + rev.len[len - i]);
		}
		printf("%d", ans);
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
