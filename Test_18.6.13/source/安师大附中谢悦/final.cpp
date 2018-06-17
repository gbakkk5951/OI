#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
int a[10];

int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==2){
		for(int i=-2000;i<=2000;i++){
			int t=(i*a[1]-1)/a[2];
			if(i*a[1]-t*a[2]==1&&t>=-2000&&t<=2000){
				cout<<a[1]<<" "<<a[2]<<endl<<t<<" "<<i;
				return 0;
			} 
		}
		printf("no solution");
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				puts("nan");
			}
		}
	}
	return 0;
}

