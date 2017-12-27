using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<map>
struct Status{
	char chess[16];
	inline char & operator () (int a,int b){
		if(a>=4 || b>=4 || a<0 || b<0)return chess[0];
		return chess[a*4+b];
	}
	bool friend operator < (const Status &a,const Status &b){
		int i;
		for(i=0;i<16;i++)if(a.chess[i]!=b.chess[i]){
			return a.chess [i]<b.chess [i];
		}
		return false;
	}
};
map<Status,bool> result;

struct _Main{
	
	
bool dfs(Status s){
	if(result.find(s)!=result.end()){
		return result[s];
	}else{
		Status tmp;bool nothing=true;
		int i,j;bool win=false;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++)if(s(i,j)){
				nothing=false;
				tmp=s;
				tmp(i,j)=0;
				if(dfs(tmp)==false){
					win=true;
				}
				if(i!=0 && i!=3 &&s(i,j-1)){
					tmp=s;
					tmp(i,j)=tmp(i,j-1)=0;
					if(dfs(tmp)==false){
						win=true;
					}
				}
				if(i!=0 && i!=3 &&s(i,j+1)){
					tmp=s;
					tmp(i,j)=tmp(i,j+1)=0;
					if(dfs(tmp)==false){
						win=true;
					}
				}				
				if(j!=0 && j!=3 &&s(i-1,j)){
					tmp=s;
					tmp(i,j)=tmp(i-1,j)=0;
					if(dfs(tmp)==false){
						win=true;
					}
				}
				if(j!=0 && j!=3 &&s(i+1,j)){
					tmp=s;
					tmp(i,j)=tmp(i+1,j)=0;
					if(dfs(tmp)==false){
						win=true;
					}
				}
			}
		}
		return result[s]=(win || nothing);
	}
	
}	
	
	
	
	
_Main(){
	int T;Status s;
	int i,j;char t;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			s(i,j)=0;
		}
	}
	
	scanf("%d",&T); 
	while(T--){
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if((i==0||i==3)&&(j==0 || j==3))continue;
				while(!isdigit(t=getchar()));
				s(i,j)=t-'0';
			}
		}
		printf("%d",dfs(s));
	}
	
}	
	
	
	
}ezoj1116;
