#include<stdio.h>
#include<math.h>
double f(float x)
{
	return(exp(pow(x,2))+log(pow(x,2)+2)-2.5*(x+1));
}
int main()
{
	int i=1;
	double a,b,x,err=1e-5;
	printf("The lower and upper bounds of the interval are a,b: ");
	scanf("%lf,%lf",&a,&b);
	printf("\n\n");
	printf("\n iteration \ta		\tb		\tx		\tf(a)  	\tf(b)		\tf(x)");
	printf("\n\n");
	do
{
	x=(a+b)/2;
	printf("\n   %d		  %lf		%lf		 %lf	 %lf		  %lf		  %lf",i,a,b,x,f(a),f(b),f(x));
	if (f(a)*f(x)<0)
	{
		b=x;
	}
	if (f(b)*f(x)<0)
	{
	a=x;
}
else
{
}
i++;
}while (fabs(f(x))>err);
printf("\n\nApproximate root = %.10lf\n",x);
}
