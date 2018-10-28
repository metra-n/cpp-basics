#include <iostream> 
#include <cmath> 
#include <iomanip>
#include <string>

using namespace std;

bool IsEqual(double a, double b);

int main()
{
    double xf, xl, dx, eps;
    cout << "X can be [-35;35]\n";
    cout << "Enter X first: ";
    cin >> xf;
    cout << "Enter X last: ";
    cin >> xl;
    cout << "Enter dX: ";
    cin >> dx;
    cout << "Enter Epsilon: ";
    cin >> eps;
    if (dx <= 0.0)
    {
        cout << "\nERROR!!\ndX <= 0";
        return 97;
    }
    if (xf > xl)
    {
        cout << "\nERROR!!\nX first > X last";
        return 98;
    }
    if (eps <= 0)
    {
        cout << "\nERROR!!\nEpsilon <= 0";
        return 99;
    }
    if (xf < -35)
    {
        cout << "\nERROR!!\nX first < 35";
        return 100;
    }
    if (xl > 35)
    {
        cout << "\nERROR!!\nX last > 35";
        return 101;
    }
    cout << string(65, '-') << endl;
    cout << "|      X      | sin(x)/x (cmath) ";
    cout << "| sin(x)/x (mine) | iterations |\n";
    cout << string(65, '-') << endl;
    cout << fixed;
    for (; xf <= xl; xf += dx)
    {
        cout << "|";
        cout << setw(9) << setprecision(3) << xf << "    |";
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
        double sin_math = 1, element = 1;
        const int kMaxIter = 1300;
        for (; abs(element) > eps && iterations < kMaxIter; iterations++)
        {
            element *= -xf * xf / ((2 * iterations + 2)*(2 * iterations + 3));
            sin_math += element;
        }
        cout.width(13);
        if (iterations < kMaxIter)
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