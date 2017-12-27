using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
int tail;
int top;
int q[1000010];
int idx[1000010];
int sum,cur;
struct _Main{
	
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}	
char cmd[10];
_Main(){
	int val;
	scanf("%*s");
	while(scanf("%s",cmd)){
		if(strcmp(cmd,"IN")==0){
			read(val);
			while(tail>top && q[tail-1]<val){
				tail--;
			}
			idx[tail]=sum++;
			q[tail++]=val;
			printf("%d\n",q[top]);
		}else if(strcmp(cmd,"OUT")==0){
			if(top<tail){
				if(idx[top]==cur){
					top++;
					cur++;
				}else{
					cur++;
				}
				if(top==tail){
					printf("-1\n");
				}else{
					printf("%d\n",q[top]);
				}
			}else{
				printf("-1\n");
			}	
		}else{
			return;
		}
		
	}
	
	
}
		
	
}jsk;
