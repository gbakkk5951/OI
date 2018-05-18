#include<bits/stdc++.h>
#define maxn 1000010
#define ll long long
using namespace std;

struct node{
	int l,r,s;
}t[maxn<<5];
int n,rt,cnt=0;
const int p=1e9+7;
void insert(int &x,int l,int r,int pos){
	if(!x)
		x=++cnt;
	t[x].s++;
	if(l==r)
		return;
	int mid=l+r>>1;
	if(pos<=mid)
		insert(t[x].l,l,mid,pos);
	else
		insert(t[x].r,mid+1,r,pos);
}
int query(int x,int l,int r,int k){
	if(l==r)
		return l;
	int mid=l+r>>1;
	if(t[t[x].l].s>=k)
		return query(t[x].l,l,mid,k);
	else
		return query(t[x].r,mid+1,r,k-t[t[x].l].s);
}
inline ll gen(ll x,ll y){
	return (1714636915*x+1681692777)%p*((846930886*y+1804289383)%p)%p;
}
int main(){
	freopen("mid.in","r",stdin);
	freopen("mid.out","w",stdout);
	int lst,x,ans=0;
	scanf("%d%d",&n,&x);
	if(n>1e6)
		return puts("ม๏มหม๏มห"),0;
	for(int i=1;i<=n;i++){
		insert(rt,1,1e9+7,x);
		ans^=(lst=query(1,1,1e9+7,i+1>>1));
		x=gen(x,lst);
	}
	printf("%d\n",ans);
}
