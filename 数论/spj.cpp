using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
namespace OI {
typedef long long lld;
const string sp = " ";
struct _Main {
lld mod = 1e4 - 2;
	lld fastpower(lld base, lld pow, lld mod) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? base * ret % mod : ret;
			base = (pow >>= 1) ? base * base % mod : base;
		}
		return ret;
	}
	_Main() {
		int cnt = 0;
		while (1) {
			int flag = 0;
			lld a, b, c, m, x, y, z;
			a = rand() % mod + 1, b = rand() % mod + 1, c = rand() % mod + 1, m = rand() % mod + 3;
			cerr << "loop " << cnt << ": " << a << sp << b << sp << c << sp << m << endl;
			ofstream cout("data.in");
			cout << 1 << endl;
			cout << a << sp << b << sp << c << sp << m << endl;
			cout.close();
			system("./51nod1479 < data.in > data.out");
			ifstream cin("data.out");
			cin >> x >> y >> z;
			if ((fastpower(a, x, m) + fastpower(b, y, m)) % m != fastpower(c, z, m)) {
				flag = 1;
			}
			
			if (flag) {
				cerr << "wrong" << endl;
				getchar();
			} else {
				cerr << "AC" << endl;
			}
		}
		
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
}spj;
}
