using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>
struct _Main{
int cnt[3];//0 greater;1 less;2 equal

void getnxt(char* str,int *nxt,int len){
	int i,j,k,l,p;
	nxt[0]=len;
	p=0;
	while(p+1<len && str[p]==str[p+1])p++;
	nxt[1]=p;k=1;
	for(i=2;i<len;i++){
		p=k+nxt[k]-1;
		l=nxt[i-k];
		if(i+l<=p){
			nxt[i]=l;
		}else{
			j=p-i+1;
			j=max(j,0);
			while(i+j<len && str[i+j]==str[j])j++;
			nxt[i]=j;
			k=i;
		}
	}
}
int nxt[200010];
char num[200010];
int len;	
_Main(){
	int i;
	scanf("%s",num);
	len=strlen(num);
	memcpy(num+len,num,len*sizeof(char));
	getnxt(num,nxt,len<<1);
	cnt[2]++;
	for(i=1;i<len;i++){
		if(nxt[i]>=len)break;
		else cnt[num[i+nxt[i]]<num[nxt[i]]]++;
	}
	printf("%d %d %d",cnt[1],cnt[2],cnt[0]);
}
	
	
	
	
}jsk;
