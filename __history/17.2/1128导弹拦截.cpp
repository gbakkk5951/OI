#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int x1,y1,x2,y2;
int ra1,ra2,rb1,rb2;
struct index{
	int d1,d2;
	friend bool operator < (index ia,index ib){
		return ia.d1 <ib.d1 ;
		
	}
}sz[100010];


int main(){
	int i,j,k;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&j,&k);
		sz[i].d1 =(j-x1)*(j-x1)+(k-y1)*(k-y1);
		sz[i].d2 =(j-x2)*(j-x2)+(k-y2)*(k-y2);
	}
	int mx=0;
	int ans=2147483647;
	sort(sz,sz+n);
	for(i=n-1;i>=0;i--){
		ans=min(ans,mx+sz[i].d1);
		mx=max(mx,sz[i].d2);
	}
	ans=min(ans,mx);
	printf("%d",ans);
}
