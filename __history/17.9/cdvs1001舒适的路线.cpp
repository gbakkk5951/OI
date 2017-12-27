using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<bitset>
int edge[5005];
int to[10005];
int en;
int val[10005];
int head[502];
int nxt[10005];
int idx;
int base;
bitset<505>vis;
int mx;
int s,t;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
		
	}


void inline add(int a,int b,int c){
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	to[idx]=b;
	val[idx]=c;
}

bool islink(int nd,int mx,int mn){
	int i;
	if(nd==t)return true;
	if(nd==s)vis.reset();
	vis[nd]=1;
	for(i=head[nd];i;i=nxt[i])if(val[i]<=mx &&val[i]>=mn &&!vis[to[i]]){
		if(islink(to[i],mx,mn)){
			return true;
		}
	}return false;
}

struct _Main{

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int n,m;
int fz,fm;
_Main(){
	fz=-1;
	int a,b,c;int i,j,k;int l,r;int mid;
	read(n);read(m);
	for(i=0;i<m;i++){
		read(a);read(b);read(c);
		add(a,b,c);
		add(b,a,c);
		edge[i]=c;
	}sort(edge,edge+m);en=unique(edge,edge+m)-edge;
	read(s);read(t);
	if(!islink(s,edge[en-1],edge[0])){
		printf("IMPOSSIBLE");
		return;
	}
	for(i=0;i<en;i++){
		l=i;r=en-1;
		while(l<r){
			mid=(l+r)>>1;
			if(islink(s,edge[mid],edge[i])){
				if(fz==-1 ||(double)edge[mid]/edge[i] < (double)fz/fm){
					fz=edge[mid];fm=edge[i];
				}
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		mid=(l+r)>>1;
		if(islink(s,edge[mid],edge[i])){
			if(fz==-1 ||(double)edge[mid]/edge[i] < (double)fz/fm){
				fz=edge[mid];fm=edge[i];
			}
		}else if(r==en-1){
			break;
		}
	}
	a=gcd(fz,fm);
	fz/=a;fm/=a;
	if(fm!=1)
	printf("%d/%d",fz,fm);
	else printf("%d",fz);
}
	
	
	
}cdvs1001;
