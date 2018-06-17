#include <cstdio>
using namespace std;
const int N=6;
int n; int mat[N][N];
int inv(int x,int mod) {
	int res=1,b=x%mod,t=mod-2;
	while(t) {
		if (t&1) (res*=b)%=mod;
		(b*=b)%=mod,t>>=1;
	}
	return res;
}
void read() {
	scanf("%d",&n);
	for (int j=1;j<=n;j++)
		scanf("%d",&mat[1][j]);
	return;
}
namespace s1 {
	void work() {
		if (n==1) {
			printf("%d\n",mat[1][1]);
			return;
		}
		mat[2][2]=inv(mat[1][1],mat[1][2]);
		mat[2][1]=(mat[1][1]*mat[2][2]-1)/mat[1][2];
		for (int i=1;i<=n;i++) {
			for (int j=1;j<n;j++)
				printf("%d ",mat[i][j]);
			printf("%d\n",mat[i][n]);
		}
		return;
	}
}
int main() {
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	read();
	if (n<=2) s1::work();
	return 0;
}