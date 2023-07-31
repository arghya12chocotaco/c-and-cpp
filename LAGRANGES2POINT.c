//Q. Lagrange's Interpolation

#include<stdio.h>
main()
{
	int n,i,j;
	printf("Enter the number of interpolating points: ");
	scanf("%d", &n);
	float x[n],y[n],D[n],d[n],a,b,w,sum;
	
	
	//input the table
	printf("Enter the values in the form x,y:\n");
	for (i=0;i<n;i++)
		scanf("%f %f",&x[i],&y[i]);
	printf("Enter the value of x's for which the value of y's are wanted:");
	scanf("%f %f",&a, &b);
	
	w=1.0;
	//making w(x)
	for (i=0;i<n;i++)
		w = w * (a - x[i]);
	
	//making D[i]'s
	for (i=0;i<n;i++)
	{
		D[i] = 1;
		for (j=0;j<n;j++)
		{
			if(j==i)
				D[i]=D[i]*(a-x[j]);
			else
				D[i]=D[i]*(x[i]-x[j]);
		}
	}
    
    sum=0.0;
    //now carrying out interpolation
    for (i=0;i<n;i++)
    	sum=sum + y[i]/D[i];
    sum=w*sum;
    printf("y(%2.3f)=%.6f\n",a,sum);

	w=1.0;
	//making w(x)
	for (i=0;i<n;i++)
		w = w * (b - x[i]);
	
	//making d[i]'s
	for (i=0;i<n;i++)
	{
		d[i] = 1;
		for (j=0;j<n;j++)
		{
			if(j==i)
				d[i]=d[i]*(b-x[j]);
			else
				d[i]=d[i]*(x[i]-x[j]);
		}
	}
    
    sum=0.0;
    //now carrying out interpolation
    for (i=0;i<n;i++)
    	sum=sum + y[i]/d[i];
    sum=w*sum;
    printf("y(%2.3f)=%.6f\n",b,sum);

}
