#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x,y) ((y*y) - (y/x))

int main()
{
	int i,n;
	float x0,y0,y1,y1_0,h,x1,xn;
	
	printf("Enter the value of x0 and xn and y0\n");
	scanf("%f %f %f", &x0,&xn,&y0);
	printf("Enter the incremental value\n");
	scanf("%f", &h);
	n=(xn-x0)/h;
	
	for(i=0;i<n;i++)
	{
		y1_0=y0+h*f(x0,y0);
		x1=x0+h;
		y1=y0+h*(f(x0,y0)+f(x1,y1_0))/2;
		
		while(fabs(y1_0-y1)>=0.0001)
		{
			y1_0=y1;
			y1=y0+h*(f(x0,y0)+f(x1,y1_0))/2;
		}
		x0=x1;
		y0=y1;
		
	}
	
	printf("The value of y at x = %f is y = %f\n",x0,y0);
}
