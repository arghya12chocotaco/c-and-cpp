#include<stdio.h>
main()
{
	int n,i,j;
	printf("Enter the number of interpolating points: ");
	scanf("%d",&n);
	float x[n],y[n],d[n][n],a,sum,term;
	// Input The table
	printf("Enter the values in the form x,y\n");
	for(i=0;i<n;i++)
	scanf("%f,%f",&x[i],&y[i]);
	printf("Enter the value of x for which the value of y is wanted ");
	scanf("%f",&a);
	// Making difference table
	for(i=0;i<n;i++)
	d[i][0]=y[i];
	for(j=1;j<n;j++)
	{
		for(i=0;i<=n-j;i++)
		{
			d[i][j]=d[i][j-1]-d[i+1][j-1]/x[i]-x[j];
		}
	}
	//Carrying out of interpolatiion
	sum=y[0];
	term=(a-x[0]);
	for(j=1;j<n;j++)
	{
		sum=sum+term*d[0][j];
		term=term*(a-x[j]);
	}
	printf("y(%.2f)=%.6f",a,sum);
}
