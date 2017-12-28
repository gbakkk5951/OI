using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<functional>
#include<queue>
struct Range{
	int l,r;
	int mxval;
	bool friend operator < (const Range &a,const Range &b){
		return a.mxval==b.mxval?a.l<b.l:a.mxval<b.mxval;
	}
}Rangetmp,Rangend;
priority_queue<Range>heap;


struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
	int n,m,times;
	int dis[1006],mx[1005],arrnum[1005];
	int pbeg[10010],pdst[10010],ptme[10010];
	int arrtme[1005];
	int numsum[1005];
	long long ans;
	_Main(){
		int i,j,k;int a,b,c;int dec;
		read(n);read(m);read(times);
		for(i=1;i<=n-1;i++){
			read(dis[i]);
		}
		for(i=1;i<=m;i++){
			read(a);read(b);read(c);
			ptme[i]=a;
			pbeg[i]=b;
			pdst[i]=c;
			mx[b]=max(mx[b],a);
			arrnum[c]++;
		}
		int lst=1;
		int tme=mx[1]+dis[1];arrtme[1]=0;
		for(i=2;i<=n;i++){
			numsum[i]=numsum[i-1]+arrnum[i];
			arrtme[i]=tme;
			if(arrtme[i]<=mx[i] || dis[lst]==0 || i==n){
				if(dis[lst]!=0){
					Rangetmp.l=lst;
					Rangetmp.r=i;
					Rangetmp.mxval=numsum[i]-numsum[lst];
					if(Rangetmp.mxval>0)
						heap.push(Rangetmp);					
				}
				lst=i;
			}
			tme=max(tme,mx[i])+dis[i];
		}
		while(times>0 && !heap.empty()){
			Rangend=heap.top();
			heap.pop();
			int mn=min(times,dis[Rangend.l]);
			for(i=Rangend.l+1;i<=Rangend.r-1;i++){
				mn=min(mn,arrtme[i]-mx[i]);
			}
			dis[Rangend.l]-=mn;
			times-=mn;
			for(i=Rangend.l+1;i<=Rangend.r;i++){
				arrtme[i]-=mn;
			}
			lst=Rangend.l;
			for(i=Rangend.l+1;i<=Rangend.r;i++){
				if(arrtme[i]<=mx[i] || dis[lst]==0 ||i==Rangend.r){
					if(dis[lst]!=0){
						Rangetmp.l=lst;
						Rangetmp.r=i;
						Rangetmp.mxval=numsum[i]-numsum[lst];
						if(Rangetmp.mxval>0)
							heap.push(Rangetmp);					
					}
					lst=i;
				}
			}
		}
		for(i=1,ans=0;i<=m;i++){
			ans+=arrtme[pdst[i]]-ptme[i];
		}
		printf("%lld",ans);
	}

}ezoj1152;
