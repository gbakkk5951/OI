using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<iostream>
const double eps=1e-8;
struct Scnot{
	double num;
	int pow;
template<typename Type>
	Scnot operator = (Type b){
		num=b;pow=0;
		fix();
		return *this;
	}
	Scnot (){
		
	}	
	
template<typename Type>	
	Scnot (Type b){
		*this=b;
	}	
	
	Scnot (const Scnot &b){
		num=b.num;pow=b.pow;
	}
	
	Scnot operator = (Scnot b){
		num=b.num;pow=b.pow;
		return *this;
	}
	
	Scnot friend operator * (Scnot a,Scnot b){
		Scnot ret(a);
		ret.num*=b.num;
		ret.pow+=b.pow;
		ret.fix();
		return ret;
	}
	bool friend operator < (Scnot a,Scnot b){
		if(a.num*b.num<-eps){
			return a.num<0;
		}else if(fabs(a.num*b.num)<eps){
			return a.num <b.num;
		}
		else if(a.num<-eps){
			return a.pow==b.pow?a.num<b.num:a.pow>b.pow;
		}else{
			return a.pow==b.pow?a.num<b.num:a.pow<b.pow;
		}
	}
	bool friend operator == (Scnot a,Scnot b){
		return a.pow==b.pow && (a.num+eps>b.num && a.num -eps <b.num);
	}
	bool friend operator > (Scnot a,Scnot b){
		return !(a<b || a==b);
	}
	bool friend operator != (Scnot a,Scnot b){
		return !(a==b);
	}

	template<typename Type>	
	Scnot friend operator * (Scnot a,Type b){
		Scnot temp(b);
		return a*temp;
	}
	template<typename Type>	
	bool friend operator < (Scnot a,Type b){
		Scnot tmp(b);
		return a<tmp;
	}
	template<typename Type>		
	bool friend operator == (Scnot a,Type b){
		Scnot tmp(b);
		return a==tmp;
	}
	template<typename Type>		
	bool friend operator > (Scnot a,Type b){
		Scnot tmp(b);
		return a>tmp;
	}
	template<typename Type>		
	bool friend operator != (Scnot a,Type b){
		Scnot tmp(b);
		return a!=tmp;
	}
	
	template<typename Type>	
	Scnot friend operator * (Type b,Scnot a){
		Scnot temp(b);
		return a*temp;
	}
	template<typename Type>	
	bool friend operator < (Type b,Scnot a){
		Scnot tmp(b);
		return a<tmp;
	}
	template<typename Type>		
	bool friend operator == (Type b,Scnot a){
		Scnot tmp(b);
		return a==tmp;
	}
	template<typename Type>		
	bool friend operator > (Type b,Scnot a){
		Scnot tmp(b);
		return a>tmp;
	}
	template<typename Type>		
	bool friend operator != (Type b,Scnot a){
		Scnot tmp(b);
		return a!=tmp;
	}	
	
	void fix(){
		while(fabs(num)>eps && fabs(num)<1-eps){
			num*=10;pow--;
		}
		while(fabs(num)>eps && fabs(num)>10-eps){
			num/=10;pow++;
		}
		if(fabs(num)<eps){
			pow=0;num=0;
		}
	}
	
	void zero(){
		num=0;pow=0;
	}	
	void print(){
		if(pow==0){
			printf("%.3lf\n",num);
		}else{
			printf("%.3lfE%d",num,pow);
		}
	}
    friend inline ostream & operator << (ostream &output, Scnot a){
		char str[20];
		if(a.pow==0){
			sprintf(str,"%.3lf",a.num);
		}else{
			sprintf(str,"%.3lfE%d",a.num,a.pow);
		}
		output<<str;
		return output;
	}
    friend inline istream & operator >> (istream &input, Scnot &a){
		input>>a.num;a.pow=0;
		a.fix();
		return input;
	}
	
};


struct _Main{
	Scnot mx,mn,t1,t2,t3,one,ans;
	int n;double in;
	
	_Main(){
		std::ios::sync_with_stdio(false);
		int i,j,k;
		mx=1;mn=1;one=1;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>t3;
			t1=mx;t2=mn;
			mx=max(t1*t3,t2*t3);
			mn=min(t1*t3,t2*t3);
			ans=max(ans,mx);
			mx=max(mx,one);
			mn=min(mn,one);
		}if(n==1){
			ans=t3;
		}
		cout<<ans;
		
	}
	
	
	
	
	
}ezoj1015;
