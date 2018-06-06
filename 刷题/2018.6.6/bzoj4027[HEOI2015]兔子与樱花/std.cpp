using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <vector>
namespace OI {
const int MXN = 2e6 + 10;
int sum[MXN], ans;
bool cmp(int a, int b) {
	return sum[a] < sum[b];
}
struct _Main {
	int n, m, ans;
	vector<int> s[MXN];
	void dfs(int nd) {
		for(int i = 0; i < s[nd].size(); i++) {
			dfs(s[nd][i]);
		}
		
		sort(s[nd].begin(), s[nd].end(), cmp);
		
		for (int i = 0; i < s[nd].size(); i++) {
			if (sum[nd] + sum[s[nd][i]] - 1 <= m) {
				sum[nd] += sum[s[nd][i]] - 1;
				++ans;
			} else {
				break;
			}
		}
	}
	_Main() {
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(sum[i]);
		}
		int kn, a;
		for (int i = 1; i <= n; i++) {
			read(kn);
			sum[i] += kn;
			s[i].resize(kn);
			for (int j = 0; j < kn; j++) {
				read(a);
				s[i][j] = a + 1;
			}
		}
		dfs(1);
		printf("%d", ans);
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
