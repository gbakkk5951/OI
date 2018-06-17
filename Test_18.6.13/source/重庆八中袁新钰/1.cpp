#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define tm ndhsfjk
#define y1 cjdksl
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-') f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f) x=-x;
			return ;
		}
}
//*********************************************

int main()
{
	double e=exp(-1.0);
	printf("%.20f\n",e);
	for(int i=1;i<=30;i++){
		int t=(int)e;
		printf("%d %.10f\n",t,e);
		e=(e-t)*10;
	}
	return 0;
}
