#include<cstdio>
#include<cstring>
#define hhf puts("");
using namespace std;
char in[16000];
int l;
int sa[16000],rank[16000];
int ay[32000];
int nu[16000];
int an[32000];
int height[16000];
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void calheight(){
	int i,j,k;
	for(i=0;i<l;height[rank[i++]]=k){
		if(rank[i]>0)
		for(k?k--:0,j=sa[rank[i]-1];in[i+k]==in[j+k];k++);
	}
	height[0]=0;
	
}
int main(){

	scanf("%*d");
	int m=256;
	int *y=ay;
	int *nn=an;
	int i,j,k;
	scanf("%s",in); 
	 l=strlen(in);
	for(i=0;i<l;i++){
		nu[nn[i]=in[i]]++;
	}
	for(i=1;i<m;i++){
		
		nu[i]+=nu[i-1];
	}
	for(i=l-1;i>=0;i--){
		sa[--nu[in[i]]]=i;
	}


			for(j=1;j<=14;j++){
				if(1<<(j-1)>=l){
					break;
				}
			for(i=l-(1<<(j-1)),k=0;i<l;i++){
				y[k++]=i;
			}
			for(i=0;i<l;i++){
				if(sa[i]>=(1<<(j-1)))y[k++]=sa[i]-(1<<(j-1));
			}

			memset(nu,0,sizeof(nu));			
			for(i=0;i<l;i++){
				nu[nn[y[i]]]++;
			}
			for(i=1;i<m;i++){
				nu[i]+=nu[i-1];
			}
			for(i=l-1;i>=0;i--){
				sa[--nu[nn[y[i]]]]=y[i];
			}
			int *t;
			
			for(t=y,y=nn,nn=t,nn[sa[0]]=0,i=1,k=1;i<l;i++){
				nn[sa[i]]= cmp(y,sa[i-1],sa[i],(1<<(j-1)))?k-1:k++;
			}
			m=k;

	}
	for(i=0;i<l;i++){
		rank[sa[i]]=i;
	}
	calheight();
	for(i=0;i<l;i++){
		printf("height[%d]=%d ",i+1,height[i]);
	}hhf
	for(i=0;i<l;i++){
		printf("%d\n",sa[i]+1);
	}

	
}
