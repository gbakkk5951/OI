using namespace std;
int main(){}
#include<cstring>
#include<cstdio>
#include<cctype>
#include<queue>

struct Pos{
	int x;int y;int dir;int dis;
	bool friend operator > (const Pos &a,const Pos &b){
		return a.dis>b.dis;
	}
};

struct _Main{
queue<int>q;
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
char map[35][35];
int step[35][35][4][4];//0ÉÏ£¬1ÏÂ£¬2×ó£¬3ÓÒ 
int dis[35][35];
int dis2[35][35][4];
void preproc(){
	int i,j,k;int I;int g;int s;int hang,lie;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)if(map[i][j]){
			for(k=0;k<4;k++){
				switch (k){
				case 0:{
					if(map[i-1][j]) q.push((i-1)*100+j);
					break;
				}
				case 1:{
					if(map[i+1][j]) q.push((i+1)*100+j);
					break;
				}					
				case 2:{
					if(map[i][j-1]) q.push(i*100+j-1);
					break;
				}					
				case 3:{
					if(map[i][j+1]) q.push(i*100+j+1);
					break;
				}					
					
				}
				if(q.empty())continue;
				memset(dis,63,sizeof(dis));
				dis[q.front()/100][q.front()%100]=0;
				s=0;				
				while(!q.empty()){
					g=q.size();
					for(I=0;I<g;I++){
						hang=q.front()/100;
						lie=q.front()%100;
						q.pop();
						if(map[hang-1][lie] && dis[hang-1][lie]>30000 && !(hang-1==i && lie==j)){
							dis[hang-1][lie]=s+1;
							q.push((hang-1)*100+lie);
						}
						if(map[hang+1][lie] && dis[hang+1][lie]>30000 && !(hang+1==i && lie==j)){
							dis[hang+1][lie]=s+1;
							q.push((hang+1)*100+lie);
						}
						if(map[hang][lie-1] && dis[hang][lie-1]>30000 && !(hang==i && lie-1==j)){
							dis[hang][lie-1]=s+1;
							q.push(hang*100+lie-1);
						}
						if(map[hang][lie+1] && dis[hang][lie+1]>30000 && !(hang==i && lie+1==j)){
							dis[hang][lie+1]=s+1;
							q.push(hang*100+lie+1);
						}
					}
					s++;
				}
				step[i][j][k][0]=dis[i-1][j];
				step[i][j][k][1]=dis[i+1][j];
				step[i][j][k][2]=dis[i][j-1];
				step[i][j][k][3]=dis[i][j+1];
			}
		}
	}
}

priority_queue<Pos,vector<Pos>,greater<Pos> >heap;
void play(){
	int i,j,k,g,s;int hang,lie;
	int ex,ey,sx,sy,tx,ty;
	read(ex);read(ey);
	read(sx);read(sy);	
	read(tx);read(ty);	
	if(sx==tx && sy==ty){
		printf("0\n");
		return;
	}
	memset(dis,63,sizeof(dis));
	s=0;
	q.push(ex*100+ey);
	dis[ex][ey]=0;
	while(!q.empty()){
		g=q.size();
		for(i=0;i<g;i++){
			hang=q.front()/100;
			lie =q.front()%100;
			q.pop();
			if(map[hang-1][lie] && dis[hang-1][lie]>30000 && !(hang-1==sx && lie==sy) ){
				dis[hang-1][lie]=s+1;
				q.push((hang-1)*100+lie);
			}
			if(map[hang+1][lie] && dis[hang+1][lie]>30000 && !(hang+1==sx && lie==sy)){
				dis[hang+1][lie]=s+1;
				q.push((hang+1)*100+lie);
			}
			if(map[hang][lie+1] && dis[hang][lie+1]>30000 && !(hang==sx && lie+1==sy)){
				dis[hang][lie+1]=s+1;
				q.push(hang*100+lie+1);
			}
			if(map[hang][lie-1] && dis[hang][lie-1]>30000 && !(hang==sx && lie-1==sy)){
				dis[hang][lie-1]=s+1;
				q.push(hang*100+lie-1);
			}
		}
		s++;
	}
	
	if(dis[sx-1][sy]<30000){
		heap.push((Pos){sx,sy,0,dis[sx-1][sy]});
		dis2[sx][sy][0]=dis[sx-1][sy];
	}
	if(dis[sx+1][sy]<30000){
		heap.push((Pos){sx,sy,1,dis[sx+1][sy]});
		dis2[sx][sy][1]=dis[sx+1][sy];
	}
	if(dis[sx][sy-1]<30000){
		heap.push((Pos){sx,sy,2,dis[sx][sy-1]});
		dis2[sx][sy][2]=dis[sx][sy-1];
	}
	if(dis[sx][sy+1]<30000){
		heap.push((Pos){sx,sy,3,dis[sx][sy+1]});
		dis2[sx][sy][3]=dis[sx][sy+1];
	}
	memset(dis2,63,sizeof(dis2));
	Pos tp,tmp;
	while(!heap.empty()){
		tp=heap.top();heap.pop();
		if(tp.x==tx && tp.y==ty){
			break;
		}
		if(step[tp.x][tp.y][tp.dir][0]<=30000&& 
		dis2[tp.x-1][tp.y][1]>tp.dis+step[tp.x][tp.y][tp.dir][0]+1){
			tmp.x=tp.x-1;tmp.y=tp.y;tmp.dir=1;tmp.dis=tp.dis+step[tp.x][tp.y][tp.dir][0]+1;
			dis2[tp.x-1][tp.y][1]=tmp.dis;
			heap.push(tmp);
		}
		if(step[tp.x][tp.y][tp.dir][1]<=30000&&
		dis2[tp.x+1][tp.y][0]>tp.dis+step[tp.x][tp.y][tp.dir][1]+1){
			tmp.x=tp.x+1;tmp.y=tp.y;tmp.dir=0;tmp.dis=tp.dis+step[tp.x][tp.y][tp.dir][1]+1;
			dis2[tp.x+1][tp.y][0]=tmp.dis;
			heap.push(tmp);			
		}
		if(step[tp.x][tp.y][tp.dir][2]<=30000&&
		dis2[tp.x][tp.y-1][3]>tp.dis+step[tp.x][tp.y][tp.dir][2]+1){
			tmp.x=tp.x;tmp.y=tp.y-1;tmp.dir=3;tmp.dis=tp.dis+step[tp.x][tp.y][tp.dir][2]+1;
			dis2[tp.x][tp.y-1][3]=tmp.dis;
			heap.push(tmp);			
		}
		if(step[tp.x][tp.y][tp.dir][3]<=30000&&
		dis2[tp.x][tp.y+1][2]>tp.dis+step[tp.x][tp.y][tp.dir][3]+1){
			tmp.x=tp.x;tmp.y=tp.y+1;tmp.dir=2;tmp.dis=tp.dis+step[tp.x][tp.y][tp.dir][3]+1;
			dis2[tp.x][tp.y+1][2]=tmp.dis;
			heap.push(tmp);					
		}
	}
	if(heap.empty()){
		printf("-1\n");
	}else{
		printf("%d\n",tp.dis);
	}
	while(!heap.empty()){
		heap.pop();
	}
}
_Main(){
	int i,j,k;int q;
	read(n);read(m);read(q);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			read(map[i][j]);
		}
	}
	preproc();
	for(i=0;i<q;i++){
		play();
	}
	fclose(stdout);
}	
	
	
	
	
}ezoj1111;
