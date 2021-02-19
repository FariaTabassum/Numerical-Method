#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//definition of the function f(x)
float f(float x)
{
	return(x*x-4*x-10);
}

//definition of the function fd(x)
float fd(float x)
{
	return(2*x-4);
}
int main()
{
    float x1,x3,x2,f1,f2,f3,a,b,c,d;
    int k = 0;
    float f(float x);
	float fd(float x);
    printf("Enter the value of x1:");
    scanf("%f",&x1);
    printf("Enter the value of x2:");
    scanf("%f",&x2);


    do {
        f1=f(x1);
        f2=f(x2);
        a=f2*x1;
        b=f1*x2;
        c=(a-b);
        d=f2-f1;
        x3 = c/d;
        f3=f(x3);
        x1=x2;
        f1=f2;
        x2=x3;
        f2=f(x3);


        k++;
        printf("no of iteration = %d\t",k);
        printf("no of root = %f\t",x3);
        printf("value of function = %f\n",f(x3));


    }while(fabs(f(x3-x2))> 0.0001);
    printf("\n root is %f",x3);

    return 0;
}
