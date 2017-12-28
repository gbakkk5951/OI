using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
const long long mod=1e9+7;
struct _Main{

long long below[100010][4];
long long above[100010][4];
int fa[100010][17];
long long dis[100010][17];
long long val[200010];
long long inc_to_fa[100010][4];
int h[100010];
int head[100010],nxt[200010],to[200010];

int eidx;
void inline addedge(int a,int b,int c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	val[eidx]=c;
}
long long inline pf(long long a){
	return a*a%mod;
}
long long inline lf(long long a){
	return a*a%mod*a%mod;
}
long long add(long long *pos,int pow,long long val){
	switch(pow){
		case 0:{
			return pos[0];
			break;
		}
		case 1:{
			return (pos[1]+pos[0]*val)%mod;
			break;
		}		
		case 2:{
			return (pos[2]+2*pos[1]*val+pos[0]*pf(val))%mod;
			break;
		}	
		case 3:{
			return (pos[3]+3*val*pos[2]+3*pf(val)*pos[1]+pos[0]*lf(val))%mod;
			break;
		}			
	}
	
}
void dfs0(int nd=1,int from=1){
	fa[nd][0]=from;
	int i,I,j;
	for(I=1;I<=16;I++){
		fa[nd][I]=fa[fa[nd][I-1]][I-1];
		(dis[nd][I]=dis[fa[nd][I-1]][I-1]+dis[nd][I-1])%=mod;
	}
	for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
		h[to[i]]=h[nd]+1;
		dis[to[i]][0]=val[i];
		dfs0(to[i],nd);
		for(j=0;j<4;j++){
			(below[nd][j]+=inc_to_fa[to[i]][j]=add(below[to[i]],j,val[i]))%=mod;
		}
	}
	below[nd][0]++;
}

void dfs1(int nd=1,int from=0){
	int i;
	long long tmp[4];
	memcpy(tmp,above[from],sizeof(tmp));
	
	for(i=0;i<4;i++){
		tmp[i]=above[from][i]+below[from][i]-inc_to_fa[nd][i];
	}
	for(i=0;i<4;i++){
		above[nd][i]=add(tmp,i,dis[nd][0]);
	}
	for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
		dfs1(to[i],nd);
	}	
}

template<typename Type>
void read(Type &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;a+=t-'0';
	}
}	
int n,m;
long long len,res;
_Main(){
	int I;
	int i,j,k;
	int a,b,c;
	int x,y;
	read(n);
	for(i=1;i<=n-1;i++){
		read(a);read(b);read(c);
		addedge(a,b,c);addedge(b,a,c);
	}
	dfs0();
	dfs1();
	read(m);
	for(i=0;i<m;i++){
		len=0;
		read(x);read(y);
		a=x;b=y;
		if(h[a]<h[b])swap(a,b);
		for(I=16;I>=0;I--){
			if(h[fa[a][I]]>=h[b]){
				(len+=dis[a][I])%=mod;
				a=fa[a][I];
			}
		}
		
		if(a!=b){
			for(I=16;I>=0;I--){
				if(fa[a][I]!=fa[b][I]){
					(len+=dis[a][I]+dis[b][I])%=mod;
					a=fa[a][I];b=fa[b][I];
				}
			}
			(len+=dis[a][0]+dis[b][0])%=mod;
		}
		if(a==b && h[x]>=h[y]){
			res=(below[x][3]+above[x][3]-2*add(above[y],3,len))%mod;
		}else{
			res=(2*add(below[y],3,len)-below[x][3]-above[x][3])%mod;
		}
		printf("%lld\n",(res%mod+mod)%mod);
		
	}
	
	
}
	
}ezoj1200;
