using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
namespace OI {
typedef long long lld;
const lld mod = 1e9;
struct big {
	lld num[51];
	int high;
	lld & operator [] (int idx) {
		return num[idx];
	}
	big (const big &b) {
		memcpy(this, &b, sizeof(big));
	}
	big () {
		memset(this, 0, sizeof(big));
	}
	void jw() {
		for (int i = 0; i <= 50; i++) {
			if (num[i]) {
				high = i;
				jw(i);
			}
		}
	}
	void jw(int i) {
		lld t;
		if (num[i] >= mod) {
			num[i + 1] += (t = num[i] / mod);
			num[i] -= t * mod;
		} else if (num[i] < 0) {
			num[i + 1] += (t = (num[i] - mod + 1) / mod);
			num[i] -= t * mod;
		}
	}
	big operator + (big b) {
		big ret = *this;
		for (int i = 0; i <= b.high; i++) {
			ret[i] += b[i];
		}
		ret.jw();
		return ret;
	}
	big operator - (big b) {
		big ret = *this;
		for (int i = 0; i <= b.high; i++) {
			ret[i] -= b[i];
		}
		ret.jw();
		return ret;
	}
	
	big operator * (big b) {
		big ret;
		for (int i = 0; i <= high; i++) {
			for (int j = 0; j <= b.high; j++) {
				ret.jw(i + j);
				ret[i + j] += num[i] * b[j];
				ret.jw(i + j);
			}
		}
		ret.jw();
		return ret;
	}
	void print() {
		printf("%lld", num[high]);
		for (int i = high - 1; i >= 0; i--) {
			printf("%09lld", num[i]);
		}
	}
};
struct _Main {
	big pow[1270];
	big com[51][51];
	big dp[51];
	void calc(int i) {
		dp[i] = pow[i * (i - 1) >> 1];
		for (int j = 1; j <= i - 1; j++) {
			dp[i] = dp[i] - dp[j] * pow[(i - j) * (i - j - 1) >> 1] * com[i - 1][i - j];
		}
	}
	_Main() {
		dp[1].num[0] = 1;
		pow[0].num[0] = 1;
		pow[1].num[0] = 2;
		for (int j = 2; j <= 1250; j++) {
			pow[j] = pow[j - 1] * pow[1];
		}
		com[0][0].num[0] = 1;
		for (int i = 1; i <= 50; i++) {
			com[i][0].num[0] = 1;
			for (int j = 1; j <= 50; j++) {
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
			}
		}
		int mx = 1;
		int a;
		while (~scanf("%d", &a)) {
			if (a == 0) break;
			while (a > mx) {
				calc(++mx);
			}
			dp[a].print();
			printf("\n");
		}
	}
}poj1737;
}
