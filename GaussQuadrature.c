//Q. Gauss Quadrature

#include<stdio.h>
#include<math.h>
#define pi 2*asin(1)

float f (float a,float b,float t) //difining the integrand
{
	float x,y;
	x = (b+a)/2 + t*(b-a)/2;
	y=((pow(sin(x+3),2))+(pow(cos(x+3),3)))/(sqrt((4*pow(sin(x+3),3))+(5*pow(cos(x+3),2))));
	return (y);
}
main ()
{
	    int n,i;
	    float a, b;
	    
	    printf("Enter the lower & upper limits:");
	    scanf("%f %f",&a,&b);
	    
		printf("Enter the number of ordinates n:");
	    scanf("%d",&n);
		
		double t[n], w[n], sum;
		
	    a=(a*pi)/180;   
	    b=(b*pi)/180;
	    
	    printf("Enter the ordinates:\n");
		for(i=0;i<n;i++)
	    	scanf("%lf",&t[i]);
	    
	    printf("Enter the weights:\n");
		for(i=0;i<n;i++)
	    	scanf("%lf",&w[i]);
	    
	    sum=0;
	    for(i=0;i<n;i++)    
	    	sum=sum+w[i]*f(a,b,t[i]);
	    sum=sum*(b-a)/2;
	    
	    printf("The value of integral correct upto 5D is %.5lf",sum);  
}
