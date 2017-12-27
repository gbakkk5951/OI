#include<stdio.h>
using namespace std;
int main()
{
	
	void pigeonhole_sort();
	
}








void pigeonhole_sort(int* array, int length) {
int NUM=50;
int auxiliary[NUM] = {0};

int i, k,j = 0;

for(i = 0; i < length; ++i)

auxiliary[array]++;

for(i = 0; i < NUM; ++i)

for(k = 0; k < auxiliary; ++k)

array[j++] = i;

}
