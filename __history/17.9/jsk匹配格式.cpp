int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
struct _Main{
char str[1000010];	
int nxt[1000010];
int pos[1000010];
int len;
void getnxt(){
	int i,j,k,l,p;
	nxt[0]=len;
	i=0;
	while(i<len && str[i]==str[i+1])i++;
	nxt[1]=i;k=1;
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
		if(i>=nxt[i]){
			pos[nxt[i]]=min(pos[nxt[i]],i);
		}else{
			pos[i]=min(pos[i],i);
		}
	}
	
	
}

_Main(){
	int i;
	scanf("%s",str);
	len=strlen(str);
	memset(pos,63,(len+5)*sizeof(int));
	getnxt();
	for(i=len-1;i>=1;i--){
		pos[i]=min(pos[i],pos[i+1]);
	}
	for(i=len/3*2;i<len;i++){
		if(nxt[i]==len-i && pos[nxt[i]]<=i){
			break;
		}
	}
	printf("%d",nxt[i]);
}	
	
	
}jsk;
