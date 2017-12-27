using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cmath>
const double pi=asin(1);
char ca[100010];
char cb[100010];
complex<double> a[270010],b[270010],c[270010],t[2][270010];
complex<double> wn[20];
int ans[270010];
struct _Main{
int L_b;
int lenth;
int la,lb;
_Main(){	

	int i,j,k;
	scanf("%s%s",ca,cb);
	la=strlen(ca);
	lb=strlen(cb);
	L_b=ceil(log(la+lb+1)/log(2));
	lenth=1<<L_b;
	for(i=0,la--;i<=la;i++){
		a[i]=ca[la-i]-'0';
	}la++;
	for(i=0,lb--;i<=lb;i++){
		b[i]=cb[lb-i]-'0';
	}lb++;	
	for(i=1;i<=L_b;i++){
		wn[i].imag(sin(2.0*pi/(double)(1<<(i-1))));
		wn[i].real(cos(2.0*pi/(double)(1<<(i-1))));
	}
	FFT(a);
	FFT(b);
	for(i=1;i<=L_b;i++){
		wn[i].imag(sin(-2.0*pi/(double)(1<<(i-1))));
		wn[i].real(cos(-2.0*pi/(double)(1<<(i-1))));
	}
	for(i=0;i<lenth;i++){
		c[i]=a[i]*b[i];
	}
	FFT(c);
	int t;
	for(i=0;i<lenth;i++){
		c[i]/=lenth;
	}

	
	
	for(i=0;i<lenth;i++){
		if((ans[i]+=round(c[i].real()))>=10){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	for(i=lenth;i>=0;i--){
		if(ans[i]){
			break;
		}
	}
	if(i<0) putchar('0');
	for(;i>=0;i--){
		putchar(ans[i]+'0');
	}
}	
int reverse(int num){
	int ans=0;
	int i;
	for(i=0;i<L_b;i++){
		ans<<=1;
		ans|=num&1;
		num>>=1;
	}
	return ans;
}
void FFT(complex<double> *l){
	int i,j,k;
	int iter=0;
	
	for(i=0;i<lenth;i++){
		t[iter][reverse(i)]=l[i];
	}
	complex<double>w;
	complex<double>t2;
	int mid,step;
	int s;
	for(i=1;i<=L_b;i++){
		iter^=1;
		mid=1<<(i-1);
		step=1<<i;
		for(j=0;j<lenth;j+=step){
			w=1;
			for(k=0;k<mid;k++){
				s=j+k;
				t2=w*t[iter^1][s+mid];
				t[iter][s]=t[iter^1][s]+t2;
				t[iter][s+mid]=t[iter^1][s]-t2;
				w*=wn[i];
			}
		}
	}
	memcpy(l,t[iter],lenth*sizeof(complex<double>));
}
	
	
	
	
	
	
	
	
}cdvs3123;
