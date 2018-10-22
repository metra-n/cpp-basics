#include <iostream> 
#include <cmath> 
#include <iomanip>
#include <string>

using namespace std;

struct EndTaylor
{
	int iterations;
	double sin_math;
};

bool IsEqual(double a, double b);
bool HaveError(double dx, double xf, double xl, double eps);
EndTaylor TaylorSeries(double X, double eps, const int kMaxIter);

int main()
{
	double xf, xl, dx, eps;
	cout << "X can be [-30;30]\n";
	cout << "Enter X first: ";
	cin >> xf;
	cout << "Enter X last: ";
	cin >> xl;
	cout << "Enter dx: ";
	cin >> dx;
	cout << "Enter Epsilon: ";
	cin >> eps;
	if (HaveError(dx, xf, xl, eps)) return 100;
	cout << string(71, '-') << endl;
	cout << "|      X      | sin(x)/x (built-in) | sin(x)/x (series)  | iterations |\n";
	cout << string(71, '-') << endl;
	cout << fixed;
	const int kMaxIter = 1300;
	for (; xf <= xl; xf += dx)
	{
		cout << "|";
		cout << setw(10) << setprecision(3) << xf << "   |";
		cout.width(17);
		if (!IsEqual(xf, 0.0))
		{
			double sin_lib = sin(xf) / xf;
			cout << setprecision(6) << sin_lib << "    |";
		}
		else
		{
			cout << " inf or NaN" << "    |      inf or NaN    |      0     |\n";
			continue;
		}
		EndTaylor result = TaylorSeries(xf, eps, kMaxIter);
		cout.width(16);
		if (result.iterations < kMaxIter)
		{
			cout << setprecision(6) << result.sin_math << "    |";
			cout << setw(7) << result.iterations << "     |\n";
		}
		else
		{
			cout << "   Max iterations   |  MAX_ITER  |\n";
			continue;
		}
	}
	cout << string(71, '-');
	return 0;
}

bool IsEqual(double a, double b)
{
	if (abs(a - b) < 1e-15) return 1;
	else return 0;
}

bool HaveError(double dx, double xf, double xl, double eps)
{
	if (dx <= 0.0)
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

EndTaylor TaylorSeries(double X, double eps, const int kMaxIter)
{
	EndTaylor str;
	double element = 1;
	str.iterations = 0;
	str.sin_math = 1;
	for (; abs(element) > eps && str.iterations < kMaxIter; str.iterations++)
	{
		element *= -X * X / ((2 * str.iterations + 2)*(2 * str.iterations + 3));
		str.sin_math += element;
	}
	return str;
}