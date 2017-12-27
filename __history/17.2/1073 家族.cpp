#include<cstdio>
int n,m,q;
int p[5002]={0};
int h[5002]={1};
bool re[5002];
int main(){
	int i=0,j=0;
bool find(int,int);
	void merge(int,int);
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	p[i]=i;
	int t1,t2;
	for(i=1;i<=m;i++)
	{scanf("%d%d",&t1,&t2);
	merge(t1,t2);
	}
	for(i=1;i<=q;i++)
	{scanf("%d%d",&t1,&t2);
re[i]=find(t1,t2);

	}
		for(i=1;i<=q;i++)
	{if(re[i])
printf("Yes\n");
else printf("No\n");

	}
	
}
void merge(int a,int b){
	int ha,hb,pa,pb;
	pa=p[a];
	while(p[pa]!=pa)
	pa=p[pa];
	pb=p[b];
	while(p[pb]!=pb)
	pb=p[pb];
	ha=h[pa];
	hb=h[pb];
	if(ha<hb)
	p[pa]=pb;
	else
	p[pb]=pa;
	if(ha==hb)
	h[pa]++;
}
bool find(int a,int b)
{	int pa,pb;
	pa=p[a];
	while(p[pa]!=pa)
	pa=p[pa];
	pb=p[b];
	while(p[pb]!=pb)
	pb=p[pb];
	return pb==pa;
	
}
