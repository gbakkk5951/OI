#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>

int n=0;
using namespace std;
char ca[502],cb[502];
int a[60]={0},re[60]={0};
int main(){
void scan();
int j=0;
	scanf("%d",&n);
	int k=0;
	for (k=0;k<n;k++)
{
for(j=0;j<60;j++)
{a[j]=0;
re[j]=0;
}
scan();
}
	

	} 
void scan(){	
	int j=0;
scanf("%s",ca);
int la;
char ct[10];
la=strlen(ca);

int next=0;
int max=la;

max=ceil((float)max/9);

for(j=1;j<=max;j++)
{
memset(ct,0,10);
if(j==ceil((float)la/9))
if(la+9-j*9==1&&ca[0]=='-')
{la--;
 a[j-2]=-a[j-2];	
 max=la;
max=ceil((float)max/9);
break;
}
else
strncpy(ct,ca,la+9-j*9);
else if(j*9<=la)
strncpy(ct,&ca[la-j*9],9);

stringstream sa(ct);
sa>>a[j-1];



	
	
	
	
}


next=0;
int i=0;

for(i=0;i<max;i++){
	bool c=false;
	if(i==max-1 &&next==-1)
	re[i]=a[i]+1;
	else
if(i==0 &&a[max-1]>=0)
re[i]=a[i]+1;
else if(i==0&&i==max-1&&a[max-1]<0)
re[i]=a[i]+1;
else if(i==0 &&a[max-1]<0)
{if(a[i]==0)
{
re[i]=999999999;
next=-1 ;
c=true;
}	else re[i]=a[i]-1;
	
}

else 
if(a[i]==0&&next==-1) 
{
re[i]=999999999;
next=-1 ;
c=true;
}else re[i]=a[i]+next;
if(!c)
next=re[i]/1000000000;

if((i==max-1)&&( next!=0)){

max++;

}
if(!c)
re[i]-=next*1000000000;


}

for(i=max-1;i>=0;i--){
if(i!=max-1||re[i]!=0)
if(i==0 &&i!=max-1)
printf("%09d ",re[i]);
else
if(i==0&&i==max-1)
printf("%d ",re[i]);
else
if(i!=max-1)
printf("%09d",re[i]);
else printf("%d",re[i]);
else if(a[max-1]<0&&max>1)
printf("-");
else printf("0 ");
}
}
