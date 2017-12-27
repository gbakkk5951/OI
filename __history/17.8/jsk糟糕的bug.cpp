using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
const char FailTip[]="Bug!";
const char SuccTip[]="Good Luck!";
class TrieNode{
public:
	bool end;
	TrieNode *Nxt[26];
}Trie[466670];
int TrieIdx;
TrieNode *Root;
bool BugFlag;
struct _Main{
void ini(){
	Root=&Trie[0];
}	
int n;
char Buf[15];

void Insert(){
	bool NewNode=false;
	TrieNode *nd=Root;
	int i;
	for(i=0;Buf[i]!='\0';i++) if(isalpha(Buf[i])){
		if(nd->Nxt[Buf[i]-'a'] == 0){
			nd->Nxt[Buf[i]-'a']=&Trie[++TrieIdx];
			NewNode=true;
		}
		
		nd=nd->Nxt[Buf[i]-'a'];
		if(nd->end ){
			BugFlag=true;
			return;
		}
	}
	nd->end=true;
	if(NewNode==false){
		BugFlag=true;
	}
	
}

_Main(){
	int i;
	ini();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",Buf);
		Insert();
		if(BugFlag){
			printf("%s",FailTip);
			return;
		}
	}printf("%s",SuccTip);
}	
	
	
}bug;
