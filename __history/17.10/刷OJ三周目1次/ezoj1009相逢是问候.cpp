int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
long long phi[35];
long long arr[50005];
long long tree[50005];
long long org[50005];
int n;
int pcnt;
struct List{
	List *r;
	int idx;int cnt;
	List * getright(){
		if(r && r->cnt>pcnt){
			r=r->getright();
		}return r;
	}
}list[50005];
void getphi(){
	int i;int g;int p;
	while(phi[pcnt]!=1){
		p=phi[pcnt];
		phi[++pcnt]=p;
		g=sqrt(p);
		for(i=2;i<=g;i++){
			if(p%i==0){
				phi[pcnt]/=i;
				phi[pcnt]*=i-1;
				while(p%i==0){
					p/=i;
				}
			}
		}
		if(p>1){
			phi[pcnt]/=p;
			phi[pcnt]*=p-1;
		}
	}
	phi[++pcnt]=1;
}
template<typename Type>
	Type lb(Type a){
		return a&(-a);
	}
struct _Main{
long long getsum(int nd){
	long long ans=0;
	for(;nd;nd-=lb(nd)){
		ans+=tree[nd];
	}return ans;
}
long long add(int nd,long long val){
	for(;nd<=n;nd+=lb(nd)){
		tree[nd]+=val;
	}
}
long long query(int l,int r){
	return (getsum(r)-getsum(l-1))%phi[0];
}
long long fastpower(long long base,long long pow,int pos){
	long long ans=1;
	while(pow){
		if(base>=phi[1]){
			modflag=true;
			base%=phi[pos];
		}
		if(pow&1){
			ans=ans*base;
			if(ans>=phi[1]){
				modflag=true;
			}
			if(modflag){
				ans%=phi[pos];
			}
		}
		base=base*base;
		if(modflag){
			base%=phi[pos];
		}
		pow>>=1;
	}
	return ans;
}


long long calc(int idx,int times,int pow){
	long long p;
	if(pow<times){
		p=calc(idx,times,pow+1);
		if(modflag){
			p+=phi[pow+1];
		}
	}else{
		return org[idx];
	}
	return fastpower(c,p,pow);
}
long long c;
bool modflag;

long long change(int l,int r){
	List *now=&list[l];
	if(now->cnt >pcnt)now=now->getright();
	while(now && now->idx<=r){
		add(now->idx ,-arr[now->idx]);
		modflag=false;
		arr[now->idx]=calc(now->idx,++now->cnt,0);
		add(now->idx,arr[now->idx]);
		now=now->getright();
	}
}
void buildtree(){
	int i;
	for(i=1;i<=n;i++){
		tree[i]+=arr[i];
		if(i+lb(i)<=n){
			tree[i+lb(i)]+=tree[i];
		}
	}
}

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

_Main(){
	int m;read(n);read(m);read(phi[0]);read(c);
	getphi();
	int i;int a,b,c;
	for(i=1;i<=n;i++){
		read(org[i]);arr[i]=org[i];
	}buildtree();
	list[1].idx=1;
	for(i=2;i<=n;i++){
		list[i].idx=i;
		list[i-1].r=&list[i];
	}
	
	for(i=0;i<m;i++){
		read(a);read(b);read(c);
		switch(a){
			case 0:{
				change(b,c);
				break;
			}
			case 1:{
				printf("%lld\n",query(b,c)%phi[0]);
				break;
			}
			
		}		
	}
}	
}ezoj1009;


