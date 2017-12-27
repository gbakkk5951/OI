#include<sstream>
#include<fstream>
#include<iostream>

using namespace std;
char buf[2000];
int main(){
	ifstream conin("test.txt");
	stringstream os;
	os<<conin.rdbuf();
	cout<<os.rdbuf();
	
	
	
	
}
