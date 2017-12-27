using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
const int base=1024;

struct st_seg{
	int l,r,val;
	bool friend operator < (st_seg a,st_seg b){
		return a.r<b.r;
	}
}seg[1010];
struct _Main{
	
int read(){
	int ans;
	char t,f=1;
	while(!isdigit(t=getchar())){
		if(t=='-'){
			f=-1;
		}
	}
	ans=t-'0';
	while( isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}return ans*f;
}
int dp[1010];
int n;
_Main(){
	int i,j,k;
	n=read();
	for(i=0;i<n;i++){
		seg[i].l  =read();
		seg[i].r  =read();
		seg[i].val=read();
	}
	sort(seg,seg+n);
	st_seg temp;
	temp.l=0;
	for(i=0;i<n;i++){
		temp.r=seg[i].l;
		k=upper_bound(seg,seg+i,temp)-seg;
		k--;
		if(i) dp[i]=dp[i-1];
		if(k>=0){
			dp[i]=max(dp[i],dp[k]+seg[i].val);
		}else{
			dp[i]=max(dp[i],seg[i].val);
		}
	}
	printf("%d",dp[n-1]);
}	
	
	
	
	
	
	
	
	
}cdvs3027;
