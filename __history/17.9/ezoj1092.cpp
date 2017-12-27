
using namespace std;
int main(){}
#include<cstdio>
#include<vector>
#include<cctype>
#include<algorithm>
template<typename Type>
struct ForeverVec{

struct KidVec{
	Type key;int idx;
	bool friend operator < (const KidVec &a,const KidVec &b){
		return a.idx<b.idx;
	}
	
}emptyobj;

vector<KidVec> vec;
typename vector<KidVec>::iterator it;

ForeverVec(){
	vec.push_back((KidVec){0,0});
}
Type find(int idx){
	emptyobj.idx=idx;
	it=upper_bound(vec.begin(),vec.end(),emptyobj);
	it--;
	return it->key;
}
void insert(Type val,int idx){
	vec.push_back((KidVec){val,idx});
}

};
ForeverVec<int> fa[50005];
int height[50005];
int n,m;
int getfa(int nd,int idx){
	int t;
	if(t=fa[nd].find(idx)){
		return getfa(t,idx);
	}return nd;
}


template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
	
struct _Main{
	
_Main(){
	int i;int a,b;int f1,f2;
	read(n);read(m);int l,r;
	for(i=1;i<=m;i++){
		read(a);read(b);
		if((f1=getfa(a,i))!=(f2=getfa(b,i))){
			if(height[f1]>height[f2]){
				fa[f2].insert(f1,i);
			}else if(height[f1]<height[f2]){
				fa[f1].insert(f2,i);
			}else{
				fa[f1].insert(f2,i);height[f2]++;
			}
		}else{
			l=0;r=i-2;
			while(l<r){
				if(getfa(a,((l+r)>>1)+1)==getfa(b,((l+r)>>1)+1)){
					r=((l+r)>>1);
				}else{
					l=((l+r)>>1)+1;
				}
			}
			printf("%d\n",l);
		}
	}
}

}ezoj1092;
