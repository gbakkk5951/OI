using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cmath>

struct point{
	int x;int y;
	bool friend operator == (point a,point b){
		return a.x==b.x && a.y==b.y;
	}
	bool friend operator < (point a,point b){
		return a.x==b.x ?a.y<b.y:a.x<b.x;
	}	
};
const int dx[]={+1,-1,+0,+0,+1,+1,-1,-1};
const int dy[]={+0,+0,-1,+1,+1,-1,-1,+1};

vector<point>ps;
queue<point>q[2];
bitset<1000010>v;
bitset<1000010>b;
int dis[1010];
int impress(int x,int y){
	return x+y*1000;
}

struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int n,m,bn;
bool inline islegal(int x,int y){
	return x>=0&&y>=0 &&x<m&&y<n;
}
_Main(){
	int i,j,k;int x,y;
	read(n);read(m);read(bn);
	if(m==1){
		if(bn!=0){
			printf("0");
		}else{
			printf("1");
		}
	}else if(n==1) {
		int ind;
		for(i=0;i<bn;i++){
			read(x);read(y);
			ps.push_back((point){x,y}); 
		}
		sort(ps.begin() ,ps.end());
		ind=unique(ps.begin(),ps.end())-ps.begin();
		printf("%d",m-ind);
	}else if(m<=1000 && n<=1000){
		for(i=0;i<bn;i++){
			read(y);read(x);
			b[impress(x-1,y-1)]=1;
		}
		int iter=0;
		j=0;
		for(i=0;i<n;i++){
			if(b[impress(j,i)]){
				q[0].push((point){j,i});
			}else{
				q[1].push((point){j,i});
			}
		}
		int ans=0;int temp;
		for(;!q[iter].empty() || !q[iter^1].empty();iter^=1,ans++){
			while(!q[iter].empty()){
				x=q[iter].front().x;
				y=q[iter].front().y;
				q[iter].pop();
				if(x==m-1)goto End;
				for(i=0;i<8;i++){
					if(islegal(x+dx[i],y+dy[i])&&!v[temp=impress(x+dx[i],y+dy[i])]){
						if(b[temp]){
							q[iter  ].push((point){x+dx[i],y+dy[i]}); 
						}else{
							q[iter^1].push((point){x+dx[i],y+dy[i]}); 
						}
						v[temp]=1;
					}
				}
			}
		}
		End:printf("%d",ans);
	}else{
		for(i=0;i<bn;i++){
			read(y);read(x);
			ps.push_back((point){x-1,y-1});
		}
		sort(ps.begin(),ps.end());
		bn=unique(ps.begin(),ps.end())-ps.begin();
		for(i=0;i<bn;i++){
			dis[i]=ps[i].x;
		}
		dis[bn]=m;
		for(i=0;i<bn;i++){
			x=-1;
			for(j=0;j<bn;j++)if(!v[j]){
				if(x==-1 || dis[x]>dis[j]){
					x=j;
				}
			}
			v[x]=1;
			for(j=0;j<bn;j++)if(j!=x){
				dis[j]=min(dis[j],dis[x]+max(abs(ps[x].x-ps[j].x),abs(ps[x].y-ps[j].y))-1);
			}dis[bn]=min(dis[bn],dis[x]+m-ps[x].x-1);
		}
		printf("%d",dis[bn]);	
	}
	
}
	
	
	
	
	
	
}cdvs4236;
