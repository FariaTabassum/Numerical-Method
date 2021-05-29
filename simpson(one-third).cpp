#include<stdio.h>
#include<math.h>

float f(float x)
{
    float a;
    a=x/(1+x);
    return a;
}

int main(){

	float a,b,n,h,sum1=0,sum2=0,I,y0,yn;
	int i;

	printf("\n Enter the upper limit: ");
    scanf ("%f",&b);
    printf("\n Enter the lower limit: ");
    scanf ("%f",&a);
    printf("\n Enter the interval: ");
    scanf ("%f",&n);


	h=(b-a)/n;

	y0=f(a+0*h);
	yn=f(a+n*h);

	i=1;
    while(i<n)
    {
        if(i%2 == 0)
			sum1 = sum1 + f(a+i*h);
		else
			sum2 = sum2 + f(a+i*h);
        i++;
    }


	I =(h/3)*(y0 + yn + 2*sum1 +4*sum2);


	printf("\n The integral of the equation using Simpson's (One-third) Rule is %.3f\n",I);


	return 0;
}
