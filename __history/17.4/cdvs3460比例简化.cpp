#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int a,b,c;
	int ans1,ans2;
	double bili=1000;
	double d,e;
	scanf("%d%d%d",&a,&b,&c);
	e=(double)a/b;
	int i,j,k;
	for(i=1;i<=c;i++){
		for(j=1;j<=c;j++){
			if((d=(double)i/j-e)>=0&&d<bili){
				ans1=i;ans2=j;
				bili=d;
			}
		}
		
	}
	printf("%d %d",ans1,ans2);
}
