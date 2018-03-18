using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
const int MXN = 100010;
struct Node {
	Node *s[2], *f;
	int sig, size, val;
}pool[MXN], *null;
int pidx;
Node *new_() {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = nd->f = null;
	nd->size = 1;
	return nd;
}
class ArtSplay {
public:
	ArtSplay() {
		null = new_();
		null->size = 0;
		null->s[0] = null->s[1] = null->f = null;
	}
	void update(Node *nd) {
		nd->size = 1;
		for (int i = 0; i < 2; i++) {
			nd->size += nd->s[i]->size;
		}
	}
	void push(Node *nd) {
		if (nd->sig) {
			swap(nd->s[0], nd->s[1]);
			for (int i = 0; i < 2; i++) {
				nd->s[i]->sig ^= 1;
			}
			nd->sig = 0;
		}
	}
	Node *root;
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf != null) {
			gf->s[f == gf->s[1]] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s != null) {
			s->f = f;
		}
		f->f = nd;
		nd->s[pos ^ 1] = f;
		update(f);
		update(nd);
	}
	void splay(Node *nd, Node *rt) {
		Node *f;
		while ((f = nd->f) != rt) {
			if (f->f != rt) {
				if ((nd == f->s[1]) == (f == f->f->s[1])) {
					rotate(f);
				} else {
					rotate(nd);
				}
			}
			rotate(nd);
		}
		if (rt == null) {
			root = nd;
		}
	}
	Node *getnode(int rk) {
		Node *nd = root;
		int sum;
		while (1) {
			push(nd);
//			printf("nd = %lld rk = %d\n", nd - pool, rk);
			if ((sum = nd->s[0]->size) >= rk) {
//				printf("ls\n");
				nd = nd->s[0];
			} else if (++sum == rk) {
//				printf("ret %lld\n", nd - pool);
				return nd;
			} else {
//				printf("rs\n");
				rk -= sum;
				nd = nd->s[1];
			}
		}
	}
	void change(int l, int r) {
		splay(getnode(l), null);
		splay(getnode(r + 2), root);//忘了+2 
		root->s[1]->s[0]->sig ^= 1;
//		printf("tag %d = 1\n", root->s[1]->s[0] - pool);
	}
	
	
	Node* build(int l, int r) {
		Node *nd = new_();
		int mid = l + r >> 1;
		nd->val = mid;
		if (l < mid) {
			nd->s[0] = build(l, mid - 1);
			nd->s[0]->f = nd; //忘了向上连 
		}
		if (mid < r) {
			nd->s[1] = build(mid + 1, r);
			nd->s[1]->f = nd;
		}
		update(nd);
		return nd;
	}
	void print(Node *nd, int arr[], int &idx) {
		push(nd);//忘了push 
		if (nd->s[0] != null) {
			print(nd->s[0], arr, idx);
		}
		arr[idx++] = nd->val;
		if (nd->s[1] != null) {
			print(nd->s[1], arr, idx);
		}
	}
}tree;


int arr[MXN];
struct _Main {
	_Main() {
		int n, Qn;
		int l, r;
		read(n); read(Qn);
		tree.root = tree.build(0, n + 1);
		for (int Q = 1; Q <= Qn; Q++) {
			read(l); read(r);
			tree.change(l, r);
		}
		int t = 0;
		tree.print(tree.root, arr, t);
		for (int i = 1; i <= n; i++) {
			printf("%d ", arr[i]);
		}
	}
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
}bzoj3223;
}
