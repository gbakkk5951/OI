using namespace std;
int main(){}
#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>

struct _Main{
int eidx;
int head[100010][2];//0表出1表入
int to[2000010][2];
int out[100010];
void inline add(int a,int b){
	eidx++;
	to[eidx][1]=head[a][0];
	head[a][0]=eidx;
	to[eidx][0]=b;
	out[a]++;
	eidx++;
	to[eidx][1]=head[b][1];
	head[b][1]=eidx;
	to[eidx][0]=a;	
}
long long dmg[100010];
void del(int nd){
	out[nd]=-1;
	int i;
	long long sum=patk[nd];
	for(i=head[nd][0];i;i=to[i][1]){
		sum+=dmg[to[i][0]];
	}
	dmg[nd]=min(dmg[nd],sum);
	for(i=head[nd][1];i;i=to[i][1]){
		out[to[i][0]]--;
		if(out[to[i][0]]==0){
			del(to[i][0]);
		}
	}
}
struct Node{
	long long val;
	int pos;
	bool friend operator < (const Node &a,const Node &b){
		return a.val<b.val;
	}
}arr[100010];
int arridx;

long long patk[100010];	
	template<typename Type>
		void read(Type &a){
			char t;
			while(!isdigit(t=getchar()));
			a=t-'0';
			while( isdigit(t=getchar())){
				a*=10;a+=t-'0';
			}
		}
	int n;
	_Main(){
		int i,j,k;
		int a,b,c;
		read(n);
		for(i=1;i<=n;i++){
			read(patk[i]);
			read(dmg[i]);
			read(a);
			for(j=1;j<=a;j++){
				read(b);
				add(i,b);
			}
		}
		for(i=1;i<=n;i++){
			if(out[i]==0){
				del(i);
			}
		}
		arridx=0;
		for(i=1;i<=n;i++){
			if(out[i]>0){
				arr[arridx++]=(Node){dmg[i],i};
			}
		}
		sort(arr,arr+arridx);
		for(i=0;i<arridx;i++){
			if(out[arr[i].pos]>0){
				del(arr[i].pos);
			}
		}
		printf("%lld",dmg[1]);
	}
	
	
	
	
}ezoj1124;

