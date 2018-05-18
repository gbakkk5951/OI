using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
namespace OI {
const int MXN = 500010;
int n;

struct Node {
	Node *s[2];
	int sum;
};
Node *root[MXN];
class ChairTree {
public:
Node *null;
Node pool[MXN * 20];
int pidx;
int ridx;
Node* new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
ChairTree (){
	null = new_();
	null->s[0] = null->s[1] = null;
	root[ridx++] = null;
}
int query(int l, int r) {
	Node *a = root[r], *b = root[l - 1];
	int need = r - l + 1 >> 1;
	int i;
	int nl = 1, nr = n, mid;
	while (nl < nr) {
		mid = nl + nr >> 1;
		if (a->s[0]->sum - b->s[0]->sum > need) {
			a = a->s[0]; b = b->s[0];
			nr = mid;
		} else if(a->s[1]->sum - b->s[1]->sum > need) {
			a = a->s[1]; b = b->s[1];
			nl = mid + 1;
		} else {
			return 0;
		}
	}
	return nl;
}
void insert(int val) {
	Node *b = root[ridx - 1];
	Node *a = root[ridx++] = new_();
	int nl = 1, nr = n, mid, pos;
	while (nl < nr) {
		mid = nl + nr >> 1;
		pos = val > mid;
		a->sum = b->sum + 1;
		a->s[pos ^ 1] = b->s[pos ^ 1];
		a = a->s[pos] = new_();
		b = b->s[pos];
		if (pos == 1) {
			nl = mid + 1;
		} else {
			nr = mid;
		}
	}
	a->sum = b->sum + 1;
}
}tree;
struct _Main {
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
_Main() {
	int i, j, k;
	int Qn;
	int a;
	int l, r;
	read(n); read(Qn);
	for (i = 1; i <= n; i++) {
		read(a);
		tree.insert(a);
	}
	for (int Q = 1; Q <= Qn; Q++) {
		read(l); read(r);
		printf("%d\n", tree.query(l, r));
	}
	
}

}bzoj3524;

}
