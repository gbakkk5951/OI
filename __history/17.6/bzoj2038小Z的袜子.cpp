int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cmath>
int sq;
long long gcd(long long a,long long b){
	if(b){
		return gcd(b,a%b);
	}return a;
}

struct query{
	int l;int r;int order;int block;
	bool friend operator < (const query &a,const query &b){
		if(a.block < b.block ){
			return true;
		}else if( a.block > b.block ){
			return false;
		}
		return a.r<b.r;
	}
}list[50007]; 
struct _Main{
	
int read(){
	char t;
	int ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}
int n,q,tl,tr;
long long fz;
int num[50015];
int color[50010];
long long ans1[50011],ans2[50013];
void more(int &bound,int goal,char add){
	for(bound+=add;bound-add!=goal;bound+=add){
		fz-=(long long)num[color[bound]]*(num[color[bound]]-1);
		num[color[bound]]++;
		fz+=(long long)num[color[bound]]*(num[color[bound]]-1);
	}
	bound-=add;
}
void less(int &bound,int goal,char add){
	for(;bound!=goal;bound+=add){
		fz-=(long long)num[color[bound]]*(num[color[bound]]-1);
		num[color[bound]]--;
		fz+=(long long)(num[color[bound]])*(num[color[bound]]-1);
	}
}

_Main(){
	int i;
	long long j;
	long long k,a1,a2;
	n=read();
	sq=sqrt(n);
	q=read();
	for(i=1;i<=n;i++){
		color[i]=read();
	}
	for(i=0;i<q;i++){
		list[i].l=read();
		list[i].block=list[i].l/sq;
		list[i].order =i;
		list[i].r=read();
	}
	sort(list,list+q);
	tl=1,tr=1;
	fz=0;
	num[color[1]]++;
	for(i=0;i<q;i++){
		if(list[i].l<tl){
			more(tl,list[i].l,-1);
		}else{
			less(tl,list[i].l,+1);
		}
		
		if(list[i].r>tr){
			more(tr,list[i].r,+1);
		}else{
			less(tr,list[i].r,-1);
		}
		k=list[i].order;
		a1=fz;
		a2=(long long)(tr-tl+1)*(tr-tl);
		if(a2==0){
			a2=1;
		}
		j=gcd(a1,a2);
		a1/=j;
		a2/=j;
		ans1[k]=a1;
		ans2[k]=a2;
	}
	for(i=0;i<q;i++){
		printf("%lld/%lld\n",ans1[i],ans2[i]);
	}
	
}
}bzoj2038;
