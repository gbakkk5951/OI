#include<vector>
#include<cstdio>
using namespace std;
int cnt;
struct test{
test(){
	printf("%d\n",cnt++);
}
};
vector<test>d;

int main(){
int b;
test temp;
while(1){
	scanf("%d",&b);
	d.push_back(temp);
}
	

} 
