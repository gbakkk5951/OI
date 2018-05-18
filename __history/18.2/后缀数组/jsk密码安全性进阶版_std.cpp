    #include <cstdio>  
    #include <cstring>  
    const int N = 1017;  
    int wa[N], wb[N], wv[N], ws[N];  
    int rank[N]; //��������  
    int  height[N]; //�������ڵ�������׺�������ǰ׺  
    char str[N];  
    int s[N], sa[N]; //saΪ��׺����,n����׺��С�����������֮����ź���ĺ�׺�Ŀ�ͷλ��  
      
    int Max(int a, int b)  
    {  
        return a > b ? a:b;  
    }  
    int Min(int a, int b)  
    {  
        return a < b ? a:b;  
    }  
    int cmp(int *r, int a, int b, int l)  
    {  
        return r[a]==r[b] && r[a+l]==r[b+l];  
    }  
    //get_sa�����Ĳ���n�����ַ������ַ��ĸ����������n�����ǰ�����Ϊ���ַ���ĩβ��ӵ��Ǹ�0��  
    //get_sa�����Ĳ���m�����ַ������ַ���ȡֵ��Χ���ǻ��������һ��������  
    //���ԭ���ж�����ĸ����ֱ��ȡ128��  
    //���ԭ���б����������Ļ�����m����ȡ������������1��ֵ��  
    void get_sa(int *r, int *sa, int n, int m) //�����㷨  
    {  
        int i,j,p,*x=wa,*y=wb,*t;  
        for(i=0; i<m; i++) ws[i]=0;  
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;  
        for(i=1; i<m; i++) ws[i]+=ws[i-1];  
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i; //�Գ���Ϊ1���ַ�������  
        for(p=1,j=1; p<n; j*=2,m=p)  
        {  
            for(p=0,i=n-j; i<n; i++) y[p++]=i;  
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j; //�ڶ��ؼ���������  
      
            for(i=0; i<n; i++) wv[i]=x[y[i]];  
            for(i=0; i<m; i++) ws[i]=0;  
            for(i=0; i<n; i++) ws[wv[i]]++;  
            for(i=1; i<m; i++) ws[i]+=ws[i-1];  
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i]; //��һ�ؼ�������  
      
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)  
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; //����rank����  
        }  
        return;  
    }  
    void get_height(int *r, int *sa, int n) //��height����  
    {  
        int i, j, k=0;  
        for(i=1; i<=n; i++) rank[sa[i]]=i;  
        for(i=0; i<n; height[rank[i++]]=k)  
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);  
        return;  
    }  
      
    int main()  
    {  
        while(scanf("%s",str) != EOF)  
        {  
            int len = strlen(str);  
            if(str[0] == '#')  
                break;  
            for(int i = 0; i < len; i++)  
                s[i] = str[i]-'a'+1;  
            s[len] = 0;//�����ֵΪ0�ǹؼ�����  
            get_sa(s,sa,len+1,27);  
            get_height(s,sa,len);  
            //for(int i=0;i<len+1;i++) printf("%d %d\n",i,sa[i]);  
            int ans = 0;  
            for(int i = 1; i <= (len+1)/2; i++)  
            {  
                //��һ��ͺ��ˣ����ȴ��ڣ�len+1��/2���Ӵ��������ظ�������  
                //����Ϊi���ظ��Ӵ�  
                int minn = N;  
                int maxn = -1;  
                for(int j = 1; j <= len; j++)  
                {  
                    if(height[j] >= i)//����  
                    {  
                        minn = Min(minn,Min(sa[j-1],sa[j]));  
                        maxn = Max(maxn,Max(sa[j-1],sa[j]));  
                    }  
                    else//��height��ֵ������������i��  
                    {  
                        if(minn+i <= maxn)  
                            ans++;  
                        minn = N, maxn = -1;  
                    }  
                }  
                if(minn+i <= maxn)  
                    ans++;  
            }  
            printf("%d\n",ans);  
        }  
        return 0;  
    }  
