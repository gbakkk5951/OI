#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<string> st;
char a[100];
int main()
{
	string tm;
while(~scanf("%s",a))
{tm=a;
st.insert(st.begin() ,tm); 
	
	}
	int i=0;	
	for(;i<st.size() ;i++)
	{
		if(i!=st.size() -1)
	printf("%s ",st[i].data());
	else printf("%s",st[i].data() );
}}

