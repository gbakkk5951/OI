#include<cstdio>
#include<algorithm>
using std::stable_sort;
using std::lower_bound;
struct _Main{
	struct statue{
	short h,w,num;
	bool friend operator < (statue a,statue b){
		if(a.h<b.h)return true;
		if(a.h>b.h)return false;
		if(a.w<b.w)return true;
		return false;
	}
	}ins[10000];
int n;
int abs(int in){
	return (in>>31)^((in>>31)+in);
}
int read(){
	char f=1,t;int ans=0;
	while((t=getchar())<'0'||t>'9'){if(t=='-')f=-1;}
	do{ans*=10;ans+=t-'0';}while((t=getchar())<='9'&&t>='0');
	return ans;
}
_Main(){
	int i;
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		ins[i].h=read();ins[i].w=read();
		ins[i].num=i;
	}
	stable_sort(ins,ins+n);
	for(i=0;i<n;i++){
		sum+=abs(ins[i].num-i);
	}
	printf("%d",sum);
}

}instance;int main(){} 
