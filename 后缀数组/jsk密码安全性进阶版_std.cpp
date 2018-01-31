    #include <cstdio>  
    #include <cstring>  
    const int N = 1017;  
    int wa[N], wb[N], wv[N], ws[N];  
    int rank[N]; //名次数组  
    int  height[N]; //排名相邻的两个后缀的最长公共前缀  
    char str[N];  
    int s[N], sa[N]; //sa为后缀数组,n个后缀从小到大进行排序之后把排好序的后缀的开头位置  
      
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
    //get_sa函数的参数n代表字符串中字符的个数，这里的n里面是包括人为在字符串末尾添加的那个0的  
    //get_sa函数的参数m代表字符串中字符的取值范围，是基数排序的一个参数，  
    //如果原序列都是字母可以直接取128，  
    //如果原序列本身都是整数的话，则m可以取比最大的整数大1的值。  
    void get_sa(int *r, int *sa, int n, int m) //倍增算法  
    {  
        int i,j,p,*x=wa,*y=wb,*t;  
        for(i=0; i<m; i++) ws[i]=0;  
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;  
        for(i=1; i<m; i++) ws[i]+=ws[i-1];  
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i; //对长度为1的字符串排序  
        for(p=1,j=1; p<n; j*=2,m=p)  
        {  
            for(p=0,i=n-j; i<n; i++) y[p++]=i;  
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j; //第二关键字排序结果  
      
            for(i=0; i<n; i++) wv[i]=x[y[i]];  
            for(i=0; i<m; i++) ws[i]=0;  
            for(i=0; i<n; i++) ws[wv[i]]++;  
            for(i=1; i<m; i++) ws[i]+=ws[i-1];  
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i]; //第一关键字排序  
      
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)  
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; //更新rank数组  
        }  
        return;  
    }  
    void get_height(int *r, int *sa, int n) //求height数组  
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
            s[len] = 0;//这个赋值为0是关键所在  
            get_sa(s,sa,len+1,27);  
            get_height(s,sa,len);  
            //for(int i=0;i<len+1;i++) printf("%d %d\n",i,sa[i]);  
            int ans = 0;  
            for(int i = 1; i <= (len+1)/2; i++)  
            {  
                //查一半就好了，长度大于（len+1）/2的子串不可能重复俩次啦  
                //长度为i的重复子串  
                int minn = N;  
                int maxn = -1;  
                for(int j = 1; j <= len; j++)  
                {  
                    if(height[j] >= i)//连续  
                    {  
                        minn = Min(minn,Min(sa[j-1],sa[j]));  
                        maxn = Max(maxn,Max(sa[j-1],sa[j]));  
                    }  
                    else//若height的值不是连续大于i的  
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
