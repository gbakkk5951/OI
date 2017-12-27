using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>

struct st_seg{
	long long l,r,val;
	bool friend operator < (st_seg a,st_seg b){
		return a.r<b.r;
	}
}seg[1000010];

struct _Main{
long long inline abs(long long a){
	return a>>63^((a>>63)+a);
}	
long long inline max(long long a,long long b){
	return (a+b+abs(a-b))>>1;
}


long long read(long long &ans){
	char t;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while( isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
}
int erfen(int r,long long val){
	int l=0,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(seg[mid].r<=val ){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	if(seg[l].r<=val){
		return l+1;
	}else{
		return l;
	}
}

long long dp[1000010];
long long n;
_Main(){
	int i,j,k;
	read(n);
	for(i=0;i<n;i++){
		read(seg[i].l  );
		read(seg[i].r  );
		read(seg[i].val);
	}
	sort(seg,seg+n);
	dp[0]=seg[0].val;
	for(i=0;i<n;i++){
		k=erfen(i-1,seg[i].l);
		if(k){
			dp[i]=max(dp[i],dp[k-1]+seg[i].val);
		}
		dp[i+1]=max(dp[i],seg[i+1].val);
	}
	printf("%lld",dp[n-1]);
}
	
	
	
	
	
	
	
	
}cdvs3037;
