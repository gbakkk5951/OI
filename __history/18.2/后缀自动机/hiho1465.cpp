using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

namespace OI {
typedef long long lld;
const int 
	MAXN = 100010;
struct Node {
	Node *s[26], *f;
	int mx, mn, id, is_pre;
};

class SAM {
public:
	Node *root, *tail;
	Node pool[MAXN << 1];
	int pidx;
	Node *node(int mx, int is_pre, Node *org = 0) {
		Node *nd = &pool[pidx];
		nd->mx = mx;
		nd->id = pidx++;
		nd->is_pre = is_pre;
		if (org) {
			memcpy(nd->s, org->s, sizeof(Node *) * 26);
		}
		return nd;
	}
	SAM() {
		root = tail = node(0, 0);
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(int c) {
		Node *nd = node(tail->mx + 1, 1);
		tail->s[c] = nd;
		Node *f = tail->f;
		tail = nd;
		while (f && f->s[c] == 0) {
			f->s[c] = nd;
			f = f->f;
		}
		if (f == 0) {
			ref(nd, root);
			return;
		}
		Node *s = f->s[c];
		if (f->mx + 1 == s->mx) {
			ref(nd, s);
			return;
		}
		Node *nf = node(f->mx + 1, 0, s);
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
	int vis[MAXN << 1], right[MAXN << 1], ans;
	int in[MAXN << 1];
	int len;
	int run_id;
	char *str;
	void topo(int id) {
		Node *nd = &pool[id];
		in[id] = -1;
		right[id] += nd->is_pre;
		if (id) {
			int f = nd->f->id;
			right[f] += right[id];
			if (--in[f] == 0) {
				topo(f);
			}
		}
	}
	Node *run_nd;
	int run_l;
	void run(int c) {
		Node *nd = run_nd;
		int l = run_l;
		while (nd != root && nd->s[c] == 0) {
			nd = nd->f;
			l = nd->mx;
		}
		if (nd->s[c]) {
			nd = nd->s[c];
			l++;
		}
		if (l > len) {
			while (nd->f->mx >= len) {
				nd = nd->f;
				l = nd->mx;
			}
		}
		if (l >= len && vis[nd->id] != run_id) {
			ans += right[nd->id];
			vis[nd->id] = run_id;
		}
		run_nd = nd;
		run_l = l;
	}
	void getRight() {
		for (int i = 1; i < pidx; i++) {
			in[pool[i].f->id]++;
		}
		for (int i = 1; i < pidx; i++) {
			if (in[i] == 0) {
				topo(i);
			}
		}
	}
	int getAns(char *_str, int _len) {
		str = _str; len = _len + 1 >> 1;
		ans = 0;
		run_id++;
		run_nd = root;
		run_l = 0;
		for (int i = 0; i < _len; i++) {
			run(str[i] - 'a');
		}
		return ans;
	}
}sam;

struct _Main {
	char buf[MAXN << 1];
	_Main() {
		int i, j, k;
		int len;
		int n;
		scanf("%s", buf);
		len = strlen(buf);
		for (i = 0; i < len; i++) {
			sam.insert(buf[i] - 'a');
		}
		sam.getRight();
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", buf);
			len = strlen(buf);
			memcpy(buf + len, buf, (len - 1) * sizeof(char));
			len += len - 1;
			printf("%d\n", sam.getAns(buf, len));
		}
	}

}hiho1465;


}
//增加了函数参数， 但没有用到该参数
//root 的 f 不能调用 
//需要处理的长度可能大于用于判断的长度 
//与节点挂钩的数组一定要双倍空间 
