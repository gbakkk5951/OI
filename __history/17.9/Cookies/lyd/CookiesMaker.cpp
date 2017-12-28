using namespace std;
int main(){}
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
const 
struct _Main{
FILE *fout;
int n,m;
_Main(){
	srand(time(0));
	freopen("Cookies.in","w",stdout);
	int i,j,k;
	n=5;
	m=50;
	printf("%d %d\n",n,m);
	for(i=0;i<n;i++){
		printf("%d ",rand()%50);
	}
	fclose(stdout);
}
}CookiesMaker;

