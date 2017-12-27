using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>

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
int n,m,len;
int pos[50010];
bool del[50010];
bool legal(int gap){
	int i,j,k;int rem=m;
	memset(del,0,sizeof(del));
	for(i=0,j=n+1;i<j;i++,j--){
		if(!del[i]){
			for(k=i+1;k<=n;k++)if(!del[k] && pos[k]-pos[i]<gap){
				rem--;del[k]=1;
				if(rem<0)return false;
			}else{
				break;
			}
		}
		if(!del[j]){
			for(k=j-1;k>=1;k--)if(!del[k] && pos[j]-pos[k]<gap){
				rem--;del[k]=1;
				if(rem<0)return false;
			}else{
				break;
			}
		}
	}
	return true;
}
_Main(){
	int i,j,k;
	pos[0]=0;
	read(len);read(n);read(m);
	pos[n+1]=len;
	for(i=1;i<=n;i++){
		read(pos[i]);
	}
	int l,r;
	l=1;r=len;
	while(l<r){
		if(legal(((l+r)>>1)+1)){
			l=((l+r)>>1)+1;
		}else{
			r=(l+r)>>1;
		}
	}
	printf("%d",l);
}	
	
}stone;
