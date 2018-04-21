using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 4100, MXM = 27000;
const int DST = 0, NXT = 1, FLOW = 2;
struct Dinic {
	int eidx;
	int head[MXN], now[MXN], edge[MXM][3];
	Dinic () {
		eidx = 1;
	}
	void dir_add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][FLOW] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void add(int a, int b, int c) {
		dir_add(a, b, c);
		dir_add(b, a, c);
	}
	
}flow;
struct _Main {
	
	_Main() {
	
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


