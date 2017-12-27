#include<cstdio>
#include<cctype>
#include<cmath>
struct _Main{
long long node [131199];	
long long list[50010][68];
long long phi[67];
int cnt[50011];
bool lazy[131107];
int base;
bool flag;
int pmax;
long long p;
long long modify(int pos){
	int i;
	if(cnt[pos]>=pmax){
		lazy[base+pos]=true;
		return node[base+pos];
	}
	cnt[pos]++;
	for(i=cnt[pos];i<=pmax;i++){
		flag=false;
		list[pos][i]=fast_pow(c,list[pos][i],phi[i-cnt[pos]]);
		if(flag&&i!=cnt[pos]){
			list[pos][i]+=phi[i-cnt[pos]];
		}
	}
	return list[pos][cnt[pos]];	
}
void change (int l,int r,int nd=1,int tl=1,int tr=65536){
	
	if(lazy[nd]||r<tl||l>tr){
		return;
	}
	else{
		if(tl==tr){
			
			node[nd]=modify(nd-base);
		}else{
			change(l,r,nd<<1,tl,(tl+tr)>>1);
			change(l,r,nd<<1^1,((tl+tr)>>1)+1,tr);
			node[nd]=(node[nd<<1]+node[nd<<1^1])%p;
			lazy[nd]=lazy[nd<<1]&lazy[nd<<1^1];
		}
	}
}
int query(int l,int r){
	long long ans=0;
	for(l=l+base-1,r=r+base+1;l^r^1;l>>=1,r>>=1){
		if(~l&1) ans=(ans+node[l^1])%p;
		if( r&1) ans=(ans+node[r^1])%p;
	}
	return (int)ans;
}
void ini(){
	lazy[base]=true;
	int i=base+1;
	int g=base+n;
	int j;
	for(;i<=g;i++){
		for(j=0;j<=pmax;j++){
			if(node[i]>=phi[j]){
				list[i-base][j]=node[i]%phi[j]+phi[j];
				
			}else{
				list[i-base][j]=node[i];
			}
		}
	}
	for(i=base+n+1;i<=(base<<1)+1;i++){
		lazy[i]=true;
	}
	
	int l=base+1;
	int r=g;
	l>>=1;
	r>>=1;
	while(l|r){
		for( i = l; i <= r; i ++){
			node[i]=(node[i<<1]+node[(i<<1)|1])%p;
		}
		l>>=1;
		r>>=1;
	}
	l=base+n+1;
	r=base<<1;
	l>>=1;
	r>>=1;
	while(l|r){
		for(i=l;i<=r;i++){
			lazy[i]=lazy[i<<1]&lazy[i<<1^1];
		}
		l>>=1;
		r>>=1;
	}
	
}
int read(){
	char t;int ans;
	while(!isdigit ( t = getchar ()));
	ans=t-'0';
	while( isdigit ( t = getchar ())){
		ans*=10;
		ans+=t-'0';
	}
	
	
	return ans;
}
int m,n,c;
long long fast_pow(int base,int zpow,int mod){
	long long ans=1;
	long long now=base;
	for(;zpow;zpow>>=1){
		if(now>=mod){
			flag=true;
			now%=mod;
		}
		if(zpow&1){
			ans=ans*now;
			if(ans>=mod){
				flag=true;
				ans%=mod;
			}
		}
		now*=now;
	}
	return ans;
}
int getphi(int val){
	int ans=val;
	int g=sqrt(val);
	int i;
	for(i=2;i<=g;i++){
		if(!(val%i)){
			ans=ans/i*(i-1);
			val/=i;
			while(!(val%i)){
				val/=i;
			}
		}
	}
	if(val!=1){
		ans/=val;
		ans*=val-1;
	}
	return ans;
}
_Main(){

	n=read();
	m=read();
	p=read();
	c=read();

	base=65536;
	int i,j,k;

	phi[0]=p;
	for(i=0;phi[i]!=1;i++){
		phi[i+1]=getphi(phi[i]);
	}
	phi[i+1]=1;
	phi[i+2]=1;
	pmax=i+1;
	
	j=base+n;
	for(i=base+1;i<=j;i++){
		node[i]=read();
	}
	ini();
	for(i=0;i<m;i++){
		if(read()){
			j=read();
			k=read();			
			printf("%d\n",query(j,k));
		}else{
			j=read();
			k=read();
			change(j+1,k+1);
		}
	}
	fclose(stdout);
}
	
	
	
}bzoj4869;int main(){}


