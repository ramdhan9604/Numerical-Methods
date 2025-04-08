#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i;
	float a[20], b[20], c[20],d[20], x[20], alpha[20], beta[20];
	
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	
	printf("Enter the values of a's\n");
	for(i=2;i<=n;i++)
	{
		scanf("%f", &a[i]);
	
	}
	
	printf("Enter the values of b's\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f", &b[i]);
		
	}
	
	printf("Enter the values of c's\n");
	for(i=1;i<n;i++)
	{
		scanf("%f", &c[i]);
	}
	
	printf("Enter the values of d's\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f", &d[i]);
		
	}
	
	alpha[1]=b[1];
	
	for(i=2;i<=n;i++)
	{
		alpha[i]=b[i]-a[i]*c[i-1]/alpha[i-1];
	}
	
	beta[1]=d[1]/b[1];
	
	for(i=2;i<=n;i++)
	{
		beta[i]=(d[i]-a[i]*beta[i-1])/alpha[i];
	}
	
	x[n]=beta[n];
	
	for(i=n-1;i>=1;i--)
	{
		x[i]=beta[i]-c[i]*x[i+1]/alpha[i];
		
	}
	
	printf("The solution are\n");
	
		for(i=1;i<=n;i++)
	{
		printf("%f\t", x[i]);
	}
	return 0;
	
}
