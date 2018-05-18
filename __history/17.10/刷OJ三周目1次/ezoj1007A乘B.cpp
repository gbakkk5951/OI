int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
const double pi=acos(-1);
struct _Main{
int rev(int a,int len){
	int ans=0;
	for(len>>=1;len;len>>=1){
		ans<<=1;
		if(a&1){
			ans|=1;
		}
		a>>=1;
	}return ans;
}
void FFT(complex<double> *a, int len,int kind=1){
	int i,j,k;complex<double>x,y,w,wn;
	for(i=0;i<len;i++) if((j=rev(i,len))<i){
		swap(a[j],a[i]);
	}
	for(i=1;i<len;i<<=1){
		wn.real(cos(pi/i) );wn.imag(sin(kind*pi/i));
		for(j=0;j<len;j+=(i<<1)){
			w.real(1);w.imag(0); 
			for(k=0;k<i;k++){
				x=a[j+k];y=a[j+k+i]*w;
				a[j+k]=x+y;
				a[j+k+i]=x-y;
				w*=wn;
			}
		}
	}
	if(kind==-1){
		for(i=0;i<len;i++){
			a[i]/=len;
		}
	}
}
char sa[100010],sb[100010];
complex<double>a[270010],b[270010];
int ans[270010];
int la,lb,len;
_Main(){
	int i,j,k;
	scanf("%s%s",sa,sb);
	la=strlen(sa);lb=strlen(sb);
	len=1<<(int)ceil(log(la+lb+2)/log(2));
	for(i=0;i<la;i++){
		a[i].real(sa[la-i-1]-'0');
	}
	for(i=0;i<lb;i++){
		b[i].real(sb[lb-i-1]-'0');
	}
	FFT(a,len);FFT(b,len);
	for(i=0;i<len;i++){
		a[i]*=b[i];
	}FFT(a,len,-1);
	for(i=0;i<len;i++){
		ans[i]+=round(a[i].real());
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	for(i=len;i>=0;i--) if(ans[i]){
		break;
	}
	if(i<0){
		putchar('0');
	}else{
		for( ; i>=0;i--){
			printf("%d",ans[i]);
		}
	}
}	
	
}ezoj1007;
