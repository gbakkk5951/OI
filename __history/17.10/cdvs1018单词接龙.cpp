using namespace std;
int main(){}
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

struct _Main{
int n;
char head;
string word[20];
string str;
int cnt[20];	
int ans;
void dfs(){
	ans=max(ans,(int)str.length());
	string org=str;
	int i,j,k,l,m;
	for(i=0;i<n;i++)if(cnt[i]<2){
		
		for(j=str.length() -1;j>=str.length()-min(str.length(),word[i].length());j--){
			for(k=0;j+k<str.length();k++){
				if(str[j+k]!=word[i][k]){
					goto EndFor1;
				}
			}
			break;
			EndFor1:;
		}
		if(j==str.length()-min(str.length(),word[i].length())-1 )continue;
		cnt[i]++;
		str=str+ word[i].substr( k ,word[i].length()- k ); 
		dfs();
		str=org;
		cnt[i]--;
	}
	
	
	
	
}
_Main(){
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>word[i];
	}
	cin>>str;
	dfs();
	printf("%d",ans);
}
	
	
	
	
	
}cdvs1018;
