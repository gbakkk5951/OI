using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<vector>
struct dp{
	int lar,len;
	bool friend operator < (dp a,dp b){
		return a.lar < b.lar;
	}
};
vector<dp> que;
struct _Main{
int read(){
	char t,f=1;
	int ans;
	while(!isdigit( t= getchar())){
		if(t=='-'){
			f=-1; 
		}
	}
	ans=t-'0';
	while( isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}return ans*f;
}
int n;
int num[5010];
_Main(){
	int ans=0;
	int i,j,k;
	n=read();
	for(i=0;i<n;i++){
		num[i]=read();
	}
	dp temp;
	vector<dp>::iterator it;
	for(i=0;i<n;i++){
		temp.lar=num[i];
		it=lower_bound(que.begin(),que.end(),temp);
		if(it!=que.begin()){
			temp.len =(--it)->len+1; 
		}
		else
			temp.len =1;
		k=it-que.begin();
		ans=max(ans,temp.len );
		que.insert(it,temp);
		while(++k < que.size()){
			if(que[k].len<temp.len){
				que.erase(que.begin()+k);
			}else{
				break;
			}
		}
	}
	printf("%d",ans);
	
}
	
}cdvs1576;
