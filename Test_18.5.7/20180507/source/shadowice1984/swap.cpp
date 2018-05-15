#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;typedef long long ll;const int N=2*1e5+10;
int n;
namespace solve1
{
	int res=0x3f3f3f3f;struct data{int l;int r;};vector <data> opt;vector <data> tr;
	inline void clear(vector <data>& ve){vector <data> emp;swap(emp,ve);}
	inline int mabs(int x){return x>0?x:-x;}
	int qbl[10];int a[10];int b[10];int loc[10];int t[10];int tp[10];
	inline void solvep1()
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){loc[b[i]]=i;}
		for(int i=1;i<=n;i++)qbl[i]=i;
		do
		{
			int ret=0;clear(tr);
			for(int i=1;i<=n;i++){t[a[i]]=i;}
			for(int i=1;i<=n;i++){tp[i]=a[i];}
			for(int i=1;i<=n;i++)
			{
				int pos1=t[a[qbl[i]]];int pos=loc[a[qbl[i]]];
				if(pos1==pos){continue;}
				ret+=mabs(pos1-pos);
				tr.push_back((data){pos1,pos});
				swap(t[tp[pos1]],t[tp[pos]]);
				swap(tp[pos1],tp[pos]);
			}
			if(res>ret){res=ret;swap(opt,tr);}
		}while(next_permutation(qbl+1,qbl+n+1));
		printf("%d\n",opt.size());
		for(int i=0;i<opt.size();i++)
		{
			printf("%d %d\n",opt[i].l,opt[i].r);
			swap(a[opt[i].l],a[opt[i].r]);
		}return ;
	}
};
namespace solve2
{
	int a[N];int b[N];int loc[N];int tw[N];bool book[N];
	map <int,bool> mp[N];
	inline int mabs(int x){return (x>0)?x:-x;}
	struct data
	{
		int l;int r;
		friend bool operator <(data a,data b)
		{return mabs(a.l-a.r)>mabs(b.l-b.r);}
	};vector <data> opt;priority_queue <data> pq;
	inline void clear(priority_queue <data>& pq){priority_queue <data> emp;swap(emp,pq);}
	inline void dfs(int u)
	{
		book[u]=true;
		if(!book[tw[u]]){dfs(tw[u]);}
		pq.push((data){u,tw[u]});
	}
	inline void solvep2()
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)loc[b[i]]=i;
		for(int i=1;i<=n;i++)tw[i]=loc[a[i]];
		for(int i=1;i<=n;i++)
		{
			if(!book[i]){dfs(i);}
			while(!pq.empty())
			{
				data now=pq.top();pq.pop();
				if(now.l==now.r){continue;}
				if(mp[now.l][now.r]){continue;}
				opt.push_back(now);mp[now.r][tw[now.r]]=true;
				int nl=now.l;int nr=tw[now.r];tw[nl]=nr;
				pq.push((data){nl,nr});
			}
		}
		printf("%d\n",opt.size());
		for(int i=0;i<opt.size();i++)
		{
			printf("%d %d\n",opt[i].l,opt[i].r);
		}return ;
	}
}
int main()
{
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	scanf("%d",&n);
	if(n<=8){solve1::solvep1();}
	else {solve2::solvep2();}
	fclose(stdin);fclose(stdout);return 0;
}


