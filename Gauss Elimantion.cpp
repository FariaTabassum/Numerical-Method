/*gauss elimination method*/
#include<stdio.h>


int main()
{
    float a[10][10],x[10],c,sum=0.0;
    int i,j,k,n;
    printf("Enter the order of matrix:");
    scanf("%d",&n);
    printf("enter the elements of the augmented matrix rowwise\n");
    for(i=1; i<=n; i++)
        {
           for(j=1; j<=(n+1); j++)
           {
               printf("a[%d][%d]:",i,j);
               scanf("%f",&a[i][j]);
           }

        }
    /*
    a11 a12 a13 a14
    a21 a22 a23 a24
    a31 a32 a33 a34
    */
    //To find upper triangular matrix
    for(i=1 ;j<n ;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
                c=a[i][j]/a[j][j];
                for (k=1;k<n+1;k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
            }
            printf("\n");
            printf("for j=%d and i=%d",j,i);
            printf("\n \n");
            for(int x=1 ; x<=n ; x++)
            {
                for(int y=1 ; y<=(n+1); y++)
                {
                    printf("%f\t",a[x][y]);
                }
                printf("\n");
            }

        }

    }
    x[n]=a[n][n+1]/a[n][n];
    /* backward substitution*/
    for(i=n-1;i>=1;i--)
    {
        sum = 0;
        for (j=i+1;j<=n;j++)
        {
            sum = sum + a[i][j]*x[j];
        }
        x[i]=(a[i][n+1]-sum)/a[i][i];
    }
    printf("The value of x,y,z is: \n");
    for(i=1;i<=n;i++)
    {
        printf("\n x%d=%f\t",i,x[i]);
    }
    return 0;

}
