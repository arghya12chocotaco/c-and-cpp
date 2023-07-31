//SECANT METHOD
#include<stdio.h>
#include<math.h>
double f(double x)
{
	return(pow((x-5),3)*(x-2));
}
int main()
{
	double x0,x1,x2;
	do
	{
		printf("Enter x0:");
		scanf("%lf",&x0);
		printf("Enter x1:");
		scanf("%lf",&x1);
	} while(f(x1)*f(x0)>0);
	
	do
	{
		x2=x1-f(x1)*(x1-x0)/(f(x1)-f(x0));
		x0=x1;
		x1=x2;	
	} while (fabs(f(x2))>0.000001);
	printf("The value of the root is:%0.5lf",x2);
}
