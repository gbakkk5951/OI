#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200050;
int n,m,f[N],appear[1229312];
char s[6],ch[N],L;
int main(){
	scanf("%d",&n);
	for(int I=1;I<=n;I++){
		scanf("%s",s);
		for(L=0;s[L];L++)s[L]-=96;
		for(int i=0;i<(1<<L);i++){
			int temp=1,num=1;
			for(int j=0;j<L;j++){
				if(i&(1<<j))temp=temp*28+s[j];
				else num++,temp=temp*28+27;
			}
			appear[temp]=appear[temp]?min(appear[temp],num):num;
		}
	}
	scanf("%d%s",&m,ch+1);
	memset(f,0x3f,sizeof(f)),f[0]=0;
	for(int i=1;i<=m;i++)ch[i]-=96;
	for(int i=0;i<=m;i++)
		for(int j=1;j<=4;j++)
			for(int k=0;k<(1<<j);k++){
				int temp=1;
				for(int l=0;l<j;l++){
					if(k&(1<<l))temp=temp*28+ch[i+l+1];
					else temp=temp*28+27;
				}
				f[i+j]=min(min(f[i+j],f[i]+(appear[temp]?appear[temp]-1:N)),N);
			}
	if(f[m]<N)printf("%d\n",f[m]);
	else puts("No");
}
