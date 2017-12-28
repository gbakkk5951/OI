using namespace std;
int main(){}
#include<cstring>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<functional>
#include<queue>
#include<algorithm>
struct FiboNode;
const FiboNode *P_FiboNull= (FiboNode *)malloc(512);





template <typename Type ,typename StCmp =less<Type> > 
class FiboHeap {
private:
	int n;
	Consolidate(){
		
		
	}
	
public:
	
	
	class FiboNode{
	public:
		typedef FiboHeap<Type,StCmp>::FiboNode Node;
		int degree;
		Node *p;
		Node *child;
		Node *l;
		Node *r;
		Type key;
		bool mark;
		FiboNode(){
			l=this; 
			r=this;
			p=(Node*)P_FiboNull;
			child=(Node*)P_FiboNull;
		}
		
	}*FiboNull;
	#define NodeNull FiboNull
	typedef FiboHeap<Type,StCmp> Heap;
	typedef Heap::FiboNode Node;
	
	/*
	void inline JoinList (FiboNode *Dst,FiboNode *Src){
		if(Dst!=FiboNull){
			Src->l=Dst;
			Src->r=Dst->r;
			Dst->r->l=Src;
			Dst->r=Src;
		}
	}*/
	void inline MergeList(Node *Dst,Node *Src){
		if(Dst!=FiboNull && Src!=FiboNull){
			Src->left->right=Dst->right;
			Dst->right->left=Src->left;
			Src->left=Dst;				
			Dst->right=Src;			
		}
	}
	Node * EraseList(Node *obj){
		obj->right->left=obj->left;
		obj->left->right=obj->right;
		obj->left=obj->right=obj;
		return obj;
	}
	
	StCmp Cmp;
	void inline MemDelNode(FiboNode *obj){
		free(obj);
	}


	/*
	bool resize(int size){
		if(size>pool.capacity()){
			pool.resize(size); 
			return true;
		}else{
			return false;
		}
	}*/

	FiboNode *min;
	
	Node* insert (Type val){
		n++;
		/*if(n>pool.size()){
			pool.resize(n);
		}*/
		
		
		//FiboNode *temp=&pool[n-1];
		FiboNode *temp=calloc(sizeof(FiboNode),1);
		temp->key=val;
		//JoinList(min,temp);
		MergeList(min,temp);
		if(min==FiboNull || Cmp(temp->key,min->temp)){
			min=temp;
		}
		return temp;
	}
	FiboHeap(){
		FiboNull=(Node *)P_FiboNull;
		min=FiboNull;		
	}
	/*
	FiboHeap(int size){
		FiboNull=(FiboHeap<Type,StCmp>::FiboNode *)P_FiboNull;
		min=FiboNull;
		pool.resize(size); 		
	}
	*/
	
	Heap * copy(){
		
		
	}
	
	void clear(){
		if(n){
			FiboNode *temp=min;
			do {
				temp=temp->right;
				MemDelNode(temp->left);
			}while(temp!=min);
		}
	}
	void inline Union (Heap &Src, bool Reserve = false){
		if(Reserve){
			
			
		}else{
			if(Src.n){
				if(n){
					MergeList(min,Src->min);
					if(Cmp(min->key,Src->min->key)){
						min=Src->min;
					}
				}else{
					min=Src->min;
				}
			}
			n+=Src.n;
		}
	}
	void Pop(){
		if(min!=NodeNull){
			Node *tmp;
			tmp=min->child->right;
			do {
				MergeList( min, EraseList(tmp) );
				tmp=tmp->right;
			}while(tmp!=min->child);
			tmp=min->right;
			EraseList(min);
			if(min==tmp){
				min=NodeNull;
			}else{
				min=tmp;
				Consolidate();
			}
			n--;
		}
	}
	int inline size(){
		return n;
	}
	
	const Type * Getmin(){
		if(min!=NodeNull)
			return min->key;
		else return NULL;
	}
};


bool cmp(int a,int b){
	return a<b;
}
struct Stcmp{
	inline bool operator () (int a,int b){
//		printf("sg");
		return cmp(a,b);
	}
};

struct _Main{

_Main(){
	int s[15];
	FiboHeap<long long,Stcmp> Heap1();
	FiboHeap<int ,Stcmp> Heap2();
//	Heap1.resize(15);
	
}


	
}Proc_Main;

