#include<cstdio>
#include<cstring>
struct begin{
begin(){
	char s[100];
	char t[100];
	scanf("%s%s",s,t);
	int i=0,j=0;
	int ls=strlen(s);
	int lt=strlen(t);
	for(i=0;i<lt;i++){
		for(;j<ls;j++){
			if(t[i]==s[j]){
				break;
			}
			
		}
		if(!(j^ls)){
			printf("No\n");
			return;
		} 
	}
	printf("Yes\n");
	
}
	
	
	
	
}instance;int main(){}
