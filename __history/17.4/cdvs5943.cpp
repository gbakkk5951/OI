#include<cstdio>
#include<iostream>
#include<cstring>
#define debug cout
#define ll long long int
using namespace std;
struct _main{
ll n[50],nn[50];ll q_mod,q_yu;
bool wa;
int t,m;


_main(){
//	freopen("equation.in","r",stdin);freopen("equation.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&m);
		int i;
		memset(nn,0,sizeof(nn));
		memset(n,0,sizeof(n));
		for(i=0;i<m;i++){
			scanf("%lld%lld",&n[i],&nn[i]);
			if(nn[i])
			nn[i]=n[i]-nn[i];
		}
		for(i=1;i<m&&!wa;i++){
			merge(n[i-1],n[i],nn[i-1],nn[i]);

			n[i]=q_mod;nn[i]=q_yu;
		}
		if(wa){
			printf("-1\n");wa=false;
		}else{
			printf("%lld\n",nn[m-1]);
		}
	}
	fclose(stdout);
}
ll abs(ll in){	return (in>>63)^(in+(in>>63));
}
ll gcd(ll a,ll b){
	return (!b)?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b)
    {
       exgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1,y=0;
    }
    return ;

}
	
void merge(ll a1,ll a2,ll b1,ll b2){
	ll mod,ret;
	if(b1==0&&b2==0){
		a2=a1*a2/gcd(a1,a2);
		q_mod=a2;q_yu=0;
		return;
	}
	ll g=gcd(a1,a2),delta=b2-b1;
	if(abs(delta)%g){
		wa=true;return;
	}
	mod=a1*a2/g;
	ll yx1,yx2;
	exgcd(a1,a2,yx1,yx2);
	ret=a1*yx1*(delta/g)+b1;
	ret%=mod;
	if(ret<0)ret+=mod;
	a2=mod;b2=ret;
	q_mod=mod;q_yu=ret;
}
	
	
	
	
	
	
	
	
	
	
	
	
}instance;int main(){}
