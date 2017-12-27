using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
int w[1005];
int dp[1003][1003];
struct point{
	double x,y;int idx;
}data[1005];

struct Queue{
int head,tail;	
double inline rate(const point &a,const point & b){
	return (a.y-b.y)/(a.x-b.x);
}

void insert(point num){
	while(tail-1>head && rate(num,data[tail-1])<rate(data[tail-1],data[tail-2])){
		tail--;
	}data[tail++]=num;
}
void clear(){
	head=tail=0;
}
void move(int r){
	while(head+1<tail && rate(data[head],data[head+1] )< r){
		head++;
	}
	while(head>=tail || (head&&rate(data[head],data[head-1] )>r) ){
		head--;
	}
}
int inline getans(int r){
	move(r);
	return data[head].idx;
}
	
}q;

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
int n,m;


double inline pf(double a){
	return a*a;
}
long long dp[2][1005];
long long sum[1005],S[1005];
_Main(){
	read(n);read(m);
	int i,j,k;int iter=0;int temp;
	for(i=1;i<=n;i++){
		read(w[i]);sum[i]=sum[i-1]+w[i];
		S[i]=S[i-1]+w[i]*sum[i-1];
		dp[iter][i]=S[i];
		q.insert((point){(double)sum[i],(double)dp[iter][i]+pf(sum[i])-S[i],i});
	}
	for(i=1;i<=m;i++){
		iter^=1;
		for(j=i+1;j<=n;j++){
			q.insert((point){(double)sum[j-1],(double)dp[iter^1][j-1]+pf(sum[j-1])-S[j-1],j-1});
			temp=q.getans(sum[j]);
			dp[iter][j]=dp[iter^1][temp]+S[j]-S[temp]-(sum[j]-sum[temp])*sum[temp];
		}
		q.clear();
	}
	printf("%lld",dp[iter][n]);
}	
	
	
	
	
	
}jsk;
