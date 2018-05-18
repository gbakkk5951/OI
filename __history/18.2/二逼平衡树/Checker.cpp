#include<cstdlib>
#include<ctime>
#include<cstring>
#include<fstream>
using namespace std;
const int mod=(int)1e3+1;
int arr[10];
int inline randval(){
	return (rand()&1 ? 1:1)*(rand()<<15 | rand())%mod;
}
int main(){
	srand(time(0));
	int n,m;
	n=50;m=50000;
	int i,j,k;
	int I;
	int a,b,c,d;
	string cmd;
	
	for(I=1;1;I++){
		ofstream input("input.txt");
		printf("case %d:\n",I);
		
		input<<n<<" "<<m<<endl;
		for(i=1;i<=n;i++)input<<randval()<<" ";
		input<<endl;
		for(i=1;i<=m;i++){
			a=rand()%5+1;
			input<<a<<" ";
			switch(a){
				case 1:{
					a=rand()%n+1;
					b=rand()%(n-a+1)+a;
					if(rand()%10 == 1){
						a=1;b=n;
					}
					c=randval();
					input<<a<<" "<<b<<" "<<c<<endl;
					break;
				}
				case 2:{
					a=rand()%n+1;
					b=rand()%(n-a+1)+a;
					if(rand()%10 == 1){
						a=1;b=n;
					}
					c=rand()%(b-a+1)+1;
					
					input<<a<<" "<<b<<" "<<c<<endl;
					break;
				} 
				case 3:{
					a=rand()%n+1;
					b=randval();
					input<<a<<" "<<b<<endl;
					break;
				}
				case 4:{
					a=rand()%n+1;
					b=rand()%(n-a+1)+a;
					if(rand()%10 == 1){
						a=1;b=n;
					}
					c=randval();
					input<<a<<" "<<b<<" "<<c<<endl;			
					break;
				}
				case 5:{
					a=rand()%n+1;
					b=rand()%(n-a+1)+a;
					if(rand()%10 == 1){
						a=1;b=n;
					}
					c=randval();
					input<<a<<" "<<b<<" "<<c<<endl;					
					break;
				}				
				
			}
			
		}
		input.close();
		cmd="ezoj1000 > std.txt < input.txt";
		system(cmd.c_str());
		cmd="yousiki > brute.txt < input.txt";
		system(cmd.c_str());		
		cmd="fc std.txt brute.txt";
		if(system(cmd.c_str())){
			system("pause");
		}		
	}
	
	
}
