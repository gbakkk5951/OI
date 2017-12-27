int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<cstring>
struct _Main{

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
template<typename Type>
	void readbit(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a<<=1;
			a|=t-'0';
		}
	}	
class FWT{
public:
void Or(long long *a,int l){
	int i,j,k;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				a[i+k+j]+=a[k+j];
			}
		}
	}
}
void nOr(long long *a,int l){
	int i,j,k;
	for(i=1;i<l;i<<=1){
		for(j=0;j<l;j+=(i<<1)){
			for(k=0;k<i;k++){
				a[i+j+k]-=a[j+k];
			}
		}
	}
}	
	
}calc;
long long a[270029];
long long b[270029];
_Main(){
int T;int n,q,m;int i,j,k;int num;
	read(T);
	for(k=1;k<=T;k++){
		read(n);read(m);
		m=1<<m;
		for(i=0;i<n;i++){
			readbit(num);
			a[num]++;
		}
		for(i=0;i<n;i++){
			readbit(num);
			b[num]++;
		}
		calc.Or(a,m);
		calc.Or(b,m);
		for(i=0;i<m;i++){
			a[i]*=b[i];
		}
		calc.nOr(a,m);
		read(q);
		printf("Case #%d:\n",k);
		for(i=0;i<q;i++){
			readbit(num);
			printf("%d\n",a[num]);
		}
		memset(a,0,m*sizeof(long long));
		memset(b,0,m*sizeof(long long));
	}	
	
	
	
	
}	
	
	
	                                                                                                                                                                                                                                                                                                                                                                                                                                                       
}csu1911;
