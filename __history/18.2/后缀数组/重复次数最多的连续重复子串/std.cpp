    /*Sherlock and Watson and Adler*/  
    #pragma comment(linker, "/STACK:1024000000,1024000000")  
    #include<stdio.h>  
    #include<string.h>  
    #include<stdlib.h>  
    #include<queue>  
    #include<stack>  
    #include<math.h>  
    #include<vector>  
    #include<map>  
    #include<set>  
    #include<list>  
    #include<bitset>  
    #include<cmath>  
    #include<complex>  
    #include<string>  
    #include<algorithm>  
    #include<iostream>  
    #define eps 1e-9  
    #define LL long long  
    #define PI acos(-1.0)  
    #define bitnum(a) __builtin_popcount(a)  
    using namespace std;  
    const int N = 5005;  
    const int M = 100005;  
    const int inf = 1000000007;  
    const int mod = 1000000007;  
    const int MAXN = 50005;  
    //rnk��0��ʼ  
    //sa��1��ʼ,��Ϊ���һ���ַ�(��С��)���ڵ�0λ  
    //height��1��ʼ,��Ϊ��ʾ����sa[i - 1]��sa[i]  
    //�����㷨 O(nlogn)  
    int wa[MAXN], wb[MAXN], wv[MAXN], ws_[MAXN];  
    //Suffix�����Ĳ���m�����ַ������ַ���ȡֵ��Χ,�ǻ��������һ������,���ԭ���ж�����ĸ����ֱ��ȡ128,���ԭ���б����������Ļ�,��m����ȡ������������1��ֵ  
    //��������ַ�������r������,��r[0]��r[n-1]������Ϊn  
    //Ϊ�˷���Ƚϴ�С,�������ַ����������һ���ַ�,����ַ�û����ǰ����ַ��г��ֹ�,���ұ�ǰ����ַ���ҪС  
    //ͬ��,Ϊ�˺��������ķ���,Լ����r[n-1]�����е�r[i]������0,r[n-1]=0  
    //����������,�������sa������,��sa[0]��sa[n-1]  
    void Suffix(int *r, int *sa, int n, int m)  
    {  
        int i, j, k, *x = wa, *y = wb, *t;  
        //�Գ���Ϊ1���ַ�������  
        //һ����˵,���ַ�������Ŀ��,r�����ֵ����ܴ�,��������ʹ���˻�������  
        //���r�����ֵ�ܴ�,��ô����δ���ĳɿ�������  
        for(i = 0; i < m; ++i) ws_[i] = 0;  
        for(i = 0; i < n; ++i) ws_[x[i] = r[i]]++;//ͳ���ַ��ĸ���  
        for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];//ͳ�Ʋ������ַ�i���ַ�����  
        for(i = n - 1; i >= 0; --i) sa[--ws_[x[i]]] = i;//�����ַ�����  
        //��������  
        //x���鱣���ֵ�൱����rankֵ  
        for(j = 1, k = 1; k < n; j *= 2, m = k)  
        {  
            //j�ǵ�ǰ�ַ����ĳ���,����y������ǶԵڶ��ؼ�������Ľ��  
            //�ڶ��ؼ�������  
            for(k = 0, i = n - j; i < n; ++i) y[k++] = i;//�ڶ��ؼ���Ϊ0������ǰ��  
            for(i = 0; i < n; ++i) if(sa[i] >= j) y[k++] = sa[i] - j;//����Ϊj���Ӵ�sa[i]Ӧ���ǳ���Ϊ2 * j���Ӵ�sa[i] - j�ĺ�׺���ڶ��ؼ��֣�,�����еĳ���Ϊ2 * j���Ӵ����ݵڶ��ؼ���������  
            for(i = 0; i < n; ++i) wv[i] = x[y[i]];//��ȡ��һ�ؼ���  
            //����һ�ؼ������� (ԭ��ͬ�Գ���Ϊ1���ַ�������)  
            for(i = 0; i < m; ++i) ws_[i] = 0;  
            for(i = 0; i < n; ++i) ws_[wv[i]]++;  
            for(i = 1; i < m; ++i) ws_[i] += ws_[i - 1];  
            for(i = n - 1; i >= 0; --i) sa[--ws_[wv[i]]] = y[i];//����һ�ؼ���,������˳���Ϊ2 * j���Ӵ��������  
            //��ʱ����x�ǳ���Ϊj���Ӵ����������,����y���Ǹ��ݵڶ��ؼ��������Ľ��  
            //���㳤��Ϊ2 * j���Ӵ����������,���浽����x  
            t = x;  
            x = y;  
            y = t;  
            for(x[sa[0]] = 0, i = k = 1; i < n; ++i)  
                x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + j] == y[sa[i] + j]) ? k - 1 : k++;  
            //������Ϊ2 * j���Ӵ�sa[i]��sa[i - 1]��ȫ��ͬ,����������ͬ������  
        }  
    }  
    int Rank[MAXN], height[MAXN], sa[MAXN], r[MAXN];  
    void calheight(int *r,int *sa,int n)  
    {  
        int i,j,k=0;  
        for(i=1; i<=n; i++)Rank[sa[i]]=i;  
        for(i=0; i<n; height[Rank[i++]]=k)  
            for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);  
    }  
    int n,minnum[MAXN][16];  
    void RMQ()          //Ԥ����  O(nlogn)  
    {  
        int i,j;  
        int m=(int)(log(n*1.0)/log(2.0));  
        for(i=1;i<=n;i++)  
            minnum[i][0]=height[i];  
        for(j=1;j<=m;j++)  
            for(i=1;i+(1<<j)-1<=n;i++)  
                minnum[i][j]=min(minnum[i][j-1],minnum[i+(1<<(j-1))][j-1]);  
    }  
    int Ask_MIN(int a,int b)    //O(1)  
    {  
        int k=int(log(b-a+1.0)/log(2.0));  
        return min(minnum[a][k],minnum[b-(1<<k)+1][k]);  
    }  
    int calprefix(int a,int b)  
    {  
        a=Rank[a],b=Rank[b];  
        if(a>b)  
            swap(a,b);  
        return Ask_MIN(a+1,b);  
    }  
    char s[5];  
    int main()  
    {  
        freopen("KA0.in", "r", stdin);
        int t,i,j,k,ans,Max;  
        scanf("%d",&t);  
        while(t--)  
        {  
            Max=1;  
            scanf("%d",&n);  
            for(i=0;i<n;i++)  
            {  
                scanf("%s",s);  
                r[i]=s[0]-'a'+1;  
            }  
            r[i]=0;  
            Suffix(r,sa,n+1,3);  
            calheight(r,sa,n);  
            RMQ();  
            for(i=1;i<=n;i++)  
            {  
                for(j=0;j+i<n;j+=i)  
                {  
                    ans=calprefix(j,j+i);  
                    k=j-(i-ans%i);  
                    ans=ans/i+1;  
                    if(k>=0&&calprefix(k,k+i)>=i)  
                        ans++;  
                    //printf("L=%d,R=%d\n",i,ans);  
                    Max=max(Max,ans);  
                }  
            }  
            printf("%d\n",Max);  
        }  
        return 0;  
    }  
