using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
struct _Main{

int n,a,b,l,r;
int w;
char pat[1000010];
int pl;
char dst[1000010];
int nxt[1000010];
int ans;
_Main(){
	int i,j,k;
	scanf("%d%d%d%d%d%s",&n,&a,&b,&l,&r,pat);
	pl=strlen(pat);
	if(pl>n){
		printf("0");
		return;
	}
	for(i=0,w=b;i<n;i++){
		
		if(w>=l && w<=r){
			if(w&1){
				dst[i]='T';
			}else{
				dst[i]='A';
			}
		}else{
			if(w&1){
				dst[i]='C';
			}else{
				dst[i]='G';				
			}
		}
		w=(w+a)%n;
	}
	nxt[0]=-1;
	for(i=1,j=-1;i<pl;i++){
		while(j>=0 && pat[j+1]!=pat[i]){
			j=nxt[j];
		}
		if(pat[j+1]==pat[i]){
			j++;
		}
		nxt[i]=j;
	}
	for(i=0,j=-1;i<n;i++){
		while(j>=0 && pat[j+1]!=dst[i]){
			j=nxt[j];
		}
		if(pat[j+1]==dst[i]){
			j++;
		}
		if(j==pl-1)ans++;

	}printf("%d",ans);
	
}
	
	
	
	
}jsk;
