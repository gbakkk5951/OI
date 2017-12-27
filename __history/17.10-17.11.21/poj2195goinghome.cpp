using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<algorithm>
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
bool inline isele(char a){
	return a=='.'||a=='m'||a=='H';
}	
int lx[110],ly[110];
int dis[110][110];
int px[110],py[110],hx[110],hy[110];
int pn,hn;
int n,m;
_Main(){
	int i,j;char t;
	int ans;
	while(1){
		read(n);read(m);
		if(n==0 && m==0)return;
		memset(linkx,0,sizeof(linkx));
		memset(linky,0,sizeof(linky));
		
		
		pn=hn=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				while(!isele(t=getchar()));
				if(t=='H'){
					hn++;
					hx[hn]=i;
					hy[hn]=j;
					
				}else if(t=='m'){
					pn++;
					px[pn]=i;
					py[pn]=j;
									
				}
			}
		}
		for(i=1;i<=hn;i++){
			for(j=1;j<=pn;j++){
				dis[i][j]=-(abs(hx[i]-px[j])+abs(hy[i]-py[j]));
			}
		}
		for(i=1;i<=hn;i++){
			for(lx[i]=0,j=1;j<=pn;j++){
				lx[i]=max(lx[i],dis[i][j]);
			}
		}
		memset(ly,0,sizeof(ly));
		km();
		ans=0;
		for(i=1;i<=hn;i++){
			ans+=lx[i];
		}
		
		for(i=1;i<=pn;i++){
			ans+=ly[i];
		}
		printf("%d\n",-ans);
	}
}
bool dfs(int s){
	visx[s]=1;
	int i;
	for(i=1;i<=pn;i++)if(!visy[i]){
		int t;	
		t=lx[s]+ly[i]-dis[s][i];
		if(t==0){
			visy[i]=1;
			if(linky[i]==0 || dfs(linky[i])){
				linkx[s]=i;linky[i]=s;
				return true;
			}
		}else if(t>0){
			mindelta=min(mindelta,t);
		}
	}
	
	
	return false;
}
int linkx[110],linky[110];
int mindelta;
bool visx[110],visy[110];
void km(){
	int i,j;
	for(i=1;i<=hn;i++){
		while(1){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			mindelta=5000000;
			if(dfs(i))break;
			for(j=1;j<=hn;j++)if(visx[j]){
				lx[j]-=mindelta;
			}
			for(j=1;j<=pn;j++)if(visy[j]){
				ly[j]+=mindelta;
			}
		}
	}
	
	
	
	
	
	
}





	
}poj2195;
