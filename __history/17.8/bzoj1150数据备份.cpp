using namespace std;
int main(){}
#include<cstring>
#include<cstdio>
#include<cctype>
#include<queue>
#include<functional>
bool d[1000010];
long long ans;
struct DoubleList{
	DoubleList *pre,*nxt;
	int idx;long long lc;long long rc;
	void del(){
		pre->nxt=nxt;
		nxt->pre=pre;
		d[idx]=1;
	}
}arr[1000005];//0,n+1为保护节点 
struct Block{
	int l;int r;long long cst;
	bool friend operator < (const Block &a,const Block &b){
		return a.cst<b.cst;
	}
	bool friend operator > (const Block &a,const Block &b){
		return a.cst>b.cst;
	}
};
priority_queue<Block,vector<Block>,greater<Block> > q;

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
int n,s;	
_Main(){
	int i,j,k;
	read(n);read(s);
	arr[0].idx=0;arr[0].nxt =&arr[1];
	long long t[2];int iter=0;
	t[0]=-1000000005;
	for(i=1;i<=n;i++){
		iter^=1;
		arr[i].pre=&arr[i-1];
		arr[i].nxt=&arr[i+1];
		arr[i].idx=i;
		read(t[iter]);
		arr[i].lc=arr[i].pre->rc=t[iter]-t[iter^1];
	}arr[n+1].idx=n+1;arr[n+1].pre=&arr[n];
	arr[n+1].pre->rc=2000000005-t[iter];
	arr[n+1].lc=2000000005-t[iter];
	
	for(i=1;i<=n-1;i++){
		q.push((Block){i,i+1,arr[i].rc}); 
	}
	bool flag;int l,r;long long cst;
	for(i=1;i<=s;i++){
		
		flag=false;
		do{
			l=q.top().l;r=q.top().r;cst=q.top().cst;q.pop();			
			if(!d[l] && !d[r]){
				ans+=cst;
				arr[r].nxt->lc=arr[l].pre->rc=arr[l].lc+arr[r].rc-cst; 
				q.push( (Block){ arr[l].pre->idx , arr[r].nxt->idx , arr[l].pre->rc} );
				arr[l].del() ;arr[r].del() ;
				flag=true;
			}
			
		}while(flag==false);
	}
	printf("%lld",ans);
}	
	
	
}bzoj1150;
