using namespace std;
int main(){}
#include<cstdio>
#include<string>
struct _Main{
char temp[105];
string name,str;
_Main(){
    scanf("%s",temp);
    name=temp;
    scanf("%s",temp);
    str=temp;
    //printf("%d",str.find(name));
    if(str.find(name)!=-1){
    	printf("YES");
	}else{
		printf("NO");
	}
    
}
    
}cdvs3096;
