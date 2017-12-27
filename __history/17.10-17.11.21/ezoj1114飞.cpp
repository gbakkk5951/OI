using namespace std;
int main(){}
#include<cstdio>
#include<cctype>

int n,x,a,mod;

struct ArrayTree{
public:
	int query(int nd){
		int ans=0;
		for(nd++;nd>0;nd-=lowbit(nd)){
			ans+=node[nd];
		} return ans;
	}
	void insert(int nd){
		for(nd++;nd<=a;nd+=lowbit(nd)){
			node[nd]++;
		}
	}
private:
	int inline lowbit(int a){
		return a&(-a);
	}
	int node[100010];
}tree;

struct _Main{
long long  begblock,bn,ri,tot,pos;
long long  loops;
long long ans,tmp;
_Main(){
	scanf("%d%d%d%d",&n,&x,&a,&mod);
	a%=mod;x%=mod;
	pos=x%a;
	begblock=x/a;
	bn=mod/a;
	ri=mod%a;
	tot=(mod-x+a-1)/a;
	n-=tot;
	x=(x+tot*a)%mod;
	while(1){
		if((mod-x+a-1)/a>n)break;
		ans+=(tree.query(a-1)-tree.query(x))*bn+(bn-1+0)*bn/2 *loops;
	
		ans+=tree.query(ri-1)*bn;
		if(x<ri )ans+=tree.query(ri-1)-tree.query(x);
		
		ans+=begblock*tot;
		tmp=ans;
		
		if(x<pos){
			ans+=(bn-begblock+1)*(bn-begblock)/2;
			if(pos<=ri -1)ans+=(bn-begblock)+1;
		}else{
			ans+=(bn-begblock-1+0)*(bn-begblock)/2;
			if(pos<=ri -1)ans+=bn-begblock;
		}
		
		tree.insert(x);
		loops++;
		n-=(mod-x+a-1)/a;
		x=(x+((mod-x+a-1)/a)*a)%mod;
	}
	if(n>0){
		tmp=ans;
		ans+=n*tree.query(ri-1);
		ans+=n*(tree.query(a-1)-tree.query(x));
		ans+=(bn-1+bn-n)*n/2*loops;
		if(n>begblock){
			
			ans+=tot*begblock;
			n-=begblock;
			if(x<pos){
				tmp=ans;
				ans+=(bn-begblock+bn-begblock-n+1)*n/2;
				if(pos<=ri -1)ans+=n;
			}else{
				ans+=(bn-begblock-1+bn-begblock-n)*n/2;
				if(pos<=ri -1)ans+=n;
			}
		}else{
			ans+=tot*n;
		}
	}

	printf("%lld",ans);
}



}ezoj1114;

