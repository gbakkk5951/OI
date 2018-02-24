#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

#define maxn 2000
const int INF=0x3f3f3f3f;
int n,k,ma,mb,ai[maxn],bi[maxn],ans;
deque<int>q;

void dfs(int p,int cnt,int sum){
    if(p>k&&(cnt<ma||k-cnt<mb))return;
    int sig;
    if(p>n){
	ans=max(ans,sum);
	return;
    }
    if(p<=k){
	q.push_back(0);
	dfs(p+1,cnt,sum+bi[p]);
	q.pop_back();
	q.push_back(1);
	dfs(p+1,cnt+1,sum+ai[p]);
	q.pop_back();
    }
    else{
	sig=q.front();q.pop_front();
	if(sig){
	    q.push_back(0);
	    dfs(p+1,cnt-1,sum+bi[p]);
	    q.pop_back();
	    q.push_back(1);
	    dfs(p+1,cnt,sum+ai[p]);
	    q.pop_back();
	}
	else{
	    q.push_back(0);
	    dfs(p+1,cnt,sum+bi[p]);
	    q.pop_back();
	    q.push_back(1);
	    dfs(p+1,cnt+1,sum+ai[p]);
	    q.pop_back();
	}
	q.push_front(sig);
    }
    return;
}

int readin(){
    int x=0,s=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*s;
}

int main(){
    freopen("entertainment.in","r",stdin);
    freopen("entertainment.out","w",stdout);
    n=readin();k=readin();ma=readin();mb=readin();
    for(int i=1;i<=n;++i)ai[i]=readin();
    for(int i=1;i<=n;++i)bi[i]=readin();
    dfs(1,0,0);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
