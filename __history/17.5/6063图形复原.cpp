#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool v[60];
vector<int>e[55];
int way[60];

struct _Main{
int n;
_Main(){
	int i,t1,t2;
	scanf("%d",&n);
	while(scanf("%d%d",&t1,&t2)==2){
		e[t1].push_back(t2);
		e[t2].push_back(t1); 
//		printf("(%d %d)",t1,t2);
	}
	for(i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end() );
	}
	way[1]=1;
	v[1]=1;
	dfs(1,1);
	for(i=1;i<=n;i++){
		printf("%d ",way[i]);
	}
	
}
bool dfs(int node,int iter){
	if(iter==n){
		int i;
		for(i=0;i<e[node].size();i++){
			if(e[node][i]==1){
				return true;
			}
		}
		return false;
	}
	int i;
	
	for(i=0;i<e[node].size();i++){
		if(!v[e[node][i]]){
			v[e[node][i]]=1;
			way[iter+1]=e[node][i];
			if(dfs(e[node][i],iter+1)){
				return true;
			}
			v[e[node][i]]=0;			
		}
	}
	return false;
}
	
	
	
	
}cdvs6063;int main(){}
