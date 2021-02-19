#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.00001
#define f(x) x*x*x-x-1
int main()
{
    float x0,x1,x2,f0,f1,f2;
    int i=0;
    printf("Enter the value of x1:");
    scanf("%f",&x1);
    printf("Enter the value of x2 :");
    scanf("%f",&x2);
    do{
        f1=f(x1);
        f2=f(x2);
        x0=(x1+x2)/2;
        f0=f(x0);
        if(f1*f0 == 0)
            break;
        else if(f1*f0<0)
        {
            x2=x0;
        }
        else {
            x1=x0;
        }
        i++;
        printf("no of iteration = %d\t",i);
        printf("no of root = %f\t",x0);
        printf("value of function = %f\n",f0);
    }while(fabs(f(x0))>e);
    printf("Approximate Root is %4.6f and no. of iteration is %d",x0,i);
    return 0;

}
