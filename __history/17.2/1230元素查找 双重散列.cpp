#include<cstdio>
#include<cstring>
using namespace std;
int h(int k,int i);
int h1(int k);
int h2(int k);
int m2=131070;
int m,n,hash[131073]={-2147483647};
bool re[100003]={false };
int main()
{
int f=0;
for(f=0;f<131073;f++)
{
hash[f]=-2147483647;


}
for(f=0;f<100000;f++)
{
re[f]=false;
}
scanf("%d%d",&n,&m);
int i=0,j=0,temp,t2;
for(i=0;i<n;i++)
{
j=0;
scanf("%d",&temp);
do
{t2=h(temp,j);
j++;

}
while(hash[t2]!=-2147483647);

hash[t2]=temp;


}

for(i=0;i<m;i++)
{
	j=0;
	scanf("%d",&temp);
	do{
	t2=h(temp,j);
	j++;

	}
	while(hash[t2]!=temp&&hash[t2]!=-2147483647&&j<=131072);

if(hash[t2]==temp)
   re[i]=true;
	
}  

for(i=0;i<m;i++)
{
if(re[i])
 printf("YES\n");
 else printf("NO\n");

} 


}
int h(int k,int i){
return( (h1(k)+i*h2(k))%131071);

}

int h1(int k)
{
	return (k%131071); 
}
int h2(int k){
return(1+k%m2);

}
