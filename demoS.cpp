#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const int n = 4; //Number of rows and columns of the file
//Array max
double max_array(double err[n])
{

    double max = err[0];
    for (int i = 1; i < n; i++)
    {
        if (err[i] > max)
        {
            max = err[i];
        }
    }
    return max;
}
//The separation matrix determines D
void arrayD(double a[n][n], double (*D)[n])
{
    for (int i = 0; i < n; i++)
        D[i][i] = a[i][i];
}
//The separation matrix determines the L, -L lower triangular matrix
void arrayL(double a[n][n], double (*L)[n])
{
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            L[i][j] = -a[i][j];
        }
    }
}
//The separation matrix determines the U, -U upper triangular matrix
void arrayU(double a[n][n], double (*U)[n])
{
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            U[i][j] = -a[i][j];
        }
    }
}
//The number of rows stored in the Jacobi x two-dimensional array is the number of x, and the number of columns is the number of iterations up to kmax times
void jacobi(double D[n][n], double L[n][n], double U[n][n], double b[n])
{
    int kmax = 40;
    double x[n][kmax] = {0};
    double err[n] = {0}; //x error
    int k = 1;           //Count the number of iterations
    int i;               //j is the number of x
    for (k; k < kmax; k++)
    {
        cout << "Number of iterations" << k << endl;
        for (i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += (L[i][j] * x[j][k - 1] +
                        U[i][j] * x[j][k - 1]);
            }
            x[i][k] = (1 / D[i][i]) * (sum + b[i]);
            cout << setiosflags(ios::fixed) << setprecision(4) << setiosflags(ios::left);
            cout << setw(15) << x[i][k] << "\t";
            err[i] = fabs(x[i][k] - x[i][k - 1]);
        }
        cout << endl;
        if (max_array(err) < 0.0001)
            break;
    }
    for (int num = 0; num < n; num++)
    {
        cout << setiosflags(ios::fixed) << setprecision(4) << setiosflags(ios::left);
        cout << endl;
        cout << "x[" << num + 1 << "]"
             << "=" << x[num][k] << endl;
    }
}
void sediel(double D[n][n], double L[n][n], double U[n][n], double b[n])
{
    int kmax = 40;
    double x[n][kmax] = {0};
    double err[n] = {0}; //x error
    int k = 1;           //Count the number of iterations
    int i;               //j is the number of x
    for (k; k < kmax; k++)
    {
        cout << "Number of iterations" << k << endl;
        for (i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += (L[i][j] * x[j][k] +
                        U[i][j] * x[j][k - 1]);
            }
            x[i][k] = (1 / D[i][i]) * (sum + b[i]);
            cout << setiosflags(ios::fixed) << setprecision(4) << setiosflags(ios::left);
            cout << setw(15) << x[i][k] << "\t";
            err[i] = fabs(x[i][k] - x[i][k - 1]);
        }
        cout << endl;
        if (max_array(err) < 0.0001)
            break;
    }
    for (int num = 0; num < n; num++)
    {
        cout << setiosflags(ios::fixed) << setprecision(4) << setiosflags(ios::left);
        cout << endl;
        cout << "x[" << num + 1 << "]"
             << "=" << x[num][k] << endl;
    }
}
void sor(double D[n][n], double L[n][n], double U[n][n], double b[n], double w)
{
    int kmax = 40;
    double x[n][kmax] = {0};
    double err[n] = {0}; //x error
    int k = 1;           //Count the number of iterations
    int i;               //j is the number of x
    for (k; k < kmax; k++)
    {
        cout << "Number of iterations" << k << endl;
        for (i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += (L[i][j] * x[j][k] +
                        U[i][j] * x[j][k - 1]);
            }
            x[i][k] = (1 - w) * x[i][k - 1] + (w / D[i][i]) * (sum + b[i]);
            cout << setiosflags(ios::fixed) << setprecision(4) << setiosflags(ios::left);
            cout << setw(15) << x[i][k] << "\t";
            err[i] = fabs(x[i][k] - x[i][k - 1]);
        }
        cout << endl;
        if (max_array(err) < 0.0001)
            break;
    }
    for (int num = 0; num < n; num++)
    {
        cout << setiosflags(ios::fixed) << setprecision(4) << setiosflags(ios::left);
        cout << endl;
        cout << "x[" << num + 1 << "]"
             << "=" << x[num][k] << endl;
    }
}
int main(void)
{

    double a[n][n] = {2, -1, 0, 0, -1, 2.5, -1, 0, 0, -1, 2.5, -1, 0, 0, -1, 2};
    double b[n] = {-4, 4, 4, -4};
    // double a[n][n] = {64, -3, -1, 2, -90, 1, 1, 1, 40};
    // double b[n] = {14, -5, 20};
    // double a[n][n] = {4, 3, 0, 3, 4, -1, 0, -1, 4};
    // double b[n] = {24, 30, -24};
    double D[n][n] = {0};
    double L[n][n] = {0};
    double U[n][n] = {0};
    arrayD(a, D);
    arrayL(a, L);
    arrayU(a, U);
    jacobi(D, L, U, b);
    sediel(D, L, U, b);
    double w = 1.16;
    sor(D, L, U, b, w);
    cin.get();
    return 0;


}
