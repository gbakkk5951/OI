using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
namespace OI {
typedef long long lld;
struct Node {
	Node *s[10];
	int now;
	vector<int> log;
	inline void add(int v, int id) {
		if ((now += v) > log.size()) {
			log.push_back(id);
		}
	}
	inline int query(int v) {
		if (log.size() < v) {
			return -1;
		} else {
			return log[v - 1];
		}
	}
};
const int SIZ = 5e4 + 13;
Node pool[SIZ];
Node *now = pool, *end = pool +SIZ;
inline Node *new_() {
	if (now == end) {
		now = (Node *)new Node[SIZ];
		end = now + SIZ;
	}
	return now++;
}
struct Trie {
	Node *root;
	Trie() {
		root = new_();
	}
	void change(int id, char str[], int v) {
		Node *nd = root;
		for (int i = 0; str[i]; i++) {
			if (!nd->s[str[i] - 'a']) nd->s[str[i] - 'a'] = new_();
			nd = nd->s[str[i] - 'a'];
			nd->add(v, id);
		}
	}
	int query(char str[], int v) {
		Node *nd = root;
		for (int i = 0; str[i]; i++) {
			if (!nd->s[str[i] - 'a']) break;
			nd = nd->s[str[i] - 'a'];
		}
		return nd->query(v);
	}

}trie;
struct _Main {
	char buf[65];
	_Main() {
		lld lstans = 0, a, b, c;
		int Qn, op;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			scanf("%s", buf);
			if (op == 1) {
				trie.change(Q, buf, 1);
			} else
			if (op == 2) {
				trie.change(Q, buf, -1);
			} else {
				read(a); read(b); read(c);
				printf("%d\n", lstans = trie.query(buf, (a * lstans + b) % c + 1));
				lstans = lstans < 0 ? -lstans : lstans;
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
}std;
}

