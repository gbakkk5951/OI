#include<cstdio>
const int maxn=200010;
int n,A[2][maxn],_A[2][maxn],
	ai[2][maxn],aj[2][maxn],acnt[2];
void swp(int k,int i,int j){
	int t=A[k][i];A[k][i]=A[k][j];A[k][j]=t;
	ai[k][acnt[k]]=_A[k][A[k][i]]=i;aj[k][acnt[k]++]=_A[k][A[k][j]]=j;
}
int main(){
	scanf("%d",&n);
	for(int k=0;k<2;k++)
		for(int i=0;i<n;i++)scanf("%d",A[k]+i),_A[k][--A[k][i]]=i;
	for(int i=0;i<n;i++)if(A[0][i]!=A[1][i]){
		if(_A[1][A[0][i]]>_A[0][A[1][i]])swp(0,i,_A[0][A[1][i]]);
		else swp(1,i,_A[1][A[0][i]]);
	}
	printf("%d\n",acnt[0]+acnt[1]);
	for(int i=0;i<acnt[0];i++)printf("%d %d\n",ai[0][i]+1,aj[0][i]+1);
	for(int i=acnt[1];i--;)printf("%d %d\n",ai[1][i]+1,aj[1][i]+1);
}
