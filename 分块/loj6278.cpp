using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
namespace OI {
typedef long long lld;
const int MXN = 50005, SQ = 230;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 31 | INF;
class Block {
public:	
	int sq;
	int id[MXN + SQ], st[MXN + SQ], ed[MXN + SQ];
	lld sorted[MXN + SQ], org[MXN + SQ], add[MXN + SQ];
	void resort(int id) {
		memcpy(sorted + st[id], org + st[id], sq * sizeof(int));
		sort(sorted + st[id], org + st[id], sq * sizeof(int));
	}
	void init(int n) {
		sq = ceil(sqrt(n));
		int idx = 0;
		st[0] = 1;
		for (int i = 1; i <= n + sq; i++) {
			id[i] = idx;
			if (i % sq == 0) {
				ed[idx] = i;
				idx++;
				st[idx] = i + 1;
			}
		}
		for (int i = n + 1; i <= ed[id[n]]; i++) {
			org[i] = LINF;
		}
		for (int i = 1; i <= n; i += )
	}

}data;

struct _Main {
	_Main() {
		
	}
}loj6278;
}
