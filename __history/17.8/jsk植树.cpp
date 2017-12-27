using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
struct stuType{
	int len,pos,happy;
	bool friend operator < (const stuType &a,const stuType &b){
		return a.pos <b.pos ;
	}
	
}stu[105];

struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int inline abs(int a){
	return (a>>31)^((a>>31)+a);
}	
int inline max(int a,int b){
	return ((a+b)+abs(a-b))>>1;
}	
int inline min(int a,int b){
	return ((a+b)-abs(a-b))>>1;
}	
int tn,pn;

int len[105],pos[105],happy[105];
int dp[16010];
int head,tail;
int q[16010];
_Main(){
	read(tn);read(pn);
	int i,j,k;
	for(i=0;i<pn;i++){
		read(stu[i].len);read(stu[i].happy);read(stu[i].pos);
	}sort(stu,stu+pn);
	for(i=0;i<pn;i++){
		memset(q,0,sizeof(q));
		head=tail=0;
		for(j=0;j<=tn;j++){
			if(j>=stu[i].pos ){
				if(tail!=head && j-q[head]>stu[i].len){
					head++;
				}
				if(j>=stu[i].pos+stu[i].len){
					dp[j]=max(dp[j],dp[j-1]);
				}else{
					dp[j]=max(dp[j],dp[q[head]]+(j-q[head])*stu[i].happy);
				}
			}else if(stu[i].pos-j<=stu[i].len){
				while(tail>head && dp[j]+(stu[i].pos-j)*stu[i].happy >= dp[q[tail-1]]+stu[i].happy*(stu[i].pos-q[tail-1])){
					tail--;
					q[tail]=0;
				}q[tail++]=j;
			}
		}
	}
	printf("%d\n",dp[tn]);
	
}





	
}jsk;
