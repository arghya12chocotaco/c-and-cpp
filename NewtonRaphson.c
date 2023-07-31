#include<stdio.h>
#include<math.h>
float f(float x)
{
	return(pow(10,x)+sin(x)+x-4);
}
float df(float x)
{
	return(pow(10,x)*log(10)+cos(x)+1);
}
int main ()
{
	      float x, h, error=1e-6;
	      printf("Enter the initial approximation:");
	      scanf("%f",&x);
	      
	      if(fabs(df(x))<1e-7)
	             printf("change the initial approximation.\n");
	             
	    else 
	    {
		
	             h=-f(x)/df(x);
	             while(fabs(h)>error)
	             {
				    x=x+h;
				    h=-f(x)/df(x);
				}
				printf("A real correct upto 5D places is=%.5f",x);
		}
}
