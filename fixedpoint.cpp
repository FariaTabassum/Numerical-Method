#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define e 0.0001
#define f(x) x*x+x-2
#define g(x) 2-x*x


int main()
{
	int k=0; //counts number of iterations
	float x1,x0; //initial guess


	printf("\nEnter the initial guess x0: ");
	scanf("%f",&x0);
	//if x0=initial guess to a root,then next approximation
	x1=x0;

	do
	{
		k++;
		x0=x1;
		x1=g(x0);//x[i+1]=g(x[i]);
		printf("no of iteration = %d\t",k);
        printf("no of root = %f\t\n",x1);
	}while(fabs(x1-x0)>e);

	printf("One root is %f obtained at %d th iteration ",x1,k);
}
