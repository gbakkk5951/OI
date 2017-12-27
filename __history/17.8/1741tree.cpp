using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}

struct node{
	int len,fa;
	struct facmp{
		bool  operator () (node a,node b){
			return a.fa==b.fa?a.len<b.len:a.fa<b.fa;
		}	
	};	
	struct lencmp{
		bool  operator () (node a,node b){
			return a.len<b.len;
		}
	};	

	
}arr[10005];


int nidx;	
struct _Main{
int n;	
int ans;
int cnt;
bool del[10005];
int result[10005];
int ms[10005];
int size[10005];
int nxt[20005];int to[20005];int head[10005];int len[20005];	
void inline add(int a,int b,int c){
	cnt++;
	nxt[cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	len[cnt]=c;
}
void inline ini(){
	memset(head,0,sizeof(head));
	cnt=0;memset(del,0,sizeof(del));ans=0;memset(result,255,sizeof(result));
	nidx=0;
}
int mx;
int gcnt;
_Main(){
	int i;int a,b,c;
	while(1){
		read(n);read(mx);
		if(n==0 && mx==0)return ;
		ini();
		for(i=0;i<n-1;i++){
			read(a);read(b);read(c);
			add(a,b,c);add(b,a,c);
		}
		result[1]=-1;
		getsize(1,0);
		getms(1,0,1);
		query(result[1]); 
		printf("%d\n",ans);
	}
}
void getms(int nd,int from,int root){
	ms[nd]=0;
	int I;
	for(I=head[nd];I;I=nxt[I]) if(to[I]!=from && !del[to[I]]){
		ms[nd]=max(size[to[I]],ms[nd]);
		getms(to[I],nd,root);
	}
	ms[nd]=max(ms[nd],size[root]-size[nd]);
	if(result[root]==-1 || ms[nd]<ms[result[root]]){
		result[root]=nd;
	}
}
void getsize(int nd,int from){
	int I;
	size[nd]=0;
	for(I=head[nd];I;I=nxt[I]) if(!del[to[I]] && to[I]!=from){
		getsize(to[I],nd);
		size[nd]+=size[to[I]];
	}
	size[nd]++;
}	

void query(int nd){
	int i;
	int temp=ans;
	del[nd]=true;
	for(i=head[nd];i;i=nxt[i]) if(!del[to[i]]){
		dfs(to[i],nd,to[i],len[i]);
	}
	sort(arr,arr+nidx,node::lencmp());
	i=nidx-1;
	while(arr[i].len>mx && i>=0) i--;
	ans+=i+1;
	
	int j=nidx-1;int k;
	for(i=0;i<nidx-1;i++){
		while(arr[j].len+arr[i].len>mx && j>0)j--;
		if(j>i){
			ans+=j-i;
		}else{
			break;
		}
	}
	sort(arr,arr+nidx,node::facmp());
	int e;
	for(i=0;i<nidx;i=e){
		for(e=i+1;arr[e].fa==arr[e-1].fa && e<nidx;e++);
		j=e-1;
		for(k=i;k<e;k++){
			while(arr[j].len+arr[k].len>mx && j>i)j--;
			if(k<j){
				ans-=j-k;
			}else{
				break;
			}
		}
	}
	for(i=head[nd];i;i=nxt[i])if(!del[to[i]]){
		nidx=0;
		result[to[i]]=-1;
		getsize(to[i],nd);
		getms(to[i],nd,to[i]);
		query(result[to[i]]);
	}
}	
int dfs(int nd,int from,int fa,int l){
	arr[nidx].fa=fa;
	arr[nidx].len=l;
	nidx++;
	int i;
	for(i=head[nd];i;i=nxt[i]) if(!del[to[i]] && to[i]!=from){
		dfs(to[i],nd,fa,l+len[i]);
	}
}
	
	
}poj1741;	
	
