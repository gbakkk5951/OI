#include<cstdio>
int main()
{
	int l,r;
	printf("Enter the speed limit: ");
	scanf("%d",&l);
	printf("Enter the recorded speed of the car: ");
	scanf("%d",&r);
	if(l>=r)
	printf("Congratulations, you are within the speed limit");
	else
	if(r-l<=20)
	printf("You are speeding and your fine is $ 100");
	else if (r-l<=30)
	printf("You are speeding and your fine is $ 270");
	else printf("You are speeding and your fine is $ 500");
	
}
