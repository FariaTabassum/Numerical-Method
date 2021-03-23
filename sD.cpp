#include <stdio.h>

int main()
{

     int n,i,a[10],b[10],x;

     printf("\nEnter degree of the polynomial X :: ");
     scanf("%d",&n);
     printf("\nEnter coefficient's of the polynomial X :: \n");
     for(i=0;i<=n;i++)
     {
            printf("\nEnter Coefficient of [ X^%d ] :: ",n-i);
            scanf("%d",&a[i]);
     }

     printf("\nEnter the value of X :: ");
     scanf("%d",&x);
     b[0]= a[0];
     for(i=1;i<=n;i++){
            b[i] = (b[i-1]*x)+a[i];
                }

     printf("\n New Coefficients of quotient are: \n");
     for(i=0;i<n;i++){
            printf("\t%d",b[i]);
                }


return 0;

}
