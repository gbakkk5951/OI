using namespace std;
int main(){}
#include<cstdio>
#include<bitset>
#include<cstring>
const char Fail[]="Impossible";
bitset<750005>v;
int queue[750005];
int idx;
struct _Main{
void ini(){
	idx=0;v.reset();bx=-1;by=-1;
}
int inline impress(int x,int y,int p){
	return x+y*500+p*250000;
}
int inline getx(int status){
	return status%500;
}
int inline gety(int status){
	return status%250000 /500;
}
int inline getp(int status){
	return status/250000;
}
int bx,by;
int h,l;
int goal;
int map[505][505];
_Main(){
	int i,j;
	char t;
	int status;
	while(1){
		ini();
		scanf("%d%d",&h,&l);
		if(h==0 && l ==0)return;
		for(i=0;i<h;i++){
			for(j=0;j<l;j++){
				while(isspace(t=getchar()));	
				map[j][i]=t;
				if(t=='O'){
					goal=impress(j,i,0);
				}else if(t=='X'){
					if(bx==-1){
						bx=j;by=i;
						status=impress(j,i,0);
					}else{
						if(j==bx){
							status=impress(bx,by,1);
						}else{
							status=impress(bx,by,2);
						}
					}
				}
			}
		}
		insert(status);
		bfs();
	}
}

void inline insert (int status){
	if(!v[status]){
		v[status]=1;
		queue[idx++]=status;
	}
}


void bfs(){
	int i,gap;int s; 
	i=0;int x,y,p;int ts;
	int dis=0;
	while(i<idx){
		gap=idx;
		for(;i<gap;i++){
			s=queue[i];
			if(s==goal){
				goto End;
			}
			x=getx(s);y=gety(s);p=getp(s);
			if(p==0){
				if(x>=2  && map[x-1][y]!='#' && map[x-2][y]!='#'){
					insert(impress(x-2,y,2));
				}
				if(x<l-2 && map[x+1][y]!='#' && map[x+2][y]!='#'){
					insert(impress(x+1,y,2));
				}
				if(y>=2  && map[x][y-1]!='#' && map[x][y-2]!='#'){
					insert(impress(x,y-2,1));
				}
				if(y<h-2 && map[x][y+1]!='#' && map[x][y+2]!='#'){
					insert(impress(x,y+1,1));
				}
			}else if(p==1){
				if(x<l-1 && map[x+1][y]!='#' && map[x+1][y+1]!='#'){
					insert(impress(x+1,y,1));
				}
				if(x>0   && map[x-1][y]!='#' && map[x-1][y+1]!='#'){
					insert(impress(x-1,y,1));
				}				
				if(y>0   && map[x][y-1]!='#' && map[x][y-1]!='E'){
					insert(impress(x,y-1,0));
				}
				if(y<h-2 && map[x][y+2]!='E' && map[x][y+2]!='#'){
					insert(impress(x,y+2,0));
				}
			}else{
				if(y<h-1 && map[x][y+1]!='#' && map[x+1][y+1]!='#'){
					insert(impress(x,y+1,2));
				}
				if(y>0   && map[x][y-1]!='#' && map[x+1][y-1]!='#'){
					insert(impress(x,y-1,2));
				}		
				if(x>0   && map[x-1][y]!='#' && map[x-1][y]!='E'){
					insert(impress(x-1,y,0));
				}
				if(x<l-2 && map[x+2][y]!='E' && map[x+2][y]!='#'){
					insert(impress(x+2,y,0));
				}
			}
		}
		dis++;
	}
	End:
		if(s==goal){
			printf("%d\n",dis);
		}else{
			printf("%s\n",Fail);
		}
}
	
	
	
	
	
}bloxorz;
