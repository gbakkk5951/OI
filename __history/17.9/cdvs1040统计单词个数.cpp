using namespace std;
int main(){}
#include <cstring>
#include<cctype>
#include<cstdio>
#include<algorithm>
#include<bitset>
bitset<210>use;
char str[210];
int cnt[205][205];
char word[6][210];
int nxt[6][210];
int lw[6];int wn;
int len;int pn;
struct _Main{

void getnxt(){
	int i,j,k;
	for(k=0;k<wn;k++){
		nxt[k][0]=nxt[k][1]=0;
		for(i=1,j=0;i<lw[k];i++){
			while(word[k][i]!=word[k][j] && j!=0){
				j=nxt[k][j];
			}nxt[k][i]=j;
			if(word[k][i]==word[k][j]){
				j++;
			}
		}nxt[k][lw[k]]=j;
	}
	
}
void getcnt(){
	int l,r;int i,j,k;int d;char *s;
	for(l=0;l<len;l++){
		s=&str[l];
		for(r=l;r<len;r++){
			use.reset();
			d=r-l+1;
			for(k=0;k<wn;k++){
				for(i=0,j=0;i<d;i++){
					if(d-i+j<lw[k])break;
					while(j && word[k][j]!=s[i]){
						j=nxt[k][j];
					}
					if(s[i]==word[k][j]){
						j++;
						if(j==lw[k]){
							use[l+i+1-lw[k]]=1;
							j=nxt[k][j];
						}
					}
				}
			}
			cnt[l][r]=use.count();
			legal[0][l][r]=true;
		}
	}
}
int dp[7][205][205];	
bool legal[7][205][205];
_Main(){
	int n;
	scanf("%d",&n);
	int p;int i,j,k;int iter=0;int l,r,m;
	while(n--){
		scanf("%d%d",&p,&pn);pn--;
		for(i=0;i<p;i++){
			scanf("%s",str+i*20);
		}len = 20 * p;
		scanf("%d",&wn);
		for(i=0;i<wn;i++){
			scanf("%s",word[i]);
			lw[i]=strlen(word[i]);
		}
		getnxt();
		getcnt();
		memcpy(dp[iter],cnt,sizeof(cnt));
		for(i=1;i<pn;i++){
			for(l=0;l<len;l++){
				for(r=l+i;r<len;r++){
					legal[i][l][r]=true;
					for(j=l;j<r;j++){
						for(m=0;m<i;m++)if(legal[m][l][j] && legal[i-m-1][j+1][r]){
							dp[i][l][r]=max(dp[i][l][r],dp[m][l][j]+dp[i-m-1][j+1][r]);
						}
					}
				}
			}
		}
		i=pn;l=0;r=len-1;
		if(i>0){
			for(j=l;j<r;j++){
				for(m=0;m<i;m++)if(legal[m][l][j] && legal[i-m-1][j+1][r]){
					dp[i][l][r]=max(dp[i][l][r],dp[m][l][j]+dp[i-m-1][j+1][r]);
				}
			}	
		}

		printf("%d",dp[i][l][r]);
	}
}	
	
	
	
	
}cdvs1040;
