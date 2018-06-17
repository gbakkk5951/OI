#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
long long a,b;
const double e=2.718281828459045;
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	a=1;b=-1;
	for(int i=1;i<=n;i++){
		a=1-i*a;
		b=-b;
		b=i*b;
	}
	printf("%.4lf",(double)(a)+(double)(b)/e);
	return 0;
}

