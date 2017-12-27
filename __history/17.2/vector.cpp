#include <stdio.h>
#include<vector>

using namespace std;
vector<int> a;
int main()
{
	void out();
	int i;
	for(i=0;i<=10;i++)
	{
		
a.push_back(i);
           


		
		
	}
a.insert(a.begin()+2,-5) ;
	out();
	

	
	
}

void out()
{
	int n;
	for(n=0;n<=a.size()-1;n++)
	{
		
		printf("%d:%d ",n,a.at(n));
	
		
		
	}
	
	putchar('\n');
	
	
	
 } 
