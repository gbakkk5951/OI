using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}	
int in[200010],to[200010];
bool vis[200010];	
int n;

int ans;
_Main(){
	
	int i;int nd;int len;
	read(n);ans=n;
	for(i=1;i<=n;i++){
		read(to[i]);in[to[i]]++;
	}
	for(i=1;i<=n;i++)if(in[i]==0 && !vis[i]){
		nd=i;
		do{
			vis[nd]=1;
			in[nd=to[nd]]--;
		}while(in[nd]==0);
	}
	for(i=1;i<=n;i++)if(!vis[i]){
		for(nd=i,len=0;!vis[nd];nd=to[nd],len++){
			vis[nd]=true;
		}
		ans=min(ans,len);
	}
	printf("%d",ans);
}	
		
}info;

