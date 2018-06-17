#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define e 2.718281828459045090795598298427648842334747314453125
using namespace std;
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int n;cin>>n;
	if(n<=27){
		double f[10005];
		f[0]=1-1/e;
		for(int i=1;i<=n;i++)
			f[i]=1-i*f[i-1];
		printf("%.4f",f[n]);
		exit(0);
	}
}
