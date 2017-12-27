#include<cstdio>
#include<ctime>
struct begin{
begin(){//	freopen("Ëæ»úÊý.out","r",stdin);	freopen("¶ÑÅÅÐò.txt","w",stdout);
	read();
	build();
	heapsort();
}
int data[100020];
int n;
void read(){
	while(~scanf("%d",&data[n+1]))	{
		n++;
	}
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
