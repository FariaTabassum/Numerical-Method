#include<stdio.h>
#include<math.h>
#define f(x,y) (1-y)
int main()
{
    float x0,y0,h,xn,z,x,y;
    printf("\nEnter x0,y0,h,xn:\n ");
    printf("initial value of: x0 = ");
    scanf("%f", &x0);
    printf("initial value of: y0 = ");
    scanf("%f", &y0);
    printf("step size: h = ");
    scanf("%f", &h);
    printf("Required value of :y(x) = ");
    scanf("%f", &xn);

    x=x0;
    y=y0;
    printf("\nThe iterations are:\n");
    printf("\n  x\t  solution's by Eular method's\t\t m=slope\n");
    while(x<xn)
    {
        y=y+h*f(x,y);
        x=x+h;
        printf("%0.1f\t\t\t %0.2f\t\t\t  %0.2f\n",x,y,f(x,y));
    }
    return 0;
}

