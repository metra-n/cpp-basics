#include <iostream>
#include <cmath>

using namespace std;

bool IsEqual(double a, double b);

int main()
{
    double xf, xl, dx, a, b, c, f;
    int expression;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter X first: ";
    cin >> xf;
    cout << "Enter X last: ";
    cin >> xl;
    cout << "Enter dX: ";
    cin >> dx;
    if (dx <= 0)
    {
        cout << "\nERROR!!\ndX < 0";
        return 99;
    }
    else if (xf > xl)
    {
        cout << "\nERROR!!\nX first > X last";
        return 99;
    }
    expression = ~(static_cast<int>(a) | static_cast<int>(b) | static_cast<int>(c));
    cout << "---------------------------------------\n";
    cout << "|        X         |         F        |\n";
    cout << "---------------------------------------\n";
    cout.precision(3);
    cout << fixed;
    for (; xf <= xl; xf += dx)
    {
        cout << "|";
        cout.width(12);
        cout << xf;
        cout << "      |";
        cout.width(12);
        if (xf < 0 && !IsEqual(b, 0.0))
        {
            f = -a * pow(xf, 2) + b;
        }
        else if (xf > 0 && IsEqual(b, 0.0))
        {
            if (!IsEqual(xf, c)) f = xf / (xf - c) + 5.5;
            else
            {
                cout << "    inf or NaN";
                cout << "    |\n";
                continue;
            }
        }
        else
        {
            if (IsEqual(c, 0.0))
            {
                cout << "    inf or NaN";
                cout << "    |\n";
                continue;
            }
            f = xf / -c;
        }
        if (expression != 0)
        {
            cout << f;
        }
        else
        {
            cout << static_cast<int>(f);
        }
        cout << "      |\n";
    }
    cout << "---------------------------------------\n";
    return 0;
}

bool IsEqual(double a, double b)
{
    if (abs(a - b) < 1e-15)
        return 1;
    else
        return 0;
}