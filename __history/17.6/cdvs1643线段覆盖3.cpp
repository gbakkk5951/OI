using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>

struct st_seg{
	int  l,r,val;
	bool friend operator < (st_seg a,st_seg b){
		return a.r<b.r;
	}
}seg[1000010];

struct _Main{
int  inline abs(int  a){
	return a>>31^((a>>31)+a);
}	
int  inline max(int  a,int  b){
	return (a+b+abs(a-b))>>1;
}


void  read(int  &ans){
	char t;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while( isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
}
int erfen(int r,int  val){
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

int  dp[1000010];
int  n;
_Main(){
	int i,j,k;
	read(n);
	for(i=0;i<n;i++){
///		printf("[%d]",i);
		read(seg[i].l  );
		read(seg[i].r  );
		
	}
	sort(seg,seg+n);
	dp[0]=1;
	for(i=0;i<n;i++){
		k=erfen(i-1,seg[i].l);
		if(k){
			dp[i]=max(dp[i],dp[k-1]+1);
		}
		dp[i+1]=dp[i];
	}
	printf("%d",dp[n-1]);
}
	
	
	
	
	
	
	
	
}cdvs1643;
