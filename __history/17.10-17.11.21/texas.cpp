using namespace std;
int main(){}
#include<iostream>
#include<cctype>
#include<functional>
#include<algorithm>
	bool cmp1(char a,char b){
		return a<b;
	}
	bool cmp2(char a,char b){
		if(a==1)return false;
		if(a!=1 && b==1)return true;
		return a<b;
	}

struct CardCom{
	int type;
	char card[5];
	
	bool operator < (const CardCom &b){
		const CardCom &a=*this;
		if(a.type==b.type){
			int i;
			for(i=4;i>=0;i--){
				if(a.card[i]!=b.card[i]){
					if(a.type==5){
						return cmp1(a.card[i],b.card[i]);
					}else{
						return cmp2(a.card[i],b.card[i]);
					}
				}
			}
			return false;
		}else{
			return a.type<b.type;
		}
	}
	void finish(){
		sort(card,card+5,cmp1);
		int i,j;
		for(i=1;i<5;i++){
			if(card[i]!=card[i-1]+1){
				break;
			}
		}
		if(i==5){
			type=7-3;
			return;
		}
		sort(card,card+5,cmp2);
		for(i=0;i<2;i++){
			for(j=i+1;j<i+4;j++){
				if(card[i]!=card[j]){
					break;
				}
			}
			if(j==i+4){
				type=7-1;
				return;
			}
		}
		for(i=0;i<2;i++){
			for(j=i+1;j<i+3;j++){
				if(card[i]!=card[j]){
					break;
				}
			}
			int a=-1,b;
			if(j==i+3){
				for(j=0;j<5;j++){
					if(j<i || j>=i+3){
						if(a==-1)a=card[j];
						else if(card[j]==a){
							type=7-2;
							return;
						}else{
							type=7-3;
							return;
						}
					}
				}
			}
		}
		for(i=1;i<5;i++){
			if(card[i]==card[i-1]){
				for(j=i+2;j<5;j++){
					if(card[j]==card[j-1]){
						type=7-5;
						return;
					}
				}
				type=7-6;
			}
		}
	}

}cards[50];
struct _Main{
	char buf[5];
	int card[7];
	_Main(){
		freopen("texas.in","r",stdin);
		freopen("texas.out","w",stdout);
		int i,j,k;
		for(i=0;i<7;i++){
			cin>>buf;
			if(isalpha(buf[0])){
				switch (buf[0]){
					case 'A':{
						card[i]=1;
						break;
					}
					case 'J':{
						card[i]=11;
						break;
					}
					case 'Q':{
						card[i]=12;
						break;
					}
					case 'K':{
						card[i]=13;
						break;
					}
				}
				
			}else{
				if(buf[0]=='1'){
					if(buf[1]=='0'){
						card[i]=10;
					}else{
						card[i]=1;
					}
				}else{
					card[i]=buf[0]-'0';
				}
			}
		}
		int idx1=0,idx2;
		for(i=0;i<7;i++){
			for(j=i+1;j<7;j++){
				idx2=0;
				for(k=0;k<7;k++){
					if(k!=i && k!=j){
						cards[idx1].card[idx2++]=card[k];
					}
				}
				cards[idx1].finish();

				idx1++;
			}
		}
		
		sort(cards,cards+idx1);
		
		for(i=4;i>=0;i--){
			output(cards[idx1-1].card[i],i);
		}
		fclose(stdout);
	}
	
void output(char a,bool end){
	switch (a){
		case 1:{
			printf("A");
			break;
		}
		case 11:{
			printf("J");
			break;
		}
		case 12:{
			printf("Q");
			break;
		}
		case 13:{
			printf("K");
			break;
		}
		default:{
			printf("%d",(int)a);
			break;
		}								
	}
	if(end)putchar(' ');
}	
	
	
	
	
	
}texas;


