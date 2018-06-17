#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int get(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ex(int a,int b,int &x,int &y){	
	int d,t;	
	if(b==0) {d=a;x=1;y=0;}	
	else {		
		d=ex(b,a%b,x,y);		
		t=x;x=y;y=t-(a/b)*y;	
	}	
	return d;
}
int n;
int main(){
  freopen("final.in","r",stdin);
  freopen("final.out","w",stdout);
	n=get();
	if(n==2){
		int x,y,a,b;
		a=get();b=get();
		ex(a,-b,x,y);
		cout<<x<<" "<<y<<endl;
		return 0;
	}
	return 0;
}

