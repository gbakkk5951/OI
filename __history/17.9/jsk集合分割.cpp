using namespace std;
int main(){} 
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
struct point{
	double x,y;int idx;
}q[2005];
double rate(point a,point b){
	return (a.x-b.x)/(a.y-b.y);
}

int head,tail;
struct _Main{
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
template<typename Type>
	Type pf(Type a){
		return a*a;
	}
long long num[2005];int n,m;
long long dp[2][2005];
_Main(){
	int i,j,k;int iter=0;
	read(n);read(m);
	if(n==m){
		printf("0");
		return;
	}
	for(i=1;i<=n;i++){
		read(num[i]);
	}
	sort(num+1,num+n+1);
	n=unique(num+1,num+1+n)-num-1;
	for(i=1;i<=n;i++){
		dp[iter][i]=pf(num[i]-num[1]);
	}
	for(i=1;i<m;i++){
		iter^=1;
		head=tail=0;
		for(j=i;j<=n;j++){
			point ele=(point){dp[iter^1][j-1]+pf(num[j]),num[j],j-1};
			while(tail>1 && rate(q[tail-1],ele)<rate(q[tail-1],q[tail-2])){
				tail--;
			}
			q[tail++]=ele;
			while(head+1<tail && rate(q[head+1],q[head])<2*num[j]){
				head++;
			}
			while(head &&(head>=tail ||  rate(q[head-1],q[head]) > 2*num[j] )){
				head--;
			}
			dp[iter][j]=dp[iter^1][q[head].idx]+pf(num[j]-num[q[head].idx+1]);
		}
	}
	printf("%lld",dp[iter][n]);
	
}	
	
	
}jsk;
