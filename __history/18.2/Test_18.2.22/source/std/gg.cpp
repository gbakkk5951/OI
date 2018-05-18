#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	system("dir /B /A:D > name.log");
	FILE *fp = fopen("name.log","r");
	char tmp[100];
	while(~fscanf(fp,"%s",tmp)){
		string now = tmp;
		if (now.find("JF")!=string::npos){
			system(("dir "+now+" /B /A:D > namet.log").c_str());
			FILE *f=fopen("namet.log","r");
			while(~fscanf(f,"%s",tmp)){
				string dn = tmp;
				//cout<<("move "+now+"/"+dn+" .")<<endl;
				system(("move "+now+"/"+dn+" .").c_str());
			}
			fclose(f);
			system(("rd /s /q "+now).c_str());
		}
	}
	fclose(fp);
	system("del name.log");
	system("del namet.log");
	return 0;
}