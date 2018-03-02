#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 100010
using namespace std;
char s[N];
int sa[N],rk[N],xx[N],yy[N],wv[N],num[N],h[N],tree[N*4],n,m,st,ed;
bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void build(int l,int r,int pos){
	if(l==r){tree[pos]=h[l];/*if (l != 0)printf("tree[%d, %d] = %d\n", sa[l], sa[l - 1], tree[pos]);*/;return;}
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	build(l,mid,lson);build(mid+1,r,rson);
	tree[pos]=min(tree[lson],tree[rson]);
	return;
}
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
	return;
}
int find(int l,int r,int pos){
	
	if(st<=l&&r<=ed) return tree[pos];
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(ed<=mid) return find(l,mid,lson);
	if(mid<st) return find(mid+1,r,rson);
	return min(find(l,mid,lson),find(mid+1,r,rson));
}
int main()
{
	int i,l,lcp,ans=0;m=28;
	scanf("%s",s);n=strlen(s);
	for(i=0;i<n;i++) s[i]=s[i]-'a'+1;
	n++;hou();build(0,n,1);
	for (int i = 0; i < n; i++) {
		for (int j = sa[i]; j < n; j++) {
			printf("%d ", s[j]);
		}
		printf("\n{%d}\n", h[i]);
	}
	
	for(l=1;l<n;l++){
		
		for(i=0;i+l<n;i+=l){
			st=rk[i],ed=rk[i+l];
			if(st>ed) swap(st,ed);
			st++;
			printf("q[%d, %d]\n", st, ed);
			lcp=find(0,n,1);
			ans=max(ans,lcp/l+1);
			if (l == 3) {
				printf("i = %d lcp = %d\n", i, lcp);
			}
			if(i>=(l-lcp%l)){
				st=rk[i-l+lcp%l],ed=rk[i+lcp%l];
				if(st>ed) swap(st,ed);
				lcp+=find(0,n,1);
				ans=max(ans,lcp/l+1);
			if (l == 3) {
				printf("[2]i = %d lcp = %d\n", i, lcp);
			}
			}
		}
	}
	printf("%d\n",ans);
	return 0; 
}
