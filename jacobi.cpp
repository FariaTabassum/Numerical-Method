##include<stdio.h>
#include<math.h>
#define e 0.0001
#define x(x,y,z)(12-2*y-z)/5
#define y(x,y,z)(15-x-2*z)/4
#define z(x,y,z)(20-x-2*y)/5


int main()
{
    float x0=0, y0=0, z0=0, x1, y1, z1,f1,f2,f3;
    int i=1;
    printf("\nIteration\tx\ty\tz\n");
    do
    {

        x1 = x(x0,y0,z0);
        y1 = y(x1,y0,z0);
        z1 = z(x1,y1,z0);
        printf("%d\t% f\t% f\t% f\n",i, x1,y1,z1);

        f1 = fabs(x0-x1);
        f2 = fabs(y0-y1);
        f3 = fabs(z0-z1);

        i++;

        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;
    }
    while(f1>e && f2>e && f3>e);

    printf("\nSolution: x=%f, y=%f and z = %f\n",x1,y1,z1);


    return 0;
}
