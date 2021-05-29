#include<stdio.h>
#include<math.h>
#define f(x,y) (2*y)/x
int main()
{
    float x0,y0,h,xn,x,y,m2,m1;
    printf("\nEnter x0,y0,h,xn:\n ");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("h = ");
    scanf("%f", &h);
    printf("y(x) = ");
    scanf("%f", &xn);
    x=x0;
    y=y0;
    printf("\n  x\t  y\t m1\t m2\n");
    while(x<xn)
    {
        m1=f(x,y);
        m2=f(x+h,y+m1*h);
        x=x+h;
        y=y+0.5*h*(m1+m2);
        printf("%0.2f\t%0.2f\t%0.2f\t%0.2f\n",x,y,m1,m2);
    }
    return 0;
}
