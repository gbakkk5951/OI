using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
char str[1000010];
int l;

struct _Main{
int nxt[1000010];	
_Main(){
	int i,j,k;
	scanf("%d%s",&l,str);
	nxt[0]=-1;
	for(i=1,j=-1;i<l;i++){
		while(j>=0 && str[j+1]!=str[i]) {
			j=nxt[j];
		}
		if(str[i]==str[j+1]){
			j++;
		}
		nxt[i]=j;
	}

	printf("%d",l-1-nxt[l-1]);

}	
	
	
}jsk; 

