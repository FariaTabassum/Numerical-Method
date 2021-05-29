#include<stdio.h>
#include<conio.h>

int main()
{
    int n, i,j,k;
    float x[100], y[100], sumX=0, sumX2=0, sumX3=0,sumX4=0,sumY=0, sumXY=0,sumX2Y=0, a,m[3][4],c;

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
    m[0][0] = n;
    m[0][1] = sumX;
    m[0][2] = sumX2;
    m[0][3] = sumY;
    m[1][0] = sumX;
    m[1][1] = sumX2;
    m[1][2] = sumX3;
    m[1][3] = sumXY;
    m[2][0] = sumX2;
    m[2][1] = sumX3;
    m[2][2] = sumX4;
    m[2][3] = sumX2Y;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(i!=j)
            {
                c = m[j][i]/m[i][i];
                for(k = 0; k < 4; k++)
                {
                    m[j][k] = m[j][k] - c * m[i][k];
                }
            }
        }
    }
    for(i = 0; i < 3; i++){
        a = m[i][i];
        for(j = 0; j < 4; j++){
            m[i][j] /= a;
        }
    }
    printf("The value of a0,a1,a2 is: \n");
    for(i=0;i<3;i++)
    {
        printf("\n a%d=%f\t",i,m[i][3]);

    }

    return 0;

}

