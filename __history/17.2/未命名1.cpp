#include<cstdio>
#include<set>
#include<sstream> 
#include<string>
using namespace std;
int main()
{
char n []="   sada   156   ";	
stringstream ss(n);

char b[100];
while(ss>>b)
{

//temp.copy(b,temp.size());
printf("%s\n",b);
}
}
