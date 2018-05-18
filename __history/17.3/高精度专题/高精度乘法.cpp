#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
struct big{
	int l;
	char n[100010];
	char s;
	big(){
		l=0;
		memset(this,0,sizeof(big));
		s=1;
	}
	void clear(){
		l=0;
		memset(this,0,sizeof(big));
		s=1;		
	}


big friend operator * (big a,big b){
	int i=0,j;
	int k;
	big ans,temp;

	for(i=0;i<b.l;i++){
		temp.clear();
		for(j=0;j<a.l;j++){
			temp.n[i+j]+=a.n[j]*b.n[i];
			temp.n[i+j+1]+=	temp.n[i+j]/10;
			temp.n[i+j]%=10;		
			
		}
		for(k=a.l+b.l+1;k>1;k--){
			if(temp.n[k-1])break;
		}
		temp.l=k;

		ans+=temp;
	}
	if(a.s==b.s){
		ans.s=1;
	}else{
		ans.s=-1;
	}	
	return  ans;
	
}
	
	char buffer[100050];
	void scan(){
		int i;
		
		char temp;
		l=0;
		while((temp=getchar())!='-'&&!isdigit(temp));
		if(temp=='-'){
			s=-1;
		}else{
			buffer [l++]=temp;
		}
		while(isdigit(temp=getchar())){
			buffer[l++]=temp;
		}
		for(i=0;i<l;i++)
		{n[i]=buffer[l-i-1]-'0';
		}
	}
	void print(){
		int i;
		if(s==-1){
			putchar('-');
		}
		for(i=l-1;i>=0;i--){
			putchar('0'+n[i]);
		}
	}
	big friend operator + (big a,big b){
		big ans;
		int i;
		int ml=max(a.l ,b.l );
		if(a.s==b.s)
		{
			ans.s=a.s;
			for(i=0;i<ml;i++){
			ans.n[i]+=a.n[i]+b.n[i];
				if(ans.n[i]>=10){
					ans.n[i+1]+=(ans.n[i]/10);
					ans.n[i]%=10;
				}
			}
			if(ans.n[i]!=0){
				ml++;
			}
			ans.l=ml;
		}else{
			if(a.s==-1){
				a.s=1;
				ans=b-a;
			}else{
				b.s=1;
				ans=a-b;
			}
			
		}

		return ans;
	}
	big friend operator - (big a,big b){
		big ans;
		int i;
		int ml=max(a.l,b.l);
		if(a.s!=b.s){
			if(a.s==-1){
				b.s=-1;
				ans=a+b;
			}else{
				b.s=1;
				ans=a+b;
			}		
		}else{
			
			if(a.s==-1&&b.s==-1){
				a.s=1;b.s=1;
				ans=a-b;
				ans.s=-(ans.s);
			}else{
				int temp;
				if(a<b){
					
					ans=b-a;
					ans.s=-ans.s;
				}else{
					
					for(i=0;i<ml;i++){
						ans.n[i]+=a.n[i]-b.n[i];
						if(ans.n[i]<0){
							ans.n[i]+=10;
							ans.n[i+1]-=1;
						}
						
					}
					for(i=ml;i>=0;i++){
						if(a.n[i-1]!=0){
							break;
						}
					}
					ans.l=i;
				}
				
				
				
			}
			
			
			
		}
	for(i=ml;i>=1;i--){
		if(ans.n[i-1]!=0){
			break;
		}
	}

	ans.l=i;
		return ans;
		
	}
bool friend operator < (big a,big b){
	if(a.s==-1&&b.s==1){
		return true;
	}else{
		if(a.s==1&&b.s==-1)
		return false;
	}
	int i;
	if(a.s==-1){
		if(a.l>b.l)
		return true;
		if(a.l<b.l)
		return false;
		for(i=a.l-1;i>=0;i++){
			if(a.n[i]>b.n[i]){
				return true;
			}if(a.n[i]<b.n[i]){
				return false;
			}
			return false;
		}
		
	}else{
		if(a.l<b.l)
		return true;
		if(a.l>b.l)
		return false;
		for(i=a.l-1;i>=0;i--){
			if(a.n[i]<b.n[i]){
				return true;
			}if(a.n[i]>b.n[i]){

				return false;
			}

		}	
		
					return false;	
	}
	
	
}

bool friend operator == (big a,big b){
	if(a.s!=b.s){
		return false;
	}
	if(a.l!=b.l)
	return false;
	
	int i=0;
	for(i=0;i<a.l;i++){
		if(a.n[i]!=b.n[i]){
			return false;
		}
	}
	return true;
}

bool friend operator != (big a,big b){
	return !(a==b);
}

bool friend operator <= (big a,big b){
if(a<b||a==b)
return true;
return false;
} 

bool friend operator >= (big a,big b){
if(a>b||a==b)
return true;
return false;
} 

bool friend operator > (big a,big b){
	if(a!=b&&!(a<b)){
		return true;
	}return false;
}

void  operator = (int b){
	this->clear();
	if(b<0){
		this->s=-1;
	}else{
		this->s=1;
	}
	int i=1;
	int j=0;
	this->l=1;
	for(j=0;j<31;j++){
		if(b/i>0){
			this->l=j+1;
		}
			this->n[j]=(b/i)%10;
		i*=10;
		
	}
}

big operator = (big b){
	this->l=b.l;
	this->s=b.s;
	memcpy(this->n,b.n ,sizeof(b.n ));
}

big operator *= (big b){

	*this=(*this)*b;
	return *this;	
}

big operator *= (int b){
	big temp;
	temp=b;
	(*this)*=temp;	
	return *this;
}

big friend operator -= (big &a,big b){
	a=a-b;	
	return a;
}

big friend operator * (big a,int b){
	big temp;
	temp=b;
	a*=temp;	
	return a;
}

big friend operator += (big &a,big b ){
	a=a+b;
	return a;
}

big friend operator += (big &a,int b ){
	big temp;
	temp=b;
	a+=temp;	
	return a;
}

big friend operator / (big a,big b){

	big temp;
	big re;
	char rs;
	if(a.s==b.s){
		rs=1;
	}else{
		rs=-1;
	}	
	a.s=1;b.s=1;
	temp=0;
	big t2;
	int i;
	int l,r;
	int j;
	for(i=a.l-1;i>=0;i--){
		temp*=10;
		j=0;
		temp+=a.n[i];
		l=0,r=9;
		if(temp>=b){
			for(j=1;j<10;j++){
				if(temp<b*j){
					break;
				}
			}j--;

		}

			temp-=b*j;
			re*=10;
	
			re+=j;
	}
	re.s=rs;
return re;	
}
}a,b,c;


int main(){
a.scan();
b.scan();
c=a+b;
c.print();

}
