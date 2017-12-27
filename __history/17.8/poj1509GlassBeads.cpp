using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>

struct _Main{

char obj[10010];
int la;
int readstr(char *a){
	la=0;
	while(!isalpha(*a=getchar()));
	do{
		la++;a++;
	}while(isalpha(*a=getchar()));
	*a='\0';return la;
}
int n;
_Main(){
	scanf("%d",&n);
	while(n--){
		la=readstr(obj);
		printf("%d\n",minexp(obj,la)+1);	
	}
}
char temp[20020];
int minexp(char *a,int len){
	memcpy(temp,a,len*sizeof(char));
	memcpy(temp+len,a,len*sizeof(char));
	int i=0,j=1;int k=0;
	for(k=0;k<len;k++){
		if(j>=len) return i;
		if(i>=len) return j;
		if(temp[i+k]<temp[j+k]){
			j=j+k+1;
			if(j==i) j++;
			k=-1;
		}else if(temp[i+k]>temp[j+k]){
			i=i+k+1;
			if(j==i) i++;
			k=-1;
		}
	}
	return min(i,j);
}	
	
	
	
}poj1509;
