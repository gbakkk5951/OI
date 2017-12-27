using namespace std;
int main(){}
#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
#include<set>
queue<string>q;
set<string> tree;
struct _Main{
string org[6],to[6];
int tn;
_Main(){
	int i,j,k;int I,J,K;int goal;string t;
	tn=6;
	string a,b;
	cin>>a>>b;
	for(i=0;i<6;i++){
		cin>>org[i]>>to[i];
		if(org[i].empty()){
			tn=i;
			break;
		}
	}
	int cnt=0;
	q.push(a);
	while(cnt<=10){
		goal=q.size();
		for(I=0;I<goal;I++){
			a=q.front();q.pop();
			if(a.compare(b)==0){
				goto EndFlag;
			}
			for(i=0;i<tn;i++){
				j=-1;
				while(j+org[i].length()<=a.length()){
					j=a.find(org[i],j+1 );
					if(j!=string::npos ){
						t=a;
						t.replace(j,org[i].length(),to[i]);	
						if(tree.find(t)==tree.end()){
							tree.insert(t);
							q.push(t);
						}
					}else{
						break;
					}
				}
			}
		}
		cnt++;
	}
	EndFlag:
	if(cnt>10){
		printf("NO ANSWER!");
	}else{
		printf("%d",cnt);
	}
		
		
	
}	
	
	
	
	
	
	
}cdvs1099;
