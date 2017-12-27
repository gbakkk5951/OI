int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<cstring>
#include<bitset>

struct _Main{
int inline getbit (int data,int pos){
	return (data >>(pos<<1))&3;
}
void inline writebit(int &data,int pos,int val){
	data&=~(3<<(pos<<1));
	data|=(val<<(pos<<1));
}
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int inline max(int a,int b){
	return (a+b+abs(a-b))>>1;
}
int inline min(int a,int b){
	return (a+b-abs(a-b))>>1;
}
char map[100][5];
int dp[2][2170];
int  que[2][2171];
bitset<2050>in[2];
int front[2];
int n;
void inline insert(int kt,int num,int iter){
	if(!in[iter][kt]){
		in[iter][kt]=1;
		dp[iter][kt]=num;
		que[iter][front[iter]++]=kt;
	}else{
		dp[iter][kt]=min(dp[iter][kt],num);
	}
	
}
void updata(int &a,char pos){
	int i,j,k;
	k=getbit(a,pos);
	bool flag;
	
	if(!(j=getbit(a,pos))){
		j=10;
	}
	for(i=pos-1;i>=0;i--){
		if(getbit(a,i)){
			j=min(j,getbit(a,i));	
		}else{
			break;
		}
	}
	
	int g=i;
	for(i=pos-1;i>g;i--){
		if(getbit(a,i)!=j ){
			writebit(a,i,j);
		}
	}
	
	if(k){
		for(i=pos+1;i<5;i++){
			if(getbit(a,i)==k){
				writebit(a,i,j);
			}else if(getbit(a,i)==k+1){
				writebit(a,i,j+1);
			}
		}
	}
	
	if(j==10){
		j=1;
		for(i=0;i<pos;i++){
			if(getbit(a,i)==j){
				j++;
			}
		}
		for(i=pos+1;i<5;i++){
			if(getbit(a,i)==j){
				writebit(a,i,j+1);
			}else if(getbit(a,i)==j+1){
				writebit(a,i,j+2);
			}
		}
	}
	writebit(a,pos,j);
}

_Main(){
	bool flag;
	int i,j,k,s,iter;
	int kt;
	kt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			while(!isdigit(map[i][j]=getchar()));
			map[i][j]-='0';
		}
	}
	for(i=n-1;i>=0;i--){
		k=0;
		for(j=0;j<5;j++){
			k|=map[i][j];
		}
		if(k==0){
			n--;
		}else{
			break;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			if(map[i][j]){
				flag=true;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	iter=0;
	dp[iter][0]=0;
	que[iter][front[iter]++]=0;
	flag=false;

	for(;i<n;i++){
		for(j=0;j<5;j++){
		iter^=1;
			memset(dp[iter],127,8196);
		    memset(que[iter],0,front[iter]<<2);
			in[iter].reset();
			front[iter]=0;
			for(k=0;k<front[iter^1];k++){
				s=que[iter^1][k];
				if(map[i][j]){
					kt=s;
					updata(kt,j);
					insert(kt,dp[iter^1][s],iter);					
				}else{
					kt=s;
					updata(kt,j);
					insert(kt,dp[iter^1][s]+1,iter);
					if(getbit(s,j)){
						flag=false;
						for(kt=0;kt<5;kt++){
							if(kt!=j && getbit(s,kt) == getbit(s,j) ){
								flag=true;
								break;
							}
						}
					}else{
						flag=true;
					}
					if(flag){
						kt=s;
						writebit(kt,j,0);		
						insert(kt,dp[iter^1][s],iter);
					}
				}
			}
		}
	}
	int ans=3000;
	for(i=0;i<front[iter];i++){
		s=que[iter][i];
		flag=true;
		k=0 ;
		for(j=0 ;j< 5 ;j++){
			if( k==0 && getbit(s,j)){
				k=getbit(s,j);
			}else if(k!=0 && getbit(s,j)){
				if(k!=getbit(s,j)){
					flag=false;
				}
			}
		}
		if(flag||k==0){
			ans=min(ans,dp[iter][s]);
		}
	}
	printf("%d",ans);
}	
		
}cdvs1050;
