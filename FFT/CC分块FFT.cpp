using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
namespace OI {
int sq = 173;
const int SQN = 180, MXN = 100005, MX = 30005;
const lld ans;
struct com {
	lf r, i;
	
};

namespace FFTSpace {
	
	void FFT(com arr[], int len) {
		static com w[65537], w, x, y;
		int i, j, k;
		com *a, *b;
		for (int I = 1; 1 << I <= len; I++) {
			
		}
	}
}

struct _Main {
	int st[SQN], ed[SQN], id[MXN];
	int cnt[MX];
	int arr[MXN];
	int idx;
	int n;
	com c1[65537], c2[65537];
	void maincalc() {
		for (int i = 2; i < id[n]; i++) {
			memset(c1, 0, 2 * MX * sizeof(com));
			memset(c2, 0, 2 * MX * sizeof(com));
			for (int j = 1; j < st[i]; j++) {
				c1[arr[j]].r += 1;
			}
			for (int j = ed[i] + 1; j <= n; j++) {
				c2[arr[j]].r += 1;
			}
			using FFTSpace::FFT;
			FFT(c1, MX, 1);
			FFT(c2, MX, 1);
			for (int j = 0; j < MX; j++) {
				c1[j] = c1[j] * c2[j];
			}
			FFT(c1, MX, -1);
			for (int j = st[i]; j <= ed[i]; j++) {
				ans += round(c1[arr[j] * 2].r);
			}
		}
	}
	void init() {
		sq = min(sq, n + 1);
		for (int i = 1; i <= n; i++) {
			id[i] = idx;
			if (i % sq == 0) {
				ed[idx] = i;
				st[++idx] = i + 1;
			}
		}
		ed[id[n]] = n;
		st[id[1]] = 1;
		ed[0] = st[0] = n + 1;
	}
	void precalc() {
		int t;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= ed[id[i]]; j++) {
				t = arr[i] - (arr[j] - arr[i]);
				if (t >= 1 && t <= MX) {
					ans += cnt[t];
				}
			}
			cnt[arr[i]]++;
		}
		memset(cnt, 0, MX * sizeof(int));
		for (int i = n; i >= 1; i--) {
			for (int j = i - 1; j >= st[id[i]]; j--) {
				t = arr[i] + arr[i] - arr[j];
				if (t >= 1 && t <= MX) {
					ans += cnt[t];
				}
			}
			if (i == st[id[i]]) {
				for (int j = st[id[i]]; j <= st[id[i]]; j++) {
					cnt[arr[j]]++;
				}
			}
		}
	}
	
	void maincalc() {
	
	}
	_Main() {
		read(n);
		if (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		precalc();
		maincalc();
		printf("%lld", ans);
	}
template <typename type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}CC;

}
