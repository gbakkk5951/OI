#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

const double E=2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274;

int N;
double a=1,Ans;

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int i;
	scanf("%d",&N);
	for(i=N+1;i<=100000;i++){
		a=-a*(1.0/i);
		Ans+=a;
	}
	printf("%.4lf\n",fabs(Ans));
	return 0;
}
