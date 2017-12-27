#include<cstdio>
#include<ctime>
using namespace std;

//new

/*
struct node{
	node *a,*b,*f;
	int val;
};
int main(){
float a=clock();
int i;
for(i=0;i<10000000;i++){
	node *a=new node();
	delete a;
}
printf("%f",clock()-a);
}


*/
//pool
#include<queue>
struct node;
queue<node*>q; 
struct node{
	node *a,*b,*f;
	int val;
}pool[10000000];
int tot;
inline void del(node *in){
	q.push(in); 
}



int main(){
float a=clock();
int i;
for(i=0;i<10000000;i++){
	node *a;
//	if(q.empty())
	a=&pool[tot++];
//	else {a=q.front();q.pop();}
//	del(a);
}
printf("%f",clock()-a);	
	
}


