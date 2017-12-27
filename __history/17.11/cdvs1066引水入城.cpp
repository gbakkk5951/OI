using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
struct Range{
	int l,r;	
	Range(int _l,int _r):l(_l),r(_r){}	
	Range(){
		l=1e9;r=0;
	}

	Range inline friend operator + (const Range &a,const Range &b){
		return (Range){min(a.l,b.l),max(a.r,b.r)};
	}
	void inline operator +=(const Range &a){
		*this=*this+a;
	}
	bool friend operator == (const Range &a,const Range &b){
		return !memcmp(&a,&b,sizeof(Range));
	}
	bool friend operator != (const Range &a,const Range &b){
		return !(a==b);
	}	
}dp[505][505],zero;
bool vis[505][505];
int h[505][505];
int n,m;

Range GetRange(int x,int y,int from){
	if(x>0 && y>0 && x<=n && y<=m && h[x][y]<from){
		if(!vis[x][y]){
			vis[x][y]=1;
			dp[x][y]+=GetRange(x+1,y,h[x][y]);
			dp[x][y]+=GetRange(x-1,y,h[x][y]);
			dp[x][y]+=GetRange(x,y+1,h[x][y]);
			dp[x][y]+=GetRange(x,y-1,h[x][y]);				
			if(x==n)dp[x][y]+=(Range){y,y};
		}
		return dp[x][y];
	}
	return zero ;
}


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




_Main(){
	Range covered,mx;
	int i,j,cnt;
	read(n);read(m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			read(h[i][j]);
		}
	}

	for(i=1;i<=m;i++){
		GetRange(1,i,1e7);
	}

	for(i=1,cnt=0;i<=m;i++){
		if(!vis[n][i])cnt++;
	}
	if(cnt){
		printf("0\n%d",cnt);
		goto EndMain;
	}
	mx=dp[1][1];
	for(i=2,cnt=0;i<=m;i++){
		if(dp[1][i]!=zero){
			if(dp[1][i].l>covered.r+1){
				covered+=mx;
				cnt++;
				if(covered.r==m)break;
			}
			mx=dp[1][i];
		}
	}
	if(covered.r!=m){
		cnt++;
		covered+=mx;
	}
	printf("1\n%d",cnt);
	EndMain:
	fclose(stdout);
}

	
	
	
	
}cdvs1066;
