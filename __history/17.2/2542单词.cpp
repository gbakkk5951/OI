#include<cstring>
#include<cstdio>
using namespace std;
struct acnode{
	int nxt[26];
	int3  fail;
	int p;
	int count;

}ac[1000010];

char int[1000010]

int tot=1; 
int insert(char in[1000010]){
	int l=strlen(in);
	int i=0;
	int index=0;
	for(i=0;i<l;i++){
		if(!ac[root].nxt[in[i]-'a'])
		{
			ac[root].nxt[in[i]-'a']=tot++;
		}
		root=ac[root].nxt[in[i]-'a'];
	}
}



int main(){
	
	
	
	
}
