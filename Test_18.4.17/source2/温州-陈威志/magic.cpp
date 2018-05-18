#include<cstdio>
#define L long long
using namespace std;
int n,ans,P;
int ni[1000001],a[1000001],b[1000001];

int mi(int t,int num)
{
  if(num==1) return t%P;
  if(num==0) return 1;
  int tt=mi(t,num/2),ttt;
  ttt=(L)tt*tt%P;
  if(num&1) ttt=(L)ttt*t%P;
  return ttt;
}

int main()
{
  int i,j,t=0,pd=0,tt;
  freopen("magic.in","r",stdin);
  freopen("magic.out","w",stdout);
  scanf("%d%d",&n,&P);
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  if(n<=2000)
    {
	  for(i=1;i<n;i++)
	   {
	    for(j=1;j<=n-i;j++) a[j]=(a[j]+a[j+1])%P;
	   }
      printf("%d\n",a[1]);
      return 0;
	}
  if(P==10) t=P,P=2;
  ni[0]=ni[1]=1,tt=1; 
  for(i=2;i<=n;i++) ni[i]=mi(i,P-2);
  for(i=1;i<=n;i++) 
   if(n-i!=P)
    b[i]=tt,tt=(L)b[i]*(n-i)%P*ni[i]%P;
    else b[i]=tt,tt=(L)b[i]%P*ni[i]%P;
  for(i=1;i<=n;i++) ans=(ans+(L)b[i]*a[i])%P;
  if(t)
    {
	  pd=ans,ans=0,P=t/P;
	  ni[0]=ni[1]=1,tt=1; 
      for(i=2;i<=n;i++) ni[i]=(L)ni[P%i]*(P-P/i)%P;
      for(i=1;i<=n;i++) b[i]=tt,tt=(L)b[i]*(n-i)%P*ni[i]%P;
      for(i=1;i<=n;i++) ans=(ans+(L)b[i]*a[i])%P;
      if((ans%2)!=(pd%2)) ans=(ans+5)%t;
	}
  printf("%d\n",ans);
} 
