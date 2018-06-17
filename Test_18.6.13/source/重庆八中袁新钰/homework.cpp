#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define tm ndhsfjk
#define y1 cjdksl
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-') f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f) x=-x;
			return ;
		}
}
//*********************************************

#define MAXN 10000
typedef long long LL;

int n;

namespace Part1{
double f[MAXN+10];
void solve(){
	f[0]=1-exp(-1);
	for(int i=1;i<=n;i++)
		f[i]=1-i*f[i-1];
	printf("%.4f\n",f[n]);
}
}

namespace Part2{
#define MAXL 100000
int a[MAXL+10],b[MAXL+10],c[MAXL+10],d[MAXL+10],f[MAXL+10],g[MAXL+10],h[MAXL+10],c2[MAXL+10];
void Multi(int *a,int d){
	int len=abs(a[0]);
	for(int i=1;i<=len;i++)
		a[i]*=d;
	len+=5;
	for(int i=1;i<=len;i++){
		a[i+1]+=a[i]/1000;
		a[i]%=1000;
	}
	while(len>1&&!a[len]) len--;
	if(a[0]>0) len*=-1;
	a[0]=len;
}
void Add(int *a,int d){
	int len=abs(a[0])+1;
	a[1]+=a[0]<0?-1:1;
	for(int i=1;i<=len;i++){
		a[i+1]+=a[i]/1000;
		a[i]%=1000;
	}
	while(len>1&&!a[len]) len--;
	a[0]=(a[0]<0?-1:1)*len;
}
void Multi2(int *a,int *b,int *c){
	int len=abs(a[0])+abs(b[0]);
	for(int i=1;i<=abs(a[0]);i++)
		for(int j=1;j<=abs(b[0]);j++)
			c[i+j-1]+=a[i]*b[j];
	len+=5;
	for(int i=1;i<=len;i++){
		c[i+1]+=c[i]/1000;
		c[i]%=1000;
	}
	while(len>1&&!c[len]) len--;
	c[0]=(a[0]<0?-1:1)*(b[0]<0?-1:1)*len;
}
void Minus(int *a,int *b,int *c){
	int len=max(abs(a[0]),abs(b[0]))+5;
	for(int i=1;i<=len;i++){
		c[i]+=a[i]-b[i];
		if(c[i]<0) c[i]+=1000,c[i+1]--;
	}
	while(len>1&&!c[len]) len--;
	c[0]=len;
}
int cmp(int *a,int *b){
	for(int i=max(abs(a[0]),abs(b[0]));i;i--)
		if(a[i]>b[i]) return 1;
		else if(a[i]<b[i]) return -1;
	return 0;
}
void Add2(int *a,int *b,int *c){
	if(a[0]<0&&b[0]>0||a[0]>0&b[0]<0){
		if(cmp(a,b)>0){
			Minus(a,b,c);
			if(a[0]<0) c[0]*=-1;
		}else{
			Minus(b,a,c);
			if(b[0]<0) c[0]*=-1;
		}
	}else{
		int len=max(abs(a[0]),abs(b[0]))+5;
		for(int i=1;i<=len;i++){
			c[i]+=a[i]+b[i];
			c[i+1]+=c[i]/1000;
			c[i]%=1000;
		}
		while(len>1&&!c[len]) len--;
		c[0]=(a[0]<0?-1:1)*len;
	}
}
void Trans(int *a,int *b){
	int len=abs(a[0])*3;
	for(int i=1,j=1;i<=len;i+=3,j++){
		b[i]=a[j]%10,b[i+1]=a[j]%100/10,b[i+2]=a[j]/100;
	}
	while(len>1&&!b[len]) len--;
	b[0]=(a[0]<0?-1:1)*len;
}

void Upd(int *a){
	int len=abs(a[0])+5;
	for(int i=1;i<=len;i++){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(len>1&&!a[len]) len--;
	a[0]=(a[0]<0?-1:1)*len;
}
void print(int *a){
	if(a[0]<0) printf("-");
	for(int i=abs(a[0]);i;i--)
		printf("%d%d%d",a[i]/100,a[i]%100/10,a[i]%10); //puts("");
}
void solve(){
	a[0]=-1,a[1]=1;
	b[0]=1,b[1]=1;
	for(int i=1;i<=n;i++){
		//a'=-i*a b'=-i*b+1
		Multi(a,i),Multi(b,i),Add(b,1);
		//print(a),printf(" "),print(b),puts("");
	}
	//print(a),printf(" "),print(b),puts("");
	c[0]=max(abs(a[0])*2,abs(a[0])+5);
	double e=exp(-1);
	for(int i=0;i<=c[0]*3;i++){
		int t=(int)e;
		c2[i]=t;
		e=(e-t)*10;
	}
	reverse(c2+1,c2+c[0]*3+1);
	for(int i=1,j=1;j<=c[0];i+=3,j++){
		c[j]=c2[i+2]*100+c2[i+1]*10+c2[i];
	}
	//print(c),puts("");
	Multi2(a,c,d);
	//print(d),puts("");
	int ts=c[0]*3;
	int lb=abs(b[0]);
	for(int i=1;i<=lb;i++)  h[i+c[0]]=b[i];
	h[0]=(b[0]<0?-1:1)*(lb+c[0]);
	//print(h),puts("");
	Add2(d,h,f);
	//print(f),puts("");
	Trans(f,g);
	//print(g),puts("");
	//printf("ts: %d\n",ts);
	if(g[0]<0) printf("-");
	g[0]=abs(g[0]);
	if(ts>4&&g[ts-4]>=5) g[ts-3]++;
	if(g[0]>ts){
		for(int i=g[0];i>ts;i--) printf("%d",g[i]);
	}else printf("0");
	printf(".");
	for(int i=ts;i>=ts-3;i--) printf("%d",g[i]); puts("");
}
}

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	
	Read(n);
	//if(n<=10)
	Part1::solve();
	//else 
	//Part2::solve();
	return 0;
}
