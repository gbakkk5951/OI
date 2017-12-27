#include<cstdio>
#include<cstring>
#include<deque>

using namespace std;
struct _Main{
short n,m;
short head[1010];
short tail[1010];
short nxt[20020];
short to[20020];
short val[20020];
short tot;
void add(){
	short d1,d2,c1,c2;d1=read();d2=read();c1=read();c2=read();
	int i,j,k;
	
	if(!head[d1]){
		head[d1]=tot;
	}else nxt[tail[d1]]=tot;
	tail[d1]=tot;
	to[tot]=d2;
	val[tot]=c1;
	tot++;
	
	if(!head[d2]){
		head[d2]=tot;
	}else nxt[tail[d2]]=tot;
	tail[d2]=tot;
	to[tot]=d1;
	val[tot]=c2;
	tot++;	
}
short read(){
	char f=1,t;short ans=0;
	while((t=getchar())<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
	}
	do{
		ans*=10;
		ans+=t-'0';
	}while(( t=getchar() )>='0' && t<='9');
	return f*ans;
}
void clear(){
	memset(head,0,2020);
	memset(tail,0,2020);
	memset(to,0,40040);	
	memset(nxt,0,40040);
	memset(val,0,40040);
	memset(d,127,4040);
	d[1]=0;
	memset(cnt,0,2020);
	memset(in,0,1010);
	tot=1;
	vetex.clear();
}
_Main(){
	int i,j,k;
	tot=1;
	while((n=read())&&(m=read())){
		clear();
		for(i=0;i<m;i++){
			add();
		}
		spfa();
	}
	
	
	
}	
deque<short>vetex;
int d[1010];
short cnt[1010];
bool in[1010];
void spfa(){
	int i,j,k;
	i=head[1];
	cnt[1]++;
	vetex.push_back(1); 
	while(vetex.size()){
		j=vetex.front();
		vetex.pop_front();
		in[j]=0;
		i=head[j];
		while(i){
			if(d[j]+val[i]<d[to[i]]){
				cnt[j]++;
				if(cnt[j]>n){
					printf("No such path\n");
					return;
				}
				d[to[i]]=d[j]+val[i];
				if(!in[to[i]]){
					in[to[i]]=true;
					if(vetex.size()&&d[vetex.front()]>d[to[i]])
					vetex.push_front(to[i]); 
					else
					vetex.push_back(to[i]);
				}
			}
			
			i=nxt[i];
		}
		
		
		
	}
		if(d[n]>2047483648){
			printf("No such path\n");
			return;
		}
		printf("%d\n",d[n]);
	
	
	
	
	
	
}
	
	
	
	
}instance;int main(){}
