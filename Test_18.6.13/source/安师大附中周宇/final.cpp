#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

const int Maxn=10;

int N;
int a[Maxn];

void ex_gcd(int a,int b,int &x,int &y){
	if(b==0){x=1,y=0;return;}
	ex_gcd(b,a%b,y,x),y-=(a/b)*x;
}

int main(){
	freopen("final.in","r",stdin),
	freopen("final.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	if(N==1){
		if(a[1]==1) puts("1");
		else puts("no solution");
		return 0;
	}
	if(N==2){
		int x,y;
		ex_gcd(a[1],a[2],y,x);
		printf("%d %d\n",a[1],a[2]);
		printf("%d %d",-x,y);
		return 0;
	}
	puts("no solution");
	return 0;
}

