#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=400010;
int n,K;
int a[N];int P[N],cnt[N];int cnt_prime;int cj[N],num[N];
int C[N][20];
int ans;

ll power(ll x,int y,int mod){
	ll ret=1;
	for(;y;y>>=1,x=x*x%mod){
		if(y&1)	ret=ret*x%mod;
	}
	return ret;
}

void decompose(int K){
	int i;
	for(i=2;i*i<=K;i++){
		if(K%i==0){
			P[++cnt_prime]=i;
			while(K%i==0){
				K/=i;cnt[cnt_prime]++;
			}
		}
	}
	if(K>1)	P[++cnt_prime]=K,cnt[cnt_prime]=1;
}

/*int calc_fac(int x,int mod){
	if(x<mod)	return 0;
	return x/mod+calc_prime(x/mod);
}*/

void work(int id){
	int i;int p,c;int x;
	p=P[id];c=cnt[id];
	int mod=power(p,c,10000000);int phi=mod/p*(p-1);
	cj[0]=1;
	rep(i,1,n){
		x=i;num[i]=0;
		while(x%p==0)	x/=p,num[i]++;
		cj[i]=1ll*cj[i-1]*x%mod;num[i]+=num[i-1];
	}
	//rep(i,1,n)	num[i]=calc_prime(i,p);
	rep(i,0,n){
		C[i][id]=1ll*power(cj[i],phi-1,mod)*power(cj[n-i],phi-1,mod)%mod*cj[n]%mod;
		C[i][id]=1ll*C[i][id]*power(p,num[n]-num[i]-num[n-i],mod)%mod;
	}
}

void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

void CRT(int id){
	int i;
	int A=power(P[1],cnt[1],10000000),r1=C[id][1],B,R;int r2;
	int lcm=1;int x,y;
	rep(i,2,cnt_prime){
		B=power(P[i],cnt[i],10000000);r2=C[id][i];R=r2-r1;
		exgcd(A,B,x,y);
		lcm=A*B;
		x=(1ll*x*R%lcm+lcm)%lcm;
		r1=(1ll*x*A+r1)%lcm;
		A=lcm;
	}
	//printf("C[%d][%d] mod %d=%d\n",n,id,K,r1);
	ans=(ans+1ll*a[id]*r1)%K;
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int i;int j;
	scanf("%d%d",&n,&K);n--;
	decompose(K);
	rep(i,1,cnt_prime)	work(i);
	/*rep(i,0,n){
		rep(j,1,cnt_prime){
			printf("C[%d][%d] mod %d=%d\n",n,i,P[j],C[i][j]);
		}
	}
	printf("=====================\n");*/
	rep(i,0,n)	scanf("%d",&a[i]);
	rep(i,0,n){
		CRT(i);
	}
	printf("%d",ans);
}



























