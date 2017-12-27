using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define DoNothing()	

namespace Protector{
	
const int inf=0x3f3f3f3f;
int fa[300010]; 
int getfa(int a){
	return fa[a]?(fa[a]=getfa(fa[a])):a;
}
struct Node{
	int idx;
	Node *r;
}Pl[300010];
int Plidx;
int n;
struct List{
	Node *head,*tail;
	List(){
		head=tail=&Pl[Plidx++];
	}
	void inline merge(List *b){
		tail->r=b->head;
		tail=b->tail;
	}
}list[300010];
int L[300010],R[300010],pos[300010];
int base;
struct SegTree{
	int node[1050000];	
	void change(int s,int t,int val){
		int A;
		for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
			if(~s&1)node[s^1]+=val;
			if( t&1)node[t^1]+=val;
			A=max(node[s],node[s^1]);
			node[s]-=A;node[s^1]-=A;node[s>>1]+=A;
			A=max(node[t],node[t^1]);
			node[t]-=A;node[t^1]-=A;node[t>>1]+=A;			
		}
		while(s>>1){
			A=max(node[s],node[s^1]);
			node[s]-=A;node[s^1]-=A;
			node[s>>=1]+=A;
		}
	}
	int query(int s,int t){
		int Lans=-inf,Rans=-inf;
		for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
			Lans+=node[s];Rans+=node[t];
			if(~s&1)Lans=max(Lans,node[s^1]);
			if( t&1)Rans=max(Rans,node[t^1]);
		}
		Lans=max(Lans+node[s],Rans+node[t]);
		while(s>>=1){
			Lans+=node[s];
		}
		return Lans;
	}
	void build(){
		int i,A;
		for(i=base+n;i>1;i-=2){
			A=max(node[i],node[i^1]);
			node[i]-=A;node[i^1]-=A;
			node[i>>1]+=A;
		}
	}
}tree;
int segidx;

struct Ques{
	char Qtype[5];
	int val[2];
}ques[300010];


struct _Main{
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
		a*=f;
	}

int Qn;	
int arr[300010];
_Main(){
	int Q;
	int i,j,k;
	char str[5];
	int a,b;
	
	read(n);
	for(base=1;base<n+2;base<<=1);
	for(i=1;i<=n;i++){
		read(arr[i]);
		list[i].head->idx=i;
	}
	read(Qn);
	for(i=1;i<=Qn;i++){
		scanf("%s",ques[i].Qtype);
		if(ques[i].Qtype[0]=='U' || (ques[i].Qtype[0]=='A' && ques[i].Qtype[1]!='3')){
			read(ques[i].val[0]);read(ques[i].val[1]);
			if(ques[i].Qtype[0]=='U'){
				if((a=getfa(ques[i].val[0]))!=(b=getfa(ques[i].val[1]) )){
					list[a].merge(&list[b]);
					fa[b]=a;
				}
			}
		}else if(ques[i].Qtype[0]!='F' || ques[i].Qtype[1]!='3'){
			read(ques[i].val[0]);
		}else{
			DoNothing();
		}
	}

	Node *nd;
	for(i=1;i<=n;i++){
		if(fa[i]==0){
			for(nd=list[i].head;nd; nd=nd->r){
				pos[nd->idx]=L[nd->idx]=R[nd->idx]=++segidx;
			}
		}
	}
	for(i=1;i<=n;i++){
		tree.node[base+pos[i]]=arr[i];
	}
	tree.build();	
	
	memset(fa,0,(n+1)*sizeof(int));
	for(Q=1;Q<=Qn;Q++){
		memcpy(str,ques[Q].Qtype,5*sizeof(char));
		a=ques[Q].val[0];b=ques[Q].val[1];
		switch(str[0]){
			case 'U':{
				if((a=getfa(a))!=(b=getfa(b))){
					fa[b]=a;
					L[a]=min(L[a],L[b]);
					R[a]=max(R[a],R[b]);
				}
				break;
			}
			case 'F':{
				switch(str[1]){
					case '1':{
						printf("%d\n",tree.query(pos[a],pos[a]));
						break;
					}
					case '2':{
						printf("%d\n",tree.query(L[getfa(a)],R[getfa(a)]));
						break;
					}
					case '3':{
						printf("%d\n",tree.query(1,n));
						break;
					}
				}
				
				break;
			}
			case 'A':{
				switch(str[1]){
					case '1':{
						tree.change(pos[a],pos[a],b);
						break;
					}
					case '2':{
						tree.change(L[getfa(a)],R[getfa(a)],b);
						break;
					}
					case '3':{
						tree.change(1,n,a);
						break;
					}
				}
				break;
			}
			
		}
	}
}
	
	
}cdvs2407;


}

//离线不一定要重排操作顺序，可能只需要处理一些信息 
//zkw 记得^1
//数据结构理解原理。 
//离线重标号，要把数据暂存一下，然后放到标号后的位置。 

/*
不需要排序的ques其实不如直接存数组，对于nlogn来说O(n)的 
访存没必要节省，反而增加代码长度 
*/
