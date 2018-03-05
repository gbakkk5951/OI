#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
struct point{
	long long x,y;
	friend point operator -(const point &a,const point &b){
		point ret;
		ret.x=a.x-b.x;
		ret.y=a.y-b.y;
		return ret;
	}
	friend long long operator *(const point &a,const point &b){
		long long ret=a.x*b.y-a.y*b.x;
		return ret;
	}
	friend long long operator ^(const point &a,const point &b){
		long long ret=a.x*b.x+a.y*b.y;
		return ret;
	}
	friend bool operator <(const point &a,const point &b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	}
}in;
int decode(long long x,long long a){return x^(a&0x7fffffff);}
vector<point>shang[1600010],xia[1600010];
long long ans=0ll;
char s[5],flg[5];
int m,st,ed;
void merges(vector<point> &lson,vector<point> &rson,vector<point> &pos){
	unsigned i=0,j=0,all=0;
	while(i!=lson.size()||j!=rson.size()){
		if(i==lson.size()) in=rson[j++];
		else if(j==rson.size()) in=lson[i++];
		else in=(lson[i]<rson[j])?lson[i++]:rson[j++];
		while(all>=2&&((pos[all-1]-pos[all-2])*(in-pos[all-2]))>=0) all--,pos.pop_back();
		all++,pos.push_back(in);
	}return;
}
void mergex(vector<point> &lson,vector<point> &rson,vector<point> &pos){
	unsigned i=0,j=0,all=0;
	while(i!=lson.size()||j!=rson.size()){
		if(i==lson.size()) in=rson[j++];
		else if(j==rson.size()) in=lson[i++];
		else in=(lson[i]<rson[j])?lson[i++]:rson[j++];
		while(all>=2&&((in-pos[all-2])*(pos[all-1]-pos[all-2]))>=0) all--,pos.pop_back();
		all++,pos.push_back(in);
	}return;
}
void insert(int l,int r,int pos){
	if(l==r){
		shang[pos].push_back(in);
		xia[pos].push_back(in);
		return;
	}
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(m<=mid) insert(l,mid,lson);
	else insert(mid+1,r,rson);
	if(r==m) merges(shang[lson],shang[rson],shang[pos]),mergex(xia[lson],xia[rson],xia[pos]);
	return;
}
void sanfen(vector<point> &pos){
	int i,l=0,r=pos.size()-1,lmid,rmid;
	while(r-l>2){
		lmid=(l*2+r)/3,rmid=(l+r*2)/3;
		if((pos[lmid]^in)>(pos[rmid]^in)) r=rmid;
		else l=lmid;
	}
	for(i=l;i<=r;i++) ans=max(ans,(pos[i]^in));
	return;
}
void find(int l,int r,int pos){
	if(st<=l&&r<=ed){
		if(in.y>=0) sanfen(shang[pos]);
		else sanfen(xia[pos]);
		return;
	}
	int mid=(l+r)/2,lson=pos*2,rson=pos*2+1;
	if(st<=mid) find(l,mid,lson);
	if(mid<ed) find(mid+1,r,rson);
	return;
}
int read(){
	int ret=0;bool flag=false;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-') flag=true;c=getchar();}
	while('0'<=c&&c<='9') ret=ret*10+c-'0',c=getchar();
	return flag?-ret:ret;
}
int main()
{
//	freopen("data0.in", "r", stdin);
	int i,n,x,y;
	n=read();
	scanf("%s",flg);
	for(i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='A'){
			x=read(),y=read();
			if(flg[0]!='E'){x=decode(x,ans),y=decode(y,ans);}
			in.x=x,in.y=y,m++;
			insert(1,n,1);
		}
		else{
			x=read(),y=read(),st=read(),ed=read();
			if(flg[0]!='E'){x=decode(x,ans),y=decode(y,ans),st=decode(st,ans),ed=decode(ed,ans);}
			in.x=x,in.y=y;ans=-4611686014132420609ll;
			find(1,n,1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
