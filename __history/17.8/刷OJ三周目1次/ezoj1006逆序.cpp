int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<cstring>
#include<queue>
#include<algorithm>
const long long p=1e9+7;
#define mod p
struct _Main{
queue<int>q;
int in[605];int v[605];long long way[605];


long long fastpower(long long base,long long pow,long long mod=p){
	long long ans=1;
	while(pow){
		if(pow & 1){
			ans=ans*base%p;
		}
		base=base*base%p;
		pow>>=1;
	}
	return ans;
}
void floodfill(int s){

	int i;
	for(i=head[s];i;i=nxt[i]){
		in[t[i]]++;
		if(!v[t[i]]){
			v[t[i]]=1;
			floodfill(t[i]);
		}
	}
}
void getway(int s,int mod = p){
	int i;
	memset(in,0,sizeof(in));
	memset(v,0,sizeof(v));
	memset(way,0,sizeof(way));
	floodfill(source[s]);
	way[source[s]]=1;
	q.push(source[s]);
	
	while(!q.empty() ){
		for(i=head[q.front()];i;i=nxt[i]){
			in[t[i]]--;
			way[t[i]]+=way[q.front()];
			way[t[i]]%=mod;
			if(in[t[i]]==0){
				q.push(t[i]); 
			}
		}
		q.pop();
	}

	for(i=0;i<sn;i++){
		matrix[s][i]=way[gather[i]];
	}
	
}
long long *row[305];
int swp;
bool gause(int size){
	swp=1;
	long long div;long long times;
	int i,j,k;
	for(i=0;i<size;i++){
		row[i]=matrix[i];
	}
	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if(row[j][i])break;
		}if(j==size){
			return false;
		}
		if(i!=j){
			swap(row[j],row[i]);
			swp*=-1;
		}
		div=fastpower(row[i][i],p-2);

		for(j=i+1;j<size;j++)if(row[j][i]){
			times=div*row[j][i]%mod;
			for(k=i;k<size;k++){
				row[j][k]=( (row[j][k] - row[i][k]*times ) %mod +mod ) %mod;
			}
		}
	}
	return true;
}

int n,m,sn;
int source[305];
int gather[305];
int nxt[360010];
int t[360010];
int head[605];
int idx;

void inline add(int a,int b){
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	t[idx]=b;
}
long long matrix[305][305];
_Main(){
	int i,j;int a,b,c;long long ans=1;
	scanf("%d%d%d",&n,&m,&sn);
	for(i=0;i<sn;i++){
		scanf("%d",source+i);
	}
	for(i=0;i<sn;i++){
		scanf("%d",gather+i);
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(i=0;i<sn;i++){ 
		getway(i);
	}
	gause(sn);

	for(i=0;i<sn;i++){
		ans=ans*row[i][i]%p;
	}ans*=swp;
	ans=(ans%p+p)%p;
	printf("%lld",ans);
}
	
	
}reverse;
