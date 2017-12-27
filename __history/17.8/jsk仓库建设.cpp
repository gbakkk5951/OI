using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
int q[1000010];
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int head,tail;
struct _Main{
int n;
int pro[1000010];
int pos[1000010];
int cos[1000010];
long long sum[1000010];
long long num[1000010];
long long dp[1000010];
long long x[1000010];
double inline getrate(int a,int b){
	return  (double)((double)x[a]-x[b] )/(double)(num[a]-num[b]);
}
_Main(){
	int i,j,k;
	read(n);
	for(i=1;i<=n;i++){
		read(pos[i]);
		read(pro[i]);
		read(cos[i]);
		num[i]=num[i-1]+pro[i];
		sum[i]=sum[i-1]+(pos[i]-pos[i-1])*num[i-1];
	}
	q[tail++]=0;
	for(i=1;i<=n;i++){
		while(head+1<tail && getrate(q[head+1],q[head])<pos[i]){
			head++;
		}
		while( (head>=tail) ||(head && getrate(q[head],q[head-1])>pos[i]) ){
			head--;
		}
		dp[i]=dp[q[head]]+sum[i]-sum[q[head]]-num[q[head]]*(pos[i]-pos[q[head]])+cos[i];
		x[i]=dp[i]-sum[i]+num[i]*pos[i];
		while(1<tail && (getrate(q[tail-1],q[tail-2])>=getrate(i,q[tail-1]))){
			tail--;
		}
		
		q[tail++]=i;
	}
	printf("%lld",dp[n]);
	
	
}


	
	
}jsk;
