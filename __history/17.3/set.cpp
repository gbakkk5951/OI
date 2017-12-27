#include<cstdio>
#include<set>

using namespace std;
set<int>tree;

int main(){
	int m,n,i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&j);
		tree.insert(j);
	}
	for(i=0;i<m;i++){
		scanf("%d",&j);
		if(tree.find(j)==tree.end()){
			printf("0 ");
		}else{
			printf("1 ");		
			
		}
	}
	
}
