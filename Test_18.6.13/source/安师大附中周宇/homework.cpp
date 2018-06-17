#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef long double LD;

const LD E=exp(-1.0);

int N;
int a,b;
LD Ans;

int main(){
	freopen("homework.in","r",stdin),
	freopen("homework.out","w",stdout);
	scanf("%d",&N);
	a=1,b=-1;
	for(int i=1;i<=N;++i)
		a=1-i*a,b*=(-i);
	//cout<<a<<' '<<b<<endl;
	Ans=(LD)a+(LD)b*E;
	printf("%.4lf",(double)Ans);
	return 0;
}

