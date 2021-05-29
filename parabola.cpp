#include<stdio.h>
#include<conio.h>

int main()
{
    int n, i,j,k;
    float x[100], y[100], sumX=0, sumX2=0, sumX3=0,sumX4=0,sumY=0, sumXY=0,sumX2Y=0, a[10],m[3][4],c;

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
        sumX3 = sumX3 + x[i]*x[i]*x[i];
        sumX4 = sumX4 + x[i]*x[i]*x[i]*x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i]*y[i];
        sumX2Y = sumX2Y + x[i]*x[i]*y[i];
    }
    m[1][1] = n;
    m[1][2] = sumX;
    m[1][3] = sumX2;
    m[1][4] = sumY;
    m[2][1] = sumX;
    m[2][2] = sumX2;
    m[2][3] = sumX3;
    m[2][4] = sumXY;
    m[3][1] = sumX2;
    m[3][2] = sumX3;
    m[3][3] = sumX4;
    m[3][4] = sumX2Y;
    for(j=1 ;j<=n ;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
                c=m[i][j]/m[j][j];
                for (k=1;k<3;k++)
                {
                    m[i][k]=m[i][k]-c*m[j][k];
                }
            }
            printf("\n");


        }

    }
    a[n]=m[n][n]/m[n][n];
     for(i=1;i<=n;i++)
    {
        int sum = 0;
        for (j=i;j<n;j++)
        {
            sum = sum + m[i][j]*a[j];
        }
        a[i]=(m[i][4]-sum)/m[i][i];
    }
    printf("The value of a1,a2,a3 is: \n");
    for(i=1;i<n;i++)
    {
        printf("\n a%d=%f\t",i,a[i]);

    }

    return 0;

}

