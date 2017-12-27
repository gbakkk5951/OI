#include<cstdio>
#include<cstring>
using namespace std;
char mid[10],after[10],first[10];
int l;
void dfs(int fb,int ap,int mb,int n)
{


	if(n<=0||fb>=l||ap<0||mb<0||mb>=l||ap>=l||fb<0)
	return;     
	
	int m=(int)(strchr(mid,after[ap])-mid);

	first[fb]=after[ap];
//зѓзг 
	dfs(fb+1,ap-(mb+n-m),mb,m-mb);
//гвзг 
	dfs(fb+1+(m-mb),ap-1,m+1,n-(m-mb)-1);

	
}

int main(){
	int i,j,k;
	scanf("%s%s",mid,after);
	l=strlen(mid);
	dfs(0,l-1,0,l);
	printf("%s",first);
}
