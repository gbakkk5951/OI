using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
namespace OI {
struct op {
	int src, dst, xs;//xs = 0表示交换
	
}stk[100];
int top;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
struct _Main {
	int ma[7][7];
	int vec[7];
	int hl;
	int n;
	int a, b, c;
	_Main() {
		freopen("final.in", "r", stdin);
		freopen("final.out", "w", stdout);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &vec[i]);
		}
		if (n == 1) {
			if (vec[1] == 1) {
				printf("%d", 1);
			} else {
				printf("no solution");
			}
			fclose(stdout);
			return;
		}
		
		for (int i = 1; i <= n; i++) {//找到ab
			for (int j = i + 1; j <= n; j++) {
				if (gcd(vec[i], vec[j]) == 1 || gcd(vec[i], vec[j]) == -1) {//神Tm gcd(i, j)
					a = i; b = j;
					break;
				}
			}
			if (a) break;
		}
		if (a == 0) {
			printf("no solution");
			fclose(stdout);
			return;
		}
		
		while (vec[a] && vec[b]) {//辗转相除
			if (abs(vec[a]) > abs(vec[b])) {
				swap(a, b);
			}
			stk[++top] = (op) {a, b, -vec[b] / vec[a]};
			vec[b] -= vec[b] / vec[a] * vec[a];
		}
		if (vec[b]) swap(a, b);
		int swped = 0;
		if (a != 1) {
			swped = 1;
			swap(vec[a], vec[1]);
			stk[++top] = (op){a, 1, 0};
			a = 1;//忘了这个
		}
		for (int i = 1; i <= n; i++) {
			ma[1][i] = vec[i];
		}
		for (int i = 2; i <= n; i++) {
			ma[i][i] = 1;
		}
		
		if ((vec[a] == -1) ^ (swped)) {
			ma[2][2] = -1;
		}
		while (top) {//逆操作
			a = stk[top].src;
			b = stk[top].dst;
			c = stk[top].xs;
			if (c == 0) {
				for (int i = 1; i <= n; i++) {
					swap(ma[i][a], ma[i][b]);
				}
			} else {
				for (int i = 1; i <= n; i++) {
					ma[i][b] -= ma[i][a] * c;//逆变换要-=
				}
			}
			--top;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d ", ma[i][j]);
			}
			printf("\n");
		}
		fclose(stdout);
	}
}final_;
}
