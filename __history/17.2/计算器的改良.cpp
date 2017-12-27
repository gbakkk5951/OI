#include<stdio.h>
#include<string>
#include<cctype>
#include<sstream>
using namespace std;
int main()
{

	char temp;
	char cha;
	int i=0;
	int nu=0,al=0;
	string stemp;
	
	int te=0;
	for(i=0;1;i++)
	{
		
		temp=getchar();
		if(stemp.size()!=0){
		
		if(temp=='-'||temp=='+')
	{
			{
		stringstream ss(stemp);
		te=0;
		ss>>te;
		nu-=te;
		stemp.clear();
		stemp.insert(stemp.begin(),temp);
		}
	}else

		if(isalpha(temp)){
		cha=temp;
		if(stemp.size()==1)
		{if(stemp[0]=='-')
		al--;
		else if(stemp[0]=='+') 
		al++;
	else
	{
			stringstream ss(stemp);
		ss>>te;
		al+=te;
	
		}	
			stemp.clear();
		}else{
		
		stringstream ss(stemp);
		te=0;
		ss>>te;
		al+=te;
		stemp.clear();
	}
		}
		else if(temp=='=')
		{
			if(stemp.size()!=0){
			
		stringstream ss(stemp);
		ss>>te;
	
		nu-=te;
		stemp.clear();
			}break;
		}
		
		else{
		 stemp.insert(stemp.end(),temp);
	}
	
	
	}
	else
	{
		if(temp=='=')
		break;
		if(isalpha(temp))
		al++;
		else
		stemp.insert(stemp.end(),temp);

	}
	
	}

	stemp.clear();
		for(i=0;1;i++)
	{
		
		temp=getchar();
		if(stemp.size()!=0){
		
		if(temp=='-'||temp=='+')
	{
		
			{
		stringstream ss(stemp);
		te=0;
		ss>>te;
		nu+=te;
		stemp.clear();
		stemp.insert(stemp.begin(),temp);
		}
	}else

		if(isalpha(temp)){
		cha=temp;
		if(stemp.size()==1)
		{if(stemp[0]=='-')
		al++;
		else if(stemp[0]=='+') 
		al--;
	else
	{
			stringstream ss(stemp);
			te=0;
		ss>>te;
		al-=te;
	
		}	
			stemp.clear();
		}else{
		
		stringstream ss(stemp);
		te=0;
		ss>>te;
		al-=te;
		stemp.clear();
	}
		}
		else if(temp==EOF)
		{
			if(stemp.size()!=0){
		stringstream ss(stemp);
		te=0;
		ss>>te;

		nu+=te;
		stemp.clear();
			}break;
		}
		
		else{
		 stemp.insert(stemp.end(),temp);
	}
	
	
	}
	else
	{
		if(temp==EOF)
		break;
		if(isalpha(temp))
		al--;
		else
		stemp.insert(stemp.end(),temp);

	}
	
	}
	
	float t=(float) nu /(float)al;
	if(t==0.00)
	t=0.000;
	printf("%c=%.3f",cha,t);
	
}
