using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
int inline lowbit(int a){
	return a&(-a);
}
const int Max_X=32005;
int tree[33000];
int cnt[15005];
void add(int idx,int val=1){
	for(idx+=1;idx<=Max_X;idx+=lowbit(idx)){
		tree[idx]+=val;
	}
}
int getsum(int idx){
	int ans=0;
	for( idx+=1;idx;idx-=lowbit(idx)){
		ans+=tree[idx];
	}return ans;
}

struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int n;	
_Main(){
	read(n);
	int i;int x,y;
	for(i=0;i<n;i++){
		read(x);read(y);
		cnt[getsum(x)]++;
		add(x);
	}
	for(i=0;i<=n-1;i++){
		printf("%d\n",cnt[i]);
	}
}	
	
	
}poj2352;
