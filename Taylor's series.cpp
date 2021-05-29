#include<bits/stdc++.h>
#define ll long long int
using namespace std;
double yp[100];

int fact(int n)
{
    if(n==0)
        return(1);  /Terminating condition/
    else
    {
        return(n*fact(n-1));
    }
}

double derivative(double x, double y, int c)
{
    //cout<<c<<endl;
    if(c==0)
        return x+y;
    else if(c==1)
        return 1+y;
    else if(c==2 || c==3)
        return y;
}


double taylor(double x, double h, double x0, double y0)
{
    int cnt = 1;
    while(x-x0>0.01)
    {
        double y1, x1;
        yp[-1]=y0;
        for(int e=0; e<4; e++)
        {
            yp[e]= derivative(x0,yp[e-1],e);
        }
        y1 = y0;
        for(int u=1; u<=4; u++)
        {
            y1 = y1 + ((pow(h,u))/fact(u)) * yp[u-1];
            //cout<<y1<<endl;
        }
        x1 = x0 + h;
        printf("y%d = y(%.1lf) = %.3lf\n",cnt++,x1,y1);
        //cout<<"y = "<<y1<<"x ="<<x1<<endl;
        y0 = y1; x0 = x1;
    }

}


int main()
{
    double x,h,x0,y0;
    cout<<"The given equation is : dy/dx = x +y\n";
    cout<<"Enter the required value of x : ";
    cin>>x;
    cout<<"Enter the step-size h : ";
    cin>>h;
    cout<<"Enter the x0 : ";
    cin>>x0;
    cout<<"Enter the y0 : ";
    cin>>y0;
    printf("y = y(%.1lf) = %.1lf\n",x0,y0);
    /*double answer = */taylor(x,h,x0,y0);
    //cout<<"\nArea under the limit : "<<answer<<endl;
}
