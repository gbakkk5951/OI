using namespace std;
#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>
int main(){}
struct DoubleList{
	DoubleList *l,*r;
	int idx;
	void del(){
		l->r=r;
		r->l=l;
	}
}list[1000010];
int winner[1000010];
int winneridx;
int mxidx;
vector<int> win[1000010];

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
int n;
_Main(){
	int i,j;int a,b;
	read(n);
	
	list[0].r=&list[1];
	for(i=1;i<=n;i++){
		list[i].l=&list[i-1];
		list[i].r=&list[i+1];
		list[i].idx=i;
		read(a);if(a>win[mxidx].size()){
			mxidx=i;
		}
		win[i].resize(a);
		for(j=0;j<a;j++){
			read(b);
			win[i][j]=b;
		}
		sort(win[i].begin(),win[i].end());
	}
	if(mxidx==0){
		printf("%d ",n);
		for(i=1;i<=n;i++){
			printf("%d ",i);
		}
		return;
	}
	list[n+1].l=&list[i-1];
	list[mxidx].del();
	winner[winneridx++]=mxidx;
	DoubleList *iter;
	for(i=0;i<winneridx;i++){
		j=0;
		for(iter=list[0].r;iter!=&list[n+1];iter=iter->r){
			while(j+1<win[winner[i]].size() && win[winner[i]][j+1]<=iter->idx){
				j++;
			}
			if(win[winner[i]].size()==0 || win[winner[i]][j]!=iter->idx){
				iter->del();
				winner[winneridx++]=iter->idx;
			}
		}
	}
	sort(winner,winner+winneridx);
	printf("%d ",winneridx);
	for(i=0;i<winneridx;i++){
		printf("%d ",winner[i]);
	}
}	
	
	
}ezoj1062;
