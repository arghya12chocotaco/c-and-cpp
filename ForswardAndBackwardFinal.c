#include<stdio.h>
void main()
{
	int m,n,i,j,k;
	printf("Enter the number of interpolating points: ");
	scanf("%d", &n);
	double x[n],y[n],d[n][n],sum1,sum2,a,b,h,u1,u2,term1,term2;
	
	//input the table
	printf("Enter the values in the form x,y:\n");
	for (i=0;i<n;i++)
		scanf("%lf %lf",&x[i],&y[i]);
	printf("Enter the value of x's for which the value of y's are wanted:");
	scanf("%lf %lf",&a, &b);
	h=x[1]-x[0]; //we already know that the arguments are equispaced
	
	//now making the difference table
    for (i=0;i<n;i++)
    	d[i][0]=y[i];
    for (j=1;j<n;j++)
    	for (i=0;i<n-j;i++)
    		d[i][j]=d[i+1][j-1]-d[i][j-1];
    printf("\nThe difference table is\n");
    for (i=0;i<n;i++)
    {
    	for (j=0;j<n-i;j++)
    		printf("%.10lf  ", d[i][j]); //the given data is upto 6D places
    	printf("\n");
	}
	
	//now finding x0(the starting point)
	i=0;
    while (!(x[i]>a))
        i++;
        
    //now finding xn(the starting point)
	k=n-1;
    while (!(x[k]<b))
        k--;
    
    //now x[i] is x0 and y[i] is y0
    i--;
    u1 = (a-x[i])/h;
    sum1 = y[i];
    
    //now x[k] is xn and y[k] is yn
    k++;
    u2 = (b-x[k])/h;
    sum2 = y[k];
    
    //elemination of noise level
    printf("\nEnter the column no. in which noise level appears, otherwise press 0\n");
    scanf("%d", &m);
    if(m==0)
    	m=n;
   
	//now carrying out FORWARD interpolation
    term1 =u1;
    for (j=1;j<m-1;j++)   //j denotes the order of the difference
    	{
    		sum1 = sum1 + term1 * d[i][j]; //x[i] stands for the starting point
    		term1 = term1 * (u1-j)/(j+1);
		}
    printf("y(%.2lf)=%.10lf",a,sum1);  //the answer should be rounded off to the given number of decimal places 		

	printf("\n");
	
    //now carrying out BACKWARD interpolation
    term2 =u2;
    
    for (j=1;j<m-1;j++)   //j denotes the order of the difference
    	{
    		sum2 = sum2 + term2 * d[k-j][j]; //x[i] stands for the starting point
    		term2 = term2 * (u2+j)/(j+1);
		}
    printf("y(%.2lf)=%.10lf",b,sum2);  //the answer should be rounded off to the given number of decimal places 		   
}
