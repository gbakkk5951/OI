#include <cstdio>
#include <cstring>
#include <iostream>
#define R register
int n, A[200010], B[200010], to[200010], Q[2000010][2], cnt, pos[200010], sta[200010][2], tot;
int main()
{
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	scanf("%d", &n);
	for(R int i = 1; i <= n; ++i) scanf("%d", &A[i]);
	for(R int i = 1; i <= n; ++i) scanf("%d", &B[i]);
	for(R int i = 1; i <= n; ++i) pos[A[i]] = i;
	for(R int i = 1; i <= n; ++i) to[B[i]] = i;
	for(R int i = 1; i <= n; ++i) if(A[i] != B[i])
	{
		R int t = pos[B[i]];
		if(to[A[i]] >= pos[B[i]]) 
		{
		//	printf("[%d %d]\n", i, t);
			std::swap(A[i], A[t]);
			pos[A[i]] = i; pos[A[t]] = t;
		//	while(tot){ Q[++cnt][0] = sta[tot][0]; Q[cnt][1] = sta[tot--][1]; }
			Q[++cnt][0] = i; Q[cnt][1] = t;
		}
		else
		{
			t = to[A[i]];
		//	printf("<%d %d>\n", i, t);
		
			std::swap(B[i], B[t]);
			to[B[i]] = i; to[B[t]] = t;
			sta[++tot][0] = i; sta[tot][1] = t;
		}
	//	for(R int j = 1; j <= n; ++j) printf("%d ", A[j]); puts("");
	//	for(R int j = 1; j <= n; ++j) printf("%d ", B[j]); puts("\n");
	}
	while(tot){ Q[++cnt][0] = sta[tot][0]; Q[cnt][1] = sta[tot--][1]; }
	printf("%d\n", cnt);
	for(R int i = 1; i <= cnt; i++) printf("%d %d\n", Q[i][0], Q[i][1]);
	return 0;
}
