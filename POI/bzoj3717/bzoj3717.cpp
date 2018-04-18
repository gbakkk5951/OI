using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <ctime>
#include <map>
namespace OI {
struct _Main {
	int rl[101];
	int size[1 << 24];
//	map<int, int> size;
	int n;
	int now[1 << 24], rem[1 << 24];
	_Main() {
//		float a = clock();
		int m;
		read(n); read(m);
//		n = 24; m = 100;
		for (int i = 0; i < n; i++) {
			read(size[1 << i]);
//			size[1 << i] = 1;
		}
		for (int i = 0; i < m; i++) {
			read(rl[i]);
//			rl[i] = 1;
		}
		sort(rl, rl + m, greater<int>());
		memset(now, 63, (1 << n) * sizeof(int));
		now[0] = 0; rem[0] = rl[0];
		int rm, nd, t, tn, tr;
		for (int I = 0; I < 1 << n; I++) {
			if (now[I] > 100) continue;
			/*
			printf("[");
			for (int i = 0; i < n; i++) {
				printf("%d", I >> i & 1);
			}
			printf("]");
			printf(" = (%d, %d)\n", now[I], rem[I]);
			*/
			for (rm = ~ I; (nd = rm & (-rm)) < 1 << n; rm -= nd) {
				t = I | nd;
				if (rem[I] < size[nd]) {
					tr = rl[tn = now[I] + 1] - size[nd];
					if (tr < 0) continue;
				} else {
					tn = now[I]; tr = rem[I] - size[nd];
				}
				if (tn < now[t]) {
					now[t] = tn;
					rem[t] = tr;
				} else if (tn == now[t]) {
					rem[t] = max(rem[t], tr);
				}
			}
		}
		if (now[(1 << n) - 1] < n) {
			printf("%d", now[(1 << n) - 1] + 1);
		} else {
			printf("NIE");
		}
//		printf("\n%f\n", clock() - a);
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
}instance;

}
