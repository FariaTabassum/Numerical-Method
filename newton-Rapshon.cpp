#include <stdio.h>
#include <stdlib.h>
#include "math.h"


//definition of the function f(x)
float f(float x)
{
	return(x*x-3*x+2);
}

//definition of the function fd(x)
float fd(float x)
{
	return(2*x-3);
}
int main()
{
    float x1,x0,f1,f0,a,b,c;
    int k = 0;
    float f(float x);
	float fd(float x);
    printf("Enter the value of x0:");
    scanf("%f",&x0);

    do {
        a=f(x0)/fd(x0);
        x1 = x0-a;
        f1=f(x1);
        if(f0*f1 == 0)
            break;
        else
        {
            x0=x1;
        }

        k++;
        printf("no of iteration = %d\t",k);
        printf("no of root = %f\t",x0);
        printf("value of function = %f\n",f(x0));


    }while(fabs(f(x0))> 0.000001);
    printf("\n root is %.6f   and no. of iteration is %d",x0,k);

    return 0;
}

