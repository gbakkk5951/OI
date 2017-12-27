#include<cstdio>
#include<cctype>
int n,k;
int arr[20];
char str[100][50];
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int to[50];
int main(){
	int i,j,l;
	read(n);read(k);
	for(i=1;i<=n;i++){
		read(to[i]);
	}fgets(str[0]+1,205,stdin);
	for(i=1;i<=n;i++)if(!isalpha(str[0][i])){
		str[0][i]=' ';
	}str[0][n+1]='\0';
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			str[i][to[j]]=str[i-1][j];
		}
		for(l=1;l<=n;l++)putchar(str[i][l]);putchar('\n');
	}
}
