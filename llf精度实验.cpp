#include <cstdio>
typedef long double llf;
int main() {
	printf("size = %d\n", sizeof(llf));
	llf now = 2147483648LLU * 2147483648LLU * 2 - 1;
	for (int i = 0; i <= 200; i++) {
		printf("%Lf\n", now  - i / 2.0);
	}
}
