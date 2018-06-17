#include <iostream>
#include <cstdio>
using namespace std;
int n, mat[10][10];
int exgcd(int a, int b, int &x, int &y){
	if(!b){
		x=1, y=0; return a;
	}
	int t=exgcd(b, a%b, x, y);
	swap(x, y); y-=a/b*x;
	return t;
}
int main(){
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &mat[1][i]);
	int a, b, x, y; bool f=0;
	for(int i=1;!f&&i<=n;i++)
		for(int j=i+1;!f&&j<=n;j++)
			if(exgcd(mat[1][i], mat[1][j], x, y)==1)
				a=i, b=j, f=1;
	if(a==1)
		if(b>2)
			x*=-1,
			swap(mat[1][2], mat[1][b]);
		else
			y*=-1;
	else
		y*=-1,
		swap(mat[1][1], mat[1][a]), swap(mat[1][2], mat[1][b]);
	mat[2][2]=x, mat[2][1]=y;
	for(int i=3;i<=n;i++)
		mat[i][i]=1;
	for(int i=1;i<=n;i++){
		swap(mat[i][2], mat[i][b]), swap(mat[i][1], mat[i][a]);
		for(int j=1;j<=n;j++)
			printf("%d%c", mat[i][j], j==n?'\n':' ');
	}
	return 0;
}
