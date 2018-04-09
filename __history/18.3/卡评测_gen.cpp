#include <cstdio>
// 效果M^N, 代码复杂度 M*(N^2)
const int N = 17, M = 2;
int main() {
	int i, j, k;
	
	freopen("KA.cpp", "w", stdout);
	
	for (i = 0; i < M; i++) {
		printf("class T%d{}b%d;\n", i, i);
	}
	printf("template <");
	for (int i = 0; i < N; i++) {
		if (i) {
			printf(", ");
		}
		printf("typename t%d", i);
	}
	printf(">\n	void bomb(");
	for (i = 0; i < N; i++) {
		if (i) {
			printf(", ");
		}
		printf("t%d a%d", i, i);
	}
	printf(") {\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("		bomb(");
			for (k = 0; k < N; k++) {
				if (k) {
					printf(", ");
				}
				if (k == i) {
					printf("b%d", j);
				} else {
					printf("a%d", k);
				}
				
			}
			printf(");\n");
		}
	}
	printf("}");
	
	printf("int main() {\n	bomb(");
	for (i = 0; i < N; i++) {
		if (i) {
			printf(", ");
		}
		printf("b0");
	}
	printf(");\n}");
}
