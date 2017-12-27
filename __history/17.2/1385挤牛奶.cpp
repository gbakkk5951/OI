#include<cstdio>
int a[1000010];
int main()
{int i,n,t1,t2;
scanf("%d",&n);
int m=0,mi=1000000;
for(i=0;i<n;i++)
{scanf("%d%d",&t1,&t2);
 a[t1]++;
 a[t2]--;
 if(t2>m)
 m=t2;
 if(t1<mi)
 mi=t1;
}

int mx=0,mxn=0,nbeg=-1,mbeg=-1,now=0;
	for(i=mi;i<m;i++)
	{
		now+=a[i];
		if(now==0)
		{mbeg=-1;
		if(nbeg!=-1)
		{
		if(mxn<i-nbeg+1)
		mxn=i-nbeg+1;	
		}else {
		nbeg=i;
		if(mxn<1)mxn=1;
		}
		}else
		{nbeg=-1;
		if(mbeg!=-1)
		{
			if(mx<i-mbeg+1)
			mx=i-mbeg+1;
			
		}else
		{mbeg=i;
		if(mx<1)
		mx=1;
		}
			
			
			
			
		 } 
		
		
	}
	printf("%d %d",mx,mxn);
}
