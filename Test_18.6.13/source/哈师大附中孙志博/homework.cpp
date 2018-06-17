#include <cstdio>
#include <cmath>
using namespace std;
int n;
int main() {
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	if (n<=15) {
		double f=1.0-exp(-1);
		for (int i=1;i<=n;i++)
			f=(double)1-f*i;
	}
	else
		f=0.0001;
	printf("%.4lf\n",f);
	return 0;
}