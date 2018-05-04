using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <ctime>
namespace OI {
struct _Main {
	_Main() {
		float t1;
		int a = 0, b = 0, c = 0;
		int sym;
		scanf("%d", &sym);
		t1 = clock();
		for (int i = 1; i <= 500000000; i++) {
			a += sym == 1 ? i : -i;
		}
		printf("test 1 uses %f ms.\n", clock() - t1);
		t1 = clock();
		for (int i = 1; i <= 500000000; i++) {
			b += sym * i;
		}
		printf("test 2 uses %f ms.\n", clock() - t1);
		t1 = clock();
		for (int i = 1; i <= 500000000; i++) {
			if (sym == 1) {
				c += i;
			} else {
				c -= i;
			}
		}
		printf("test 3 uses %f ms.\n", clock() - t1);
		if (a != b || b != c) {
			printf("???");
		}
	}
}ins;
}
