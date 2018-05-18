    #include <iostream>  
    #include<cstdio>  
    #include<algorithm>  
    #include<cstring>  
    #include<cmath>  
    using namespace std;  
    const int MAXN=500000+1000;  
    char S[MAXN],T[MAXN];  
    int n;//串S与串T的长都为n  
    int next[MAXN],extend1[MAXN],extend2[MAXN];  
    int val[30],sum[MAXN];  
    void EKMP(char *S,char *T,int *next,int *extend)  
    {  
        int j=0;  
        int k=1;  
        while(j+1<n && T[0+j]==T[1+j])  
            j++;  
        next[1]=j;  
        for(int i=2;i<n;i++)  
        {  
            int len=k+next[k]-1,L=next[i-k];  
            if(L<len-i+1)  
                next[i]=L;  
            else  
            {  
                j=max(0,len-i+1);  
                while(i+j<n && T[i+j] == T[0+j])  
                    j++;  
                next[i]=j;  
                k=i;  
            }  
        }  
        j=0;  
        while(j<n && S[0+j]==T[0+j])  
            j++;  
        extend[0]=j;  
        k=1;  
        for(int i=1;i<n;i++)  
        {  
            int len=k+extend[k]-1,L=next[i-k];  
            if(L<len-i+1)  
                extend[i]=L;  
            else  
            {  
                j=max(0,len-i+1);  
                while(i+j<n && j<n && S[i+j]==T[j])  
                    j++;  
                extend[i]=j;  
                k=i;  
            }  
        }  
    }  
    int main()  
    {  
    	freopen("data.in","r",stdin);
    	freopen("std.out","w",stdout);
        int kase;  
        scanf("%d",&kase);  
        while(kase--)  
        {  
            for(int i=0;i<26;i++)  
                scanf("%d",&val[i]);  
            scanf("%s",S);  
            n=strlen(S);  
            for(int i=0;i<n;i++)  
            {  
                T[i]=S[n-1-i];  
                if(i==0)sum[i]=val[S[i]-'a'];  
                else sum[i]=sum[i-1]+val[S[i]-'a'];  
            }  
            T[n]=0;  
            EKMP(T,S,next,extend1);  
            EKMP(S,T,next,extend2);  
            int max_s=-1e8;  
            for(int i=1;i<n;i++)//i表示前半段的长度  
            {  
            
                int sc=0;//分数  
                //求前缀[0,i-1]分数  
                if(extend1[n-i]+n-i==n)  
                {  
                    sc+= sum[i-1];  
                }  
                //求后缀[i,n-1]的分数  
                if(extend2[i]+i==n)  
                {  
                    sc+= sum[n-1]-sum[i-1];  
                }  
                max_s=max(max_s,sc);  
            }  
            printf("%d\n",max_s);  
        }  
        return 0;  
    }  
