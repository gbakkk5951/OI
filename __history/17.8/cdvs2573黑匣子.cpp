int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cctype>
#include<functional>

template<typename KeyType,typename CmpType=greater<KeyType> >
class HeapType{
CmpType Cmp;
private:
	vector<KeyType>Node;
template<typename EleType>
	void inline swap(EleType &a,EleType &b){
		EleType t=a;
		a=b;
		b=t;
	}
public:
	int inline size(){
		return Node.size()-1;
	}	
	int inline capacity(){
		return Node.capacity();
	}
	KeyType inline top(){
		return Node[1];
	}
	void insert(KeyType a){
		Node.push_back(a) ; 
		int i=size();
		while(i!=1 && Cmp(Node[i],Node[i>>1])){
			swap(Node[i],Node[i>>1]);
			i>>=1;
		}
	}
	HeapType(){
		Node.resize(1);
	}
	void pop(){
		swap(Node[1],Node[size()]);
		Node.pop_back() ;
		int i=(1<<1);
		while(i <=size()){
			if(((i|1)<=size()) &&(Cmp(Node[i|1],Node[i])) ){
				i|=1;
			}
			if(Cmp(Node[i],Node[i>>1])){
				swap(Node[i>>1],Node[i]);
				i<<=1;			
			}else break;
		}
	}
};


struct query{
	int idx;int pos;
	bool friend operator < (const query &a,const query &b){
		return a.pos<b.pos;
	}
}q[200005];
int ans;
struct _Main{
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-') f=-1;
		}
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}a*=f;
	}
HeapType<int,less<int> > sh;
HeapType<int,greater<int> > lh;
int An,Gn;
int arr[200005];

int num;

void add(int a){
	sh.insert(a);
}



int get(){
	num++;
	while(lh.size()<num){
		lh.insert(sh.top());
		sh.pop();
	}
	while(sh.size()&& lh.size() && sh.top() < lh.top()){
		
		
		sh.insert(lh.top());lh.pop();
		lh.insert(sh.top());sh.pop();
	}
	return lh.top();
}
int ans[200005];
_Main(){

	int i,j;int idx=0;
	read(An);read(Gn);
	for(i=1;i<=An;i++){
		read(arr[i]);
	}
	for(i=0;i<Gn;i++){
		read(q[i].pos);
		q[i].idx=i;
	}stable_sort(q,q+Gn);
	for(i=0;i<Gn;i++){
		for(j=idx+1;j<=q[i].pos;j++){
			add(arr[j]);
		}idx=q[i].pos;
		ans[q[i].idx]=get();
	}
	for(i=0;i<Gn;i++){
		printf("%d\n",ans[i]);
	}
}
	
	
}cdvs2573;
