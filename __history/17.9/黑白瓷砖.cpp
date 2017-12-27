using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
int rev[22];
int rot[22];
int org;
const long long mod=1e9;
struct big{
	long long num[8];int high;
	void inline zero(){
		memset(this,0,sizeof(big));
	}
	template<typename Type>
	big (Type org){
		*this=org;
	}
	big (){
		
	}
	template<typename Type>
	big operator = (Type b){
		zero();num[0]=b;
		if(num[0]>=mod){
			num[1]+=num[0]/mod;num[0]%=mod;
			high=1;
			if(num[1]>=mod){
				num[2]+=num[1]/mod;num[1]%=mod;
				high=2;
			}
		}
		return *this;
	}
	big operator = (const big &b){
		memcpy(this,&b,sizeof(big));
		return *this;
	}
	inline long long & operator [] (int idx){
		return num[idx];
	}
	big friend operator + (big a,big b){
		int i;
		for(i=0;i<=a.high || i<=b.high;i++){
			a[i]+=b[i];
			if(a[i]>=mod){
				a[i+1]+=a[i]/mod;a[i]%=mod;
			}
		}
		for(i=min(7,max(a.high ,b.high )+1);i>0;i--){
			if(a[i]){
				a.high =i;
				break;
			}
		}
		return a;
	}
	big friend operator * (big a,big b){
//		a.print() ;printf("*");b.print();printf("\n");
		
		int i,j;big ret(0);
		for(i=0;i<=a.high ;i++){
			for(j=0;j<=b.high ;j++){
				if(ret[i+j]>=mod){
					ret[i+j+1]+=ret[i+j]/mod;
					ret[i+j]%=mod;
				}				
				ret[i+j]+=a[i]*b[j];
				if(ret[i+j]>=mod){
					ret[i+j+1]+=ret[i+j]/mod;
					ret[i+j]%=mod;
				}
			}
		}
		for(i=min(a.high +b.high +1,7);i>=0;i--){
			if(ret[i]){
				ret.high =i;break;
			}
		}
		return ret;
	}
	template<typename Type>
	big friend operator / (big &a,Type &b){
		big ret(a);int i;
		for(i=ret.high;i>=0;i--){
			if(i)ret[i-1]+=mod*(ret[i]%b);
			ret[i]/=b;
		}
		for(i=ret.high ;i>=0;i--){
			if(ret[i]){
				ret.high =i;break;
			}
		}return ret;
	}
	template<typename Type>
	inline big friend operator >> (big a,Type &b){
		int i;
		for(i=1;i<=b;i++){
			a/=2;
		}
		return a;
	}
	template<typename Type>
	inline big operator >>=	(Type a){
		return *this=*this>>a;
	}
	template<typename Type>
	inline big friend operator << (big a,Type b){
		int i;
		for(i=1;i<=b;i++){
			a*=2;
		}
		return a;
	}
	template<typename Type>
	inline big operator <<=	(Type a){
		return *this=*this<<a;
	}
	template<typename Type>
	inline big operator /=	(Type a){
		return *this=*this/a;
	}
	template<typename Type>
	inline big operator *=	(Type a){
		return *this=*this*a;
	}
	
	template<typename Type>
	inline big operator +=	(Type a){
		return *this=*this+a;
	}	
	
	template<typename Type>
	inline big friend operator * (big a,Type b){
		big tmp(b);
		return tmp*a;
	}
	template<typename Type>
	inline big friend operator * (Type b,big a){
		big tmp(b);
		return tmp*a;
	}
	template<typename Type>
	inline big friend operator + (big a,Type b){
		big tmp(b);
		return tmp+a;
	}
	template<typename Type>
	inline big friend operator + (Type b,big a){
		big tmp(b);
		return tmp+a;
	}	
	void print(){
		int i;
		printf("%lld",num[high]);
		for(i=high-1;i>=0;i--){
			printf("%09lld",num[i]);
		}
		
	}
};
struct _Main{
void ini(){
	int i;org=n*(n+1)/2;
	rev[1]=rot[1]=rot[2]=1;
	for(i=2;i<=n;i++){
		rev[i]=rev[i-1]+((i+1)/2);
	}
	for(i=3;i<=n;i++){
		rot[i]=rot[i-3]+i-1;
	}
}
int n;
template<typename Type1,typename Type2>
big fastpower(Type1 basein,Type2 pow){
	big base(basein),ans(1);
	while(pow){
		if(pow&1){
			ans*=base;
		}
		if(pow>>=1)base*=base;
	}
	return ans;
}
big sum;
_Main(){
	int i,j;
	scanf("%d",&n);
	ini();
	sum+=fastpower(2,org);
	sum+=fastpower(2,rot[n])*2;	
	sum+=fastpower(2,rev[n])*3;
	sum/=6;
	sum.print() ;		
}	
	
	
	
}jsk;
