using namespace std;
int main(){}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
struct _Main{
int head[55];
int eidx;
int to[100010];
int val[100010];
int nxt[100010];
int in[55];
int out[55];
string word[100010];
int tocode(char a){
	return isupper(a)?a-'A':(a-'a'+26);
}

void inline add(int a,int b,int c){
	eidx++;
	in[b]++;out[a]++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	val[eidx]=c;
}
int n;
int beg,end;
_Main(){
	beg=end=-1;
	int i,j,k;
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>word[i];
	}
	sort(word,word+n);
	for(i=n-1;i>=0;i--){
		add(tocode(word[i][0]),tocode(word[i][word[i].size()-1]),i);
	}
	for(i=0;i<52;i++){
		if(in[i]!=out[i]){
			if(in[i]==out[i]+1){
				if(end==-1){
					end=i;
				}else{
					break;
				}
			}else if(in[i]==out[i]-1){
				if(beg==-1){
					beg=i;
				}else{
					break;
				}
			}else{
				break;
			}
		}
	}
	if(i<52){
		cout<<-1;
		return;		
	}else if(beg==-1 && end==-1){
		end=tocode(word[0][0]);beg=tocode(word[n-1][0]);
	}else{
		add(end,beg,n);
	}
		
	
	

	word[n]=*(word[end].end()-1);
	
	geteura();
	for(i=1;i<=n;i++)if(ans[i]!=n){
		cout<<word[ans[i]]<<endl;
	}
	fclose(stdout); 
}
int stk[100010];
int ans[100010];
void geteura(){
	int v=n;int i,j,k;bool noedge;
	int p;int top=0;
	stk[top++]=p=end;
	while(top){
		noedge=true;
		if(i=head[p]){
			stk[top++]=val[i];
			head[p]=nxt[head[p]];
			p=to[i];
		}else{
			if(top-1==0)break;
			ans[v--]=stk[top-1];
			p=tocode(word[stk[top-1]][0]);
			top--;
		}
	}
}	
	
	
	
	
	
}ezoj1122;
