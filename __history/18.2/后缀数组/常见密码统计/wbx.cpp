#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 110000
using namespace std;

int s[N],sa[N],xx[N],yy[N],num[N],wv[N],rk[N],h[N],n,m,k;

char in[N];

bool vis[110];

int bel[N],ans[N],cnt=0;

bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}

void hou(){
	int i,j,p,k=0,*x=xx,*y=yy;
	
	for(i=0;i<m;i++) num[i]=0;
	for(i=0;i<n;i++) num[x[i]=s[i]]++;
	for(i=1;i<m;i++) num[i]+=num[i-1];
	for(i=n-1;i>=0;i--) sa[--num[x[i]]]=i;
	
	for(j=1,p=1;p<n;j*=2,m=p){
		p=0;
		
		for(i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) wv[i]=x[y[i]];
		
		for(i=0;i<m;i++) num[i]=0;
		for(i=0;i<n;i++) num[wv[i]]++;
		for(i=1;i<m;i++) num[i]+=num[i-1];
		for(i=n-1;i>=0;i--) sa[--num[wv[i]]]=y[i];
		
		swap(x,y),p=1,x[sa[0]]=0;
		for(i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
		
	}
	
	for(i=0;i<n;i++) rk[sa[i]]=i;
	for(i=0;i<n;h[rk[i++]]=k) for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
		
}


bool check(int len){
	int i,j,num=0,st=0;
	memset(vis, 0, sizeof(vis));
	for(i=0;i<n;i++){
		if(h[i]<len){
			if(num>=k) return true;
			num=0;
			
			for(j=st;j<=i;j++) vis[bel[sa[j]]]=false;
			if(bel[sa[i]]&&vis[bel[sa[i]]]==false) vis[bel[sa[i]]]=true,num++;
			st=i;
		}
		else{
			if(bel[sa[i]]&&vis[bel[sa[i]]]==false) vis[bel[sa[i]]]=true,num++;
		}
	}
	if(num>=k) return true;
	return false;
}

void print(int len){
	int i,j,num=0,st=0;
	memset(vis, 0, sizeof(vis));
	for(i=0;i<n;i++){
		if(h[i]<len){
			if(num>=k) ans[++cnt]=sa[i-1];
			num=0;
			
			for(j=st;j<=i;j++) vis[bel[sa[j]]]=false;
			if(bel[sa[i]]&&vis[bel[sa[i]]]==false) vis[bel[sa[i]]]=true,num++;
			
			st=i;
		}
		else{
			if(bel[sa[i]]&&vis[bel[sa[i]]]==false) vis[bel[sa[i]]]=true,num++;
		}
	}
	if(num>=k) ans[++cnt]=sa[i-1];
}


int main()
{
	int t,i,j,len,l,r,tans=0;
	scanf("%d",&t);m=28+t,k=(t+1)>>1;
	
//	printf("k=%d\n",k);
	
	for(i=1;i<=t;i++){
		scanf("%s",in);
		len=strlen(in);
		
		for(j=0;j<len;j++) s[n]=in[j]-'a'+1,bel[n++]=i;
		s[n++]=26+i;
		
	}
	
	if(t==1){printf("%s\n",in);return 0;}
	
	n++;hou();
	
	
	l=0,r=n;
	while(l<r){
		len=(l+r)/2;
		if(check(len)==true) l=len+1,tans=len;
		else r=len;
	}
	if(tans==0){
		printf("?\n");
		return 0;
	}
	else{
		print(tans);
		for(i=1;i<=cnt;i++){
			for(j=ans[i];j<=ans[i]+tans-1;j++) printf("%c",s[j]+'a'-1);
			printf("\n");
		}
	}
	
}
