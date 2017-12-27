using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>

struct Heap{
	int heap[7600000];
	int n;
	bool inline empty(){
		return n==0;
	}
	inline const int & top(){
		return heap[1];
	}
	void sink(int nd){
		int idx;
		while(1){
			idx=0;
			if((nd<<1) <=n){
				if(heap[nd<<1]>heap[nd]){
					idx=nd<<1;
					if((nd<<1|1)<=n && heap[(nd<<1)|1]>heap[idx]){
						idx=(nd<<1|1);
					}					
				}else if((nd<<1|1)<=n && heap[(nd<<1)|1]>heap[nd]){
					idx=(nd<<1|1);
				}
			}
			if(idx){
				swap(heap[nd],heap[idx]);
				nd=idx;
			}else{
				break;
			}
		}
	}
	void swim(int nd){
		while((nd>>1) &&(heap[nd>>1]<heap[nd]) ){
			swap(heap[nd>>1],heap[nd]);
			nd>>=1;
		}
	}
	void inline pop(){
		swap(heap[n],heap[1]);n--;
		sink(1);
	}
	void inline push(int val){
		heap[++n]=val;
		swim(n);
	}
}heap;

struct _Main{

int tottime,begnum,lenadd,u,v,t;
int totadd;
double rate;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}


_Main(){
	int i;int a,b,c;
	read(begnum);read(tottime);read(lenadd);read(u);read(v);read(t);
	rate=(double)u/v;
	for(i=0;i<begnum;i++){
		read(a);heap.push(a);
	}
	
	for(i=1;i<=tottime;i++){
		a=heap.top()+totadd;heap.pop();
		b=a*u/v;c=a-b;
		if(i%t==0){
			printf("%d ",a);
		}
		totadd+=lenadd;
		heap.push(c-totadd);
		heap.push(b-totadd);
	}printf("\n");
	for(i=1;!heap.empty();i++){
		if(i%t==0){
			printf("%d ",heap.top()+totadd);
		}
		heap.pop();
	}
	
}



	
	
	
}earthworm;





