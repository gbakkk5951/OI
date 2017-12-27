using namespace std;
int main(){}
#include<cstdio>
#include<queue>
#include<bitset>

//bitset<10000000>v[2];
queue<int>q[2];
struct _Main{
void decom(char map[4][5],int num){
	int a1=(num >> 14) &15;
	int a2=(num >> 18) &15;
	int i,j,k;
	for(i=0,k=0;i<4;i++){
		for(j=0;j<4;j++){
			if((i<<2)+j==a1 || (i<<2)+j == a2){
				map[i][j]='o';
			}else{
				if((num>>k) & 1){
					map[i][j]='b';
				}else{
					map[i][j]='w';
				}
				k++;
			}
		}
	}
}	
int com(char map[4][5]){
	int i,j,k;int num=0;
	for(i=0,k=0;i<4;i++){
		for(j=0;j<4;j++){
			switch(map[i][j]){
				case 'w':{
					k++;
					break;
				}
				case 'b':{
					num|=(1<<k);
					k++;
					break;
				}
				case 'o':{
					if((i<<2)+j==k){
						num|=((i<<2)+j)<<14;
					}else{
						num|=((i<<2)+j)<<18;
					}
					break;
				}
			}
		}
	}
	return num;
}
_Main(){
	int i,j,k;int goal;int I;bool flag;int t;int J;char color[2]={'w','b'};
	char map[4][5];
	int num;int cnt=0;
	for(i=0;i<4;i++){
		scanf("%s",map[i]);
		for(j=0;j<4;j++)map[i][j]=tolower(map[i][j]);
	}num=com(map);
	q[1].push(num);//v[1][num]=1;
	q[0].push(num);//v[0][num]=1;
	while(1){
		
		swap(color[0],color[1]);
		for(J=0;J<2;J++){
			goal=q[J].size();
			for(I=0;I<goal;I++){
				num=q[J].front();q[J].pop();			
				decom(map,num);
				flag=false;
				for(i=0;i<4 && !flag;i++){
					flag=true;
					for(j=1;j<4;j++){
						if(map[i][j]!=map[i][j-1]){
							flag=false;break;
						}
					}
				}
				for(i=0;i<4 && !flag;i++){
					flag=true;
					for(j=1;j<4;j++){
						if(map[j][i]!=map[j-1][i]){
							flag=false;break;
						}
					}
				}
				if(!flag)for(i=1,flag=true;i<4;i++){
					if(map[i][i]!=map[i-1][i-1]){
						flag=false;break;
					}
				}
				if(!flag)for(i=1,flag=true;i<4;i++){
					if(map[i][3-i]!=map[i-1][3-i+1]){
						flag=false;break;
					}
				}
				if(flag)goto EndFlag;
				for(k=0;k<2;k++){
					t=(num>>(14+(k<<2)))&15;
					i=t>>2;j=t&3;
					if(i>0 && map[i-1][j]==color[J]){
						swap(map[i][j],map[i-1][j]);
						t=com(map);
					//	if(!v[J][t]){
							q[J].push(t); 
					//		v[J]=1;
					//	}
						swap(map[i][j],map[i-1][j]);
					}
					if(j>0&& map[i][j-1]==color[J]){
						swap(map[i][j],map[i][j-1]);
						t=com(map);
//						if(!v[J][t]){
							q[J].push(t); 
//							v[J][t]=1;
//						}
						swap(map[i][j],map[i][j-1]);
					}
					if(i<3&& map[i+1][j]==color[J]){
						swap(map[i][j],map[i+1][j]);
						t=com(map);
//						if(!v[J][t]){
							q[J].push(t); 
//							v[J][t]=1;
//						}
						swap(map[i][j],map[i+1][j]);
					}
					if(j<3&& map[i][j+1]==color[J]){
						swap(map[i][j],map[i][j+1]);
						t=com(map);
//						if(!v[J][t]){
							q[J].push(t); 
//							v[J][t]=1;
//						}
						swap(map[i][j],map[i][j+1]);
					}
				}
			}
		
		}
		cnt++;
	}

	
	EndFlag:	

	printf("%d\n",cnt);
	
}	
	
	
}cdvs1004;
