#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
long long x[1010][1010],y[1010][1010],c[1010][1010],val[500010],r[1010],cc[1010],yy[1010],xx[1010],inf=4611686018427387904ll;
int head[40010],nxt[500010],whr[500010],ceng[40010],id[210][210],nn,tot=0,cnt=2;
void add(int a,int b,long long v1,long long v2){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	val[cnt]=v1;
	head[a]=cnt++;
	nxt[cnt]=head[b];
	whr[cnt]=a;
	val[cnt]=v2;
	head[b]=cnt++;
	return;
}
queue<int>q;
long long dfs(int pos,long long liu){
	if(pos==nn) return liu;
	long long tmp,ret=0ll;
	for(int i=head[pos];i;i=nxt[i]){
		if(val[i]>0ll&&ceng[whr[i]]==ceng[pos]+1){
			tmp=dfs(whr[i],min(liu,val[i]));
			if(tmp){
				ret+=tmp;
				liu-=tmp;
				val[i]-=tmp;
				val[i^1]+=tmp;
			}
			else ceng[whr[i]]=-1;
			if(liu==0ll) break;
		}
	}
	return ret;
}
int main()
{
	freopen("data16.in", "r", stdin);
	
////	freopen("edge_std.in", "w", stdout);
	srand(32142664);
	ios::sync_with_stdio(false);
	int n,m,i,j,t,a,b;
	long long in,ans=0ll;
	bool flag=true;
	for(i=1;i<=1000;i++) r[i]=rand();
	cin>>t>>n>>m;nn=n*n+1;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) id[i][j]=++tot;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>in,ans+=in;
			if((i+j)%2==0) add(0,id[i][j],in,0ll);
			else add(id[i][j],nn,in,0ll);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>in,ans+=in;
			if((i+j)%2==1) add(0,id[i][j],in,0ll);
			else add(id[i][j],nn,in,0ll);
		}
	}
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) cin>>x[i][j];
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) cin>>y[i][j];
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) cin>>c[i][j];
	for(i=1;i<=m;i++){cc[i]=0ll;for(j=1;j<=m;j++) cc[i]+=c[i][j]*r[j];}
	for(i=1;i<=m;i++){yy[i]=0ll;for(j=1;j<=m;j++) yy[i]+=y[i][j]*r[j];}
	for(i=1;i<=m;i++){xx[i]=0ll;for(j=1;j<=m;j++) xx[i]+=x[i][j]*yy[j];}
	for(i=1;i<=m;i++) if(xx[i]!=cc[i]) flag=false;
	if (flag == false) printf("He\n");
	if(flag==false) for(i=1;i<=m;i++) for(j=1;j<=m;j++) c[i][j]=x[i][j]*y[i][j];
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) c[i][j]%=1000000001ll;
	cin>>a>>b;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i-1>=1){
				ans+=c[i+a-1][j+b-1]+c[i+a-2][j+b-1];
				add(id[i][j],id[i-1][j],c[i+a-1][j+b-1]+c[i+a-2][j+b-1],c[i+a-1][j+b-1]+c[i+a-2][j+b-1]);
			}
			if(j-1>=1){
				ans+=c[i+a-1][j+b-1]+c[i+a-1][j+b-2];
				add(id[i][j],id[i][j-1],c[i+a-1][j+b-1]+c[i+a-1][j+b-2],c[i+a-1][j+b-1]+c[i+a-1][j+b-2]);
			}
		}
	}
	do{
		memset(ceng,0,sizeof(ceng));
		q.push(0);ceng[0]=1;
		while(!q.empty()){
			t=q.front();
			q.pop();
			for(i=head[t];i;i=nxt[i]){
				if(ceng[whr[i]]==0&&val[i]>0){
					ceng[whr[i]]=ceng[t]+1;
					q.push(whr[i]);
				}
			}
		}
		if(ceng[nn]==0) break;
		in=dfs(0,inf);
		ans-=in;
	}while(in);
	printf("%lld", ans);
//	cout<<ans<<endl;
	return 0;
}
