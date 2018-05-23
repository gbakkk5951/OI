using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>

namespace OI {
typedef long long lld;
typedef pair<int, int> p;
const int MXV = 1e6 + 10, MXN = 5e3 + 10;

struct ArrayTree {
	int n;
	lld node[MXV];
	void add(int nd, lld v) {
		for (nd = n - nd + 1; nd <= n; nd += nd & (-nd)) {
			node[nd] += v;
		}
	}
	lld query(int nd) {
		lld ret = 0;
		for (nd = n - nd + 1; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
}cnttree, valtree;

struct _Main {
	vector<p> tag[MXV << 1];
	lld mxam, mxamhp, mxatk;
	void gettag(int hp, int am, int atk) {
		int lst = hp, t;
		for (int st = 1, ed = 1; st <= hp; st = ed + 1) {
			ed = hp / (t = hp / st);
			ed -= st < ed && hp % ed == 0;
			t = (hp + st - 1) / st;
			if (t != lst && am + st > mxam + 1) {
				tag[am + st].push_back((p) {atk, t - lst});
			}
			lst = t;
		}
	}
	lld am[MXN], hp[MXN], atk[MXN];
	lld ahp, aam, aatk;
	lld acst;
	lld amcst, atkcst;
	int n;
	_Main() {
		lld nam = 0;
		acst = 9e18;
		read(n); read(atkcst); read(amcst);
		for (int i = 1; i <= n; i++) {
			read(hp[i]); read(atk[i]); read(am[i]);
			mxam = max(mxam, am[i]);
			mxamhp = max(mxamhp, am[i] + hp[i]);
			nam = max(nam, atk[i]);
		}
		for (int i = 1; i <= n; i++) {
			gettag(hp[i], am[i], atk[i]);
		}
		cnttree.n = nam;
		valtree.n = nam;
		lld icnt;
		lld natk = mxam + 1;
		for (int i = 1; i <= n; i++) {
			icnt = (hp[i] + natk - am[i] - 1)/ (natk - am[i]);
			cnttree.add(atk[i], icnt);
			valtree.add(atk[i], icnt * atk[i]);
		}
		lld namcst, natkcst, nhp, ncst;
		lld tatk, tcnt;
		for (; natk <= mxamhp; natk++) {
			for (int i = 0; i < tag[natk].size(); i++) {
				tatk = tag[natk][i].first;
				tcnt = tag[natk][i].second;
				cnttree.add(tatk, tcnt);
				valtree.add(tatk, tatk * tcnt);
			}
			while (nam > 1 && cnttree.query(nam) <= amcst) {
				nam--;
			}
			namcst = nam * amcst;
			natkcst = natk * atkcst;
			nhp = valtree.query(nam) - cnttree.query(nam) * nam + 1;//剩一滴血
			ncst = namcst + natkcst + nhp;
			if (ncst < acst) {
				ahp = nhp;
				aam = nam;
				aatk = natk;
				acst = ncst;
			}
		}
		printf("%lld %lld %lld", ahp, aatk, aam);
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
}std;
}
