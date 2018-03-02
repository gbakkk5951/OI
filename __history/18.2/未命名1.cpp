

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int head[110],nxt[1010],whr[1010],val[1010],cst[1010],dis[110],pre[110],cnt=2,inf=1061109567;
bool inq[110];
void add(int a,int b,int v,int c){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	val[cnt]=v;
	cst[cnt]=c;
	head[a]=cnt++;
	nxt[cnt]=head[b];
	whr[cnt]=a;
	val[cnt]=0;
	cst[cnt]=-c;
	head[b]=cnt++;
}
queue<int>q;
int main()
{
	int n,i,t,ans=0,all,nn;
	scanf("%d",&n);nn=n+1;
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		all+=t;add(0,i,t,0);
		if(i!=1) add(i,i-1,inf,1);
		if(i!=n) add(i,i+1,inf,1);
	}all/=n;
	add(1,n,inf,1);add(n,1,inf,1);
	for(i=1;i<=n;i++) add(i,nn,all,0);
	while(1){
		memset(pre,-1,sizeof(pre));
		memset(dis,0x3f,sizeof(dis));
		memset(inq,false,sizeof(inq));
		q.push(0),inq[0]=true,dis[0]=0;
		while(!q.empty()){
			t=q.front();
			q.pop();
			inq[t]=false;
			for(i=head[t];i;i=nxt[i]){
				if(val[i]>0&&dis[whr[i]]>dis[t]+cst[i]){
					dis[whr[i]]=dis[t]+cst[i];
					pre[whr[i]]=i;
					if(inq[whr[i]]==false){
						inq[whr[i]]=true;
						q.push(whr[i]);
					}
				}
			}
		}
		if(pre[nn]==-1) break;
		t=inf;
		for(i=nn;i;i=whr[pre[i]^1]) t=min(t,val[pre[i]]);
		for(i=nn;i;i=whr[pre[i]^1]){
			val[pre[i]]-=t;
			val[pre[i]^1]+=t;
			ans+=cst[pre[i]]*t;
		}
	}
	printf("%d",ans);
}

