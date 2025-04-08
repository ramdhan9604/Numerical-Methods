#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x, float y)
{
	return (x+y*y);
}
int main()
{
	int i;
	float x0,y0,xn,h,yn,n,x,y,k1,k2,k3,k4,k;
	h=0.1;

	printf("Enter the initial value of x\n");
	scanf("%f", &x0);
	printf("Enter the initial value of y at x=%f\n", x0);
	scanf("%f", &y0);
	printf("Enter the value of x for which the integral is to be calculated\n");
	scanf("%f", &xn);
	n=(xn-x0)/h;
	x=x0;y=y0;
	
	for(i=0;i<n;i++)
	{
	k1=h*f(x,y);
	k2=h*f((x+h/2),(y+k1/2));
	k3=h*f(x+h/2,y+k2/2);
	k4=h*f(x+h,y+k3);
	k=(k1+2*k2+2*k3+k4)/6;
	//x=x+h;
	//y=y+k;
}

     printf("The value of y at x=%f is y=%f\n", x,y);
 }
	
