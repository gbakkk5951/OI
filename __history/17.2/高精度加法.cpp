#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;
char ca[502],cb[502];
int a[60]={0},b[60]={0},re[60]={0};
int main(){
int j=0;
for(j=0;j<60;j++)
{a[j]=0;
b[j]=0;
re[j]=0;
}
//////////////////////////////////	
//	printf("%d",1111111111/1000000000);
	
	
	
	
	
//////////////////////////////////
scanf("%s%s",ca,cb);
int la,lb;
char ct[10];
la=strlen(ca);
lb=strlen(cb);
///////////////////////////////////
int next=0;
int max=la>lb?la:lb;

max=ceil((float)max/9);
//printf("[%d];",max);
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
//printf("(b%d)=%d,",j*9,b[j-1]);
	continue;
	
}
stringstream sa(ct);
sa>>a[j-1];
//printf("(a%d)=%d,",j*9,a[j-1]);

memset(ct,0,10);
if(j==ceil((float)lb/9))
strncpy(ct,cb,lb+9-j*9);
else if(j*9<=lb)
strncpy(ct,&cb[lb-j*9],9);
else continue;
stringstream sb(ct);
sb>>b[j-1];
	
//printf("(b%d)=%d,",j*9,b[j-1]);
	
	
	
	
}

////////////////////////////////////
/*int i=ceil((float)la/9);
do{
		memset(ct,'\0',10);
if(i>1||ceil((float)la/9)==floor((float)la/9))
strncpy(ct,&ca[i-1],9);
else strncpy(ct,ca,la-floor((float)la/9)*9);
		
		
/if(la-i*9<0)
strncpy(ct,ca,9+(la-i*9));
else
strncpy(ct,&ca[la-i*9],9);
//ct[10]='\0';

stringstream sa(ct);
sa>>a[i-1];
//printf("(%d)=%d,",i*9,a[i-1]);
i--;
}
while(i>0);
i=ceil((float)lb/9);
do{
	memset(ct,'\0',10);
	
if(i>1||ceil((float)lb/9)==floor((float)lb/9))
strncpy(ct,&cb[i-1],9);
else strncpy(ct,cb,lb-floor((float)lb/9)*9);
*
if(lb-i*9-1<0)
strncpy(ct,cb,9+(lb-i*9));
else
strncpy(ct,&cb[lb-i*9-1],9);
/

stringstream sb(ct);
sb>>b[i-1];
//printf("(%d)=%d,",i*9,b[i-1]);
i--;
}while(i>0);
*//*
int next=0;
int max=la>lb?la:lb;

max=ceil((float)max/9);
*/
//printf("max=%d",max);
next=0;
int i=0;
for(i=0;i<max;i++){
//	printf("\n{(b%d)=%d,",i,b[i]);
//	printf("(a%d)=%d,",i,a[i]);
//	printf("(next=%d,)",next);
	
re[i]=a[i]+b[i]+next;
//	printf("(re%d)=%d,",i,re[i]);
next=re[i]/1000000000;
//	printf("(next=%d,)",next);
if((i==max-1)&&( next!=0)){
//printf("[%d]",next);
//printf("%d",next);
max++;
/*
re[max-1]=next;*/}
//printf("[%d]",next);
re[i]-=next*1000000000;

	//	printf("(re=%d,)\n",re[i]);
}

for(i=max-1;i>=0;i--)
if(i!=max-1)
printf("%09d",re[i]);
else printf("%d",re[i]);

}
