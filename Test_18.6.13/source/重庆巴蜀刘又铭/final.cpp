#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int n,h[105];
int ryl(){
	int r=0,z=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')z=-1;c=getchar();
	}
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	return r*z;
}
int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	n=ryl();
	for(int i=1;i<=n;i++)h[i]=ryl();
	if(n==1){
		cout<<h[1];return 0;
	}
	if(n==2){
		for(int i=-2000;i<=2000;i++)
			for(int j=-2000;j<=2000;j++)
				if(h[1]*j-h[2]*i==1){
					cout<<h[1]<<" "<<h[2]<<'\n';
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
		puts("no solution");
	}
	if(n>=3)puts("no solution");
	return 0;
}

