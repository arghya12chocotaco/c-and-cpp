//REGULA FALSI METHOD

#include<stdio.h>
#include<math.h>
double f(double x)
{
	return (pow(x,3)-6*x*x+12*x-8);
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
	}while(f(x0)*f(x1)>0);
	
	do
	{
		x2=x0-f(x0)*((x1-x0)/(f(x1)-f(x0)));
		if (f(x0)*f(x2)<0)
			x1=x2;
		if(f(x2)*f(x1)<0)
			x0=x2;	
	}while(fabs(f(x2))>0.0000001);
