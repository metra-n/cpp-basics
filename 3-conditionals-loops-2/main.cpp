#include <iostream> 
#include <cmath> 
#include <iomanip>
#include <string>

using namespace std;

bool isEqual(double a, double b)
{
	const double kEps = 1e-15;
	if (abs(a - b) < kEps) return 1;
	else return 0;
}

int main()
{
	double sin_lib, sin_math, Xf, Xl, dX, Eps, element;
	int iterations;
	const int kMaxIter = 1300;
	cout << "X can be [-35;35]\n";
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
		cout << "\nERROR!!\ndX <= 0";
		return 97;
	}
	if (Xf > Xl)
	{
		cout << "\nERROR!!\nX first > X last";
		return 98;
	}
	if (Eps <= 0)
	{
		cout << "\nERROR!!\nEpsilon <= 0";
		return 99;
	}
	if (Xf < -35)
	{
		cout << "\nERROR!!\nX first < 35";
		return 100;
	}
	if (Xl > 35)
	{
		cout << "\nERROR!!\nX last > 35";
		return 101;
	}
	cout << string(71, '-') << endl;
	cout << "|      X      | sin(x)/x (built-in) | sin(x)/x (series)  | iterations |\n";
	cout << string(71, '-') << endl;
	cout << fixed;
	for (; Xf <= Xl; Xf += dX)
	{
		cout << "|";
		cout << setw(10) << setprecision(3) << Xf << "   |";
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
		iterations = 0;
		for (; abs(element) > Eps && iterations < kMaxIter; iterations++)
		{
			element *= -Xf * Xf / ((2 * iterations + 2)*(2 * iterations + 3));
			sin_math += element;
		}
		cout.width(16);
		if (iterations < kMaxIter)
		{
			cout << setprecision(6) << sin_math << "    |";
		}
		else
		{
			cout << "   Max iterations   |  MAX_ITER  |\n";
			continue;
		}
		cout << setw(7) << iterations << "     |\n";
	}
	cout << string(71, '-');
	return 0;
}