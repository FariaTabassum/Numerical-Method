#include <iostream>
#include <cmath>
using namespace std;



int fact (int a)
{

    if (a > 1)

        return (a * fact (a-1));

    else

        return (1);

}
double derivative(double x, double y, int z)
{
    //cout<<c<<endl;
    if(z==0)
        return x+y;
    else if(z==1)
        return 1+y;
    else if(z==2 || z==3)
        return y;
}



double pow (int n, int i)

{

    double taylor;

    double sum;

    double value=0;

    for (int x=1; x<=n; x++)

    {

        sum=((pow(n,x))/fact(x));

        value+=sum;

    }

    taylor = 1+value;

    return taylor;

}

int main ()

{
    int i;
    long n;
    cout << "Please type a number: ";
    cin >> n;
    cout << "the taylor aproximation is" <<pow (  n,  i)<<endl;

    return 0;
}
