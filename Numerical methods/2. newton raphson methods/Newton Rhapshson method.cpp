#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

float function1(float x, float y)
{
	float f= x*x+x*y-10;
	return(f);
}

float function2(float x, float y)
{
	float g= y+3*x*y*y-57;
	return(g);
}

float funcfx(float x, float y)
{
	float fx=2*x+y;
	return(fx);
}

float funcfy(float x, float y)
{
	float fy=y;
	return(fy);
}

float funcgx(float x, float y)
{
	float gx= 3*y*y;
	return(gx);

}

float funcgy(float x,float y)
{
	return (1+6*x*y);
}

float det(float x,float y)
{

	return((funcfx(x,y))*(funcgy(x,y))-(funcgx(x,y))*(funcfy(x,y)));
}

float detx(float x, float y)
{
	float f,fy,g,gy;
	f=function1(x,y);
	g=function2(x,y);
	fy=funcfy(x,y);
	gy=funcgy(x,y);
	
	float dx=f*gy-g*fy;
	return(dx);
}

float dety(float x,float y)
{
	float fx,f,gx,g;
	fx=funcfx(x,y);
	f=function1(x,y);
	g=function2(x,y);
	gx=funcgx(x,y);
	
	float dy=fx*g-gx*f;
	return(dy);
}

int main()
{
	float D,Dx,Dy,x,y,t,s,h,k,x1,y1,xo,yo,err;
	printf("Enter the intial approximations\n");
	scanf("%f %f", &xo, &yo); //1.5,3.5
	int i=1;
	
	do
	{
		Dx= detx(xo,yo);
		Dy= dety(xo,yo);
		D = det(xo,yo);
		
		
		h=-Dx/D;
		k=-Dy/D;
		x=xo+h;
		y=yo+k;
		
		printf("The value of %dth iteration is x=%d and y=%d\n",i,x,y);
		i=i+1;
		
		x1=xo;
		y1=yo;
		xo=x;
		yo=y;	
		
	}
	while(fabs(x1-xo)>0.001 && fabs(y1-yo)>0.001);
	
	printf("The solution of the equation is\n");
	printf("%f\t and\t %f\n", xo,yo);
	return 0;
}
