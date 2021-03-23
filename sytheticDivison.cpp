#include<stdio.h>
#include<conio.h>

int main(){

                int poly[6], n, r, i, q[6];
                printf("\t\tSYNTHETIC DIVISION");
                printf("\n Enter the degree of the equation: ");
                scanf("%d",&n);

                for(i=0;i<=n;i++){
                                printf("\n Coefficient x[%d] = ", n-i);
                                scanf("%d",&poly[i]);
                }

                printf("\n Enter the value of constant in (x-r) : ");
                scanf("%d",&r);
                q[0] = poly[0];
                for(i=1;i<=n;i++){
                                q[i] = (q[i-1]*r)+poly[i];
                }

                printf("\n Coefficients of quotient are: \n");
                for(i=0;i<n;i++){
                                printf("\t%d",q[i]);
                }

getch();
return 0;

}
