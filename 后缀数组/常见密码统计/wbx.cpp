#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#define N 101000
using namespace std;
char s[N];
int sa[N],xx[N],yy[N],wv[N],num[N],rk[N],h[N],len[110],ll[N],rr[N],ss[N],n,m,q;
bool vis[110],pd=true;
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
	for(i=0;i<n;h[rk[i++]]=k){for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k];k++);}
	return;
}
bool check(int k){
	int i,j,num,a,b;
	for(i=0;i<n;i++){
		if(h[i]<k){
			for(j=1;j<=q;j++) if(vis[j]) num++;
			memset(vis,false,sizeof(vis));
			if(num>=(q+2)/2) return true;
			num=0;
		}
		else{
			a=lower_bound(len+1,len+q+1,sa[i-1]+1)-len;
			b=lower_bound(len+1,len+q+1,sa[i]+1)-len;
			vis[a]=true;vis[b]=true;
		}
	}
	memset(vis,false,sizeof(vis));
	return false;
}
int main()
{
	int i,j,l,r,a,b,mid,shu,ans=0;m=200;
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%s",s+len[i-1]);
		len[i]=strlen(s);
		for(j=len[i-1];j<len[i];j++) ss[j]=s[j]-'a'+1;
		s[len[i]]=ss[len[i]]=26+i;
		len[i]++;
	}
	s[len[q]-1]='a'-1;
	n=strlen(s);n++;
	l=0,r=100000;
	for(i=0;i<n;i++) s[i]=ss[i];
	hou();
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid;
	}
	l=ans,ans=0;
	for(i=0;i<n;i++){
		if(h[i]<l){
			for(j=1;j<=q;j++) if(vis[j]) shu++;
			memset(vis,false,sizeof(vis));
			if(shu>=(q+2)/2){
				ans++;
				ll[ans]=sa[i-2];
				rr[ans]=ll[ans]+l-1;
			}
			shu=0;
		}
		else{
			if(pd==true){
				a=lower_bound(len+1,len+q+1,sa[i-1]+1)-len;
				b=lower_bound(len+1,len+q+1,sa[i]+1)-len;
				vis[a]=vis[b]=true;
			}
		}
	}
	for(i=1;i<=ans;i++){
		for(j=ll[i];j<=rr[i];j++) printf("%c",s[j]+'a'-1);
		printf("\n");
	}
	if(ans==0) printf("?");
	return 0;
}
