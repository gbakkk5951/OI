using namespace std;
int main(){}
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<string>
int from[2000010];
int dp[2000010];
int arridx;//查一次清空一次 
string str;
int ans;
struct Tire{
	int nodeidx;
	int nxt[2000010];
	char alp[2000010];
	int head[2000010];
	int num[2000010];
	
	void insert(int strnum){
		int len=str.length();
		int nd=0;int i;int I;
		for(I=0;I<len;I++){
			for(i=head[nd];i;i=nxt[i])if(alp[i]==str[I]){
				nd=i;
				if(num[nd]){
					from[arridx++]=num[nd];
				}
				break;
			}
			
			if(i==0){
				nd=add(nd,str[I]);
			}
		}
		num[nd]=strnum;
	}
	
	int add(int fa,char s){
		nodeidx++;
		nxt[nodeidx]=head[fa];
		head[fa]=nodeidx;
		alp[nodeidx]=s;
		return nodeidx;
	}
}rev,nor;


struct _Main{

int n;
_Main(){
	
	
	std::ios::sync_with_stdio(false);
	int i,j,beg,t=0;
	cin>>n;
	if(n==1){
		printf("1");
		return;
	}
	for(i=1;i<=n;i++){
		arridx=0;
		cin>>str;
		nor.insert(i);
		reverse(str.begin(),str.end());
		rev.insert(i);
		sort(from,from+arridx);
		for(j=1,t=0;j<arridx;j++)if(from[j]==from[j-1]){
			t=max(t,dp[from[j]]);
		}
		dp[i]=t+1;
		ans=max(ans,t+1);
	}
	cout<<ans;
	
	

}	
	
	
	
	
	
	
	
}jsk;
