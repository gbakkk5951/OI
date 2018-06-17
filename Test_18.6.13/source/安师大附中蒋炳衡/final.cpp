#include<iostream>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int N=21;

void ex_gcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	ex_gcd(b,a%b,x,y);
	int t=x;x=y,y=t-a/b*y;
}

int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	
	int j,k,a,b,n;
	cin>>n>>j>>k;
	if(n<=2){
		ex_gcd(j,-k,a,b);
		if(j*a-b*k==-1)b=-b,a=-a;
		printf("%d %d\n%d %d",j,k,b,a);
	}else{
		puts("no solution");
	}
	
	return 0;
}

