#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;
char ca[100502],cb[100502];
int a[60]={0},b[60]={0},re[60]={0};
int main(){
int j=0;
for(j=0;j<60;j++)
{a[j]=0;
b[j]=0;
re[j]=0;
}

	
	
	
scanf("%s%s",ca,cb);
int la,lb;
char ct[10];
la=strlen(ca);
lb=strlen(cb);

int next=0;
int max=la>lb?la:lb;

max=ceil((float)max/9);

for(j=1;j<=max;j++)
{
memset(ct,0,10);
if(j==ceil((float)la/9))
strncpy(ct,ca,la+9-j*9);
else if(j*9<=la)
strncpy(ct,&ca[la-j*9],9);
else{
	memset(ct,0,10);
if(j==ceil((float)lb/9))
strncpy(ct,cb,lb+9-j*9);
else if(j*9<=lb)
strncpy(ct,&cb[lb-j*9],9);
else continue;
stringstream sb(ct);
sb>>b[j-1];

	continue;
	
}
stringstream sa(ct);
sa>>a[j-1];


memset(ct,0,10);
if(j==ceil((float)lb/9))
strncpy(ct,cb,lb+9-j*9);
else if(j*9<=lb)
strncpy(ct,&cb[lb-j*9],9);
else continue;
stringstream sb(ct);
sb>>b[j-1];
	

	
	
	
	
}


next=0;
int i=0;
for(i=0;i<max;i++){

	
re[i]=a[i]+b[i]+next;

next=re[i]/1000000000;

if((i==max-1)&&( next!=0)){

max++;

}

re[i]-=next*1000000000;


}

for(i=max-1;i==max-1&&i>0;i--)
if(re[i]==0)
max--;


for(i=max-1;i>=0;i--)
if(i!=max-1)
printf("%09d",re[i]);
else printf("%d",re[i]);

}
