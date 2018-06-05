using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <set>
namespace OI {
typedef long long lld;
typedef int p;
const lld MOD = 479 << 21 | 1;
const lld base = 10007;
const int MXN = 2010;
typedef set<p>::iterator it;
p make_ele(set<p> &a) {
	lld val = 1;
	int len = 0;
	val += 1;
	for (it t = a.begin(); t != a.end(); t++) {
		val = (val * base + *t) % MOD;
	}
	val = (val * base + 2) % MOD;
	return val;
}
set<p> stk[MXN], tmp;
int top;
struct _Main {
	char op[15];
	_Main() {
		int Qn;
		scanf("%d", &Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'P') {//加入空集
				stk[++top] = stk[0];
			} else if (op[0] == 'D') {//复制
				++top;
				stk[top] = stk[top - 1];
			} else if (op[0] == 'U') {//并集 神tm op[1]
				set_union(stk[top].begin(), stk[top].end(), stk[top - 1].begin(), stk[top - 1].end(), inserter(tmp, tmp.begin()));
				stk[--top] = tmp;
				tmp.clear();
			} else if (op[0] == 'I') {//交集
				set_intersection(stk[top].begin(), stk[top].end(), stk[top - 1].begin(), stk[top - 1].end(), inserter(tmp, tmp.begin()));
				stk[--top] = tmp;
				tmp.clear();
			} else if (op[0] == 'A') {//次顶中插入顶
				top--;
				stk[top].insert(make_ele(stk[top + 1]));
			}
			printf("%d\n", stk[top].size());
		}
	}
}std;
}
