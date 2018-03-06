#pragma GCC optimize(2)
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
namespace OI {
struct Node {
	Node *s[2];
	int sum;
}pool[20000 * 17 * 17 + 10000 * 17];
int pidx;
Node *null;
Node *new_() {
	Node* nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = null;
	return nd;
}
int n, mx;
class SegTree {
public:
	Node *root;
	SegTree() {
		root = new_();
	}
	void change(int val, int add) {
		Node *nd = root;
		nd->sum += add;
		int nl = 1, nr = mx, mid, pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (nd->s[pos] != null) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = new_();
			}
			nd->sum += add;
		}
	}
};
class ChairTree {
	public:
	Node *root[10005];
	ChairTree() {
		if (null == 0) {
			null = new_();
			null->s[0] = null->s[1] = null;
			null->sum = 0;
		}
		root[0] = null;
	}
	void insert(int ia, int ib, int val) {
		Node *a = root[ia] = new_(), *b = root[ib];
		a->sum = b->sum + 1;
		int nl = 1, nr = mx, mid, pos;
		while (nl < nr) {
			mid = nl + nr >> 1;
			if (pos = val > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			a->s[pos ^ 1] = b->s[pos ^ 1];
			a = a->s[pos] = new_();
			b = b->s[pos];
			a->sum = b->sum + 1;
		}
	}
}org;

class ArrayTree {
public:
	SegTree node[10005];
	int lb(int a) {
		return a & (-a);
	}
	void change(int nd, int val, int add) {
		for (; nd <= n; nd += lb(nd)) {
			node[nd].change(val, add);
		}
	}
	void query(int nd, Node *arr[], int &idx) {
		for (; nd; nd -= lb(nd)) {
			arr[idx++] = node[nd].root;
		}
	}
}cg;

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
	char oper[10005];
	int aug[10005][3];
	int arr[10005];
	int sorted[20005];
	int now[10005];
	int getrank(int val) {
		return lower_bound(sorted + 1, sorted + mx + 1, val) - sorted;
	}
	Node *node[50];
	int xishu[50];
	void change(int pos, int val) {
		cg.change(pos, now[pos], -1);
		cg.change(pos, now[pos] = val, 1);
	}
	int query(int l, int r, int rk) {
		int idx = 0, lst, sum;
		node[idx] = org.root[r]; xishu[idx++] = 1;
		node[idx] = org.root[l - 1]; xishu[idx++] = -1;
		lst = 2;
		cg.query(r, node, idx);
		for (int i = lst; i < idx; i++) {
			xishu[i] = 1;
		}
		lst = idx;
		cg.query(l - 1, node, idx);
		for (int i = lst; i < idx; i++) {
			xishu[i] = -1;
		}
		int nl = 1, nr = mx, mid, pos;
		while (nl != nr) {
			mid = nl + nr >> 1;
			sum = 0;
			for (int i = 0; i < idx; i++) {
				if (node[i] == null) {
					swap(node[i], node[idx - 1]);
					swap(xishu[i], xishu[idx - 1]);
					idx--;
				}
				sum += node[i]->s[0]->sum * xishu[i];
			}
			
			if (pos = sum < rk) {
				rk -= sum;
				nl = mid + 1;
			} else {
				nr = mid;
			}
			for (int i = 0; i < idx; i++) {
				node[i] = node[i]->s[pos];
			}
		}
		return sorted[nl];
	}
	_Main() {
		int Qn, idx = 0;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
			sorted[++idx] = arr[i];
		}
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", oper + Q);
			read(aug[Q][0]);
			read(aug[Q][1]);
			if (oper[Q] == 'Q') {
				read(aug[Q][2]);
			} else {
				sorted[++idx] = aug[Q][1];
			}
		}
		sort(sorted + 1, sorted + idx + 1);
		idx = unique(sorted + 1, sorted + idx + 1) - sorted - 1;
		OI::mx = idx;
		for (int i = 1; i <= n; i++) {
			now[i] = arr[i] = getrank(arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			if (oper[Q] == 'C') {
				aug[Q][1] = getrank(aug[Q][1]);
			}
		}
		for (int i = 1; i <= n; i++) {
			org.insert(i, i - 1, arr[i]);
		}
		xishu[0] = 1; xishu[1] = -1;
		for (int Q = 1; Q <= Qn; Q++) {
			if (oper[Q] == 'C') {
				change(aug[Q][0], aug[Q][1]);
			} else {
				printf("%d\n", query(aug[Q][0], aug[Q][1], aug[Q][2]));
			}
		}
		
	}
}bzoj1901;

}
//pos һ��Ҫ��Ӧ���Ҷ���
//Ȩֵ�߶�������Ȩֵ��val �ӵ�ֵ��add, 
//�߶��� �� 1��ʼ�Ļ�Ҫ�ر�ע���������ݵ�������ʼλ�� 
//��״���鲻�ܴ�0��ʼ�ã����� 
//�Ļ���ʼ���Ҫ������������ֵ�λ�ö�findһ�� 
//unique �� returnֵҲ�ǿ����� 
//�����Χ�ı���һ����ҪŪ�죬 ����ȡֵ������λ������ 
//���ʱ����ϸ ��Ҫһ�۹� 
//�κ��Ż���Ҫ������ȷ�ԣ�
//����nd->sum == 0�����������µĶ���0�� ���������и� 
