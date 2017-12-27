using namespace std;
int main(){}
#include<complex>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<algorithm>
const double eps=1e-8;
const double pi=acos(-1.0);
int reverse(int a,int len){
	int ret=0;len>>=1;
	while(len){
		ret<<=1;
		ret|=a&1;
		a>>=1;
		len>>=1;
	}
	return ret;
	
}
void FFT(complex<double> *Dst,int len,int kind=1){
	int i,j,k,t;complex<double> x,y,wn,w;
	for(i=0;i<len;i++) if(i<(j=reverse(i,len))){
		swap(Dst[i],Dst[j]);
	}
	for(i=1;i<len;i<<=1){
		wn.imag(sin(pi*kind/i)); wn.real(cos(kind*pi/i)); 
		for(j=0;j<len;j+=(i<<1)){
			w.real(1);w.imag(0);
			for(k=0;k<i;k++){
				x=Dst[t=j+k];y=w*Dst[t+i];
				Dst[t]=x+y;Dst[t+i]=x-y;
				w*=wn;
			}
		}
	}
	if(kind==-1) for(i=0;i<len;i++){
		Dst[i]/=len;
	}
}


struct _Main{
char buf[100010];
complex<double> a[270000],b[270000];
int ans[210000];
int len,la,lb;
_Main(){
	int i,j,k;
	scanf("%s",buf);
	la=strlen(buf);
	for(i=la-1;i>=0;i--){
		a[la-i-1]=buf[i]-'0';
	}
	scanf("%s",buf);
	lb=strlen(buf);
	for(i=lb-1;i>=0;i--){
		b[lb-i-1]=buf[i]-'0';
	}
	len=1<<(int)ceil(log(la+lb+2)/log(2));
	FFT(a,len);FFT(b,len);
	for(i=0;i<len;i++){
		b[i]=a[i]*b[i];
	}
	FFT(b,len,-1);
	len=la+lb+2;
	for(i=0;i<len;i++){
		ans[i+1]+=(int)(round(ans[i]+b[i].real()+eps)/10);
		ans[i]=(int)round(ans[i]+b[i].real()+eps)%10;
	}
	for(i=len-1;i>=0;i--){
		if(ans[i]>0)break;
	}
	if(i<=0){
		printf("0");
	}
	for( ;i>=0;i--){
		printf("%d",ans[i]);
	}
}

}FFTInstance;
