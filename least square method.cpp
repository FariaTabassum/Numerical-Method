#include<stdio.h>
#include<conio.h>

int main()
{
    int n, i;
    float x[100], y[100], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;

    printf("Enter number of data:\n");
    scanf("%d", &n);
    printf("Enter the value of X and Y:\n");
    printf("Enter the value of X:\n");
    for(i=1; i<=n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter the value of Y:\n");
    for(i=1; i<=n; i++)
    {

        scanf("%f", &y[i]);
    }

    for(i=1; i<=n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i]*x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i]*y[i];
    }
    printf("%f %f",sumX,sumX2);

    b = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
    a = (sumY - b*sumX)/n;

    printf("\n");
    printf("Values are: a=%.4f and b = %.4f\n",a,b);
    printf("So the linear equation becomes: y = %.4f + %.4fx \n",a,b);
    return(0);
}
