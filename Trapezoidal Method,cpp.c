#include<stdio.h>
#include<math.h>
float func(float x)
{
    float a;
    a=x/(1+x);
    return a;
}
int main()
{
    int n,i;
    float a,b,h,sum,integral;
    printf("\n Enter the upper limit: ");
    scanf ("%f",&a);
    printf("\n Enter the lower limit: ");
    scanf ("%f",&b);
    printf("\n Enter the interval: ");
    scanf ("%d",&n);
    h=(a-b)/n;
    sum=func(a)+func(b);
    i=2;
    while(i<=n)
    {
        sum=sum+2*func(b+(i-1)*h);
        i++;
    }
    integral=h*sum/2;
    printf("\n Answer is: %f",integral);

   return 0;
}
