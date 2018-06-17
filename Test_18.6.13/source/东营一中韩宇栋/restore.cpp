#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long double LD;
const LD eps = 5e-7;
int n, id[105], di[105];
LD d[105][105], X[105], Y[105];
double x;
inline LD sqr(LD x) { return x * x; }
bool check(int j) {
	for (int i = 1; i < j; ++i)
		if (fabs(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]) - sqr(d[id[i]][id[j]])) > eps) return false;
	return true;
}
bool dfs(int i) {
	if (i > n) return true;
	X[i] = (sqr(X[2]) + sqr(d[id[i]][id[1]]) - sqr(d[id[i]][id[2]])) / (X[2] * LD(2));
	Y[i] = sqrt(sqr(d[id[i]][id[1]]) - sqr(X[i]));
	if (check(i)) { if (dfs(i + 1)) return true; }
	Y[i] = -Y[i];
	if (check(i)) { if (dfs(i + 1)) return true; }
	return false;
}
int main() {
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout); 
	srand(time(0)^20000926);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) id[i] = i;
	random_shuffle(id + 1, id + n + 1);
	for (int i = 1; i <= n; ++i) di[id[i]] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%lf", &x);
			d[i][j] = x;
		}
	X[1] = 0; Y[1] = 0;
	X[2] = d[id[1]][id[2]]; Y[2] = 0;
	dfs(3);
	for (int i = 1; i <= n; ++i) printf("%.10lf %.10lf\n", double(X[di[i]]), double(Y[di[i]]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
