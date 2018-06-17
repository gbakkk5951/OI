#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n,x[100],s[10][10];

void exgcd(int a,int b,int &x,int &y){
	if(b==0){x=1;y=0;return;}
	exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
}

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}if(n!=2)goto abd;
	for(int i=-2000;i<=2000;i++){
		for(int j=-2000;j<=2000;j++){
			if(x[1]*j-x[2]*i==1){
				printf("%d %d\n%d %d\n",x[1],x[2],i,j);
				return 0;
			}
		}
	}abd:;
	int a,b;
	s[1][1]=x[1];
	s[1][2]=x[2];
	s[1][3]=x[3];
	s[1][4]=x[4];
	s[1][5]=x[5];
	s[2][2]=1;
	s[3][3]=1;
	s[4][4]=1;
	s[5][5]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(gcd(x[i],x[j])==1);
			exgcd(x[i],x[j],a,b);
			b=-b;
			s[j][i]=b;
			s[j][j]=a;
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					printf("%d ",s[k][l]);
				}printf("\n");
			}return 0;
		}
	}return 0;
}
