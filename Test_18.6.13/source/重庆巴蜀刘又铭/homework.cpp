#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int n;
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
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	n=ryl();
	double ans=0;
	long long g=1;
	for(int i=n+1;i<=1000000;i++){
		g*=i;
		if(i%2==0)ans+=1.0/g;
		else ans-=1.0/g;
		if(g>=10000000000ll)break;
	}
	if(n%2==0)printf("%0.4lf ",-ans);
	else printf("%0.4lf ",ans);
	return 0;
}

