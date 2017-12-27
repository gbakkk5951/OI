using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
struct st_storge{
	int beg;
	int cst;
};

struct _Main{
long long ans;
st_storge que[40010];
st_storge emp;
int tail,top;
st_storge inline get_tail(){
	if(tail>=top)	return que[tail];
	else return que[40002];
}
st_storge inline get_top(){
	return que[top];
}

void inline pop_front(){
	top++;
}
void inline pop_back(){
	tail--;
}
void inline push_back(st_storge &in){
	que[++tail]=in;
	
}
void inline initialize(){
	tail=-1;
	que[40002].beg =40000;
	emp.beg = 40000;
	emp.cst = 2147483647;
}
void read(int &ans){
	char t;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
}
int n,s,t;
_Main()	{
	initialize();
	int i,j,k;
	read(n);
	read(s);
	read(t);
	st_storge temp;
	for(i=0;i<n;i++){
		temp.beg =i;
		read(temp.cst );
		while(temp.cst<get_tail().cst+s*(i-get_tail().beg)){
			pop_back();
		}
		push_back(temp);
		read(j);
		ans+=(long long)j*(get_top().cst+(i-get_top().beg)*s);
		if(get_top().beg+t==i){
			pop_front();
		}
	}
	printf("%lld",ans);
}
	
	
}cdvs6130;
