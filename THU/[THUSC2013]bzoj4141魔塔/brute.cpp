using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
namespace OI {
const int MXN = 5e2 +10;
struct _Main {
	int cnt[MXN];
	int hp[MXN];
	int am[MXN];
	int atk[MXN];
	int n;
	int mxam, mxamhp, mxatk;
	int amcst, atkcst;
	int ahp, aam, aatk, acst;
	_Main() {
		acst = 2147483647;
		read(n); read(atkcst); read(amcst); 
		for (int i = 1; i <= n; i++) {
			read(hp[i]); read(atk[i]); read(am[i]);
			mxam = max(mxam, am[i]);
			mxamhp = max(mxamhp, am[i] + hp[i]);
			mxatk = max(mxatk, atk[i]);//atk 写成am了
		}
		int ncst, nhp;
		for (int natk = mxam + 1; natk <= mxamhp; natk++) {//攻击力尽量小
			for (int nam = 1; nam <= mxatk; nam++) {//防御力尽量小
				nhp = 1;
				ncst = nam * amcst + natk * atkcst;
				for (int i = 1; i <= n; i++) {
					nhp += (hp[i] + natk - am[i] - 1) / (natk - am[i]) * max(atk[i] - nam, 0);
				}
				ncst += nhp;
				if (ncst < acst) {
					acst = ncst;
					ahp = nhp;
					aatk = natk;
					aam = nam;
				}
			}
		}
		printf("%d %d %d", ahp, aatk, aam);
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
}brute;
}
