using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int s[200005],e[200005],d[200005];
int n;
int getsum(int mx){
	int ans=0;int i;
	for(i=0;i<n;i++)if(s[i]<=mx){
		ans+=1+(min(e[i],mx)-s[i])/d[i];
	}return ans;
}

_Main(){
	int T;int i,j,k;int l,r;int ans;
	read(T);
	while(T--){
		read(n);
		for(i=0,l=0,r=0;i<n;i++){
			read(s[i]);read(e[i]);read(d[i]);
			r=max(r,e[i]);
		}
		if(!(getsum(r)&1)){
			printf("There's no weakness.\n");
			continue;
		}
		while(l<r){
			if(getsum((l+r)>>1)&1){
				r=(l+r)>>1;
			}else{
				l=((l+r)>>1)+1;
			}
		}
		for(i=0,ans=0;i<n;i++){
			if(s[i]<=l && e[i]>=l && (l-s[i])%d[i]==0){
				ans++;
			}
		}
		printf("%d %d\n",l,ans);
	}
	
	
	
}

	
	
	
	
	
	
}ezoj1016;
