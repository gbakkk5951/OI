using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<cstdlib>

int addlimit;
struct Block{
	long long basecst;
	int size;
	int height;
};
template<typename Type>
struct DoubleList{
	DoubleList *l,*r;
	Type key;
	bool del;
};
DoubleList <Block>list[1000005];
struct SortInfo{
	int height;DoubleList<Block> *idx;
	bool friend operator < (const SortInfo &a,const SortInfo &b ){
		return a.height<b.height;
	}
}sorted[1000005];


struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int n,c;
long long cst;
_Main(){
	int i,j,k;
	read(n);read(c);
	list[0].key.height=50000;
	for(i=1;i<=n;i++){
		read(list[i].key.height);
		if(list[i].key.height==list[i-1].key.height){
			list[i-1].key.size++;
			i--;n--;
		}else{
			sorted[i-1].height =list[i].key.height;
			sorted[i-1].idx=&list[i];
			list[i].key.size=1;
			list[i].l=&list[i-1];list[i-1].r=&list[i];
		}
	}
	list[n+1].l=&list[n];list[n].r=&list[n+1];list[n+1].key.height=50000;
	sort(sorted,sorted+n);
	DoubleList<Block> *nd;
	int add;
	for(i=0;i<n;i++){
		nd=sorted[i].idx;
		if(nd->del||nd->l->key.height<=nd->key.height || 
			nd->r->key.height<=nd->key.height){
			continue;
		}
		if(nd->l->l && nd->r->r){
			add=(2*c-2*nd->key.basecst+nd->key.size)/(2*nd->key.size);
			add=min(add,nd->l->key.height-nd->key.height);
			add=min(add,nd->r->key.height-nd->key.height);
		}else if(nd->l->l){
			add=(c-2*nd->key.basecst+nd->key.size)/(2*nd->key.size);
			add=min(add,nd->l->key.height-nd->key.height);
		}else if(nd->r->r){
			add=(c-2*nd->key.basecst+nd->key.size)/(2*nd->key.size);
			add=min(add,nd->r->key.height-nd->key.height);
		}else{
			continue;
		}
		if(add<=0)continue;
		
		
		nd->key.height+=add;
		cst+=(long long)(nd->key.size)*add*add+nd->key.basecst*2*add;
//		printf("add(%lld) from %d to %d cst=%lld\n",nd-&list[0],nd->key.height-add,nd->key.height,
//			(long long)(nd->key.size)*add*add+nd->key.basecst*2*add
//		);
		nd->key.basecst+=nd->key.size*add;
		if(nd->l->key.height==nd->key.height){
//			printf("merge(%lld,%lld)",nd->l-&list[0],nd-&list[0]);
			nd->l->key.size+=nd->key.size;
			nd->l->key.basecst+=nd->key.basecst;
			nd->l->r=nd->r;
			nd->r->l=nd->l;
			if(nd->r->key.height==nd->key.height)nd->l->del=1;
			nd=nd->l;
		}
		if(nd->r->key.height==nd->key.height){
//			printf("merge(%lld,%lld)",nd->r-&list[0],nd-&list[0]);
			nd->r->key.size+=nd->key.size;
			nd->r->key.basecst+=nd->key.basecst;
			nd->l->r=nd->r;
			nd->r->l=nd->l;
			nd=nd->r;				
		}
			
			
		
	}
//	printf("cst=%lld\n",cst);
	for(nd=list[0].r->r;nd->r;nd=nd->r){
		cst+=abs(nd->key.height-nd->l->key.height)*c;
//		printf("cst=%lld\n",cst);
//		printf("height[ %lld ]=%d\n",nd->l-&list[0],nd->l->key.height);
	}
//	printf("height[ %lld ]=%d\n",nd->l-&list[0],nd->l->key.height);
	printf("%lld\n",cst);
}	
	
	
}ezoj1071;
