using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

const long long mod=(long long)1e9;
struct big{
private:long long num[175];
public:
int high;
void operator - (){
	int i;
	for(i=0;i<=high;i++){
		num[i]=-num[i];
	}
	
}
void abs(){
	int i;
	for(i=0;i<=high;i++){
		num[i]=num[i]>>63^((num[i]>>63)+num[i]);
	}
}
bool operator < ( big &a){
	if(high!=a.high){
		return high<a.high;
	}else{
		int i;
		for(i=high;i>=0;i--){
			if(num[i]!=a[i]){
				return num[i]<a[i];
			}
		}
		return false;
		
	}
	
}
long long & operator [] (int idx){
	return num[idx];
}
void zero(){
	int i;
	for(i=0;i<=high;i++){
		num[i]=0LL;
	}high=0;
}
void print(){
	int i;
	printf("%lld",num[high]);
	for(i=high-1;i>=0;i--){
		printf("%09lld",num[i]);
	}
}

big(){
	memset(this,0,sizeof(big));
}
}a1,a2,t1,t2;
void mul( big &a, big &b,big &dst){
	int i,j;
	dst.zero();
	for(i=0;i<=a.high;i++){
		for(j=0;j<=b.high ;j++){
			dst[i+j+1]+=dst[i+j]/mod;
			dst[i+j]%=mod;
			dst[i+j]+=a[i]*b[j];
			dst[i+j+1]+=dst[i+j]/mod;
			dst[i+j]%=mod;			
		}
	}
	dst.high=0;
	for(i=0;i<=a.high+b.high+1 || j;i++){
		j=0;
		if(dst[i]){
			dst.high=i;
			if(dst[i]>=mod){
				dst[i+1]+=dst[i]/mod;
				dst[i]%=mod;
				j=1;
			}
		}
	}
}
void add( big &a,big &b,big &dst,bool zero=true){
	if(zero){
		dst.zero();
	}
	int i;int sig=0;
	for(i=0;i<=max(a.high ,b.high ) || sig;i++){
		dst[i]=a[i]+b[i]+sig;
		if(dst[i]>=mod){
			dst[i]-=mod;
			sig=1;
		}else{
			if(dst[i]<0){
				dst[i]+=mod;
				sig=-1;
			}else{
				sig=0;	
			}
		}
	}
	dst.high =0;
	for(i=max(a.high ,b.high) +1;i>=0;i--){
		if(dst[i]){
			dst.high=i;
			return ;
		}
	}
}
void inline minus(big &a,big &b,big &dst,bool zero=true){
	if(a<b){
		-a;
		add(b,a,dst,zero);
		-a;
	}else{
		-b;
		add(a,b,dst,zero);
		-b;
	}
}
int a;
struct _Main{
_Main(){
//	printf("(n^2) ! ~= 1e %.2f",ceil( (log(sqrt(acos(-1.0)*2*625.0))-625.0+625.0*log(625.0) )/ log(10.0) ));
	//
	int i,j;//a2平方阶乘，a1阶乘平方 
	a2[0]=1;

	scanf("%d",&a);
	for(i=2;i<=a*a;i++){
		t1[0]=i;
		mul(a2,t1,t2);
		a2=t2;
	}
	a1[0]=1;
	for(i=2;i<=a;i++){
		t1[0]=i;
		mul(a1,t1,t2);
		a1=t2;
	}
	t1=t2=a1;
	mul(t1,t2,a1);
	a2.print();
	printf("\n");
	a1.print();
	printf("\n");
	add(a1,a2,t1);
	t1.print();
	printf("\n");
	minus(a1,a2,t1);
	t1.print();
}


}cdvs6397;
