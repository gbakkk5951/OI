#include<cstdio>
#include<cstring>
char str[205];
int main(){
	int i;int j=0;
	freopen("info0.in","r",stdin);
	while(1){
		fgets(str,200,stdin);j++;
		printf("len %d \n",strlen(str));
		
		for(i=0;i<strlen(str);i++){
			if(str[i]=='\r'){
				printf("сп");
			}
			
		}
		if(str[0]==EOF)return 0;
	}
	
}
