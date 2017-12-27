using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
struct _Main{
	
char org[100],cmp[100];	
int lo,lc;
int bego,begc;
void readstr(char *a){
	char t;
	while((!isdigit(t=getchar()))&&(!isalpha(t))); 
	*a=t;
	while(isdigit(t=getchar())||isalpha(t)){
		a++;
		*a=t;
	}a++;*a='\0';
}

_Main(){
	int i,j,k;
	readstr(org);
	lo=strlen(org);
	bego=minexp(org,lo);
	while(1){
		BegWhile1:
		readstr(cmp);
		lc=strlen(cmp);
		if(lc!=lo) {
			printf("He\n");
			continue;
		}
		begc=minexp(cmp,lc);
		for(i=0;i<lo;i++){
			if(org[(i+bego)%lo]!=cmp[(i+begc)%lc]){
				printf("He\n");
				goto BegWhile1;
			}
		}
		printf("Da\n");	
	}
}
char temp[500];
int minexp(char *a,int len){
	int i=0;int j=1;int k=0;
	memcpy(temp,a,len*sizeof(char));
	memcpy(temp+len,a,len*sizeof(char));
	for(k=0;k<len;k++){
		if(i>=len)return j;
		if(j>=len)return i;
		if(temp[i+k]>temp[j+k]){
			i=i+k+1;
			if(i==j) i++;
			k=-1;
		}else if(temp[i+k]<temp[j+k]){
			j=j+k+1;
			if(i==j) j++;
			k=-1;
		}
	}
	return i;
}	
	
	
}lx;
