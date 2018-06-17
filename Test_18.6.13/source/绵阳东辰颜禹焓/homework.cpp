#include<cmath>
#include<cstdio>
int main(){
	freopen("homework.in","r",stdin);freopen("homework.out","w",stdout);
	double x=1-exp(-1);int n;scanf("%d",&n);for(int i=1;i<=n;++i) x=1-(i+1)*x;printf("%.4f\n",x);	
	return 0;
}
