#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char pat[510];
char p[1000010];
long long hash;
long long m;
long long b;
long long goal;
struct begin{
int cnt;
begin(){
	scanf("%s",pat);
	scanf("%s",p);
	ini();		
	ct();
	printf("%d",cnt);
}

void ini(){
	b=37;
	hash=144115188075855871;
	long long temp=1,i,j;
	int l=strlen(pat);
	for(i=1;i<l;i++){
		temp=(temp*b)%hash;
	}
//	printf("m=%lld ",temp);
	m=temp;

	for(i=0;i<l;i++){
		goal=(b*goal)%hash;
		goal=(goal+pat[i]%b)%hash;
	}
}

void  ct(){
	long long hs=0;
	int i,j,k;
	int lp=strlen(p);
	int lpt=strlen(pat);
	for(i=0;i<lp;i++){

		if(i>=lpt){
			hs=(hs-m*(p[i-lpt]%b))%hash;
			if(hs<0)
			hs+=hash;

		}
		hs=(b*hs)%hash;
		hs=(hs+p[i]%b)%hash;

		if(hs==goal&&i>=lpt-1){
	//	printf(" %d=",i);
			for(j=i-lpt+1;j<=i;j++){
				if(pat[j-i+lpt-1]!=p[j]){
					break;
				}else{
					if(j==i){
						cnt++;
					}
				}
				
			}
			
			
		}
		
	}
	
	
	
}	

	











}instance;
int main(){}
