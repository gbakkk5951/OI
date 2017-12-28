using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}	
	}
long long len,pn,dn;
long long p[305],d[305];
struct _Main{

void calc(int left){
	long long nowans=0;
	int mid=0;int i;
	for(i=0;i<pn;i++){
		while(mid+1<dn && abs(left+d[mid+1]-p[i])<=abs(left+d[mid]-p[i]))mid++;
		nowans+=abs(left+d[mid]-p[i]);
	}
	if(nowans>ans || (nowans==ans && left<mnleft)){
		ans=nowans;mnleft=left;
	}
}
long long l;
long long ans,mnleft;
_Main(){
	long long i,j,tmp,lstl;
	read(l);read(pn);l*=2;
	for(i=0;i<pn;i++)read(p[i]),p[i]*=2;
	read(dn);
	for(i=1;i<dn;i++)read(d[i]),d[i]*=2;
	calc(0);calc(l-d[dn-1]);
	for(i=0,lstl=0;i<pn;i++){
		while(lstl<dn-1 &&p[i] + d[dn-1]-d[lstl]-(d[lstl+1]-d[lstl])/2 >l)lstl++;
		for(j=lstl;j<dn-1;j++){
			if( (tmp=p[i]-(d[j+1]-d[j])/2-d[j])<0)break;
			calc(tmp);
		}
	}
	printf("%.1lf %.1lf",(double)mnleft/2.0,(double)ans/2.0);
	
}	
	
	
}boat;
