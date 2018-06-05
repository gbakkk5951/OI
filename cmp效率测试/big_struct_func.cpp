using namespace std;
int main() {}
#include <algorithm>
namespace OI {
const int MXN = 1e7;

struct Big {
	int arr[(int)1];
}a[(int)1e7];
bool cmp(const Big &a, const Big &b) {
	return a.arr[0] < b.arr[0];
} 
struct _Main {

	_Main() {
		sort(a, a + (int)1e7, cmp);
	}
}instance;
}
