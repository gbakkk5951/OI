#include<cstdio>
#include<cmath>
#include<bitset>
using std::bitset;
bitset<5000010>vis;
struct _Main{
int l,r;
int inline max(int a,int b){
	return a>b?a:b;
}
int inline min(int a,int b){
	return a<b?a:b;
}
int ans;
_Main(){
	scanf("%d%d",&l,&r);		
	ans=r-max(l,2)+1;
	int i,j,g;
	g=sqrt(r)+2;
	for(i=2;i<g;i++){
		if(!vis[i]){
			for(j=i+i;j<l;j+=i){
				vis[j]=true;
			}
			for(;j<=r;j+=i){
				if(!vis[j]){
					vis[j]=true;
					ans--;									
				}
			}
		}
	}
	printf("%d",ans);

	

}
	
}cdvs1453;int main(){}
