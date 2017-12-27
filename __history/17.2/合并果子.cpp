#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>a;
int n;
int temp,sum;
bool cmp(int a,int b)
{
return a>b?true:false;
}
int main()
{
int i=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&temp);
	a.push_back(temp);
}
make_heap(a.begin(),a.end(),cmp);
while(n>1)
{
temp=a[0];
pop_heap(a.begin() ,a.end(),cmp);
a.pop_back();
temp+=a[0];
pop_heap(a.begin(),a.end(),cmp);
a.pop_back();
sum+=temp;
a.push_back(temp);
push_heap(a.begin(),a.end(),cmp);
n--;
}
printf("%d",sum);
}
