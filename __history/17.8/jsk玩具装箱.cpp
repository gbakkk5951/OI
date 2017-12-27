using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>

struct Point{
	double x,y;
	int idx;
}q[50010],temp;
int tail,head;
long long dp[50010];
struct _Main{

int n,l;
long long sum[50010];	
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}	
double inline rate (const Point &big,const Point &small){
	return (double)((double)big.y-small.y)/((double)big.x-small.x);
}
long long inline pow (long long a){
	return a*a;
}

double inline pow (double a){
	return a*a;
}
_Main(){
	read(n);read(l);
	int i,j,k;int a,b;
	for(i=1;i<=n;i++){
		read(a);
		sum[i]=sum[i-1]+a+1;
	}
	q[tail++]=(Point){(double)0LL,pow((double)-1-l),0};
	
	for(i=1;i<=n;i++){
		while(head+1<tail && (rate(q[head+1],q[head])<2*sum[i])){
			head++;
		}
		while(head>=tail || (head && (rate(q[head],q[head-1])>2*sum[i]) )){
			head--;
		}
		dp[i]=dp[q[head].idx]+pow(sum[i]-sum[q[head].idx]-1-l);
		temp.idx=i;temp.x=sum[i];temp.y=(double)dp[i]+pow((double)-sum[i]-1-l);
		while(head+1<tail && (rate(temp,q[tail-1])<rate(q[tail-1],q[tail-2])) ){
			tail--;
		}q[tail++]=temp;
	}
	printf("%lld\n",dp[n]);
}

	
	
}jsk;

