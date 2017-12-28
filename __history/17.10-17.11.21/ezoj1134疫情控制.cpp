using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>
#include<cstring>

struct Edge{
	int dst,val;
	bool friend operator < (const Edge &a,const Edge &b){
		return a.val<b.val;
	}	
};
struct Army{
	int home;
	long long rem;
	bool friend operator < (const Army &a,const Army &b){
		return a.rem<b.rem;
	}
};
vector<Edge>son[50005];
struct _Main{
	long long sum;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}	
	void inline add (int a,int b,int c){
		son[a].push_back((Edge){b,c});
	}
	Army cap[50005];
	int capidx;
	int pos[50005];
	int n,m;
	~_Main(){
		fclose(stdout);
	}
	
	int fa[50005][16];
	int dis[50005][16];
	bool occupy[50005];
	void dfs(int nd=1,int from=1){
		fa[nd][0]=from;
		int i,I;
		for(I=1;I<=15;I++){
			fa[nd][I]=fa[fa[nd][I-1]][I-1];
			dis[nd][I]=dis[fa[nd][I-1]][I-1]+dis[nd][I-1];
		}
		for(i=0;i<son[nd].size();i++){
			if(son[nd][i].dst!=from){
				dis[son[nd][i].dst][0]=son[nd][i].val;
				dfs(son[nd][i].dst,nd);
			}
		}
	}
	bool isoccupy(int nd=1,int from=1){
		if(occupy[nd])return true;
		int i;occupy[nd]=1;
		for(i=0;i<son[nd].size();i++)if(son[nd][i].dst!=from){
			occupy[nd]&=isoccupy(son[nd][i].dst,nd);
		}
		if(son[nd].size()==1){
			return occupy[nd]=false;
		}else{
			return occupy[nd];
		}
	}
	
	bool run(long long mx){
		int nd;
		int i,j,k;int I;
		long long rem;
		capidx=0;
		memset(occupy,0,sizeof(occupy));
		for(i=0;i<m;i++){
			nd=pos[i];rem=mx;
			for(I=15;I>=0;I--){
				if(fa[nd][I]!=1 &&dis[nd][I]<=rem){
					rem-=dis[nd][I];
					nd=fa[nd][I];
				}
			}
			if(fa[nd][0]==1 && dis[nd][0]<=rem){
				cap[capidx++]=(Army){nd,rem-dis[nd][0]};
			}else{
				occupy[nd]=1;
			}
		}
		sort(cap,cap+capidx);
		isoccupy();
		j=0;
		for(i=0;i<capidx;i++){
			while(j<son[1].size() && occupy[son[1][j].dst])j++;
			if(j>=son[1].size())return true;
			if(!occupy[cap[i].home]&&cap[i].home!=1){
				occupy[cap[i].home]=1;
			}else if(cap[i].rem>=son[1][j].val){
				occupy[son[1][j].dst]=1;
			}
		}
		while(j<son[1].size() && occupy[son[1][j].dst])j++;
		if(j>=son[1].size())return true;
	/*	printf("mid=%d\n",mx);
		for(j=0;j<son[1].size();j++){
			if(!occupy[son[1][j].dst]){
				printf("!occupy(%d)\n",son[1][j].dst);
			}
		}*/
		return false;
	}
	_Main(){
		int i,j,k;
		int a,b,c;
		read(n);
		for(i=1;i<=n-1;i++){
			read(a);read(b);read(c);
			sum+=c;
			add(a,b,c);add(b,a,c);
		}
		read(m);
		if(m<son[1].size()){
			printf("-1");
			return;
		}
		for(i=0;i<m;i++){
			read(pos[i]);
		}
		sort(son[1].begin(),son[1].end());
		dfs();
		long long l=0,r=sum,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(run(mid)){
				r=mid;
			}else{
				l=mid+1;
			}	
		}
		printf("%lld",l);
	}

	
	
	
}ezoj1134;
