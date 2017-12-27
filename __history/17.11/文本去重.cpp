using namespace std;
int main(){}
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

struct _Main{
vector<string>arr;
_Main(){
	string tmp;
	int n;
	while((cin>>tmp)){
		arr.push_back(tmp);
	}
	sort(arr.begin(),arr.end());
	n=unique(arr.begin(),arr.end())-arr.begin();
	arr.resize(n);
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	
	
	
}	
	
	
	
}instance;

