#include<stdlib.h>
int globa_count=0;
void merge_inversion(int *a,int l,int m,int r)
{
int i,j,k;
int n1=m-l+1;
int n2=r-m;
int *L=(int*)calloc(n1,sizeof(int));
int *R=(int*)calloc(n2,sizeof(int));
for(i=l;i<=m;i++)
L[i-l]=a[l];
for(j=m+1;j<=r;j++)
R[j-m-1]=a[j];
i=0;
j=0;
for(k=l;k<=r;k++)
{
if(i<n1&&j<n2)
{
if(L[i]<R[j])
{
a[k]=L[i++];
globa_count+=n2-1-j+1;
}
else
a[k]=R[j++];
}
else
break;
}
//processifonepartterminatelyearly
if(i==n1&&j<n2)
while(j<n2)
a[k++]=R[j++];
if(i<n1&&j==n2)
while(i<n1)
a[k++]=L[i++];
free(L);
free(R);
}
