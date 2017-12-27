#include<cstdio>
#include<ctime>
struct begin{
begin(){
	read();
	build();
	heapsort();
}
int data[600000];
int n;
void read(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&data[i+1]);
	
}
void build(){
	int i=0;
	for(i=n>>1;i;i--){
		sink(i);
	}
}
void sink(int root){
	int kid=root<<1;
	int t;
	if((kid|1)<=n&&data[kid|1]<data[kid]){
		kid|=1;
	}
	if(data[root]>data[kid]){
		t=data[root];
		data[root]=data[kid];
		data[kid]=t;
		if(( kid<<1)<=n)
		sink(kid);
	}
}	
void heapsort(){
	while(n){
		printf("%d ",data[1]);
		data[1]=data[n];
		n--;
		sink(1);		
	}	
}	
}instance;int main(){}
