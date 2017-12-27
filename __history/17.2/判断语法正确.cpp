#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
using namespace std;
stack<int>a;

vector<string> z;
bool form,name;
int po;
bool istype(int sign=0)
{
	if(z[sign]=="unsigned")
	{
	return true; 
	}
	if(z[sign]=="long")
	return true;
	if(z[sign]=="int")
	return true;
	if(z[sign]=="char")
	return true;
	if(z[sign]=="short")
	return true;
	if(z[sign]=="double")
	return true;
	if(z[sign]=="float")
	return true;
	if(z[sign]=="bool")
	return true;
}

int main()
{
	string t;
char f[100];
int l=0;
while(~scanf("%s",f))
{
	t=f;
	z.push_back(t);

    l++;
}

if(l==0||l==1)
{printf("F");
return 0;
}
if(z[0]=="unsigned")
{
if(l==1)
{printf("F");
return 0;
}
if(z[1]=="long")
{
if(l==2)
{printf("F");
return 0;
}
if(l>3)
{
if(((z[2]=="long"||z[2]=="double")&&!istype(3))||!istype(2))
{
form=true;
po=3;
}
}else if(istype(2))
{
printf("F");
return 0;
}else{
 form=true;
}
if(!istype(2))
po=2;
}
else
if(l>=3)
if(istype(1)&&!istype(2))
{
	if(z[1]!="unsigned"&&z[1]!="bool"&&z[1]!="long")
	{
	form=true;
	po=2;
         }
}
if(!istype[1])
{po=1;
form=true;
}
}

else if(z[0]=="long")
{
if(l>3)
{	
	if(z[1]=="long"&&!istype(2))
	{po=2;
	form=true;
	}
	else if(z[1]=="double"&&!istype(2))
	{po=2;
	form=true;
	}
}
else if(l>2)
	if(!istype(1))
	{po=1;
	form=true;
	}
}
else if(istype(0)&&!istype(1))
{form=true;
po=1;
}

if(!form||po!=z.size()-1)
{printf("F");
return 0;
}
else 
{
int i=0;
for(i=0;i<z[po].size() ;i++)
{if(z[po][i]=='[')
{
if(a.size())
{printf("F");
return 0;
}
else{
a.push(1); 
}
}else if(z[po][i]==']')
{
	if(a.size()&&z[po][i-1]!='[')
	a.pop() ;
	else
	{printf("F");
	return 0;
	}
	
}
}
if(a.size()||z[po][i-1]!=';' )
{
	printf("F");
	return 0;
}
printf("T");
return 0;
}
}
