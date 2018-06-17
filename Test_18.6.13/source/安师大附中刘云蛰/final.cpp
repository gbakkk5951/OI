#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=2005;
int a[N],ans[N][N];
int x,y;
int exgcd(int a,int b){
	if(b==0){x=1;y=0;return a;}
	int m=exgcd(b,a%b),t=x;
	x=y;
	y=t-a/b*y;
	return m;
}
int n;
void out(int u,int v,int x,int y){
	int i,j=0;
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++) ans[1][i]=a[i];
	ans[2][u]=y;ans[2][v]=x;
	for(i=3;i<=n;i++){
		j++;
		while(j==u||j==v) j++;
		ans[i][j]=1;
	}
	if(u-1+v-2&1) ans[2][u]=-y,ans[2][v]=-x;
	for(i=1;i<=n;i++,printf("\n"))
		for(j=1;j<=n;j++) printf("%d ",ans[i][j]);
}
int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	int i,j,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			d=exgcd(a[i],a[j]);
			if(d==-1){x=-x,y=-y;d=1;}
			if(d==1){
				while(x>=-2000){
					if(a[j]>0) x-=a[j],y+=a[i];
					else x+=a[j],y-=a[i];
				}
				while(x<-2000){
					if(a[j]>0) x+=a[j],y-=a[i];
					else x-=a[j],y+=a[i];
				}
				while(x<=2000){
					if(-2000<=y&&y<=2000){out(i,j,x,-y);return 0;}
					if(a[j]>0) x+=a[j],y-=a[i];
					else x-=a[j],y+=a[i];
				}
			}
		}
	printf("no solution\n");
	return 0;
}
