#include<cstdio>
#define fm denominator
#define fs fraction
#define fr fraction
#define fz numerator
#define sp simplify
#include<cmath>
#include<algorithm>
using namespace std;
struct query{
    int l,r;
    int bl;
    int org;
    bool friend operator < (query a,query b){
        if(a.bl==b.bl){
            return a.r<b.r;
        }else{
            return a.bl<b.bl;
        }
    }
     
}qu[50010];
 
 
unsigned long long gcd(unsigned long long a,unsigned long long b){
    if(b==0){
        return a;
    }
    else return gcd(b,a%b);
}

 
struct fraction{
bool operator < (fs b){
    unsigned long long a1,a2;
    unsigned long long g=gcd(fm,b.fm);
    a1=fz*(b.fm/g);
    a2=b.fz*(fm/g);
    return a1<a2;
}
bool operator == (fs b){
    if(fz==b.fz&&fm==b.fm){
        return true;
    }return false;
}
bool operator > (fs b){
    if(!(*this<b)&&!(*this==b)){
        return true;
    }return false;
}
 
fraction(){
    fz=0;
    this->fm=1;
}
void simplify(){
    unsigned long long a=gcd(denominator,numerator);
    if(a!=0){
     
    denominator/=a;
    numerator/=a;
    }
    if(!fz)
    fm=1;
     
    if(fm==0)
    fm=1;
    if(fm<0){
        fz=-fz;
        fm=-fm;
    }
}
    unsigned long long denominator;
    unsigned long long numerator;
fraction operator * (fraction b){
    fs ans;
   int g=gcd(fz,b.fm); 
	if(g!=0)
	{
		fz/=g;
		b.fm/=g;
	}
	g=gcd(b.fz,fm);
	if(g!=0)
	{
		b.fz/=g;
		fm/=g;
	}
    ans.fz=fz*b.fz;
    
    ans.fm=fm*b.fm;
  ans.sp();
    return ans;
}
fs operator *= (fs b){
    *this = *this * b;
}
 
 
fs operator = (unsigned long long b){
    fm=1;
    fz=b;
}
 
fs operator - (fraction b){
    fs ans;
    unsigned long long g;
    g=gcd(fm,b.fm);
 	
    ans.fm=fm/g*b.fm;
    ans.fz=fz*(b.fm/g)-b.fz*(fm/g);
 
	ans.sp();
    return ans; 
}
fs operator ++(){
    fz+=fm;
    return *this;
}
fs operator += (fs b){
    *this=*this+b;
    return *this;
}
fs operator -= (fs b){
    *this=*this-b;
    return *this;
}
fs operator + (fraction b){
    fs ans;
    unsigned long long g;
    g=gcd(fm,b.fm);
    ans.fm=fm/g*b.fm;
    ans.fz=fz*(b.fm/g)+b.fz*(fm/g);
    ans.sp();       
    return ans;
}
 
fs operator / (fraction b){
    fs ans;ans.fz=b.fm;
    ans.fm=b.fz;
    ans*=*this;
    return ans;
}
fs operator / (unsigned long long in){
    fs b;
    b.fz=in;
    fs ans;ans.fz=b.fm;
    ans.fm=b.fz;
    ans*=*this;
    return ans;
}
void print(){
    printf("%llu/%llu\n",fz,fm);
}
     
}ans;
int c[50010];fs t[500];
int n,m;
int cnt;
int main(){
    int i,j,k;
    int t1,t2,t3;
    query qt;

    scanf("%d%d",&n,&m);
    int sq=sqrt(n);    
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        c[i]=k;
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&j,&k);
        qt.l=j;qt.r=k;
        qt.org=i;
        qt.bl=ceil((double)j/sq);
        qu[cnt++]=qt;
    }
    sort(qu,qu+m);
    void getans();
    getans();

}
int L=1,R=1;
int tot[50010];
void llm(){
    fs m,n;
    m.fz=(R-L);
    m.fm=(R-L+2);
    n.fz=tot[c[L-1]]*(tot[c[L-1]]-1);
    n.fm=(R-L)*(R-L+1);
        n.sp();
    ans-=n;
    ans*=m;
    tot[c[L-1]]++;
    m.fz=tot[c[L-1]];
    m.fm=R-L+2;
    m.fz*=m.fz-1;
    m.fm*=m.fm-1;
    m.sp();
    ans+=m;
     
    L--;
}
void lrm(){
 
     
    fs m,n;
    m.fz=(R-L+1);
    m.fm=(R-L-1);
    n.fz=tot[c[L]]*(tot[c[L]]-1);
    n.fm=(R-L)*(R-L+1);
        n.sp();
	ans-=n;
    ans*=m;
    tot[c[L]]--;
    m.fz=tot[c[L]];
    m.fm=R-L;
    m.fz*=m.fz-1;
    m.fm*=m.fm-1;
    m.sp(); 
    ans+=m;

    L++;    
}
void rrm(){
 
     
    fs m,n;
    m.fz=(R-L);
    m.fm=(R-L+2);
    n.fz=tot[c[R+1]]*(tot[c[R+1]]-1);
    n.fm=(R-L)*(R-L+1);
        n.sp();
    ans-=n;    
    ans*=m;
     
    tot[c[R+1]]++;
    m.fz=tot[c[R+1]];
    m.fm=R-L+2;
    m.fz*=m.fz-1;
    m.fm*=m.fm-1;
    m.sp(); 
    ans+=m;
 
     
    R++;        
     
}
void rlm(){
    fs m,n;
    m.fz=(R-L+1);
    m.fm=(R-L-1);
    n.fz=tot[c[R]]*(tot[c[R]]-1);
    n.fm=(R-L)*(R-L+1);    
    n.sp();
	ans-=n;
    ans*=m;
    tot[c[R]]--;
    m.fz=tot[c[R]];
    m.fm=R-L;
    m.fz*=m.fz-1;
    m.fm*=m.fm-1;
    m.sp(); 
    ans+=m;
    R--;
}
bool cmp(query a,query b){
    return a.org<b.org;
     
}
fs as[50010];
void getans(){
    int I,i,j,k;
    tot[c[1]]++;
for(I=0;I<m;I++){
    while(R<qu[I].r)rrm();
    while(R>qu[I].r)rlm();   
    while(L>qu[I].l)llm();   
    while(L<qu[I].l)lrm();
    ans.sp();               
    as[qu[I].org].fz=ans.fz;
    as[qu[I].org].fm=ans.fm;
}
for(i=0;i<m;i++){
    printf("%llu/%llu\n",as[i].fz,as[i].fm);
     
}
}
