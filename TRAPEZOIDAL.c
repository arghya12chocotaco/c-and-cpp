#include<stdio.h>
#include<math.h>
#define pi 2*asin(1)
float f (float x)
{
return
(pow(sin(x+3),2)+pow(cos(x+3),3))/(sqrt((4*pow(sin(x+3),3))+(5*pow(cos(x+3),2))));
}
main()
{
int n,i;
printf("Enter the number of subintervals:");
scanf("%d",&n);
float a,b,h,x[n],sum;
printf("Enter the lower limit:");
scanf("%f",&a);
printf("Enter the upper limit:");
scanf("%f",&b);
a=(a*pi/180);
b=(b*pi/180);
h=(b-a)/n;
x[0]=a;
for(i=0;i<=n;i++)
x[i]=x[0]+i*h;
sum=0;
for(i=0;i<=n-1;i=i+1)
sum=sum+(h/2)*(f(x[i])+4*f(x[i+1]));
printf("The value of integral=%f",sum);
}
