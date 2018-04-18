#include<map>
#include<stack>
#include<queue>
#include<time.h>
#include<cstdio>
#include<string>
#include<bitset>
#include<vector>
#include<cstring>
#include<complex>
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
#define fi first
#define se second
#define il inline
#define mp make_pair
#define pb push_back
#define ll long long
#define gc getchar()
#define inf 1001001001
#define Ri register int
#define Pii pair<int,int>
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define infll 1001001001001001001LL
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define FO(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
il int read(){bool f=true;Ri x=0;char ch;while(!isdigit(ch=gc))if(ch=='-')f=false;while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=gc;}return f?x:-x;}
#define gi read()
#define N 401234
#define L 40 
#define SZ 401234
int ct[L][SZ],re[L][SZ];
int pwr[N],p[N];int pcnt;
int n,cntc1,pyz,a[N];
int pw(int a,int n,int pyz){ll res=1;for(;n;n>>=1,a=((ll)a*a)%pyz)if(n&1)res=(ll)res*a%pyz;return res;}
int c1(int n,int i){
	int p=::p[i],pk=pwr[i];
 	if(!n)return 1;  
	int ans=ct[i][pk];
	ans=pw(ans,n/pk,pk);
	ans=ans*(ll)ct[i][n%pk]%pk;
 	return ans*(ll)c1(n/p,i)%pk;
}
ll exgcd(ll a,ll b,ll &x,ll&y){
	if(!b)x=1,y=0;	
	else{
		exgcd(b,a%b,x,y);
		ll t=x;x=y;y=t-(a/b)*x;
	}
}  
int rev(int a,int m){
	if(!a)return 0;/* 
	ll x=1,y=0,r=a%m,q,t,_=m;
	if(r<0)r+=m;
	while(m%r){a=m;m=r;q=a/m;r=a%m;t=x;x=y-x*q;y=t;}
	if(r!=1)return 0;
	return x<0?x+_:x; */
	return re[m][a];
}  
  
int cal(int n,int m,int p,int q)  {  
	int pi=::p[q],pk=pwr[q];
	//fprintf(stdout,"%d,%d,%d,%d,%d\n",n,m,p,pi,pk);
	int k=0,a,b,c,ans;  
	a=c1(n,q),b=c1(m,q),c=c1(n-m,q);  
	for(int i=n;i;i/=pi)k+=i/pi;  
	for(int i=m;i;i/=pi)k-=i/pi;  
	for(int i=n-m;i;i/=pi)k-=i/pi;  
	ans=(ll)a*rev(b,q)%pk*rev(c,q)%pk*pw(pi,k,pk)%pk;  
	return (ll)ans*(p/pk)%p*rev(p/pk,q)%p;  
}  
int C(int n,int m){  
 	int ans=0;  
 	for(int i=1;i<=pcnt;i++)ans=(ans+cal(n,m,pyz,i));	
	return ans;
}  
int main(){
	FO(magic);
 	n=gi;pyz=gi;
	if(pyz==1)puts("0");
	else{
		for(int i=1;i<=n;i++)a[i]=gi;
		int ans=0;
		for(int x=pyz,i=2;x>1;i++){
			if(x%i==0){
				int k;p[++pcnt]=i;pwr[pcnt]=1;
				for(k=1;x%i==0;x/=i)pwr[pcnt]*=i;
			}
		}
		for(Ri i=1;i<=pcnt;i++){
 			ct[i][1]=1;
			for(Ri j=2;j<=n;j++){
 				if(j%p[i])ct[i][j]=(ct[i][j-1]*(ll)j)%pwr[i]; 
 				else ct[i][j]=ct[i][j-1];
			}
		}
		for(Ri i=1;i<=pcnt;i++){
 			re[i][1]=re[i][0]=1;
 			int pk=pwr[i];
			for(Ri j=2;j<=n;j++){
				re[i][j]=((ll)(pk-pk/j)*re[i][pk%j])%pk;
				if(re[i][j]<0)re[i][j]+=pk;			
			}
		}
		for(int i=1;i<=n;i++){
			ans=(ans+C(n-1,i-1)*(ll)a[i])%pyz;
		}
		cout<<ans;
	}
	return 0;
}

