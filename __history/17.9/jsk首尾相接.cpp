using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>

struct _Main{
char fir[50010],sec[50010];	
void getnxt(char *str,int *nxt,int len){
	int p=0;int i,j,k,l;
	k=1;
	nxt[0]=len;
	while(p+1<len&& str[p]==str[p+1])p++;
	nxt[1]=p;k=1;
	for(i=2;i<len;i++){
		p=k+nxt[k]-1;
		l=nxt[i-k];
		if(i+l<=p) nxt[i]=l;
		else{
			j=p-i+1;
			j=max(j,0);
			while(i+j<len && str[j]==str[i+j])j++;
			nxt[i]=j;
			k=i;
		}
	}
}
void getextend(char *suf,char *pre,int *nxt,int ls,int lp,int *extend){
	int i,j,k,p=0,l;
	while(p<ls && p< lp && suf[p]==pre[p])p++;
	extend[0]=p;
	k=0;
	for(i=1;i<ls;i++){
		p=k+extend[k]-1;
		l=nxt[i-k+1];
		if(i+l<=p){
			extend[i]=l;
		}else{
			j=p-i+1;
			j=max(j,0);
			while(i+j<ls && j<lp && pre[j] == suf[i+j])j++;
			extend[i]=j;
			k=i;
		}
	}
	
}
int len1,len2;
int nxt[50005],extend[50005];
_Main(){
	int i;
	scanf("%s%s",sec,fir);
	len1=strlen(fir);
	len2=strlen(sec);
	getnxt(fir,nxt,len1);
	getextend(fir,sec,nxt,len1,len2,extend);
	for(i=0;i<len1;i++){
		if(len1-i==extend[i]){
			break;
		}
	}
	if(i<len1){
		printf("%s %d",fir+i,extend[i]);
	}else{
		printf("0");
	}
	
}	
	
	
	
}jsk;
