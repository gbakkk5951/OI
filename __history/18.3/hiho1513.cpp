using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <bitset>
#include <algorithm>
namespace OI {
const int MXN = 30005;
bitset<MXN> now;
bitset<MXN> res[MXN][5];
struct Man {
	int rk[5], id;
}arr[MXN];

struct Cmp {
	int dim;
	bool operator () (const Man &a, const Man &b) {
		return a.rk[dim] > b.rk[dim];
	}
}cmp;
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
		int n;
		read(n);
		for (int i = 0; i < n; i++) {
			arr[i].id = i;
			for (int j = 0; j < 5; j++) {
				read(arr[i].rk[j]);
			}
		}
		for (int i = 0; i < 5; i++) {
			cmp.dim = i;
			sort(arr, arr + n, cmp);
			now.reset();
			for (int j = n - 1; j >= 0; j--) {
				res[arr[j].id][i] = now;
				now[arr[j].id] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < 5; j++) {
				res[i][0] &= res[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d\n", (int)res[i][0].count());
		}
	}
	
}hiho1513;

}
