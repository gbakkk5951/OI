using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
namespace OI {
typedef long long lld;
typedef pair<int, int> p;//价格，数量
const int MXN = 1e5 + 10;
struct _Main {
	int n, m;
	lld ans[MXN];
	lld cst[MXN], ext[MXN], tot[MXN], fade[MXN];
	vector<p> ding[MXN], once[MXN];
	priority_queue<p> ghp;
	priority_queue<int, vector<int>, greater<int> > lhp;
	int srt[11];
	int day;
	void getchain() {
		int ddl, rem;
		for (int i = 1; i <= n; i++) {
			if (fade[i] == 0) {
				once[day].push_back((p) {cst[i] + ext[i], 1});
				if (tot[i] > 1)
				once[day].push_back((p) {cst[i], tot[i] - 1});
			} else {
				ddl = (tot[i] + fade[i] - 1) / fade[i];
				if (ddl <= day) {
					once[ddl].push_back((p) {cst[i] + ext[i], 1})
					rem = (tot[i] - 1) % fade;
					if (rem > 0) {
						once[ddl].push_back((p) {cst[i], rem});
					}
					if (ddl > 1) {
						ding[ddl - 1].push_back((p) {cst[i], fade[i]});
					}
				} else {
					rem = tot[i] - day * fade[i];
					once[day].push_back((p) {cst[i] + ext[i], 1});
					if (rem > 1) {
						once[day].push_back((p) {cst[i], rem - 1});
					}
					ding[day].push_back((p) {cst, fade[i]});
				}
			}
		}
	}
	lld vsum, sold, mxsold;
	p dq[15];
	
	void get_n() {
		for (int i = n; i >= 1; i--) {
			
		}
	}
	void get_1_to_n() {
		ans[n] = vsum;
	}
	int ques[MXN];
	_Main() {
		int Qn, a;
		read(n); read(m); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(cst[i]); read(ext[i]); read(tot[i]); read(fade[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(ques[Q]);
			day = max(day, ques[Q]);
		}
		getchain();
		get_n();
		get_1_to_n();
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%lld\n", ans[ques[Q]]);
		}
	}
tempate <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
};

}
