#include<cstdio>
#include<cstring>
//const int inf=2147483647; 
//d[i][j]代表i>j
// 1为>,2为<,3为==; 
int d[310][310];
int f[310];
struct P
{
int l,r,p;	
	
}po[5010];
int ans[100010];
int at;
int pt;

int n,p,q;

int find(int x)
{
	return f[x]==f[f[x]]?f[x]:f[x]=find(f[x]);
}
int get(int x)
{
	return f[x]==f[f[x]]?f[x]:f[x]=get(f[x]);
}


int main()
{
	int qqq=1;
	for(qqq=1;qqq<=10;qqq++)
	{
	char namei[20]="scales";
	char temp[20];
	sprintf(temp,"%d.in",qqq);
	strcat(namei,temp);
	char nameo[20]="scales";
	sprintf(temp,"%d.out",qqq);
	strcat(nameo,temp);
	FILE *fa=freopen(namei,"r",stdin);
	FILE *fb=freopen(nameo,"w",stdout);
	
	int i,j,k,l;
	for(i=0;i<310;i++)
	{	
	f[i]=i;
 	for(j=0;j<310;j++)
 	d[i][j]=0;
	}
	memset(ans,0,sizeof(ans));
	memset(po,0,sizeof(po));
	at=0;
	pt=0;
	
	scanf("%d%d%d",&n,&p,&q);
	P te;
	for(i=1;i<=p;i++)//并查集 
	{
		scanf("%d%d%d",&l,&j,&k);
		if(l!=3)
		{
		te.l =j;te.r =k;te.p =l;
		po[pt]=te;
		pt++;
	    }
	    else
	    {
	    	f[find(j)]=f[find(k)];
		}
	}
	for(i=0;i<pt;i++)
	{
		if(po[i].p==1)
		{d[find(po[i].l)][find(po[i].r)]=1;
		}else d[find(po[i].r)][find(po[i].l)]=1;
	}
	
	//floyd 
	for(k=1;k<=n;k++)
	for(j=1;j<=n;j++)
	for(i=1;i<=n;i++)
	{
		if(d[find(i)][find(k)]/*^inf*/&&d[find(k)][find(j)]/*^inf*/)
		{d[find(i)][find(j)]=1;
		}
	 } 
	
	
	//question
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&j,&k);
		if(find(j)==find(k))
		ans[at++]=1;
		else if(d[find(j)][find(k)])
		{
			ans[at++]=2;
		}
		else if(d[find(k)][find(j)])
		ans[at++]=3;
		else ans[at++]=4;
		
	}
	for(i=0;i<at;i++)
	{
		if(ans[i]==1)
		printf("Balance\n");
		if(ans[i]==2)
		printf("Left\n");
		if(ans[i]==3)
		printf("Right\n");
		if(ans[i]==4)
		printf("Unknown\n");
		
		
	}
	fclose(fa);
	fclose(fb);
    }
}
