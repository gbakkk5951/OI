#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
/*
int n;
double f[11000];

double dec(double a,double b){
	return b+log(exp(a-b)-1);
}

double inc(double a,double b){
	if(a<b)swap(a,b);
	return b+log(exp(a-b)+1);
}

double Fabs(double x){
	return x>0?x:-x;
}

void dec(double &a,int &b,double c){
	if(b==0){
		b=-1;
		a=c;
	}else if(b<0){
		a=inc(a,c);
	}else if(Fabs(a-c)<1e-10){
		b=0;
		a=0;
	}else if(a>c){
		a=dec(a,c);
	}else {
		a=dec(c,a);
		b=-1;
	}
}

void inc(double &a,int &b,double c){
	if(b==0){
		b=1;
		a=c;
	}else if(b>0){
		a=inc(a,c);
	}else if(Fabs(a-c)<1e-10){
		b=0;
		a=0;
	}else if(a>c){
		a=dec(a,c);
	}else{
		a=dec(c,a);
		b=1;
	}
}

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d\n",&n);
	if(n==1){
		printf("%.4lf",exp(-1.0));
		return 0;
	}f[0]=-1.0;
	f[1]=0;
	for(int i=1;i<=n;i++){
		f[i+1]=0;
		double add=log(i);
		for(int j=0;j<=i;j++){
			f[j]+=add;
		}
	}double ans=0;int tag=0;
	for(int i=0;i<=n+1;i++){
//		printf("%ce^%f%ce^%f=",tag==1?'+':'-',ans,((n-i)%2==0)?'-':'+',f[i]);
		if((n-i)%2==0)dec(ans,tag,f[i]);
		else inc(ans,tag,f[i]);
//		printf("%ce^%f\n",tag==1?'+':'-',ans);
	}printf("%.4lf",tag*exp(ans));
	return 0;
}*/

int n;

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	double ans=0,tmp=1.0,div=n+1;
	while(tmp>=1e-20){
		tmp/=div;
		if(((int)div-n)%2==1)ans=ans+tmp;
		else ans=ans-tmp;
		div++;
	}printf("%.4lf\n",ans);
	return 0;
}

