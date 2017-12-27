#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long 
#define inf 1000000000
#define mod 1000000007
using namespace std;
int n,pos[1000005];
struct acm{
	int cnt;
	int next[1000005][26],sum[1000005],fail[1000005],q[1000005];
	char ch[1000005];
	acm(){
		cnt=1;
		for(int i=0;i<26;i++)next[0][i]=1;
	}
	void insert(int &pos){
		int now=1;
		scanf("%s",ch);
		int n=strlen(ch);
		for(int i=0;i<n;i++)
		{
			if(!next[now][ch[i]-'a'])next[now][ch[i]-'a']=++cnt;
			now=next[now][ch[i]-'a'];
			sum[now]++;
		}
		pos=now;
	}
	void buildfail(){
		int head=0,tail=1;
		q[0]=1;fail[1]=0;
		while(head!=tail)
		{
			int now=q[head];head++;
			for(int i=0;i<26;i++)
			{
				int v=next[now][i];
				if(!v)continue;
				int k=fail[now];
				while(!next[k][i])k=fail[k];
				fail[v]=next[k][i];
				q[tail++]=v;
			}
		}
		for(int i=tail-1;i>=0;i--)
			sum[fail[q[i]]]+=sum[q[i]];
	}	
}acm;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		acm.insert(pos[i]);
	acm.buildfail();
	for(int i=1;i<=n;i++)
		printf("%d\n",acm.sum[pos[i]]);
	return 0;
}
