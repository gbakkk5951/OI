#include<cstdio>
#include<cstring>
#include<deque>
#include<vector>
using namespace std;
struct _Main{
short n,m;
vector<short>link[1010];
vector<short>val[1010];

void add(){
	short d1,d2,c1,c2;d1=read();d2=read();c1=read();c2=read();
	link[d1].push_back(d2);
	val[d1].push_back(c1);  
	link[d2].push_back(d1);
	val[d2].push_back(c2);  	
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
	memset(d,127,4040);
	d[1]=0;
	memset(cnt,0,2020);
	memset(in,0,1010);
	vetex.clear() ;
	int i;
	for(i=1;i<=n;i++){
		link[i].clear() ;
		val[i].clear() ;
	}
	
}
_Main(){
	int i,j,k;
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
	vetex.push_back(1);
	cnt[1]++;
	while(vetex.size()){
		j=vetex.front();
		vetex.pop_front();
		in[j]=0;
		i=0;
		while(i<link[j].size()){
			k=link[j][i];
			if(d[j]+val[j][i]<d[k]){
				d[k]=d[j]+val[j][i];
				cnt[k]++;
				if(cnt[k]>n){
					printf("No such path\n");
					return;
				}
				if(!in[k]){
					in[k]=true;
					vetex.push_back(k);
				}
			}
			
			i++;
		}
		
		
		
	}
		if(d[n]>2047483648){
			printf("No such path\n");
			return;
		}
		printf("%d\n",d[n]);
	
	
	
	
	
	
}
	
	
	
	
}instance;int main(){}
