using namespace std;
int main() {}
#include <algorithm>
namespace OI {
const int MXN = 1e7;

struct Big {
	int arr[(int)1];
	bool operator < (const Big &b) const {
		return arr[0] < b.arr[0];
	}
}a[(int)1e7];

struct _Main {

	_Main() {
		sort(a, a + (int)1e7);
	}
}instance;
}
