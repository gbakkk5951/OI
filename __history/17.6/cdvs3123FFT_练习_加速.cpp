#include<cmath>
#include<cstdio>
#include<cstring>
#include<complex>
#include<ctime>
using std::complex;
const double pi=acos(-1);
char a1[100010];
char b1[100010];
complex<double> a[270000];
complex<double> b[270000];
complex<double>	temp[270000];
complex<double> c_ans[270000];
complex <double>wn[20];
struct _Main{
int la,lb;
int n;

void transform(){
	int i,j,k=0;
	for(i=0;i<la;i++){
		a[i]=a1[la-i-1]-'0';
	}
	for(i=0;i<lb;i++){
		b[i]=b1[lb-i-1]-'0';
	}
}

_Main(){
	scanf("%s",a1);
	scanf("%s",b1);
	la=strlen(a1);
	lb=strlen(b1);
	transform();
	n=1<<(int)ceil(
		log( la + lb + 1 ) / log(2)
	);
	int i,j=n;
	for(i=0;i<20;i++){
		wn[i].real(cos((double)2*pi/j));
		wn[i].imag(sin((double)2*pi/j));	
		j>>=1;
	}
	FFT(a,0,n-1,0);
	FFT(b,0,n-1,0);
	for(i=0;i<n;i++){
		c_ans[i]=a[i]*b[i];
	}
	j=n;
	for(i=0;i<20;i++){
		wn[i].real(cos((double)-2*pi/j));
		wn[i].imag(sin((double)-2*pi/j));	
		j>>=1;
	}
	FFT(c_ans,0,n-1,0);
	for(i=0;i<n;i++){
		c_ans[i]/=n;
	}
	for(i=0;i<n-1;i++){
		c_ans[i+1].real(c_ans[i+1].real()+(long long)round(c_ans[i].real()) /10) ;
		c_ans[i].real((long long)round(c_ans[i].real())%10) ;
	}
	for(i=n-1;i>=0;i--){
		if(round(c_ans[i].real() )!=0){
			break;
		}
	}
	
	
	if(i<0){
		printf("0");
	}
	for(;i>=0;i--){
		printf("%.0f",c_ans[i].real());
	}
	
}

void FFT(complex<double> *base,int l,int r,char iter){
	if(l==r){
		return;
	}
	int pn=r-l+1;
	int i,j;
	j=pn>>1;
	complex<double>w=1;
	complex<double>t;	
	if(iter&1){
		for(i=0;i<j;i++){
			base[l+i]=temp[l+(i<<1)];
		}
		for(;i<pn;i++){
			base[l+i]=temp[l+(i-j<<1)+1];
		}	
		FFT(base,l,l+(r-l>>1),iter+1);
		FFT(base,l+(r-l>>1)+1,r,iter+1);	

		for(i=0;i<j;i++){
			t=w*base[l+i+j];
			temp[l+i]=base[l+i]+t;
			temp[l+i+j]=base[l+i]-t;	
			w*=wn[iter];	
		}
	}else{
		for(i=0;i<j;i++){
			temp[l+i]=base[l+(i<<1)];
		}
		for(;i<pn;i++){
			temp[l+i]=base[l+(i-j<<1)+1];
		}
		FFT(base,l,l+(r-l>>1),iter+1);
		FFT(base,l+(r-l>>1)+1,r,iter+1);	
		for(i=0;i<j;i++){
			t=w*temp[l+i+j];
			base[l+i]=temp[l+i]+t;
			base[l+i+j]=temp[l+i]-t;	
			w*=wn[iter];	
		}		

	}
}

}cdvs3123;




int main(){}

