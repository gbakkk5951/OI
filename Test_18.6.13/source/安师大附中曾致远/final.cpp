
#include <cstdio>

using namespace std;

const int Max_N(7);

int N, A[Max_N][Max_N];

void init()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;++i)
		scanf("%d", &A[1][i]);
}

void Task_1()
{
	if (A[1][1] == 1)
		printf("%d\n", A[1][1]);
	else
		printf("no solution\n");
}

void Task_2()
{
	for (A[2][1] = -2000;A[2][1] <= 2000;++A[2][1])
		for (A[2][2] = -2000;A[2][2] <= 2000;++A[2][2])
			if (A[1][1] * A[2][2] - A[1][2] * A[2][1] == 1)
			{
				for (int i = 1;i <= N;++i)
				{
					for (int j = 1;j <= N;++j)
						printf("%d ", A[i][j]);
					printf("\n");
				}
				return;
			}
	printf("no solution\n");
}

void Task_3()
{
	printf("no solution\n");
}

int main()
{
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	init();
	if (N == 1)
		Task_1();
	else
		if (N == 2)
			Task_2();
		else
			Task_3();
	return 0;
}
