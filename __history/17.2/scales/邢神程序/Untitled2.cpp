#include<bits/stdc++.h>
using  namespace std;
const int inf=1061109567;
int way[310][310],n,p,q;
int main()
{
	scanf("%d%d%d",&n,&p,&q);
	memset(way,0x3f,sizeof(way));
	for(int i=1;i<=n;i++) way[i][i]=0;
	for(int i=1,k,a,b;i<=p;i++)
	{
		scanf("%d%d%d",&k,&a,&b);
		if(k==1) way[b][a]=0;
		else if(k==2) way[a][b]=0;
		else way[a][b]=way[b][a]=0;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) way[i][j]=min(way[i][j],way[i][k]+way[k][j]);
	for(int i=1,a,b;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		//cout<<way[a][b]<<"	"<<way[b][a]<<endl;
		if(way[a][b]!=inf&&way[b][a]==inf) printf("Right\n");
		else if(way[b][a]!=inf&&way[a][b]==inf) printf("Left\n");
		else if(way[b][a]!=inf&&way[a][b]!=inf) printf("Balance\n");
		else printf("Unknown\n");
	}
	return 0;
}
