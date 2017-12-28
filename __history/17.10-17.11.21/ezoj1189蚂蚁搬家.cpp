using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#define Left()
#define Right()
#define Mid()
struct Lson{
	int inline operator [] (int a){
		return a<<1;
	}
}lson;
struct Rson{
	int inline operator [] (int a){
		return a<<1|1;
	}
}rson;


struct _Main{
int node[1050000];	
void change(int nd,int val){
	node[nd+=base]-=val;
	while(nd>>=1){
		node[nd]=max(node[lson[nd]],node[rson[nd]]);
	}
}
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
	int base;
	_Main(){
		int i,j,k;
		int n,q;
		int food,pos;
		int nd,lpos,rpos;
		read(n);read(q);
		for(base=1;base<n;base<<=1);
		for(i=0;i<n;i++){
			read(node[base+i]);
		}
		for(i=base-1;i;i--){
			node[i]=max(node[lson[i]],node[rson[i]]);
		}
		for(i=1;i<=q;i++){
			read(food);read(pos);
			pos--;
			Mid(){
				if(node[base+pos]>=food){
					printf("%d\n",pos+1);
					change(pos,food);
					continue;
				}
			}
			Left(){
				nd=base+pos;
				while(nd>1){
					if((nd&1)&&(node[nd^1]>=food)){
						nd^=1;
						break;
					}
					nd>>=1;
				}
				if(nd==1){
					lpos=-1;
				}else{
					while(nd<base){
						if(node[rson[nd]]>=food){
							nd=rson[nd];
						}else{
							nd=lson[nd];
						}
					}
					lpos=nd-base;
				}
			}
			Right(){
				nd=base+pos;
				while(nd>1){
					if((~nd&1)&&(node[nd^1]>=food)){
						nd^=1;
						break;
					}
					nd>>=1;
				}
				if(nd==1){
					rpos=-1;
				}else{
					while(nd<base){
						if(node[lson[nd]]>=food){
							nd=lson[nd];
						}else{
							nd=rson[nd];
						}
					}
					rpos=nd-base;
				}
			}
			if(lpos!=-1){
				if( pos-lpos<=rpos-pos||rpos==-1){
					printf("%d\n",lpos+1);
					change(lpos,food);
				}else{
					printf("%d\n",rpos+1);
					change(rpos,food);
				}
			}else if(rpos!=-1){
				printf("%d\n",rpos+1);
				change(rpos,food);
			}else{
				printf("-1\n");
			}
		}
		fclose(stdout);
	}
	
}ezoj1189;
