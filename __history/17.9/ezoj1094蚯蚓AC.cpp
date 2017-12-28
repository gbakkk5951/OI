using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<functional>
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
struct Queue{
	int arr[7000050];
	int head;int tail;
	void inline push(int a){
		arr[tail++]=a;
	}
	bool inline empty(){
		return head==tail;
	}
	void inline pop(){
		head++;
	}
	int inline top(){
		return arr[head];
	}
}que[3];


struct _Main{

int n,m,q,u,v,t,b;
int totadd;
_Main(){
	read(n);read(m);read(q);read(u);read(v);read(t);
	int i,j,k;int a,idx;
	for(i=0;i<n;i++){
		read(que[0].arr[i]);
	}que[0].tail=n;
	sort(que[0].arr,que[0].arr+n,greater<int>());
	for(i=1;i<=m;i++){
		idx=-1;
		for(k=0;k<3;k++)if(!que[k].empty() && (idx==-1 || que[k].top()>que[idx].top())){
			idx=k;
		}
		a=que[idx].top()+totadd;
		que[idx].pop();
		if(i%t==0){
			printf("%d ",a);
		}
		b=(long long)a*u/v;
		totadd+=q;
		que[1].push(b-totadd);que[2].push(a-b-totadd);
	}printf("\n");
	for(i=1;!que[0].empty() || !que[1].empty() || !que[2].empty();i++){
		idx=-1;
		for(k=0;k<3;k++)if(!que[k].empty() && (idx==-1 || que[k].top()>que[idx].top())){
			idx=k;
		}
		if(i%t==0)printf("%d ",que[idx].top()+totadd);
		que[idx].pop();
	}
}	
	
	
	
	
	
	
	
}ezoj1094;
