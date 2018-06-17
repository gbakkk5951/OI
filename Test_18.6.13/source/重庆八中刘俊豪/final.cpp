#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
int n,a[10],b[10][10];
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]);
}
void solve2(){
	for(int i=-2000;i<=2000;i++)
		for(int j=-2000;j<=2000;j++)
			if(a[1]*j-a[2]*i==1){
				printf("%d %d\n%d %d\n",a[1],a[2],i,j);
				return;
			}
	puts("no solution");
}
typedef pair<int,int>pii;
pii cz[10];
int cnt;
int gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
void change(int i,int j){
	int k;
	for(k=1;k<=n;k++)
		swap(b[k][i],b[k][j]);
}
void print(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			printf("%d%c",b[i][j],j==n?'\n':' ');
}
void solve(){
	int i,j;
	if(a[1]==1||a[1]==-1){
		for(i=1;i<=n;i++)
			b[1][i]=a[i];
		b[2][2]=a[1];
		for(i=3;i<=n;i++)
			b[i][i]=1;
		goto out;
	}
	
	for(i=2;i<=n;i++){
		if(a[i]==1||a[i]==-1){
			cz[++cnt]=pii(1,i);
			swap(a[i],a[1]);
			for(j=1;j<=n;j++)
				b[1][j]=a[j];
			for(j=3;j<=n;j++)
				b[j][j]=1;
			b[2][2]=-a[1];
			goto out;
		}
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++)
			if(abs(gcd(a[i],a[j]))==1){
				if(i==1){
					if(j!=2){
						cz[++cnt]={j,2},cz[++cnt]={1,2};
						swap(a[j],a[2]);
						swap(a[1],a[2]);
					}
				}
				else{
					cz[++cnt]={i,1},cz[++cnt]={j,2};
					swap(a[i],a[1]);
					swap(a[j],a[2]);
				}
				for(int k=1;k<=n;k++)
					b[1][k]=a[k];
				int t1=a[2],t2=a[1],inv;
				if(t2<0)
					t1=-t1,t2=-t2;
				t1%=t2;
				if(t1<0)
					t1=t2-t1;
				for(inv=1;;inv++)
					if(t1*inv%t2==t2-1)
						break;
				b[2][1]=inv;
				b[2][2]=(a[2]*inv+1)/a[1];
				for(i=3;i<=n;i++)
					b[i][i]=1;
				goto out;
			}
	}
	out:;
	while(cnt){
		change(cz[cnt].first,cz[cnt].second);
		cnt--;
	}
	print();
}
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	read();
	if(n==2)
		solve2();
	else
		solve();
}
