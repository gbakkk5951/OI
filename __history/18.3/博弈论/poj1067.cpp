using namespace std;
int main() {}
#include <cstdio>
#include <cmath>
#include <algorithm>
namespace OI {
struct _Main {
	_Main() {
		double rate = (1.0 + sqrt(5.0)) / 2.0;
		int a, b, k;
		while (~scanf("%d%d", &a, &b)) {
			if (a > b) {
				swap(a, b);
			}
			k = b - a;
			if (a == (int)(k * rate)) {
				printf("0\n");
			} else {
				printf("1\n");
			}
		}
	}
}poj1067;

}
