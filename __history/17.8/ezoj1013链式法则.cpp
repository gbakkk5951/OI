using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
int mindiv[5000010];
struct _Main{
void read(int &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}
bool noprime[5000010];
int q[1000010];
int mx;
int prime[350000];
int cnt;
_Main(){
	int i,j,ans,t;
	for(i=0;1;i++){
		read(q[i]);
		mx=max(mx,q[i]);
		if(!q[i])break;
	}

	for(i=2;i<=mx;i++){
		if(!noprime[i]){
			mindiv[i]=i;
			prime[cnt++]=i;
		}
		for(j=0;j<cnt && (t=i*prime[j]) <=mx;j++){
			noprime[t]=1;
			mindiv[t]=prime[j];
			if(!(i%prime[j])){
				break;
			}
		}
	}
	for(i=0;q[i];i++){
		ans=0;
		while(q[i]!=1){
			ans+=mindiv[q[i]];
			q[i]/=mindiv[q[i]];
		}
		printf("%d\n",ans);
	}
}
	
	
	
}ezoj1013;
