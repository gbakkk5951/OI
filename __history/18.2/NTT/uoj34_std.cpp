#include<cstdio>
#include<cmath>
#include<algorithm>
#include <ctime>
using namespace std;
const double pi=acos(-1.0);

struct cp{
	double a,b;
	cp operator +(const cp &o)const{return (cp){a+o.a,b+o.b};}
	cp operator -(const cp &o)const{return (cp){a-o.a,b-o.b};}
	cp operator *(const cp &o)const{return (cp){a*o.a-b*o.b,b*o.a+a*o.b};}
	cp operator *(const double &o)const{return (cp){a*o,b*o};}
	cp operator !()const{return (cp){a,-b};}
}x[1050000],y[1050000],z[1050000],w[1050000];
void fft(cp x[],unsigned k,unsigned v){
	for(unsigned i=0,j=0;i<k;i++){
		if(i>j)swap(x[i],x[j]);
		for(unsigned l=k>>1;(j^=l)<l;l>>=1);
	}
	w[0]=(cp){1,0};
	for(unsigned i=2;i<=k;i<<=1){
		cp g=(cp){cos(2*pi/i),(v?-1:1)*sin(2*pi/i)};
		for(int j=(i>>1);j>=0;j-=2)w[j]=w[j>>1];
		for(unsigned j=1;j<i>>1;j+=2)w[j]=w[j-1]*g;
		for(unsigned j=0;j<k;j+=i){
			cp *a=x+j,*b=a+(i>>1);
//#pragma GCC ivdep
			for(unsigned l=0;l<i>>1;l++){
				cp o=b[l]*w[l];
				b[l]=a[l]-o;
				a[l]=a[l]+o;
			}
		}
	}
	if(v)for(unsigned i=0;i<k;i++)x[i]=(cp){x[i].a/k,x[i].b/k};
}

unsigned n,m,l,K;
int main(){
    float ta = clock();
    n = m = 5e5;
//	n=it,m=it;
//	for(unsigned i=0;i<=n;i++)(i&1?x[i>>1].b:x[i>>1].a)=it;
//	for(unsigned i=0;i<=m;i++)(i&1?y[i>>1].b:y[i>>1].a)=it;
	for(K=1;K<=n+m+1;K<<=1);
	fft(x,K,0);fft(y,K,0);
	/*for(unsigned i=0;i<K;i++){
		unsigned j=K-1&K-i;
		x[i] = x[i] * y[i];
//		z[i]=(x[i]*y[i]*4-(x[i]-!x[j])*(y[i]-!y[j])*(((i&K>>1)?(cp){1,0}-w[i^K>>1]:w[i]+(cp){1,0})))*0.25;
	}*/
	fft(x,K,1);
	printf("%f", clock() - ta);
//	for(unsigned i=0;i<=n+m;i++)if(i&1)it.out((int)(z[i>>1].b+0.1));else it.out((int)(z[i>>1].a+0.1));
	return 0;
}

