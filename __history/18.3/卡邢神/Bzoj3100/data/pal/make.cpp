#include <cstdio>
int main() {
	freopen("pal11.in", "w", stdout);
	printf("1000000\n");
	for (int I = 0; I < 2; I++) {
		for (int j = 2; j <= 500000; j++) {
			printf("%d ", j);
		}
		if (I == 0) {
			printf("1 500001 ");
		}
	}
	freopen("pal11.out", "w", stdout);
	printf("500001");
	fclose(stdout);
}
