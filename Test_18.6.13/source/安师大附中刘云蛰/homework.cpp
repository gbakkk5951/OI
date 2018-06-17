#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
typedef double db;
void solve(int n){
	db ans,tp;
	ans=0;tp=1;
	for(int i=1;i<=20;i++){
		tp/=i+n;
		if(i&1) ans+=tp;
		else ans-=tp;
	}
	printf("%.4lf\n",ans);
}
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int i,n;
	scanf("%d",&n);
	solve(n);
	return 0;
}
