#include<iostream> 
#include<cmath> 
#include<iomanip>

using namespace std;

int isEqual(double a, double b)
{
	const double kEps = 1e-15;
	if (abs(a - b) < kEps)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	double sin_lib, sin_math, Xf, Xl, dX, Eps, element;
	int iterations;
	const int MAX_ITER = 65;
	cout << "Enter X first: ";
	cin >> Xf;
	cout << "Enter X last: ";
	cin >> Xl;
	cout << "Enter dX: ";
	cin >> dX;
	cout << "Enter Epsilon: ";
	cin >> Eps;
	if (dX <= 0.0)
	{
		cout << "\nERROR!!\ndX < 0";
		return 97;
	}
	else if (Xf > Xl)
	{
		cout << "\nERROR!!\nX first > X last";
		return 98;
	}
	else if (Eps < 0)
	{
		cout << "\nERROR!!\nEpsilon < 0";
		return 99;
	}
	cout << "-----------------------------------------------------------------------\n";
	cout << "|      X      |  sin(x) (built-in)  |  sin(x) (series)   | iterations |\n";
	cout << "-----------------------------------------------------------------------\n";
	cout << fixed;
	for (; Xf <= Xl; Xf += dX)
	{
		cout << "|";
		cout.width(10);
		cout << setprecision(3) << Xf << "   |";
		cout.width(17);
		if (!isEqual(Xf, 0.0))
		{
			sin_lib = sin(Xf) / Xf;
			cout << setprecision(6) << sin_lib << "    |";
		}
		else
		{
			cout << " inf or NaN" << "    |      inf or NaN    |      0     |\n";
			continue;
		}
		element = 1;
		sin_math = 1;
		for (iterations = 0; abs(element) > Eps && iterations < MAX_ITER; iterations++)
		{
			element *= -Xf * Xf / ((2 * iterations + 2)*(2 * iterations + 3));
			sin_math += element;
		}
		cout.width(16);
		if (iterations < MAX_ITER)
		{
			cout << setprecision(6) << sin_math << "    |";
		}
		else
		{
			cout << " series diverges    |  MAX_ITER  |\n";
			continue;
		}
		cout.width(7);
		cout << iterations << "     |\n";
	}
	cout << "-----------------------------------------------------------------------\n";
	return 0;
}