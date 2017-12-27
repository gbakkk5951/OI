#include<cstdio>
#include<set>
#include<algorithm>
#include<cstdlib>
using namespace std;
int sum;

	int l[300010],r[300010],val[300010],lz[300010],f[300010],dis[300010];


int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void spread(int nd){
	if(!nd)return;
	val[l[nd]]+=lz[nd];
	lz[l[nd]]+=lz[nd];
	val[r[nd]]+=lz[nd];
	lz[r[nd]]+=lz[nd];
	lz[nd]=0;
}
int merge(int a,int b){

	if(!a)return b;
	if(!b)return a;
	
	spread(a);spread(b);
	if(val[a]<val[b]){
		swap(a,b);
	}
	r[a]=merge(r[a],b);
	f[r[a]]=a;
	if(dis[l[a]]<dis[r[a]]){
		swap(l[a],r[a]);
	}
	if(l[a]&&r[a])
	dis[a]=dis[r[a]]+1;
	else{
		dis[a]=0;
	}
	return a;	
}


void up(int nd){
	if(nd)
	if(f[nd]!=nd){
		up(f[nd]);
		spread(nd);
	}
}
int getf(int nd){
	
	while(f[nd]!=nd)
	{
	nd=f[nd];
	}return nd;
}
multiset<int>tree;
int n,q;
int main(){
	int fj,fk;
	int i,j,k,t1,t2;
	char temp[10];
	dis[0]=-1;
	n=read();
	for(i=1;i<=n;i++){
		val[i]=read();
		f[i]=i;
		tree.insert(val[i]);
	}
	q=read();
	for(i=0;i<q;i++){
		scanf("%s",temp);
		if(temp[0]=='A'){
			switch(temp[1]){
				case '1':{
					j=read();k=read();
					up(j);
					spread(j);
					fj=getf(j);
					tree.erase(tree.find(val[fj]));
					if(l[f[j]]==j){
						l[f[j]]=0;
					}
					if(r[f[j]]==j){
						r[f[j]]=0;
					}
					dis[f[j]]=0;										
					f[l[j]]=l[j];
					f[r[j]]=r[j];
					t1=merge(r[j],l[j]);				
					if(j!=f[j])
					t1=merge(t1,fj);
					f[j]=j;
					l[j]=0;
					r[j]=0;
					dis[j] =0;
					val[j]+=k;
					t1=merge(t1,j);	
					tree.insert(val[t1]);
					break;
				}
				case '2':{
					j=read();k=read();
					fj=getf(j);
					tree.erase(tree.find(val[fj]));					
					val[fj]+=k;
					lz[fj]+=k;					
					spread(fj);					
					tree.insert(val[fj]);
					break;
				}
				case '3':{
					j=read();
					sum+=j;
					break;
				}
			}
		}
		if(temp[0]=='F'){
			switch(temp[1]){
				case '1':{
					j=read();
					up(j);
					printf("%d\n",sum+val[j]);
					break;
				}
				case '2':{
					j=read();
					printf("%d\n",sum+val[getf(j)]);
					break;
				}
				case '3':{
					printf("%d\n",sum+*(--tree.end()));
					break;
				}
			}
			
		}
		if(temp[0]=='U'){
			j=read();k=read();
			fj=getf(j);fk=getf(k);
			if(fj==fk)
			continue;
			if(val[fj]<val[fk])
			tree.erase(tree.find(val[fj]));
			else
			tree.erase(tree.find(val[fk]));
			j=merge(fj,fk);
			tree.insert(val[j]);
		}
	}

}
