#include<bits/stdc++.h>
using namespace std;
inline void ri(int &x){
	x=0; static char c;
	while(c=getchar(),c<'0'||c>'9');
	do x=x*10+c-'0'; while(c=getchar(),c>='0'&&c<='9');
}
double f[22]={
0.6321,
0.367879,
0.264241,
0.207277,
0.170893,
0.145533,
0.126802,
0.112384,
0.100932,
0.0916123,
0.0838771,
0.0773522,
0.0717732,
0.0669478,
0.0627305,
0.0590431,
0.0553098,
0.0597305,
-0.0751953,
2.42578,
-47.5625};
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int i,n; ri(n);
	printf("%.4lf",f[n]);
	return 0;
}
