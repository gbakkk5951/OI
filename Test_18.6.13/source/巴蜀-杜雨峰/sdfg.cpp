void mov(int a[],int wid)
{	
	for (int i=a[0];i>0;i--)	
	{	
		a[i+wid]=a[i];	
	}	
	a[0]+=wid;
}
void movrg(int a[],int wid)
{	
for (int i=1+wid;i<=a[0];i++)
a[i-wid]=a[i];	
a[0]-=wid;
}
void numcopy(int a[],int b[],int wid)
{
	for (int i=1;i<=a[0];i++)
	b[i+wid-1]=a[i];	
	b[0]=a[0]+wid-1;
}
int cmp(int a[],int b[])
{	
if (a[0]>b[0])return 1;	
if (a[0]<b[0])return -1;	
for (int i=a[0];i>0;i--)	
{		
if (a[i]>b[i])return 1;		
if (a[i]<b[i])return -1;	
}	
return 0;
}
void sub(int a[],int b[]){ 	
for (int i=1;i<=a[0];i++)	
{ 		if (a[i]<b[i])	
	{		
		a[i]+=10;	
				a[i+1]--;
						}	
			a[i]-=b[i];
		} 
	while (a[a[0]]==0&&a[0]>0)a[0]--; 
}
int Tmp[3001];
void divijon(int a[],int b[],int c[]){	
	c[0]=a[0]-b[0]+1;
		for (int i=c[0];i>0;i--)
			{	
				memset(Tmp,0,sizeof(Tmp));		
				numcopy(b,Tmp,i);		
				while (cmp(a,Tmp)>-1)		
				{		
					c[i]++;			
					sub(a,Tmp); 		
				}//			print(a);
				//			cout<<"divij ";
			}	
		while (c[0]>0&&c[c[0]]==0)c[0]--;
} 
void qy(int a[],int b[],int wid){	
for (int i=a[0]-wid;i>0;i--)	
{		b[i]=a[i];//		cout<<"qy ";	
}	b[0]=a[0]-wid;	
}
