#include <iostream>

#include <vector>

using namespace std;

class station{

private:

int  inStation;

int  outStation;

vector<int> in_tag_sta;

vector<int> out_tag_sta;

int index;

public:

void inStationAdd(int a){

inStation++;

in_tag_sta.push_back(a);

}

void outStationAdd(int a){

outStation++;

out_tag_sta.push_back(a);

}

void inStationD(int a){

if(a==index&&inStation!=0)

inStation--;

}

void outStationD(int a){

if(a==index&&outStation!=0)

outStation--;

}

vector<int> getIn(){return in_tag_sta;}

vector<int> getOut(){return out_tag_sta;}

int getIn(){return inStation;}

int getOut(){return outStation;}

int getDis(){return abs(inStation-outStation);}

station(){}//也是与析构函数相同的情况

station(int a)

{

inStation=0;

outStation=0;

index=a;

//cout<<"start"<<endl;

}

~station(){}//这是因为你在类定义里面列出了析构函数的原型，但是没有函数体，所以链接时发生错误，所以设计一个最简单的函数体，就是空函数体（什么也没有）

//{cout<<"end"<<endl;}

};

int main()

{

 

//int result[100];

int T;

cin>>T;

int tag=T;

while(tag--){

vector<int> inStation,outStation;

int N,M,K;

cin>>N>>M>>K;

vector<station> S;

cout<<"vector size:"<<S.size()<<endl;

for(int i=0;i!=N;++i)

{

station m(i+1);

S.push_back(m);

}

cout<<"vector size:"<<S.size()<<endl;

for(int i=1;i<=M;i++){

int in,out;

cin>>in>>out;

inStation.push_back(in);

outStation.push_back(out);

S[in-1].inStationAdd(i);

S[out-1].outStationAdd(i);

}

vector<int> index_s;

index_s.push_back(0);

for(int i=1;i!=N;)

{

vector<int>::iterator Iindex=index_s.begin();

///vector<int>::size_type j=Iindex.;

int j;

for(j=0;j!=index_s.size();)

{

if((S[i].getDis())>(S[index_s[j]].getDis()))break;

j++;

Iindex++;

}

if(Iindex==index_s.end())

{

index_s.push_back(i);

}

else 

{

index_s.insert(Iindex,i);

}

i++;

}

for(int i=0;i<N;i++){cout<<index_s[i];}

while((M-K)--){

 

 

}//while

}

return 0;

}
