#include<cstdio>
#include<stack>
#include<cctype>
using namespace std;
stack<char>st;
int p[256];

struct begin{
begin(){
	p['*']=3;
	p['/']=3;
	p['+']=2;
	p['-']=2;
	p['(']=1;
	input();

}
void input(){
	char temp;
	int nu=0;
	while(~(temp=getchar())){
		if(isdigit(temp)){
			nu*=10;
			nu+=temp-'0';
		}else{
			if(nu!=0)
			printf("%d",nu);
			nu=0;
			if(temp=='('){
				st.push(temp); 
			}
			if(temp==')'){
				while(st.top() !='('){
					putchar(st.top());
					st.pop() ;
				}
				st.pop();
			}else{if(temp=='-'||temp=='+'||temp=='*'||temp=='/'){
				while(st.size()&&p[st.top()]>=p[temp]){
						putchar(st.top());
						st.pop();
					}
				st.push(temp);
			}
				
				
				
			}
		}
		
		
	}
	if(nu!=0){
		printf("%d",nu);
	}
	while(st.size()){
		putchar(st.top());
		st.pop();
	}
}
	
	
	
	
	
}instance;int main(){}

