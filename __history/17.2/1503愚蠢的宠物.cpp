#include<cstdio>
#include<vector>
#include<cmath>
#define lw(x) x&(-x)
using namespace std;
int st[1000010][22];
int h[1000010];
int mv1=0;
int mv2=0;
vector<int>kid[1000010];

int n;
int pa,pb;
int ans;
void dfs(int,int);
int main(){
	h[1]=0;
	int i,j,k,l;
	int in1,in2;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&in1,&in2);
		kid[in1].push_back(in2);
	}
	scanf("%d%d",&pa,&pb);
	if(pa==pb)
	{
		printf("%d",pa);
		return 0;
	}
	dfs(1,0);
	i=21;
	j=abs(h[pa]-h[pb]);
	for(k=22;k>=0;k--){
		if(1<<k<=j)
		{
		j-=1<<k;
		mv1+=1<<k;
		if(h[pa]>h[pb]){
			pa=st[pa][k];
		}else pb=st[pb][k];
		
		
		}
	}
	if(pa==pb)
	{
		printf("%d",pa);
		return 0;
	}
	
	
	int temp=0;
	
	while(i>=0){
		if(st[pa][i]==st[pb][i]){
			mv2=st[pa][i];
		}else{
			pa=st[pa][i];
			pb=st[pb][i];
		}
		i--;
		
		
	}
	
	printf("%d",mv2);
}

void dfs(int root,int from=0){
	int i,j,k,l;
	st[root][0]=from;
	h[root]=h[from]+1;
	for(i=1;i<22;i++){
		st[root][i]=st[st[root][i-1]][i-1];
	}
	for(i=0;i<kid[root].size();i++){
		
		dfs(kid[root][i],root);
	}
	
}

