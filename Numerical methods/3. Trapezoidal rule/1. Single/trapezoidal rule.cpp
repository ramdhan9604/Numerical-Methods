#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	float a,b,h,y0,yn,f,x,sum,p;
	int i,n;
	sum =0.0;
	
	printf("enter the lower limit of integration");
	scanf("%f",&a);
	printf("ener the upper limit of integration");
	scanf("%f",&b);
	printf("enter no of intervals");
	scanf("%d",&n);
	h=(b-a)/n;
	y0=a/(1+a);
	yn=b/(1+b);
	for(i=1;i<=n-1;i++)
	{
		x=a+(i*h);
		f=x/(1+x);
		sum=sum+f;
	}
	p=h*((y0+yn)/2+sum);
	printf("%f",p);
}
