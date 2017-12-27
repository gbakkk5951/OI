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
	int sig [1050000];
	void inline push(int nd){
		sig[nd<<1]+=sig[nd];
		node[nd<<1]+=sig[nd];
		sig[nd<<1|1]+=sig[nd];
		node[nd<<1|1]+=sig[nd];
		sig[nd]=0; 
	}
	
	void change(int l,int r,int val,int nd=1,int nl=0,int nr=base-1){
		if(r<nl || l>nr)return ;
		if(l<=nl && nr<=r){
			node[nd]+=val,sig[nd]+=val;
			return;
		}
		if(sig[nd])push(nd);
		change(l,r,val,nd<<1,nl,nl+nr>>1);
		change(l,r,val,nd<<1|1,(nl+nr>>1)+1,nr);
		node[nd]=max(node[nd<<1],node[nd<<1|1]);
	}
	int query(int l,int r,int nd=1,int nl=0,int nr=base-1){
		if(r<nl || l>nr)return -inf;
		if(l<=nl && nr<=r)return node[nd];
		if(sig[nd])push(nd);
		return max(query(l,r,nd<<1,nl,nl+nr>>1),query(l,r,nd<<1|1,(nl+nr>>1)+1,nr));
	}
	void build(){
		int i;
		for(i=base+n;i>1;i-=2){
			node[i>>1]=max(node[i],node[i^1]);
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

//记得return
//熟悉的数据结构也要用心 
//min,max 一致 
//标记清除 
//若从base+1开始用则base是0号位 

/*
不需要排序的ques其实不如直接存数组，对于nlogn来说O(n)的 
访存没必要节省，反而增加代码长度 
*/
