#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int gov;
int govp=-1;
int down;
float  top=10000000.0;
float  bottom=-10000000.0;
int mostpro;
bool df=false;
int least;
int most;

struct str{
	int price;
	int pro;
};
vector<str>price;
int main()
{
	scanf("%d",&gov);
	int tm1,tm2;
    str tm;
	while(1)
	{scanf("%d%d",&tm1,&tm2);
	if(tm1==-1)
	break;
	else if(tm1==gov)
	{govp=tm2;
	df=true;
	continue;
	}
	tm.price=tm1;
	tm.pro=tm2;
	price.push_back(tm);
	}
		scanf("%d",&down);
	least=price[0].price;
	
	bool cmp(str,str);
	sort(price.begin(),price.end(),cmp);
	

	
	
	
	
//判断段； 
    most=price[price.size() -1].price;
    mostpro=price[price.size() -1].pro;
  
    int i=0;
    int count=1;
    if(most<gov&&df)
    {most=gov;
    mostpro=govp;
	}
	 //处理更高价 
 while(price[price.size() -1].pro>0)
    {
    	tm.price =most+count;
    	tm.pro = mostpro-down*count;
    	price.push_back(tm); 
    	count++;

	}
	price.pop_back() ;
	//补中间价格
	int j=0;
	for(j=0;j<most-least-1;)
	{
		int times=price[j+1].price-price[j].price;
	//	printf("(j=%d,%d)",j,times);
		if (times==1)
		{
			j++;
			continue;
		 }
		 int cur=j+1;
		 int fpro=(price[j+1].pro-price[j].pro)/(price[j+1].price-price[j].price); 
		for(;cur<j+times;cur++)
		{
			tm.price=price[j].price+cur-j;
			tm.pro=(cur-j)*fpro+price[j].pro;
			
			price.insert(price.begin() +cur,tm);
	
		}
		j=cur;
	 } 
	 
if(!df)
govp=price[gov-least].pro;

	
	  
	float temp;
	for(i=0;i<price.size() ;i++)
	{
		temp=(double)(govp*least-govp*gov+price[i].pro*price[i].price-price[i].pro*least)/(govp-price[i].pro);
//	printf("\n%d %d temp=%f;",price[i].price,price[i].pro,temp);
		if(govp<price[i].pro)
		{
		if(temp<top)
		top=temp;
	}else if(govp>price[i].pro)
{
if(temp>bottom)	
bottom=temp;	
}else if(govp==price[i].pro)

if(gov<price[i].price)
{
printf("NO SOLUTION");
return 0;}
	}
	
	int ib,it;

ib=(int)ceil(bottom);	
it=(int)floor(top);

	//输出段 
	if(ib>it)
	printf("NO SOLUTION");
	else if(ib>=0)
	printf("%d",ib);
	else if (it<=0)
	printf("%d",it);
	else if(-ib<it)
	printf("%d",ib);
	else printf("%d",it);
	
	
	

	
}

bool cmp(str a,str b)
{
	return a.price<b.price;
	
}

