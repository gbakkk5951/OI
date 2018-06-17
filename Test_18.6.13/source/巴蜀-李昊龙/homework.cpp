#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int get(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
double f[10005];
int n;
int main(){
  freopen("homework.in","r",stdin);
  freopen("homework.out","w",stdout);
	n=get();
	double a=exp(-1);
	f[0]=1-a;
//	cout<<f[0];
	for(int i=1;i<=n;i++){
		f[i]=1-i*f[i-1];
	}
	printf("%.4lf",f[n]);
//	for(int i=0;i<=10000;i++) printf("%.4lf\n",f[i]);
	return 0;
}

