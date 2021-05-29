#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
    return x*x+y*y;
}
int main()
{
    float x0,y0,h,xn,x,y,m1,m2,m3,m4,m;
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
    printf("\n  x\t  y\t m1\t m2\t m3\t m4\t \n");
    while(x<xn)
    {

        m1=f(x,y);
        m2=f(x+0.5*h,y+0.5*m1*h);
        m3=f(x+0.5*h,y+0.5*m2*h);
        m4=f(x+h,y+m3*h);
        x=x+h;
        y=y + (m1+2*m1+2*m2+2*m3+m4)*h/6;
         printf("%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\n",x,y,m1,m2,m3,m4);
    }
}
