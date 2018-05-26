using namespace std;
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
const string sp = " ";
namespace OI {
typedef long long lld;
const int MXN = 1e6 + 10; 
struct Edge {
	int a, b, c, d;
	int id;
	bool operator < (const Edge &b) const {
		return c < b.c;
	}
}edge[MXN];
int fa[MXN];
lld to_lld(char *a) {
	stringstream os;
	os << a;
	lld ret;
	os >> ret;
	return ret;
}
lld ans;
int getfa(int a){
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}
struct _Main {
	int cho[MXN];
	int cvis[MXN];
	int ccnt;
	int cn, n, m;
	lld vsum;
	_Main() {
		ans = 9e18;	
		
		read(n); read(m); read(cn);
		for (int i = 1; i <= m; i++) {
			read(edge[i].a); read(edge[i].b);
			read(edge[i].c); read(edge[i].d);
			read(edge[i].id);
		}
		sort(edge + 1, edge + m + 1);
		int mxid = m;
		for (int i = 1; i <= m; i++) {
			int a, b;
			a = edge[i].a; b = edge[i].b;
			if (getfa(a) != getfa(b)) {
				fa[getfa(a)] = getfa(b);
				ccnt += ++cvis[edge[i].d] == 1;
				mxid = max(mxid, edge[i].d);
				cho[edge[i].id] = 1;
				vsum += edge[i].c;
			}
		}
		ans = ccnt * vsum;
		
		for (int i = 1; i <= mxid; i++) {
			if (cho[i]) {
				printf("%d\n", i);
			}
		}
		fclose(stdout);
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
}solver;
}

int main(int, char *agrv[]) {
	if (OI::ans >= OI::to_lld(agrv[1])) {
		return -1;
	}
	ofstream out(agrv[2]);
	out << OI::ans;
	out.close();
	return 0;
}
