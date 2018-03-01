using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
namespace Protector{
const int inf=2147483640;
const int Plsiz=350000;
const int mxh=10;
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
struct Node{
	Node *l,*r,*u,*d;
	int val,size;
	void inline clear(){
		memset(this,0,sizeof(Node));
	}
}Pl[Plsiz+5];
int Plidx;
queue<Node*>q;
Node *newnode(){
	if(!q.empty()){
		Node *ret=q.front();
		q.pop();
		return ret;
	}else if(Plidx<Plsiz){
		return &Pl[Plidx++];
	}else{
		return new Node;
	}
}
struct List{

Node *L[10],*R[10],*now[10];

List (){
	int i;
	for(i=0;i<mxh;i++){
		L[i]=newnode();
		R[i]=newnode();
		L[i]->r=R[i];
		R[i]->l=L[i];
		L[i]->val=-inf;
		R[i]->val= inf;
		L[i]->size=1;
		if(i){
			L[i]->d=L[i-1];
			L[i-1]->u=L[i];
			R[i]->d=R[i-1];
			R[i-1]->u=R[i];			
		}
	}

}
void inline dislink(Node *nd){
	nd->l->r=nd->r;
	nd->r->l=nd->l;
	nd->clear();
	q.push(nd);
}
void inline link(Node *left,Node *nd){
	nd->r=left->r;
	nd->l=left;
	nd->l->r=nd;
	nd->r->l=nd;
}
int getval(int rank){
	ininow();
	int i;
	
	for(i=mxh-1;i>=0;i--){
		while(now[i]->size<=rank){
			rank-=now[i]->size;
			now[i]=now[i]->r;
		}
		if(i)now[i-1]=now[i]->d;
	}
	return now[0]->val;
}
void insert(int val,char build=false){
	if(!build)lowfind(val);
	int i;
	Node *nd,*lst;
	for(i=0;i<mxh;i++){
		nd=newnode();
		if(i){
			nd->d=lst;
			lst->u=nd;
		}
		nd->val=val;
		link(now[i],nd);
		getsize(nd);
		getsize(now[i]);
		if(build)now[i]=nd;
		if(rand()&3)break;
		lst=nd;
	}
	for(i++;i<mxh;i++){
		getsize(now[i]);
	}
}
void getsize(Node *nd){
	if(!nd->d){
		nd->size=1;
	}else{
		nd->size=nd->d->size;
		Node *tmp=nd->d->r;
		for( ;!tmp->u;tmp=tmp->r){
			nd->size+=tmp->size;
		}
	}
}
void erase(int val){
	lowfind(val);
	Node *u,*l;
	int i;
	for(i=0;i<mxh;i++){
		l=now[i]->l;
		u=now[i]->u;
		dislink(now[i]);
		getsize(l);
		if(!u)break;
	}
	for(i++; i<mxh;i++){
		getsize(now[i]);
	}
} 
void inline ininow(){
	memcpy(now,L,sizeof(now));
}
int lowfind(int val){ // <= max
	ininow();
	int i,siz=0;
	for(i=mxh-1;i>=0;i--){
		while(now[i]->r->val<=val){
			siz+=now[i]->size;
			now[i]=now[i]->r;
		}
		if(i)now[i-1]=now[i]->d;
	}
	return siz;
}
int upfind(int val){ // >= min
	ininow();
	int i,siz=0;
	for(i=mxh-1;i>=0;i--){
		while(now[i]->r->val<val){
			siz+=now[i]->size;
			now[i]=now[i]->r;
		}
		if(i)now[i-1]=now[i]->d;
	}
	now[0]=now[0]->r;
	for(i=1;now[i-1]->u;i++){
		now[i]=now[i]->r;
	}
	return siz+1;	
}

void print(){
	Node *nd,*base;
		ininow();
		for(base=now[0]->r;base->r;base=base->r){
			for(nd=base;nd;nd=nd->u){
				printf("%d ",nd->val);
			}
			printf("\n");
		}
	
	
}

}tree;


struct _Main{
	
	
_Main(){
	int Q,Qn;
	int i,j,k;
	read(Qn);
	int Qtp;
	int a,b,c;
	for(Q=1;Q<=Qn;Q++){
		read(Qtp);read(a);
		switch(Qtp){
			case 1:{//插入 
				tree.insert(a);
				break;
			}
			case 2:{//删除 
				tree.erase(a);
				break;
			}
			case 3:{//求排名 
				printf("%d\n",tree.upfind(a));
				break;
			}
			case 4:{//第k大 
				printf("%d\n",tree.getval(a));
				break;
			}
			case 5:{//前驱 
				tree.lowfind(a-1);
				printf("%d\n",tree.now[0]->val);
				break;
			}
			case 6:{//后继 
				tree.upfind(a+1);
				printf("%d\n",tree.now[0]->val);				
				break;
			}
			default:{
				tree.print();
			}
		}
		
		
	}
	
}	
	
	
}cdvs4543;


}


//build 其实不用写
//相同的数据结构写多了，就会发现更好的写法
//不要加入不用的功能和参数 
//永远关注情境 不需要的扩展、安全保证 是不用考虑的 
//NameStd: Qtp, ->size  
//关注原理 
//不要用文本记忆来写代码






