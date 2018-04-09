using namespace std;
int main(){}
#include<cctype>
#include<cstdio>
#include <cstring>
#include <algorithm>
char got[100010];
int h;
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
int val[105];int num[105];
int low;
int n,m;
_Main(){
	int i,j,k;
	while(1){
		read(n);read(m);
		if(n==0 && m==0){
			return;
		}
		int mx = 0;
		memset(got, 0, (m + 1) * sizeof(char));
		got[0]=1;
		for(i=0;i<n;i++){
			read(val[i]);
		}
		for(i=0;i<n;i++){
			read(num[i]);
		}
		for(i=0;i<n;i++){
			if(val[i]>m)continue;
			for(j=0;j<val[i];j++){
				
				if(got[j]) h=j;
				else	   h=-1;
				low=j-num[i]*val[i];
				for(k=j+val[i];k<=m && low <= mx;k+=val[i]){
					low+=val[i];
					
					if(got[k]){
						h=k;
					}else if(h<low){
						h=-1;
					}else if(h!=-1){
						got[k]=1;
						mx = max(mx, k);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += got[i];
		}
		printf("%d\n", ans);
	}
}
	
	
}jsk;
