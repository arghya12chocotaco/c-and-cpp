#include<stdio.h>
#include<math.h>
#define pi 2*asin(1)
float f(float x)
{
return((sin(1+x+exp(-x)))/(sqrt(1+x)));	
}
main()
{
	int n,i;
	printf("Enter the number of sub-intervals n: ");
	scanf("%d",&n);
	float a,b,h,x[n],sum;
	printf("Enter the lower limit: ");
	scanf("%f",&a);
	printf("Enter the upper limit: ");
	scanf("%f",&b);
	a=(a*pi)/180;
	b=(b*pi)/180;
	// Making the sub-intervals
	h=(b-a)/n;
	x[0]=a;
	for(i=0;i<=n;i++)
	x[i]=x[0]+i*h;
	// Value of Integral
	sum=0;
	for(i=0;i<=n-6;i=i+6)
	sum=sum+(3.*h/10.)*(f(x[i])+5*f(x[i+1])+f(x[i+2])+6*f(x[i+3])+f(x[i+4])+5*f(x[i+5])+f(x[i+6]));
	printf("The value of integral = %.4f",sum);
}
