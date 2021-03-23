/*gauss elimination method*/
#include<stdio.h>
#define N 3
int main()
{
    float a[N][N+1],x[N],t,s;
    int i,j,k;
    printf("Enter the elements of the  matrix row-wise\n");
    for(i=0; i<N; i++)
        for(j=0; j<N+1; j++)
            scanf("%f",&a[i][j]);
    /*find the upper triangular matrix*/
    for(j=0; j<N-1; j++)
        for(i=j+1; i<N; i++)
        {
            t=a[i][j]/a[j][j];
            for(k=0; k<N+1; k++)
                a[i][k]-=a[j][k]*t;
            printf("\n");
            printf("for j=%d and i=%d",j,i);
            printf("\n \n");
            for(int x=0 ; x<N ; x++)
            {
                for(int y=0 ; y<(N+1); y++)
                {
                    printf("%f\t",a[x][y]);
                }
                printf("\n");
            }
        }
    printf("The upper triangular matrix is \n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N+1; j++)
            printf("%f",a[i][j]);
        printf("\n");
    }
    /* backward substitution*/
    for(i=N-1; i>=0; i--)
    {
        s=0;
        for(j=i+1; j<N; j++)
            s+=a[i][j]*x[j];
        x[i]=(a[i][j]-s)/a[i][i];

    }
    /*now printing the result*/
    printf("The value of x1,x2 and x3 is \n");
    for(i=0; i<N; i++)
        printf("x[%d]=%f\n",i+1,x[i]);
    return 0;
}
