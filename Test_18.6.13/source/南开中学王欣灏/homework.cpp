#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#define ll long long
using namespace std;
const ll lim=10000000000000LL;
template <typename T>
inline void _read(T& x){
	char ch=getchar();bool sign=true;
	while(!isdigit(ch)){if(ch=='-')sign=false;ch=getchar();}
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(!sign)x=-x;
}
int n;
double ans=0.0;
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int i,j,k;
	cin>>n;
	ll temp=1;
	for(i=n+1;temp*i<=lim;i++){
		temp=temp*i;
		if(i%2==(n+1)%2)ans+=double(1)/double(temp);
		else ans-=double(1)/double(temp);
	}
	cout<<fixed<<setprecision(4)<<ans;
}

