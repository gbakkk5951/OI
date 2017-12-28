using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#define M_A_D_M_A_N 

							M_A_D_M_A_N
namespace Protector{
	
struct Block{
	Block *dir[4];
	int val,base;
}pool[4020050];
int poolidx;
void move(Block *&nd,int dir){
	Block * next=nd->dir[dir+nd->base&3];
	int i;
	for(next->base=0;next->dir[next->base+dir+2&3]!=nd;next->base++);
	nd=next;
}
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
inline Block *  newblock(){
	return &pool[poolidx++];
}
Block * square[4][2];

struct _Main{
	template<typename Type>
		void read(Type &a){
			char t;
			while(!isdigit(t=getchar()));
			a=t-'0';
			while( isdigit(t=getchar())){
				a*=10;a+=t-'0';
			}
		}
	int n,m;
	Block *head[2010];
	~_Main(){
		fclose(stdout);
	}
	_Main(){
		Block *nd[2]={0,0};
		int i,j,k;
		int x,y;
		int Qn,Q;
		int a,b,c;
		int dir;
		read(n);read(m);read(Qn);
		
		for(i=0;i<=n+1;i++){
			head[i]=nd[0]=newblock();
			if(i>0) nd[1]=head[i-1];
			for(j=0;j<=m+1;j++){
				if(nd[1]){
					nd[1]->dir[2]=nd[0];
					nd[0]->dir[0]=nd[1];
					nd[1]=nd[1]->dir[1];
				}
				if(j<=m){
					nd[0]->dir[1]=newblock();
					nd[0]->dir[1]->dir[3]=nd[0];
					nd[0]=nd[0]->dir[1];
				}
			}
		}
		for(i=1;i<=n;i++){
			nd[0]=head[i]->dir[1];
			for(j=1;j<=m;j++){
				read(nd[0]->val);
				nd[0]=nd[0]->dir[1];
			}
		}
		for(Q=1;Q<=Qn;Q++){
			read(a);read(b);read(c);
			nd[0]=head[a];
			for(i=0;i<b;i++){
				move(nd[0],1);
			}
			x=a;y=b;
			for(j=0;j<=3;j++){
				square[j][1]=square[j][0]=nd[0];
				move(square[j][1],j);
				for(i=1;i<=c;i++){
					if(i!=c){
						move(nd[0],j+1&3);
						x+=dx[dir];y+=dy[j+1&3];
					}
				}
			}
			for(j=0;j<4;j++){
				nd[0]=square[j][0];
				nd[1]=square[j+1&3][1];
				for(i=1;i<=c;i++){
					nd[1]->dir[nd[1]->base+j+3&3]=nd[0];
					nd[0]->dir[nd[0]->base+j&3]=nd[1];
					if(i!=c){
						move(nd[0],j+1&3);
						move(nd[1],j+2&3);
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			nd[0]=head[i];
			for(j=1;j<=m;j++){
				move(nd[0],1);
				printf("%d ",nd[0]->val);
			}
			printf("\n");
		}
	}
	
}drink;

}
