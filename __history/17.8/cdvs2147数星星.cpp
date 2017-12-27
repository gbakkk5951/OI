using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<set>
struct _Main{
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}a*=f;
	}	
set<int> tree;
_Main(){
	int n;int i;int temp;
	set<int>::iterator it;
	read(n);
	for(i=0;i<n;i++){
		read(temp);
		it=tree.find(temp);
		if(it==tree.end()){
			putchar('0');
			tree.insert(temp);
		}else{
			putchar('1');
		}
		
	}
	
}	
	
}cdvs2147;
