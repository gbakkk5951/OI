using namespace std;
int main(){}
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
struct _Main{
int lrand(){
	return (rand()<<15) | rand();	
}
string file,cmd;
string to_string(int a){
	stringstream os;string ans;
	os<<a;
	os>>ans;
	return ans;
}

int arr[2][50005];
void make(){
	int i,j,k;int I;int l,m;int n;int lim;


	for(I=0;I<15;I++){
		file="array"+to_string(I)+".in";
		freopen(file.c_str(),"w",stdout);
		if(I<5)n=500-rand()%37;
		else if(I<10)n=5000-rand()%507;
		else n=50000-rand()%3;
		if(I==8){
			for(j=0;j<2;j++)
			for(i=0;i<n;i++){
				arr[j][i]=i;
			}
		}else if(I==9){
			for(j=0;j<2;j++)
			for(i=0;i<n;i++){
				arr[j][i]=n-i-1;
			}			
		}else if(I==7){
			for(i=0;i<n;i++){
				arr[1][i]=n-i-1;
			}				
			for(i=0;i<n;i++){
				arr[0][i]=i;
			}			
		}else{
			for(j=0;j<2;j++){
				for(i=0;i<n;i++){
					arr[j][i]=i;
				}
				for(i=0;i<n;i++){
					swap(arr[j][i],arr[j][lrand()%(i+1)]);
				}
			}
		}
		cout<<n<<endl;
		for(j=0;j<2;j++){
			for(i=0;i<n;i++){
				cout<<arr[j][i]<<" ";
			}
			cout<<endl;
		}
		fclose(stdout);
	}
	
	
	
}
	
void run(){
	int I;
	for(I=0;I<15;I++){
		cmd="std.exe > array"+to_string(I)+".out < array"+to_string(I)+".in";
		system(cmd.c_str());
	}
}	
	
_Main(){
	srand(time(0));
	make();
	run();
}	
	
	
}Maker;
