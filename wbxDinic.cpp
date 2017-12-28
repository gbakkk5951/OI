#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
long long dis[210][210],l,r,mid;
int ceng[410],n,m,st[210],ed[210],val[410][410],inf=1061109567;
queue<int>q;
int dfs(int pos,int liu){
	if(pos==n*2+1) return liu;
	int tmp,ret=0;
	for(int i=1;i<=n*2+1;i++){
		if(val[pos][i]>0&&ceng[i]==ceng[pos]+1){
			tmp=dfs(i,min(liu,val[pos][i]));
			if(tmp){
				ret+=tmp;
				liu-=tmp;
				val[pos][i]-=tmp;
				val[i][pos]+=tmp;
			}
			else ceng[i]=-1;
			if(liu==0) break;
		}
	}
	return ret;
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	int i,j,k,a,b,t,p,c,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&st[i],&ed[i]),p+=st[i];
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&t);
		dis[a][b]=min(dis[a][b],(long long)t);
		dis[b][a]=dis[a][b];
		r+=t;
	}
	for(i=1;i<=n;i++) dis[i][i]=0ll;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i!=j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(l<r){
		mid=(l+r)/2;
		memset(val,0,sizeof(val));
		for(i=1;i<=n;i++) val[0][i]=st[i],val[n+i][n*2+1]=ed[i],val[i][n+i]=inf;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(dis[i][j]<=mid) val[i][j+n]=inf;
		ans=0;
		do{
			memset(ceng,0,sizeof(ceng));
			ceng[0]=1;
			q.push(0);
			while(!q.empty()){
				t=q.front();
				q.pop();
				for(i=1;i<=n*2+1;i++){
					if(val[t][i]>0&&ceng[i]==0){
						ceng[i]=ceng[t]+1;
						q.push(i);
					}
				}
			}
			if(ceng[n*2+1]==0) break;
			c=dfs(0,inf);
			ans+=c;
		}while(c);
		if(ans==p) r=mid;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}

