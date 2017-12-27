#include<cstdio>
const int size=10000;
int data[size];
int index[size];
int find(int x); 
void replace(int x,int y);
void irepalce(int x,int y);
int main()
{
FILE *a=freopen("Ëæ»úÊý.out","r",stdin);
FILE *b=freopen("cycle sort.txt","w",stdout);

int i,j,k,l;
for(i=0;i<size;i++)
index[i]=1;

i=0;
int temp;
while(i<size&&scanf("%d",&temp)!=EOF)
{
data[i]=temp;

i++;

}
for(i=0;i<size;i++)
{

if(!index[i]||!data[i])
continue;

replace(find(data[i]),i);


}


for(i=0;i<size;i++)
{printf("%d ",data[i]);}
fclose(a);
fclose(b);
}



int find(int x)
{int i=0;
int temp=0;
for(i=0;i<size;i++)
if(x>data[i]&&data[i]!=0)
temp++;
return temp;
}

void replace(int x,int y)
{
int i=0,j=0,k=0,l=0;


//
while(x<size&&data[x]==data[y])
{
index[x]=0;
if(x==y)
{return;}
x++;
}
if(x>=size)
{
return;}
k=data[x];
data[x]=data[y];
data[y]=0;
index[x]=0;

if(k==0)
return;
else irepalce(find(k),k);
}

void irepalce(int x,int y)
{

//int i=0,j=0,k=0,l=0;
int k=0;
while(data[x]==y)
{
index[x]=0;
x++;
}
if(x>=size)
{printf("[size]");
return;}
k=data[x];
data[x]=y;
index[x]=0;

if(k==0)
return;
else irepalce(find(k),k);
}
