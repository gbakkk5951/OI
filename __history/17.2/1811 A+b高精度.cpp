#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
#include<string>
using namespace std;
int type;

char ca[100502],cb[100502];
char ta[100502],tb[100502];
int a[12000]={0},b[12000]={0},re[12000]={0};
int main(){
int j=0;

	
	
	
scanf("%s%s",ta,tb);
if(ta[0]!='-'&&tb[0]!='-')
{type=0;
strcpy(ca,ta);
strcpy(cb,tb);
}else if(ta[0]=='-'&&tb[0]=='-')
{
	type=1;
	string sa,sb;
	sa=ta;sb=tb;
	sa=sa.substr(1,strlen(ta)-1);
	sb=sb.substr(1,strlen(tb)-1);
	strcpy(ca,sa.c_str());
    strcpy(cb,sb.c_str());
}
else if(ta[0]=='-',tb[0]!='-')
{
	type=2;
	string sa,sb;
	sa=ta;sb=tb;
	sa=sa.substr(1,strlen(ta)-1);

if(sa.size()>sb.size()||sa.size()==sb.size()&&(sa>sb))
{
printf("-");
	strcpy(ca,sa.c_str());
	strcpy(cb,tb);
}
else if(sa.size()<sb.size()||(sa.size()==sb.size()&&sa<sb))
{
	strcpy(cb,sa.c_str());
	strcpy(ca,tb);
}
else {printf("0");return 0;
}
}else if(ta[0]!='-'&&tb[0]=='-')
{

		type=2;
	string sa,sb;
	sa=tb;sb=ta;
	sa=sa.substr(1,strlen(tb)-1);

if(sa.size()>sb.size()||sa.size()==sb.size()&&(sa>sb))
{
printf("-");
	strcpy(ca,sa.c_str());
	strcpy(cb,ta);
}
else if(sa.size()<sb.size()||(sa.size()==sb.size()&&sa<sb))
{
	strcpy(cb,sa.c_str());
	strcpy(ca,ta);
}
else {printf("0");return 0;
}
	
}

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
if(type==0)
for(i=0;i<max;i++){	
re[i]=a[i]+b[i]+next;
next=re[i]/1000000000;
if((i==max-1)&&( next!=0)){
max++;
}
re[i]-=next*1000000000;
}
else if(type==1)
{for(i=0;i<max;i++){	
re[i]=a[i]+b[i]+next;
next=re[i]/1000000000;
if((i==max-1)&&( next!=0)){
max++;
}
re[i]-=next*1000000000;
}
printf("-");
	
}else if(type==2)
{
//借位有问题 
next=0;
for(i=0;i<max;i++){	
re[i]=-b[i]+a[i]-next;
if(re[i]<0)
{
re[i]+=1000000000;
next=1;
}
else next=0;




}
	
	
}


for(i=max-1;i==max-1&&i>0;i--)
if(re[i]==0)
max--;


for(i=max-1;i>=0;i--)
if(i!=max-1)
printf("%09d",re[i]);
else printf("%d",re[i]);

}
