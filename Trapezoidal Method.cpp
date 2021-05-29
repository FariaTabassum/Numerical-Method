#include<stdio.h>
#include<math.h>
float f(float x)
{
    float a;
    a=x/(1+x);
    return a;
}
int main()
{
    int n,i;
    float a,b,h,sum=0,I,y0,yn;
    printf("\n Enter the upper limit: ");
    scanf ("%f",&b);
    printf("\n Enter the lower limit: ");
    scanf ("%f",&a);
    printf("\n Enter the interval: ");
    scanf ("%d",&n);
    h=(b-a)/n;
    y0=f(a+0*h);
	yn=f(a+n*h);
    i=1;
    while(i<n)
    {
        sum=sum+f(a+i*h);
        i++;
    }
    I=(h/2)*(y0 + yn + 2*sum);
    printf("\n The integral of the equation using Trapezoidal Rule is %.3f:\n",I);

    return 0;
}
