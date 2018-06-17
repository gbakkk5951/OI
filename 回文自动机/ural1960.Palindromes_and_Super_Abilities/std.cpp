using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
struct Node {
	Node *s[26], *fail;
	int len;
}pool[MXN];
int pidx;
inline Node *new_(int len) {
	Node *nd = &pool[pidx++];
	nd->len = len;
	return nd;
}
struct PalinTree {
	int cnt;
	char str[MXN];
	int n;
	Node *r1, *r0, *lst;
	PalinTree() {
		r1 = new_(-1);
		r1->fail = r1;
		r0 = new_(0);
		r0->fail = r1;
		lst = r1;
		str[0] = -1;//这个可以有
	}
	void insert(int val) {
		str[++n] = val;
		Node *nd = lst, *up, *s;
		while (str[n - 1 - nd->len] != str[n]) nd = nd->fail;
		if (!nd->s[val]) {
			++cnt;
			s = new_(nd->len + 2);
			up = nd->fail; 
			while (str[n - 1 - up->len] != str[n]) up = up->fail;
			s->fail = up->s[val] ? up->s[val] : r0;
			nd->s[val] = s;//这个最后赋
		}
		lst = nd->s[val];
	}
}tree;
struct _Main {
	char str[MXN];
	_Main() {
		scanf("%s", str);
		for (int i = 0; str[i]; i++) {
			tree.insert(str[i] - 'a');
			printf("%d ", tree.cnt);
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
}std;
}
