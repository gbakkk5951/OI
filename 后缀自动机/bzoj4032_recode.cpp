using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>

namespace OI {
const int INF = 0x3f3f3f3f;
struct Node {
	Node *s[26], *f;
	int mx, mn, id; 
};
class SAM {
public:
	Node node[4005];
	Node *root, *tail;
	int idx;
	Node *new_(int mx, Node *org = 0) {
		Node *nd = &node[idx];
		nd->id = idx++;
		nd->mx = mx;
		if (org) {
			memcpy(nd->s, org->s, 26 * sizeof(Node *));
		}
		return nd;
	}
	SAM() {
		root = tail = new_(0);
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(int c) {
		Node *nd = new_(tail->mx + 1);
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
			return ;
		}
		Node *nf = new_(f->mx, s);
		ref(nf, s->f);
		ref(nd, nf);
		ref(s, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
}sam;

class DFA {
public:
	Node node[2005];
	Node *root;
	Node *dp[26];
	void build(char str[], int len) {
		for (int i = len; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				node[i].s[j] = dp[j];
			}
			node[i].id = i;
			if (i) {
				dp[str[i - 1]] = &node[i];
			}
		}
		root = &node[0];
	}
	
}a, b;

template <typename tp>
	int match(char str[], int len, tp &a) {
		int ret = INF;
		Node *nd;
		for (int i = 0; i < len; i++) {
			nd = a.root;
			for (int j = i; j < len; j++) {
				if (!(nd = nd->s[str[j]])) {
					ret = min(ret, 1 + j - i);
					break;
				}
			}
		}
		return ret;
	}
int dp[2005][4005];
char vis[2005][4005];
int now_id;
void dfs(Node *na, Node *nb) {
	vis[na->id][nb->id] = now_id;
	int len = INF;
	int a, b;
	for (int i = 0; i < 26; i++) {
		if (na->s[i]) {
			if (nb->s[i] == 0) {
				len = 1;
				break;
			} else {
				if (vis[a = na->s[i]->id][b = nb->s[i]->id] != now_id) {
					dfs(na->s[i], nb->s[i]);
				}
				len = min(len, dp[a][b] + 1);
			}
		}
	}
	dp[na->id][nb->id] = len;
}

struct _Main {
	char s[2][2005];
	int l[2];
	void out(int ans) {
		if (ans > 2000) {
			ans = -1;
		}
		printf("%d\n", ans);
	}
	void q1() {
		out(match(s[0], l[0], sam));
	}
	void q2() {
		out(match(s[0], l[0], b));
	}
	void q3() {
		now_id++;
		for (int i = 0; i < l[0] + 1; i++) {
			memset(dp[i], 63, (sam.idx) * sizeof(int));
		}
		dfs(a.root, sam.root);
		out(dp[0][0]);
	}
	void q4() {
		now_id++;
		for (int i = 0; i < l[0] + 1; i++) {
			memset(dp[i], 63, l[1] * sizeof(int));
		}
		dfs(a.root, b.root);
		out(dp[0][0]);
	}
	
	_Main() {
		int i, j, k;
	//	srand((long long)(new unsigned long long));
		for (i = 0; i < 2; i++) {
			scanf("%s", s[i]);
			l[i] = strlen(s[i]);
			/*l[i] = rand() % 2000;
			for (j = 0; j < l[i]; j++) {
				s[i][j] = rand() % 3 + 'a';
			}*/
		}
		for (i = 0; i < 2; i++) {
			for (j = 0; j < l[i]; j++) {
				s[i][j] -= 'a';
			}
		}
		for (i = 0; i < l[1]; i++) {
			sam.insert(s[1][i]);
		}
		a.build(s[0], l[0]); b.build(s[1], l[1]);
		q1();
		q2();
		q3();
		q4();
	}

}bzoj4032;

}

