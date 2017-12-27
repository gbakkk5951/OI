using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<queue>
#include<algorithm>
priority_queue<int>heap;
struct pro{
	int p,d;
	bool friend operator < (pro a,pro b){
		return a.d<b.d;
	}
}arr[10010];
int n;

struct _Main{

bool End;

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar())){
			if(t==EOF){
				End=true;return;
			}
			
		}
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		} 
	}
_Main(){
	int i;
	int ans;
	while(1){
		ans=0;
		read(n);
		if(End) return;
		for(i=0;i<n;i++){
			read(arr[i].p);read(arr[i].d);
		}sort(arr,arr+n);
		for(i=arr[n-1].d;i>0;i--){
			while(n>0 && arr[n-1].d==i){
				heap.push(arr[n-1].p); 
				n--;
			}
			if(heap.empty()==false){
				ans+=heap.top();
				heap.pop();
			}
		}
		printf("%d\n",ans);
		while(heap.empty() ==false){
			heap.pop();
		}
	}
	
}

}poj1456;


