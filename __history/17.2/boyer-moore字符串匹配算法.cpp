#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char sa[510];
char sb[1000010];
int right[256];
int next[510];
int suffix[510];
int cnt;
int la,lb;
void getright(){
int i,j;
	for(i=0;i<256;i++)
	right[i]=-1;
	for(i=0;i<la;i++){
		right[sa[i]]=i;
	}
	
	for(i=0;i<la;i++)
	next[i]=la;
	suffix[la-1]=la;
	for(i=la-2;i>=0;i--){
		j=i;
		while(j>=0&&sa[j]==sa[la-1-i+j])
			j--;
		suffix[i]=i-j;
	}
	j=0;
	for(i=la-1;i>=0;i--){
		if(i+1==suffix[i]){
			for(;j<la-1-i;j++)
				if(next[j]==la)
				{next[j]=la-1-i;
				}
			
		}
		
	}
	for(i=0;i<=la-2;i++){
		next[la-1-suffix[i]]=la-1-i;
	}
	
	
}

int main(){
	int i,j,k;
	scanf("%s",sa);
	scanf("%s",sb);
	la=strlen(sa);
	lb=strlen(sb);
	int pos=la-1;
	int skip=0;
	getright();
	for(i=0;i<=lb-la;i+=skip){
		skip=0;
		for(j=la-1;j>=0;j--){
			if(sa[j]!=sb[i+j]){
				skip=j-right[sb[i+j]]; 
				if(skip<1)skip=1;
				skip=max(skip,next[j]);
				break;
			}
		}
		if(skip==0)
		{skip=1;
		cnt++;}
		
	}

	printf("%d",cnt);
	
	
}
