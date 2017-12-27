#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
vector<string> a;
char temp[100];
bool wa;
int main()
{
	string t;
	while(~scanf("%s",temp))
	{
	t=temp;
	a.push_back(t); 
	}
	if(a.size()<6)
{
		printf("CE");
		return 0;
}
	
	if(a[0].find("#include")!=a[0].npos)
	{
	if(a[1]=="\"stdio.h\""||a[1]=="<stdio.h>")
	{
	if(a[2]=="int")
	{
		if(a[3]=="main(){")
		{
			int it;
			if((it=a[4].find("printf(\""))!=a[4].npos)
			{
				
				if(a[4].find("HelloWorld\\n")==a[4].npos)
				{
					wa=true;
				}else wa=false;
				
				int i=0;
				for(i=8;i<a[4].size();i++)
				{if(a[4].at(i)=='\"')
					{if(i+2<a[4].size())
					{
					if(a[4].at(i+1)==')'&&a[4].at(i+2)==';')
					{
						if(a[5]=="return")
						{
							if(a[6].at(a[6].size() -1)==';')
							{
								if(a.size()!=8)
								{
								
									 printf("CE");
							     return 0;
								 }
								if(a[7]=="}")
								{
									if(wa)
									{printf("WA");
									}else printf("AC");
									return 0;
									
									
								}
								
							}
						}else if(a[6]=="}")
						{if(wa)
						{printf("WA");
						}else printf("AC");
						return 0;
						}
						
						
						
						}	
						
					}
					}
					
				}
				
			 } 
			
		}
		
		
		
		}	
		
		
		
		
	}
	else
	{

		if(a[1]=="int")
	{

		if(a[2]=="main(){")
		{

			int it;
			if((it=a[3].find("printf(\""))!=a[3].npos)
			{

				if(a[3].find("HelloWorld\\n\"")== a[3].npos)
				{
					wa=true;
				}
				
				int i=0;
				for(i=8;i<a[3].size();i++)
				{if(a[3][i]=='\"')
					{
					if(i+2<a[3].size())
					{
					if(a[3][i+1]==')'&&a[3][i+2]==';')
					{
						if(a[4]=="return")
						{
							if(a[5][a[5].size() -1]==';')
							{
								if(a.size()<7)
								{
							
									 printf("CE");
							     return 0;
								 }
								if(a[6]=="}")
								{
									if(wa)
									{printf("WA");
									}else printf("AC");
									return 0;
									
									
								}
								
							}
						}else if(a[4]=="}")
						{
						
						if(wa)
						{printf("WA");
						}else printf("AC");
						return 0;
						}
						
						
						
						}	
						
					}
					}
					
				}
				
			 } 
			
		}
		
		
		
	
		
		}	
		
		
	 } }
	 printf("CE");
}
