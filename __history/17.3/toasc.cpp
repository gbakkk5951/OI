#include<cstdio>
#include<cstring>
int main(){
char in[500];
int i;
int l;
while(1){
	gets(in);
	l=strlen(in);
	for(i=0;i<=l;i++){
		printf("%u,",(unsigned char)in[i]);
	}
	puts("");
}}

