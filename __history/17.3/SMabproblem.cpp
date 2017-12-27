#include<cstdio>
#include<cmath>
#include<limits>
using namespace std;
unsigned long long a,b;
double ans;
int main()
{
scanf("%llu%llu",&a,&b);

if(a!=0)
ans+=log10(a);
else{
ans+=log10(numeric_limits<unsigned long long>::max());
}
if(b!=0)
ans+=log10(b);
else{
ans+=log10(numeric_limits<unsigned long long>::max());
}

ans+=1;
printf("%d",(int)ans);
}
