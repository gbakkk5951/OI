using namespace std;
int main() {}
#include <algorithm>
namespace OI {
const int MXN = 1e7;

int a[MXN];
int b[MXN];
char cmp(int x, int y) {
	return b[x] < b[y];
}
struct _Main {

	_Main() {
		sort(a, a + MXN, cmp);
	}
}instance;
}
