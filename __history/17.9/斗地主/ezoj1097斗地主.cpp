using namespace std;
int main(){}
#include<cstdio>
#include<queue>
#include<algorithm> 
#include<cstring>
struct Status{
    Status(){
        memset(this,0,sizeof(Status));
    }
    void clear(){
        memset(this,0,sizeof(Status));
    }
    char cnt[15];
    char & operator [] (int a){
        return cnt[a];
    }
     
};
struct _Main{
 
 
queue<Status>q;
_Main(){
    int cnt[14];
    int T,n;int a;
    int i,j,k;int I;int l,m;
    int way;int ans;int add;
    int gap;
    int g;Status s,tmp;int tmpans;
    scanf("%d%d",&T,&n);
    while(T--){
        tmp.clear();
        for(i=0;i<n;i++){
            scanf("%d%*d",&a);
            if(a==2){
                a=1;
            }else if(a==1){
                a=13;
            }else if(a>2){
                a--;
            }
            tmp[14]++;
            tmp[a]++;
        }
 
        ans=n;
        q.push(tmp);
        way=0;
        while(!q.empty()){
            g=q.size();
            for(I=0;I<g;I++){
                s=q.front();q.pop();
                int flag=true;
                 
                for(i=2;i<=13;i++)if(s[i]){
                    for(j=i;j<=13;j++)if(s.cnt[j]==0){
                        break;
                    }
                    if(j-i>=5){
                        flag=false;
                        gap=j-i;
                        for(add=5;add<=gap;add++){
                            tmp=s;
                            for(j=i;j<i+add;j++){
                                tmp[j]--;
                                tmp[14]--;
                            }
                            if(tmp[14]==0){
                                ans=way+1;
                                goto EndFor;
                            }
                            q.push(tmp);
                        }
                    }
                    for(j=i;j<=13;j++)if(s.cnt[j]<2){
                        break;
                    }
                    if(j-i>=3){
                        flag=false;
                        gap=j-i;
                        for(add=3;add<=gap;add++){
                            tmp=s;
                            for(j=i;j<i+add;j++){
                                tmp[j]-=2;
                                tmp[14]-=2;
                            }
                            if(tmp[14]==0){
                                ans=way+1;
                                goto EndFor;
                            }                           
                            q.push(tmp);
                        } 
                    }       
                    for(j=i;j<=13;j++)if(s.cnt[j]<3){
                        break;
                    }
                    if(j-i>=2){
                        flag=false;
                        gap=j-i;
                        for(add=2;add<=gap;add++){
                            tmp=s;
                            for(j=i;j<i+add;j++){
                                tmp[j]-=3;
                                tmp[14]-=3;
                            }
                            if(tmp[14]==0){
                                ans=way+1;
                                goto EndFor;
                            }                           
                            q.push(tmp);
                        }
                    }
                }
                
                for(i=1;i<=13;i++)if(s[i]==4){
                    flag=false;
                    bool got=false;
                    if(s[0]==2){
                        got=true;
                        tmp=s;
                        tmp[0]=0;tmp[i]=0;
                        q.push(tmp);
                    }
                    for(j=1;j<=13;j++)if(j!=i && s[j]>=1){
                        for(k=j+1;k<=13;k++)if(k!=i && s[k]>=1){
                            got=true;
                            tmp=s;
                            tmp[i]=0;
                            tmp[j]--;tmp[k]--;
                            tmp[14]-=6;
                            if(tmp[14]==0){
                                ans=way+1;
                                goto EndFor;
                            }   
                            q.push(tmp);                            
 
                        }
                    }
                    for(j=1;j<=13;j++)if(j!=i && s[j]>=2){
                        for(k=j+1;k<=13;k++)if(k!=i && s[k]>=2){
                            got=true;
                            flag=false;
                            tmp=s;
                            tmp[i]=0;
                            tmp[j]-=2;tmp[k]-=2;
                            tmp[14]-=8;
                            if(tmp[14]==0){
                                ans=way+1;
                                goto EndFor;
                            }   
                            q.push(tmp);                            
                        }
                    }
                    if(!got){
                        flag=false;
                        tmp=s;
                        tmp[i]=0;
                        tmp[14]-=4;
                        if(tmp[14]==0){
                            ans=way+1;
                            goto EndFor;
                        }                   
                        q.push(tmp);
                    }
                }
                for(i=1;i<=13;i++)if(s[i]==3){
                    flag=false;
                    bool got=false;
                    if(s[0]>=1){
                        got=true;
                        tmp=s;
                        tmp[0]--;tmp[i]-=3;
                        tmp[14]-=4;
                        if(tmp[14]==0){
                            ans=way+1;
                            goto EndFor;
                        }               
                        q.push(tmp);
                    }
                    for(j=1;j<=13;j++)if(j!=i && s[j]>=1){
                        got=true;
                        flag=false;
                        tmp=s;
                        tmp[i]=0;
                        tmp[j]--;
                        tmp[14]-=4;
                        if(tmp[14]==0){
                            ans=way+1;
                            goto EndFor;
                        }
                        q.push(tmp);                            
                    }
                    for(j=1;j<=13;j++)if(j!=i && s[j]>=2){
                        got=true;
                        flag=false;
                        tmp=s;
                        tmp[i]=0;
                        tmp[j]-=2;
                        tmp[14]-=5;
                        if(tmp[14]==0){
                            ans=way+1;
                            goto EndFor;
                        }
                        q.push(tmp);                            
                    }
                    if(!got){
                        flag=false;
                        tmp=s;
                        tmp[i]-=3;
                        tmp[14]-=3;
                        if(tmp[14]==0){
                            ans=way+1;
                            goto EndFor;
                        }
                        q.push(tmp);                    
                    }
                }               
                 
                 
                if(flag){
                    tmpans=0;
                    for(j=0;j<=13;j++)if(s[j]){
                        tmpans++;
                    }tmpans+=way;
                    ans=min(tmpans,ans);
                    if(tmpans==way+1)goto EndFor;
                }
            }
            way++;
            if(ans<=way){
                break;
            }
        }
        EndFor:
        printf("%d\n",ans);
        while(!q.empty()){
            q.pop();
        }
         
    }
         
         
     
     
     
}   
     
     
     
     
     
     
}landlord;
