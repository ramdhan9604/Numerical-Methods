#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,m;
    float h,k,a,r,u[10][10];
    h = 0.5,k=0.125,a=1,n=5,m=5;
    for(j=0; j<m+1; j++)
    {
        u[0][j]=0;
    }
    for(j=0; j<m+1; j++)
    {
        u[n-1][j]=100;
    }
    u[1][0]=20;
    u[2][0]=40;
    u[3][0]=60;
    r =(k*a*a)/(h*h);
    for(j=0; j<m; j++)
    {
    for(i=1; i<n-1; i++)
            u[i][j+1] = r*(u[i-1][j]+u[i+1][j]+(1-2*r)*u[i][j]);
            printf("\n");
    }
    printf("Solution of parabolic equation: \n");
    printf("(i,j)\t");
    for(i=1; i<n; i++)
    printf("u(%d,j)\t",j);
    printf("\n");
    for(j=0; j<m+1; j++)
    {
        printf("(i,%d)\t",j);
        for(i=1; i<n; i++)
        {
            printf("%5.2f\t",u[i][j]);
        }
        printf("\n");
    }
}

