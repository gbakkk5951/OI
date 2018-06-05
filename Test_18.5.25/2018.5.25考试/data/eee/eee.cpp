#include<cstdio>
#include<algorithm>
using namespace std;
long long le[111]={0,233,2333,23333,233333,2333333,23333333,233333333,2333333333LL,23333333333LL,233333333333LL,2333333333333LL,23333333333333LL,233333333333333LL,2333333333333333LL,23333333333333333LL};
const long long gug=333333;
long long minn[gug]={};
long long lv[gug]={};
long long tree[gug]={};long long vvv;
bool vis[gug]={};
long long n,qqq;long long x,y,z;bool err;
long long a[gug]={};
struct ff{long long x,y;};
ff sum[gug]={};long long minnn[gug]={},maxx[gug]={},v[gug]={};
bool vis2[gug]={};
ff tee;int codeforces=10000000;
void chu(ff &m,long long n){
	m.y+=m.x%n*codeforces;m.x/=n,m.y/=n;
	m.x+=m.y/codeforces;m.y%=codeforces;
}
void jiaa(ff &a,ff b){
	a.x+=b.x,a.y+=b.y;
	a.x+=a.y/codeforces,a.y%=codeforces;
}
void jia(ff &m,long long n){
	m.y+=n;m.x+=(m.y/codeforces);m.y%=codeforces;
}
ff summ(ff a,ff b){
	a.x+=b.x,a.y+=b.y;a.x+=a.y/codeforces;a.y%=codeforces;return a;
}
void cheng(ff &m,long long n){
	m.x*=n,m.y*=n;m.x+=m.y/codeforces;m.y%=codeforces;
}
ff chengg(ff m,long long n){
	m.x*=n,m.y*=n;m.x+=m.y/codeforces;
	m.y%=codeforces;return m;
}
ff get0(long long a){
	a=-a;long long b=1;
	while(a<0)a=a+le[b++];
	return (ff){b,a};
}
void insert1(long long a,long long b,long long c,long long d,long long e,ff f){
	if(a==c&&b==d&&a==b)
	{
		tree[e]=minn[e]=f.y;lv[e]=f.x;return;
	}
	if(a==c&&b==d)
	{
		vis[e]=1,tree[e]=minn[e]=f.y,lv[e]=f.x;return;
	}
	if(vis[e])
	{
		vis[e]=0,vis[e*2]=vis[e*2+1]=1;
		lv[e*2]=lv[e*2+1]=lv[e],lv[e]=0;
		tree[e*2]=tree[e*2+1]=tree[e],tree[e]=0;
		minn[e*2]=minn[e*2+1]=minn[e];
	}
	else if(tree[e]!=0)
		tree[e*2]+=tree[e],tree[e*2+1]+=tree[e],minn[e*2]+=tree[e],minn[e*2+1]+=tree[e],tree[e]=0;
	long long zhong=c+d>>1;
	if(b<=zhong)insert1(a,b,c,zhong,e*2,f);
	else if(a>zhong)insert1(a,b,zhong+1,d,e*2+1,f);
	else insert1(a,zhong,c,zhong,e*2,f),insert1(zhong+1,b,zhong+1,d,e*2+1,f);
	minn[e]=min(minn[e*2],minn[e*2+1])+tree[e];
}
void insert2(long long a,long long b,long long c,long long d,long long e,long long f){
	if(a==c&&b==d){tree[e]-=f,minn[e]-=f;return;}
	long long zhong=c+d>>1;
	if(vis[e])
	{
		vis[e]=0,vis[e*2]=vis[e*2+1]=1;
		lv[e*2]=lv[e*2+1]=lv[e],lv[e]=0;
		tree[e*2]=tree[e*2+1]=tree[e],tree[e]=0;
		minn[e*2]=minn[e*2+1]=minn[e];
	}
	if(b<=zhong)insert2(a,b,c,zhong,e*2,f);
	else if(a>zhong)insert2(a,b,zhong+1,d,e*2+1,f);
	else insert2(a,zhong,c,zhong,e*2,f),insert2(zhong+1,b,zhong+1,d,e*2+1,f);
	minn[e]=min(minn[e*2],minn[e*2+1])+tree[e];
}
void insert3(long long a,long long b,long long c,long long d,long long e,long long f){
	if(a==c&&b==d&&a==b)
	{
		v[e]=minnn[e]=maxx[e]=f;
		sum[e].x=0,sum[e].y=f;return;
	}
	if(a==c&&b==d)
	{
		vis2[e]=1;sum[e]=(ff){0,f};
		cheng(sum[e],b-a+1);minnn[e]=maxx[e]=v[e]=f;
		return;
	}
	if(vis2[e])
	{
		vis2[e]=0,vis2[e*2]=vis2[e*2+1]=1;
		minnn[e*2]=maxx[e*2]=minnn[e*2+1]=maxx[e*2+1]=v[e*2]=v[e*2+1]=v[e];v[e]=0;
		sum[e*2]=sum[e];chu(sum[e*2],d-c+1);sum[e*2+1]=sum[e*2];
		cheng(sum[e*2],d-c+2>>1);cheng(sum[e*2+1],d-c+1>>1);
	}
	else if(v[e])
	{
		ff tee={0,v[e]};v[e*2]+=v[e],v[e*2+1]+=v[e];
		minnn[e*2]+=v[e],minnn[e*2+1]+=v[e];maxx[e*2]+=v[e],maxx[e*2+1]+=v[e];
		jiaa(sum[e*2],chengg(tee,d-c+2>>1)),jiaa(sum[e*2+1],chengg(tee,d-c+1>>1));
		v[e]=0;
	}
	int zhong=c+d>>1;
	if(b<=zhong)insert3(a,b,c,zhong,e*2,f);
	else if(a>zhong) insert3(a,b,zhong+1,d,e*2+1,f);
	else insert3(a,zhong,c,zhong,e*2,f),insert3(zhong+1,b,zhong+1,d,e*2+1,f);
	sum[e]=sum[e*2];jiaa(sum[e],sum[e*2+1]);
	jiaa(sum[e],chengg((ff){0,v[e]},d-c+1));
	minnn[e]=min(minnn[e*2],minnn[e*2+1]);
	maxx[e]=max(maxx[e*2],maxx[e*2+1]);
}
void insert4(long long a,long long b,long long c,long long d,long long e,long long f){
	if(a==c&&b==d)
	{
		v[e]+=f;maxx[e]+=f,minnn[e]+=f;
		ff tee={0,f};cheng(tee,b-a+1);jiaa(sum[e],tee);
		return;
	}
	if(vis2[e])
	{
		vis2[e]=0,vis2[e*2]=vis2[e*2+1]=1;
		minnn[e*2]=maxx[e*2]=minnn[e*2+1]=maxx[e*2+1]=v[e*2]=v[e*2+1]=v[e];v[e]=0;
		sum[e*2]=sum[e];chu(sum[e*2],d-c+1);sum[e*2+1]=sum[e*2];
		cheng(sum[e*2],d-c+2>>1);cheng(sum[e*2+1],d-c+1>>1);
	}
	int zhong=c+d>>1;
	if(b<=zhong) insert4(a,b,c,zhong,e*2,f);
	else if(a>zhong) insert4(a,b,zhong+1,d,e*2+1,f);
	else insert4(a,zhong,c,zhong,e*2,f),insert4(zhong+1,b,zhong+1,d,e*2+1,f);
	sum[e]=sum[e*2];jiaa(sum[e],sum[e*2+1]);
	jiaa(sum[e],chengg((ff){0,v[e]},d-c+1));
	minnn[e]=min(minnn[e*2],minnn[e*2+1])+v[e];
	maxx[e]=max(maxx[e*2],maxx[e*2+1])+v[e];
}
void print1(long long a,long long b){
	a=-a;
	while(b)a+=le[--b];
	printf("%lld\n",a);
}
void print0(long long a,long long b,long long c,long long d,long long e){
	if(vis[d]||b==c){print1(tree[d]+e,lv[d]);return;}
	e+=tree[d];
	long long zhong=c+b>>1;
	if(a<=zhong)print0(a,b,zhong,d*2,e);
	else print0(a,zhong+1,c,d*2+1,e);
}
long long findmin(long long a,long long b,long long e){
	if(a==b)return e;
	long long zhong=a+b>>1;
	if(vis[e])return e;
	else if(minn[e*2]<minn[e*2+1])return findmin(a,zhong,e*2);
	else return findmin(zhong+1,b,e*2+1);
}
void update(long long e){
	tree[e]+=le[lv[e]];minn[e]+=le[lv[e]];lv[e]++;
	while(e>1)e>>=1,minn[e]=min(minn[e*2],minn[e*2+1])+tree[e];
}
long long findminn(int a,int b,int c,int d,int e){
	if(a==c&&b==d)
		return minnn[e];
	if(vis2[e])
	{
		vis2[e]=0,vis2[e*2]=vis2[e*2+1]=1;
		minnn[e*2]=maxx[e*2]=minnn[e*2+1]=maxx[e*2+1]=v[e*2]=v[e*2+1]=v[e];v[e]=0;
		sum[e*2]=sum[e];chu(sum[e*2],d-c+1);sum[e*2+1]=sum[e*2];
		cheng(sum[e*2],d-c+2>>1);cheng(sum[e*2+1],d-c+1>>1);
	}
	int zhong=c+d>>1;
	if(b<=zhong)
		return findminn(a,b,c,zhong,e*2)+v[e];
	if(a>zhong)
		return findminn(a,b,zhong+1,d,e*2+1)+v[e];
	return min(findminn(a,zhong,c,zhong,e*2),findminn(zhong+1,b,zhong+1,d,e*2+1))+v[e];
}
long long findmaxx(int a,int b,int c,int d,int e){
	if(a==c&&b==d)
		return maxx[e];
	if(vis2[e])
	{
		vis2[e]=0,vis2[e*2]=vis2[e*2+1]=1;
		minnn[e*2]=maxx[e*2]=minnn[e*2+1]=maxx[e*2+1]=v[e*2]=v[e*2+1]=v[e];v[e]=0;
		sum[e*2]=sum[e];chu(sum[e*2],d-c+1);sum[e*2+1]=sum[e*2];
		cheng(sum[e*2],d-c+2>>1);cheng(sum[e*2+1],d-c+1>>1);
	}
	int zhong=c+d>>1;
	if(b<=zhong)
		return findmaxx(a,b,c,zhong,e*2)+v[e];
	if(a>zhong)
		return findmaxx(a,b,zhong+1,d,e*2+1)+v[e];
	return max(findmaxx(a,zhong,c,zhong,e*2),findmaxx(zhong+1,b,zhong+1,d,e*2+1))+v[e];
}
ff findsum(int a,int b,int c,int d,int e){
	if(a==c&&b==d)
		return sum[e];
	if(vis2[e])
	{
		vis2[e]=0,vis2[e*2]=vis2[e*2+1]=1;
		minnn[e*2]=maxx[e*2]=minnn[e*2+1]=maxx[e*2+1]=v[e*2]=v[e*2+1]=v[e];v[e]=0;
		sum[e*2]=sum[e];chu(sum[e*2],d-c+1);sum[e*2+1]=sum[e*2];
		cheng(sum[e*2],d-c+2>>1);cheng(sum[e*2+1],d-c+1>>1);
	}
	else if(v[e])
	{
		ff tee={0,v[e]};
		v[e*2]+=v[e],v[e*2+1]+=v[e];
		minnn[e*2]+=v[e],minnn[e*2+1]+=v[e];
		maxx[e*2]+=v[e],maxx[e*2+1]+=v[e];
		jiaa(sum[e*2],chengg(tee,d-c+2>>1)),jiaa(sum[e*2+1],chengg(tee,d-c+1>>1));
		v[e]=0;
	}
	int zhong=c+d>>1;
	if(b<=zhong)return findsum(a,b,c,zhong,e*2);
	if(a>zhong)return findsum(a,b,zhong+1,d,e*2+1);
	return summ(findsum(a,zhong,c,zhong,e*2),findsum(zhong+1,b,zhong+1,d,e*2+1));
}
int main()
{
	freopen("1","r",stdin);
	freopen("3","w",stdout);
	int tttttt=0;
	for(int i=15;i>0;i--)le[i]-=le[i-1];
	scanf("%I64d%I64d",&n,&qqq);
	for(long long i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(long long i=1;i<gug;i++)minn[i]=12345678912345678LL;
	for(long long i=1;i<=n;i++)
		insert1(i,i,1,n,1,get0(a[i])),insert3(i,i,1,n,1,a[i]);
	for(long long ii=0;ii<qqq;ii++)
	{
		long long temp;scanf("%lld",&temp);
		switch(temp)
		{
		case 1:
			scanf("%lld",&x);print0(x,1,n,1,0);
			break;
		case 2:
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			insert1(x,y,1,n,1,get0(z));insert3(x,y,1,n,1,z);
			while(true)
			{
				while(true){
					if(minn[1]>0)break;
					if(minn[1]==0)err=1;
					long long temp=findmin(1,n,1);
					update(temp);
				}
				if(err)insert2(x,y,1,n,1,1),insert4(x,y,1,n,1,1),err=0,tttttt++;
				else break;
			}
			break;
		case 3:
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			insert2(x,y,1,n,1,z);
			insert4(x,y,1,n,1,z);
			while(true)
			{
				while(true){
					if(minn[1]>0)break;
					if(minn[1]==0)err=1;
					long long temp=findmin(1,n,1);
					update(temp);
				}
				if(err)insert2(x,y,1,n,1,1),insert4(x,y,1,n,1,1),err=0,tttttt++;
				else break;
			}
			break;
		case 4:
			scanf("%lld%lld",&x,&y);vvv=findmaxx(x,y,1,n,1);
			insert1(x,y,1,n,1,get0(vvv));insert3(x,y,1,n,1,vvv);
			break;
		case 5:
			scanf("%lld%lld",&x,&y);vvv=findminn(x,y,1,n,1);
			insert1(x,y,1,n,1,get0(vvv));insert3(x,y,1,n,1,vvv);
			break;
		case 6:
			scanf("%lld%lld",&x,&y);
			tee=findsum(x,y,1,n,1);
			chu(tee,y-x+1);
			insert1(x,y,1,n,1,get0(tee.x*codeforces+tee.y));
			insert3(x,y,1,n,1,tee.x*codeforces+tee.y);
			if(minn[1]==0)err=1;
			while(true)
			{
				while(true){
					if(minn[1]>0)break;
					if(minn[1]==0)err=1;
					long long temp=findmin(1,n,1);
					update(temp);
				}
				if(err)insert2(x,y,1,n,1,1),insert4(x,y,1,n,1,1),err=0,tttttt++;
				else break;
			}
			break;
		}
	}
	printf("%d\n",tttttt);
}
