#include<cstdio>
#include<algorithm>
using namespace std;
int num[30010];
int rel[30010];
int fa[30010];
int t;
int find(int x){
	if(fa[x]==x)
	return x;
	int t=find(fa[x]);
	rel[x]+=rel[fa[x]];
	fa[x]=t;
	return t;
	
}


int main (){
	int i,j,k;
	char cmd[10];
	for(i=1;i<=30000;i++){
		num[i]=1;
		fa[i]=i;
		
	}
	
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s%d%d",cmd,&j,&k);

		
		if(cmd[0]=='M'){
			int fj=find(j),fk=find(k);
			fa[fj]=fk;
			rel[fj]=num[fk];
			num[fk]+=num[fj];

		}else{
			int fj=find(j),fk=find(k);
			if(fj==fk){

				int t;
				t=max(rel[j]-rel[k]-1,t=rel[k]-rel[j]-1);
				printf("%d\n",t);
			}else printf("-1\n");
			
		}
		
	}
	
}
