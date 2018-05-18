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
	fout=freopen("Cookies.in","w",stdout);
	int i,j,k;
	n=rand()%30+1;
	m=n+rand()%(5000-n+1);
	printf("%d %d\n",n,m);
	for(i=0;i<n;i++){
		printf("%d ",rand());
	}
	fclose(stdout);
}
}CookiesMaker;

