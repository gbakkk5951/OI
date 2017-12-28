using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<set>
#include<vector>
struct Block{
	int l;int r;
	bool friend operator < (const Block &a,const Block &b){
		return a.l<b.l && a!=b;
	}
	bool friend operator == (const Block &a,const Block &b){
		return a.l>=b.l && a.r<=b.r ||  b.l>=a.l && b.r<=a.r;
	}
	bool friend operator != (const Block &a,const Block &b){
		return !(a==b);
	}	
};
set<Block>tree;
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
vector<int>pos[10010];
set<Block>::iterator it;
int n,h[100010];
long long ans;
_Main(){
	Block tmp,tmp1,tmp2;
	int i,j,k;
	read(n);
	
	for(i=1;i<=n;i++){
		read(h[i]);
		pos[h[i]].push_back(i);
	}
	tmp.l=1;tmp.r=n;
	tree.insert(tmp);
	for(i=1;tree.size();i++){
		for(j=0;j<pos[i-1].size();j++){
			tmp.l=tmp.r=pos[i-1][j];
			it=tree.find(tmp);
			tmp1.l=tmp.r+1;
			tmp1.r=it->r;
			tmp2.l=it->l;
			tmp2.r=tmp.r-1;		
			tree.erase(it);
			if(tmp1.l<=tmp1.r){
				tree.insert(tmp1);
			}
			if(tmp2.l<=tmp2.r){
				tree.insert(tmp2);
			}
		}		
		ans+=tree.size();
	}
	printf("%d",ans);
}
	
	
	
	
	
}ezoj1109;
