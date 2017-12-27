using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
const char Fail[]="No\n";
const char Succ[]="Yes\n";
int getstr(char *a){
	int len=0;
	while(!isdigit(*a=getchar()));
	do{
		a++;
		len++;
	}while(isdigit(*a=getchar()));
	return len;
}

int minexp(char *a,int len){
	int i,j,k;
	for(i=0,j=1,k=0;k<len;k++){
		if(i>=len)return j;
		if(j>=len)return i;
		if(a[(i+k)%len]<a[(j+k)%len]){
			j=j+k+1;
			if(j==i) j++;
			k=-1;
		}else if(a[(i+k)%len]>a[(j+k)%len]){
			i=i+k+1;
			if(j==i) i++;
			k=-1;
		}
	}
	return i;
}
bool cmp(char *a,int ma,char *b,int mb,int len){
	int i;
	for(i=0;i<len;i++){
		if(a[(ma+i)%len]!=b[(mb+i)%len]){
			return false;
		}
	}
	return true;
}
void print(char *a,int ma,int la){
	int i;
	for(i=0;i<la;i++){
		putchar(a[(ma+i)%la]);
	}
}
struct _Main{
	
char ina[1000010];char inb[1000010];	
_Main(){
	int la,ma,lb,mb;
	la=getstr(ina);lb=getstr(inb);
	if(la!=lb){
		printf("%s",Fail);
		return;
	}
	ma=minexp(ina,la);mb=minexp(inb,lb);
	if(cmp(ina,ma,inb,mb,la)==true){
		printf("%s",Succ);print(ina,ma,la);
	}else{
		printf("%s",Fail);
	}
	
}	
	
	
	
	
}vijos1382;
