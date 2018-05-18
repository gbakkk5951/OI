using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int ADD = 1, QUERY = 2;
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
struct Point {
	int x[3];
	int & operator [] (int id) {
		return x[id];
	}
	char operator <= (Point &b) {
		for (int i = 0; i < 3; i++) {
			if (x[i] > b[i]) return 0;
		}
		return 1;
	}
	char operator >= (Point &b) {
		for (int i = 0; i < 3; i++) {
			if (x[i] < b[i]) return 0;
		}
		return 1;
	}
	void readx() {
		for (int i = 0; i < 3; i++) {
			read(x[i]);
		}
	}
};
struct _Main {
	Point arr[50005];
	_Main() {
		Point a, b;
		int Tn, Qn;
		int op;
		int idx, ans;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			idx = 0;
			read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				read(op);
				if (op == ADD) {
					arr[++idx].readx();
				} else {
					ans = 0;
					a.readx(); b.readx();
					for (int i = 1; i <= idx; i++) {
						ans += a <= arr[i] && arr[i] <= b;
					}
					printf("%d\n", ans);
				}
			} 
		}
	}
	
}instance;

}


