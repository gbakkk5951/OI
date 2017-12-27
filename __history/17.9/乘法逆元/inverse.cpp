using namespace std;
int main(){}
#include<cstdio>
struct _Main{
int inv[10000010];
int p;
_Main(){
	int s[2];s[1]=1;s[0]=0;
	long long sum=1;
//	freopen("inverse4.in","r",stdin);
//	freopen("inverse4.out","w",stdout);
	scanf("%d",&p);
	int i;
	inv[1]=1;
	for(i=2;i<p;i++){
		inv[i]=((long long)inv[p%i]*(-p/i)%p+p)%p;
		sum+=inv[i];s[i&1]^=inv[i];
	}
	printf("%d %d %lld",s[1],s[0],sum);
	fclose(stdout);
}
}inverse;
