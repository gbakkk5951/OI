using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

struct _Main {
	int arr[50005];
	int tmp[50005];
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
	char op[5];
	_Main() {
		int Tn;
		int Qn;
//		read(Tn);
		Tn = 1;
		int n;
		for (int T = 1; T <= Tn; T++) {
			read(n); read(Qn);
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
			}
			for(int Q = 1; Q <= Qn; Q++) {
				scanf("%s", op);
				if (op[0] == 'C') {
					int a, b;
					read(a); read(b);
					arr[a] = b;
				} else {
					int a, b, c;
					read(a) ;read(b); read(c);
					memcpy(tmp + 1, arr + a, (b - a + 1) * sizeof(int));
					sort(tmp + 1, tmp + 1 + (b - a + 1));
					printf("%d\n", tmp[c]);
				}
				
			}
		}
	}
	
}brute;
