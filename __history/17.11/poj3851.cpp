using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<cstring>
struct Queue{


bool  inline empty(){
	return head==tail;
}
void inline clear(){
	head=tail=0;
}
void inline push(int a){
	if(!inq[a]){
		q[tail++]=a;
		inq[a]=1;
	}
}
void inline insert(int a){
	if(!inq[a]){
		q[tail++]=a;
		inq[a]=1;
	}
}
int inline pop(){
	inq[q[head]]=0;
	return q[head++];
}

private:
	int q[100010];
	bool inq[100010];
	int head,tail;
}q;
struct _Main{

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

	int x[110],y[110],z[110];
	int map[110][113];
	int dis[113];
	int tme[111];
	int add[110];
	int n;
	int beg;int dst;
void SPFA(){
	q.clear();
	q.push(0);
	int nd,i,t;
	while(!q.empty()){
		nd=q.pop();
		for(i=0;i<=(n<<1|1);i++){
			if(dis[nd]+map[nd][i]<dis[i]){
				dis[i]=dis[nd]+map[nd][i];
				q.push(i);
			}
		}
		if(nd && !(nd&1)){
			if ((t=max(dis[nd],tme[nd]) +add[nd])<dis[nd+1]){
				dis[nd+1]=t;
				q.push(nd+1);
			}
		}
	}
}

	void inline readpair(int idx){
		read(x[idx]);read(y[idx]);read(z[idx]);
	}	
template<typename Type>
	double pf(Type a){
		return (double)a*a;
	}
	_Main(){
		int T;
		int i,j,k;
		beg=0;dst=1;
		read(T);
		while(T--){
			memset(dis,63,sizeof(dis));
			readpair(0);
			readpair(1);
			read(n);
			for(i=1;i<=n;i++){
				readpair(i<<1);
				readpair(i<<1|1);
				read(tme[i<<1]);read(add[i<<1]);
			}

			for(i=0;i<= (n<<1|1);i++){
				map[i][i]=0;
				for(j=i+1;j<=(n<<1|1);j++){
					map[i][j]=map[j][i]=(int)ceil(sqrt(pf(x[i]-x[j])+pf(y[i]-y[j])+pf(z[i]-z[j])));
				}
			}
			dis[0]=0;
			SPFA();
			printf("%d\n",dis[1]);
		}
	}
	
	
	
}poj3851;
