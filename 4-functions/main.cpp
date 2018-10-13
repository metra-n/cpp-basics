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

bool isEqual(double a, double b);
bool HaveError(double dX, double Xf, double Xl, double Eps);
EndTaylor TaylorSeries(double X, double Eps, const int kMaxIter);

int main()
{
	EndTaylor result;
	double sin_lib, Xf, Xl, dX, Eps;
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
	if (HaveError(dX, Xf, Xl, Eps)) return 100;
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
		result = TaylorSeries(Xf, Eps, kMaxIter);
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

bool isEqual(double a, double b)
{
	const double kEps = 1e-15;
	if (abs(a - b) < kEps) return 1;
	else return 0;
}

bool HaveError(double dX, double Xf, double Xl, double Eps)
{
	if (dX <= 0.0)
	{
		cout << "\nERROR!!\ndX <= 0";
		return 1;
	}
	if (Xf > Xl)
	{
		cout << "\nERROR!!\nX first > X last";
		return 1;
	}
	if (Eps <= 0)
	{
		cout << "\nERROR!!\nEpsilon <= 0";
		return 1;
	}
	if (Xf < -35)
	{
		cout << "\nERROR!!\nX first < 35";
		return 1;
	}
	if (Xl > 35)
	{
		cout << "\nERROR!!\nX last > 35";
		return 1;
	}
	return 0;
}

EndTaylor TaylorSeries(double X, double Eps, const int kMaxIter)
{
	EndTaylor str;
	double element = 1;
	str.iterations = 0;
	str.sin_math = 1;
	for (; abs(element) > Eps && str.iterations < kMaxIter; str.iterations++)
	{
		element *= -X * X / ((2 * str.iterations + 2)*(2 * str.iterations + 3));
		str.sin_math += element;
	}
	return str;
}