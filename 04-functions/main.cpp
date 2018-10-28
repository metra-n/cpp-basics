#include <iostream> 
#include <cmath> 
#include <iomanip>
#include <string>

using namespace std;

bool IsEqual(double a, double b);
bool HaveError(double dx, double xf, double xl, double eps);
double ComputeTaylorSeries(double X, double eps, const int kMaxIter, int& iterations);

int main()
{
    double xf, xl, dx, eps;
    cout << "X can be [-30, 30]\n";
    cout << "Enter X first: ";
    cin >> xf;
    cout << "Enter X last > X first: ";
    cin >> xl;
    cout << "Enter dX > 0: ";
    cin >> dx;
    cout << "Enter Epsilon > 0: ";
    cin >> eps;
    if (HaveError(dx, xf, xl, eps)) return 100;

    cout << string(65, '-') << endl;
    cout << "|      X      | sin(x)/x (cmath) ";
    cout << "| sin(x)/x (mine) | iterations |\n";
    cout << string(65, '-') << endl;
    cout << fixed;

    const int kMaxIter = 1300;
    for (; xf <= xl; xf += dx)
    {
        cout << "|" << setw(9) << setprecision(3) << xf << "    |";
        cout.width(13);
        if (!IsEqual(xf, 0.0))
        {
            double sin_lib = sin(xf) / xf;
            cout << setprecision(6) << sin_lib << "     |";
        }
        else
        {
            cout << "    inf or NaN" << "    |   inf or NaN    |      0     |\n";
            continue;
        }
        int iterations = 0;
        double sin_math = ComputeTaylorSeries(xf, eps, kMaxIter, iterations);
        cout.width(13);
        if (iterations <= kMaxIter)
        {
            cout << setprecision(6) << sin_math << "    |";
            cout << setw(7) << iterations << "     |\n";
        }
        else
        {
            cout << " max iterations  |  MAX_ITER  |\n";
            continue;
        }
    }
    cout << string(65, '-');
    return 0;
}

bool IsEqual(double a, double b)
{
    if (abs(a - b) < 1e-15)
        return 1;
    else
        return 0;
}

bool HaveError(double dx, double xf, double xl, double eps)
{
    if (dx <= 0)
    {
        cout << "\nERROR!!\ndX <= 0";
        return 1;
    }
    if (xf > xl)
    {
        cout << "\nERROR!!\nX first > X last";
        return 1;
    }
    if (eps <= 0)
    {
        cout << "\nERROR!!\nEpsilon <= 0";
        return 1;
    }
    if (xf < -30)
    {
        cout << "\nERROR!!\nX first < 30";
        return 1;
    }
    if (xl > 30)
    {
        cout << "\nERROR!!\nX last > 30";
        return 1;
    }
    return 0;
}

double ComputeTaylorSeries(double X, double eps, const int kMaxIter, int& iterations)
{
    double sin = 1;
    double element = 1;
    for (; abs(element) > eps && iterations <= kMaxIter; iterations++)
    {
        element *= -X * X / ((2 * iterations + 2)*(2 * iterations + 3));
        sin += element;
    }
    return sin;
}