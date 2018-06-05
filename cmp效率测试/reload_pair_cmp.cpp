using namespace std;
int main() {}
#include <algorithm>
namespace OI {
typedef pair<int, int> p;
const int MXN = 1e7;

p a[MXN];
bool cmp(p a, p b) {
	return a.second < b.second;
}
struct _Main {

	_Main() {
		sort(a, a + MXN, cmp);
	}
}instance;
}
