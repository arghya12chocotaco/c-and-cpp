#include<stdio.h>
#include<math.h>
#define m 3
double f(double x)
{
	return pow((x-5),3)*(x-2);
}
double df(double x)
{
	return 3*pow((x-5),2)*(x-2)+pow((x-5),3);
}
main()
{
	int miter,iter;
	double x0,x1,h,err,root;
	printf("Enter the first approximation:");
	scanf("%lf",&x0);
	printf("Enter the maximum number of iterations:");
	scanf("%d",&miter);
	printf("Enter the tolerance error:");
	scanf("%lf",&err); 
	printf("n\t x(n)\t f(x(n))\n");
	iter=1;
	while (iter<=miter)
	{
		h=-f(x0)/df(x0);
		x1=x0+m*h;
		printf("%d\t %0.5lf\t %0.5lf\n",iter,x1,f(x1));
		if(fabs(m*h)<err)
		{
			root=x1;
			break;
		}
		else
		x0=x1;
		iter++;
	}
	if(root==x1)
		printf("The root is:%0.5lf",root);
	else
	printf("Insufficient number of iterations.");			
}
