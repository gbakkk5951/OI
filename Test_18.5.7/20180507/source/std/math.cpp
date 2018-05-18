#include<cstdio>
#define ll long long
const int maxa=2000,mod=1000000007,P[14]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
int n,c[maxa+1],pid[maxa+1],st[maxa+1],maxp[maxa+1],f[1<<14];
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)scanf("%d",&x),c[x]++;
	for(f[0]=1;c[1];c[1]--)(f[0]*=2)%=mod;
	for(int i=0;i<14;i++)pid[P[i]]=1<<i;
	for(int i=2;i<=maxa;i++){
		if(!maxp[i])
			for(int j=i;j<=maxa;j+=i)maxp[j]=i;
		for(int x=i;x>1;x/=maxp[x])st[i]|=pid[maxp[x]];
	}
	for(int i=2;i<=maxa;i++)
		if(maxp[i]<44)
			for(int S=1<<14,T=st[i];S--;)
				S&T?1:f[S|T]=(f[S|T]+f[S]*(ll)c[i])%mod;
		else if(i==maxp[i])
			for(int S=1<<14;S--;)for(int g=f[S],j=i,T;j<=maxa;j+=i)
				S&(T=st[j])?1:f[S|T]=(f[S|T]+g*(ll)c[j])%mod;
	int ans=mod-1;
	for(int S=1<<14;S--;)(ans+=f[S])%=mod;
	printf("%d\n",ans);
}
