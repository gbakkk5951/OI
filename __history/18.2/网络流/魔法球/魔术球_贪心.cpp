

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
    freopen("out.txt", "w", stdout);
//	scanf("%d", &n);
    int I;
    
	int x = 1;
	n = 10;
	int j, j_;
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
		printf("[%d]\n",k);
    	for (int i = 0; i < k; i++) {
    		for (int j = v[i].size()-1; j >= 0; j--) printf("%2d ", v[i][j]);
    		printf("\n");
    	}	
        printf("\n");	
//		printf("[%d]%d\n", k, x - 1);
	}

//	printf("%d\n", x - 1);
    
    


	return 0;
}

