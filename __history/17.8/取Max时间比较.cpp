using namespace std;
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>

int inline abs(int a){
	return a>>31^((a>>31)+a);
}

int inline max(int a,int b){
	return (a+b+abs(a-b))>>1;
}
int ans;
void dfs(int a){
	if(a==10000)return;
	ans=max(a,ans);
	dfs(a+1);
}
int main(){
	float a,b;int i;
	a=clock();
	for(i=0;i<50000000;i++){
		ans=max(ans,i);
	}
	
	b=clock();
	printf("%f",b-a);
}
