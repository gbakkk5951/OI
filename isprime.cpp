#include <algorithm>
#include <cstdio>
int main() {
	int i, a;
	while (scanf("%d", &a)) {
		for (i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				printf("No\n");
				break;
			}
		}
		if (i * i > a) {
			printf("Yes\n");
		}
	}

}
