using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<list>
#include<cctype>
list<long long>m,r;
bool EndFlag;
struct _Main{
int k;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;
		return a;
	}long long g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
long long merge(int num,list<long long> &m,list<long long>&r){
	int i;long long x,y,g,delta;
	list<long long>::iterator itm,itr,hm,hr;
	hm=m.begin();hr=r.begin();
	for(i=1;i<k;i++){
		itm=m.begin();itm++;
		itr=r.begin();itr++;
		delta=*itr-*hr;
		g=exgcd(*hm, *itm,x,y);
		if(delta%g!=0)return -1LL;
		x=*hm*((delta/g*x)%(*itm/g))+*hr;
		*hm=*itm/g**hm;
		*hr=x%*hm;
		m.erase(itm);m.erase(itr);
	}
	if(*hr<0)*hr+=*hm;
	return *hr;
	
}

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar())){
			if(t==EOF){
				EndFlag=true;
				return;
			}
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}	
	}

_Main(){
	
	long long a,b;
	int i;
	while(1){
		read(k);
		if(EndFlag)return;
		for(i=0;i<k;i++){
			read(a);read(b);
			m.push_back(a);r.push_back(b);  
		}
		printf("%lld\n",merge(k,m,r));
		m.clear() ;r.clear() ;
	}
	
	
}

	
	
	
}poj2891;
