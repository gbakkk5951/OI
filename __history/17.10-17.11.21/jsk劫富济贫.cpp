using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
namespace Protector{
	
const long long mod[2]={10003027LL,773165616977319117LL};
const long long base[2]={37LL,31LL};
struct Name{
	Name(){
		hash[0]=hash[1]=0;
	}
	long long hash[2];
};
void readname(Name &ret){
	char t;
	while(!isalpha(t=getchar()));
	ret.hash[1]=ret.hash[0]=t-'a'+1;
	while( isalpha(t=getchar())){
		((ret.hash[0]*=base[0])+=t-'a'+1)%=mod[0];
		((ret.hash[1]*=base[1])+=t-'a'+1)%=mod[1];	
	}
}

int head[10005010];
struct List{
	int nxt;
	long long hash;
	int val;
}list[3000010];
int lidx;

void inline add(Name obj,int val){
	lidx++;
	list[lidx].nxt=head[obj.hash[0]];
	head[obj.hash[0]]=lidx;
	list[lidx].hash=obj.hash[1];
	list[lidx].val=val;
}
int find(Name obj){
	int i;
	for(i=head[obj.hash[0]];i;i=list[i].nxt){
		if(list[i].hash==obj.hash[1]){
			return list[i].val;
		}
	}
	return -1;
}
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
	_Main(){
		long long res;
		Name tmp;
		char t;
		int i,j,k;
		int a,b,c;
		read(n);
		for(i=1;i<=n;i++){
			readname(tmp);read(a);
			add(tmp,a);
		}
		read(m);
		for(i=1;i<=m;i++){
			read(a);
			res=0;
			for(j=1;j<=a;j++){
				if(res!=-1){
					readname(tmp);
					b=find(tmp);
					if(b==-1){
						res=-1;
					}else{
						res+=b;
					}
				}else{
					while(!isalpha(t=getchar()));
					while( isalpha(t=getchar()));
				}
			}
			printf("%lld\n",res);
		}
		
	}
	
}jsk;


}
