using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#define maxn 127

const int beg=0,dst=1;

struct _Main{

void clear(){
	memset(this,0,sizeof(_Main));
	memset(dis,63,sizeof(dis));
}
	
bool instk[maxn];
bool inloop[maxn];
int stk[maxn];
int stkidx;
int dis[maxn];
int map[maxn][maxn];
int tme[maxn];
int from[maxn];
int delta[maxn];
int n;
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
		a*=f;
	}

void inline readpair(const int &idx){
	read(x[idx]);read(y[idx]);read(z[idx]);
}
void SPFA(int nd=0){
	instk[nd]=1;
	stk[stkidx++]=nd;
	
	Beg:
	int i,j,mn;

	if(nd && !(nd&1)){
		if(max(dis[nd],tme[nd])+delta[nd]<dis[nd+1]){
			if(instk[nd+1]){
				mn=1e9;
				for(j=stkidx-1;j>=0;j--){
					if(stk[j]==nd+1){
						break;
					}
				}
				for(j=j;j<stkidx;j++){
					if(from[stk[j]]){
						mn=min(mn,dis[stk[j]]-tme[stk[j]]);
					}
				}
			}else{
				dis[nd+1]=max(dis[nd],tme[nd])+delta[nd];
				from[nd+1]=nd;
				SPFA(nd+1);
				from[nd+1]=0;
			}
		}
	}
	for(i=0;i<=(n<<1|1);i++){
		if(dis[nd]+map[nd][i]<dis[i]){
			
			
		}
	}
	instk[nd]=false;
	stkidx--;
}

double inline pf(int a){
	return (double)a*a;
}
_Main(){
	int i,j,k;
	int T;
	read(T);
	while(T--){
		clear();
		readpair(0);
		readpair(1);
		read(n);
		for(i=1;i<=n;i++){
			readpair(i<<1);
			readpair(i<<1|1);
			read(tme[i<<1]);
			read(delta[i<<1]);
			tme[i<<1|1]=-(int)1e8;
		}
		for(i=0;i<=(n<<1|1);i++){
			map[i][i]=0;
			for(j=i+1;j<=(n<<1|1);j++){
				map[i][j]=map[j][i]=(int)ceil(sqrt(pf(x[i]-x[j])+pf(y[i]-y[j])+pf(z[i]-z[j])));
			}
		}
		SPFA();
		printf("%lld\n",dis[1]);
	}
	fclose(stdout);
}


};
