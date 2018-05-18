#include <bits/stdc++.h>
using namespace std;
#define SZ(x) (int((x).size()))
//char S[1000010];
int rnd(int l,int r){return l+rand()%(r-l+1);}
void makecase(int id){
	int n,r,s;
	char alp[26];
	if(id<=3)n=r=10,s=10;
	else if(id<=5)n=100,r=s=10;
	else if(id<=7)n=300,r=30,s=10;
	else if(id<=10)n=1000,r=10,s=26;
	else if(id<=12)n=5000,r=50,s=26;
	else if(id<=16)n=100000,r=10,s=10;
	else if(id<=18)n=1000000,r=10,s=10;
	else if(id<=21)n=100000,r=1,s=26;
	else if(id<=23)n=300000,r=3,s=26;
	else if(id<=25)n=1000000,r=10,s=26;
	for(int i=0;i<26;i++)alp[i]=i+'a';
	std::random_shuffle(alp,alp+26);
	//for(int i=0;i<r;i++)S[i]=alp[rand()%s];
	//for(int l=r;l<n;l*=10){
	//	for(int i=l;i<l*10;i++)S[i]=S[i-l];
	//	for(int t=l;t--;)S[rand()%(l*10)]=alp[rand()%s];
	//}
	//S[n]=0;
	//puts(S);
	string S;
	S = alp[rand()%s];
	while (SZ(S) < n)
	{
		if (rnd(0,1)) 
		{
			int st = rnd(max(0, (SZ(S) << 1) - n), SZ(S) - 1);
			S += S.substr(st, rnd(0, SZ(S) - st));
		}
		else S += alp[rand()%s];
	}
	if(id>=13&&id<=18){
		int L,i;
		do L=rnd(n/2,n),i=rand()%n;while(L%2||i+L>n);
		for(int j=0;j<L/2;j++)S[i+L/2+j]=S[i+j];
	}
	cout << S << endl;
}
int main(){
	srand(47243734);
	int case_num=25;
	for(int i=1;i<=case_num;i++){
		char fn[100];
		sprintf(fn,"%d.in",i);
		freopen(fn,"w",stdout);
		makecase(i);
	}
}
