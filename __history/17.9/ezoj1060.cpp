using namespace std;

#include<cstdio>
#include<algorithm>
int n;
int tot;
bool issquare(long long s,int x,int y,int size){
	int i;
	for(i=0;i<size;i++){
		if(!(
			(s&(1ll << ( y*(2*n+1)+x+i ) ))	
		  &&(s&(1ll << ( (y+size)*(2*n+1)+x+i ) ))
		  &&(s&(1ll << ( n+(y+i)*(2*n+1)+x ) ))
		  &&(s&(1ll << ( n+(y+i)*(2*n+1)+x+size ) ))
			)){
			return false;
		}
	}
	return true;
}
int astar(long long s){
	int i,j,cnt;
	for(i=0,cnt=0;i<n;i++){
		for(j=0;j<n;j++){
			if(issquare(s,i,j,1)){
				cnt++;
			}
		}
	}
	return (cnt+1)>>1;
}
bool isok(long long s){
	int i,j,k;
	if(s<15)return true;
	for(k=1;k<=n;k++){
		for(i=0;i+k<=n;i++){
			for(j=0;j+k<=n;j++){
				if(issquare(s,i,j,k)){
					return false;
				}
			}
		}
	}
	return true;
}
//bool reach;
int ans;
void iddfs(long long s,int step,int beg){
	if(isok(s)){
		ans=min(ans,step);
		return;
	}
	int i;
	for(i=beg;i<tot;i++)if(s&(1LL<<i)){
		if(step+1+astar(s^(1LL<<i)) < ans){
			if(isok(s&((1LL<<i)-1))){
				iddfs(s^(1LL<<i),step+1,i+1);
			}else{
				return;
			}
		}
	}
}

int main(){
	int T;int i,j,k;long long s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		tot=n*(n+1)*2;
		s=(1LL<<tot)-1;
		scanf("%d",&k);
		ans=n*(n+1)-n*((n+1)/2);
		for(i=0;i<k;i++){
			scanf("%d",&j);
			s^=(1LL<<(j-1));
		}
		iddfs(s,0,0);
		printf("%d\n",ans);
	}
}


