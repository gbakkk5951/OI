#include<cstdio>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
vector<int>link[2000];
short in[2000];
bool use[2000];
char te[2005];
struct _Main{
short n;
void readin(){
	fgets(te,2003,stdin);
	char t;
	short i=0,j;
	n=0;
	while(!isdigit(t=te[i++]));
	do{
		n*=10;
		n+=t-'0';
	}while(isdigit(t=te[i++]));
	for(i=0;i<n;i++){
		fgets(te,2003,stdin);
		for(j=0;j<n;j++){
			if(te[j]-'0'){
				link[i].push_back(j);
				in[j]++; 
			}
		}
	}
	
	
	
	
}
void topo(int index=-1){
	short i,s;
	if(index^(-1)){
		in[index]--;
		if(!in[index]){
			use[index]=true;
			s=link[index].size();
			for(i=0;i<s;i++){
				topo(link[index][i]);
			}		
		}
		return;
	}
	for(i=0;i<n;i++){
		if(!in[i]&&!use[i]){
			in[i]++;
			topo(i);
		}
	}
	for(i=0;i<n;i++){
		if(in[i]){
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
	
}
_Main(){
	fgets(te,100,stdin);
	char t=te[0]-'0';
	while(t--){
		readin();
		topo();
		clear();
	}
}	
void clear(){
	int i;
	for(i=0;i<2000;i++){
		link[i].clear() ;
		in[i]=0;
		use[i]=0;
	}
}
}instance;int main(){}
