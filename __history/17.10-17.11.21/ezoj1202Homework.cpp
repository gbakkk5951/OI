using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
namespace Protector{
const int sq=550;
struct List {
	List *r;
	int val;
	List (){
		r=0;val=-1;
	}
	List * lower_bound(){
		return (val!=-1 || !r)?this:(r=r->lower_bound());
	}
}list[300050];
struct Oper{
	int val; 
	char type; // 1Îª²åÈë 2ÎªÉ¾³ý£»
}oper[100010];
int ansidx;
int ans[100010];
int modmn[sq+5];
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

char operchar[5];

_Main(){
	int mx=0;
	int i,j,k;
	int Q;
	int n;
	int a;
	memset(modmn,63,sizeof(modmn));
	read(n);
	for(Q=1;Q<=n;Q++){
		scanf("%s",operchar);
		read(a);
		oper[Q].type=operchar[0]-'A'+1;
		oper[Q].val=a;
		switch (operchar[0]){
			case 'A' : {
				for(i=1;i<=sq;i++){
					modmn[i]=min(modmn[i],a%i);
				}
				list[a].val=a;
				mx=max(mx,a);
				break;
			}
			case 'B' : {
				ansidx++;
				if(a<=sq){
					ans[ansidx]=modmn[a];
				}
				break;
			}
			
		}
	}
	for(i=0;i<=mx;i++){
		list[i].r=&list[i+1];
	}
	int lst;
	int ndans;
	for(Q=n,k=ansidx;Q>=1;Q--){
		
		switch (oper[Q].type){
			case 1 :{
				list[oper[Q].val].val=-1;
				break;
			}
			case 2:{
				if(oper[Q].val>sq){
					ndans=0x3f3f3f3f;
					lst=-1;
					for(j=0;j<=mx;j=(lst/oper[Q].val+1)*oper[Q].val ){
						lst=list[j].lower_bound()->val;
						if(lst!=-1){
							ndans=min(ndans,lst%oper[Q].val);
						}else{
							break;
						}
					}
					ans[k]=ndans;
				}
				--k;
				break;
			}
		}
	}
	for(i=1;i<=ansidx;i++){
		printf("%d\n",ans[i]);
	}
	
	
}


	
	
	
	
}ezoj1202;


}
