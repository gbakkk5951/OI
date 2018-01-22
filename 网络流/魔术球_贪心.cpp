

#include <cstdio>
#include <cmath>
#include <vector>

const int MAXN = 1000;

int n;


inline bool isSquareNumber(int x) {
	int root = floor(sqrt(x));
	return root * root == x;
}
std::vector<int> v[MAXN];
int main() {
//	scanf("%d", &n);
    int I;
    
	int x = 1;
	n = 1000;
	for (int k = 1; k <= n; k++) {
		while (1) {
			bool flag = false;

			for (int i = 0; i < k; i++) {
				if (v[i].empty() || isSquareNumber(v[i].back() + x)) {
					v[i].push_back(x++);
					flag = true;
					break;
				}
			}
			if (!flag) break;
		}
		printf("[%d]%d\n", k, x - 1);
	}

	printf("%d\n", x - 1);
    
    /*
	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < v[i].size(); j++) printf("%d%c", v[i][j], j == v[i].size() - 1 ? '\n' : ' ');
	}*/

	return 0;
}

