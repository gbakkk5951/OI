#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int id[110][110],mat[110],stp[110],num[110],n,m,ans;
bool nxt[110][110],vis[110];
vector<pair<int,int> >from,to;
bool dfs(int pos){
    for(int i=0;i<n;i++){
    	if(nxt[pos][i]&&vis[i]==false&&stp[i]==false){
	        vis[i]=true;
	        if(mat[i]==-1||dfs(mat[i])==true){
	            mat[i]=pos;
	            return true;
	        }
	    }
	}
    return false;
}
void solve(){
    int i,j,k,v,fz;
    memset(nxt,0,sizeof(nxt));
	memset(stp,0,sizeof(stp));
    for(i=0;i<m;i++) for(j=0;j<num[i];j++) id[i][j]=n++;
    for(unsigned l=0;l<from.size();l++){
        nxt[id[from[l].first][from[l].second]][id[to[l].first][to[l].second]]=true;
        nxt[id[to[l].first][to[l].second]][id[from[l].first][from[l].second]]=true;
    }
    if(m%2==0){
    	ans=n;
        memset(mat,-1,sizeof(mat));
        for(i=0;i<m;i++){
        	if(i%2==1){
        		for(j=0;j<num[i];j++){
	                memset(vis,false,sizeof(vis));
	                if(dfs(id[i][j])==true) ans--;
	            }
			}
		}
    }
	else{
        int zhong,cnt;
        for(i=0;i<m;i++) if(num[i]<=10){zhong=i;break;}
        for(i=0;i<(1<<num[zhong]);i++){
            bool flag=true,brk=false;
            for(j=0;j<num[zhong];j++){
				if(i&(1<<j)){
					for(k=j+1;k<num[zhong];k++){
						if(i&(1<<k)&&nxt[id[zhong][j]][id[zhong][k]]){
	                        flag=false;brk=true;
	                        break;
	            		}
					}
					if(brk==true) break;
				}
			}
            if(flag==true){
                v=fz=cnt=0;
				memset(stp,0,sizeof(stp));
				memset(mat, -1, sizeof(mat));
                for(j=0;j<num[zhong];j++){
                    stp[id[zhong][j]]=1;
                    if(i&(1<<j)){
                        for(k=0;k<n;k++) if(nxt[id[zhong][j]][k]) stp[k]=1;
                        cnt++;
                    }
                }
                for(j=0;j<n;j++) if(stp[j]==false){
                    memset(vis,false,sizeof(vis));
                    if(dfs(j)) fz++;
                    v++;
                }
                ans=max(ans,cnt+v-fz/2);
            }
        }
    }
    return;
}
int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
    int a,b,c;
    scanf("%d",&m);
    memset(num,0,sizeof(num));
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        from.push_back(make_pair(c-1,a-1));
        to.push_back(make_pair(c%m,b-1));
        num[c-1]=max(num[c-1],a);
        num[c%m]=max(num[c%m],b);
    }
	solve();
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
