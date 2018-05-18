using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
namespace OI {
const int MXN = 500005;
struct Range {
	int l, r, bl, id;
	bool operator < (const Range &b) const {
		if (bl != b.bl) {
			return bl < b.bl;
		}
		return r < b.r;
	}
}rg[MXN];
struct _Main {
	int cnt[MXN];
	int arr[MXN];
	int ans[MXN];
	int nowans;
	int sq;	
	void add(int num) {//���ۼӼ������ܶԴ𰸼Ӽ� 
		if (++cnt[num] == num) {
			nowans++;
		} else if (cnt[num] == num + 1) {
			nowans--;
		}
	}
	void del(int num) {
		if (--cnt[num] == num - 1) {
			nowans--;
		} else if (cnt[num] == num) {
			nowans++;
		}
	}
	
	_Main() {
		int n, Qn;
		read(n); read(Qn);
		sq = ceil(sqrt(Qn)); //Qn ����n 
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(rg[Q].l); read(rg[Q].r);
			rg[Q].id = Q;
			rg[Q].bl = (rg[Q].l + sq - 1) / sq;
		}
		sort(rg + 1, rg + Qn + 1);//Qn ����n 
		int l = 1, r = 1;
		add(arr[1]);
		for (int Q = 1; Q <= Qn; Q++) {
			while (r < rg[Q].r) {
				add(arr[++r]);
			}
			while (l > rg[Q].l) {
				add(arr[--l]);
			}
			while (l < rg[Q].l) {
				del(arr[l++]);
			}
			while (r > rg[Q].r) {
				del(arr[r--]);
			}
			ans[rg[Q].id] = nowans;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%d\n", ans[Q]);
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
}dloj1002;
}

//Ī��Ҫ�Բ����ֿ飬��Ҫ�����зֿ� 
