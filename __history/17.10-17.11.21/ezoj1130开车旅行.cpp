using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
const double eps=1e-6;
struct City{
	long long idx;
	long long h;
	bool friend operator < (const City &a,const City &b){
		return a.h<b.h;
	}
}city[100010];
set<City>tree;
struct Comp{
	City mid;
	void inline setmid(City a){
		mid=a;
	}
	bool operator () (City a,City b){
		return abs(a.h-mid.h)!=abs(b.h-mid.h)?abs(a.h-mid.h)<abs(b.h-mid.h):a.h<b.h;
	}
	void operator () (City a){
		setmid(a);
	}	
}cmp;

struct Dis{
	long long a,b;
	long long sum;
	int dst;
	void inline clear(){
		a=b=sum=dst=0;
	}
	Dis(){
		a=b=sum=dst=0;
	}
	inline Dis friend operator + (const Dis &a,const Dis &b){
		Dis ret;ret.a=a.a+b.a;ret.b=a.b+b.b;ret.sum=a.sum+b.sum;ret.dst=b.dst;
		return ret;
	}
}dp[100010][18][2];
int n,m;
struct _Main{
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}a*=f;
	}
long long h[100010];

Dis getdis(long long limit,int beg ){
	long long rem=limit;
	Dis ans;ans.dst=beg;
	int i;
	for(i=16;i>=0;i--){
		if(rem>=dp[ans.dst][i][0].sum){
			rem-=dp[ans.dst][i][0].sum;
			ans=ans+dp[ans.dst][i][0];
		}
	}
	return ans;
}
void preproc(){
	int i,j;int size;
	int I;
	City arr[4];
	set<City>::iterator it1,it2;
	for(i=n;i>=1;i--){
		size=0;
		tree.insert(city[i]);
		it1=it2=tree.find(city[i]);
		for(j=0;j<2;j++){
			if(it1==tree.begin())break;
			it1--;
			arr[size++]=*it1;
		}
		for(j=0;j<2;j++){
			it2++;
			if(it2==tree.end())break;
			arr[size++]=*it2;
		}
		cmp(city[i]);
		sort(arr,arr+size,cmp);
		if(size>=1){
			dp[i][0][1].sum=dp[i][0][1].b=abs(city[i].h-arr[0].h);
			dp[i][0][1].dst=arr[0].idx;
		}
		if(size>=2){
			dp[i][0][0].sum=dp[i][0][0].a=abs(city[i].h-arr[1].h);
			dp[i][0][0].dst=arr[1].idx;			
		}
	}
	for(I=1;I<=16;I++){
		if(I==1){
			for(i=1;i<=n;i++){
				dp[i][1][0]=dp[i][0][0]+dp[dp[i][0][0].dst][0][1];
			}
		}else{
			for(i=1;i<=n;i++){
				dp[i][I][0]=dp[i][I-1][0]+dp[dp[i][I-1][0].dst][I-1][0];
			}
		}
	}
	
}
_Main(){
	Dis temp;
	double rate=1e12;
	double rr;
	int i;long long a,b;
	read(n);int dis;int ans=n;
	for(i=1;i<=n;i++){
		read(city[i].h);
		city[i].idx=i;
	}
	preproc();
	read(dis);
	for(i=1;i<=n;i++){
		temp=getdis(dis,i);
		if(temp.b!=0){
			rr=(double)temp.a/temp.b;
		}else{
			continue;
		}
		if((double)rr<rate || (rr<rate+eps && city[i].h>city[ans].h)){
			rate=rr;
			ans=i;
		}
	}
	printf("%d\n",ans);
	read(m);
	for(i=0;i<m;i++){
		read(a);read(b);
		temp=getdis(b,a);
		printf("%lld %lld\n",temp.a,temp.b);
	}
	
	
} 

	
}ezoj1130;
