#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef long double LD;

const int Maxn=105;
const double eps=1E-3;

int N;
double T;
double P[Maxn][2];
double D[Maxn][Maxn];

bool Judge(int X){
	for(int i=3;i<X;++i)
		if(fabs(sqrt((P[X][0]-P[i][0])*(P[X][0]-P[i][0])+(P[X][1]-P[i][1])*(P[X][1]-P[i][1]))-D[i][X])>eps)
			return false;
	return true;
}

void Dfs(int i){
	if(i>N){
		for(int i=1;i<=N;++i)
			printf("%.6lf  %.6lf\n",P[i][0],P[i][1]);
		exit(0);
	}
	double A=D[1][i],B=D[2][i];
	P[i][0]=T/2.0+(A*A-B*B)/T/2.0;
	P[i][1]=sqrt(A*A-P[i][0]*P[i][0]);
	if(Judge(i)) Dfs(i+1);
	P[i][1]=-P[i][1];
	if(Judge(i)) Dfs(i+1);
}

int main(){
	freopen("restore.in","r",stdin),
	freopen("restore.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%lf",&D[i][j]);
	if(N==1){
		puts("0.000000");
		return 0;
	}
	if(N==2){
		printf("0.000000 %.6lf",D[1][2]);
		return 0;
	}
	P[1][0]=P[1][1]=0.0;
	T=P[2][0]=D[1][2],P[2][1]=0.0;
	Dfs(3);
	return 0;
}

