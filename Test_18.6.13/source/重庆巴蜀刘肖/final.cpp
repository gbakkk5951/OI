#include <cstdio>
#include <cstdlib>
int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	int n,vl[6][6];scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&vl[1][i]);
	if(n==2)
		for(int i=-2000;i<=2000;i++)
			for(int j=-2000;j<=2000;j++)
				if(vl[1][1]*i-vl[1][2]*j==1)
					printf("%d %d\n%d %d",vl[1][1],vl[1][2],j,i),exit(0);
	if(n==1)printf("%d",vl[1][1]);
}
