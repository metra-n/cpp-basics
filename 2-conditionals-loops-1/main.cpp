#include <iostream>
#include <cmath>

using namespace std;

bool IsEqual(double a, double b)
{
	if (abs(a - b) < 1e-15) return 1;
	else return 0;
}

int main()
{
	double Xf, Xl, dX, a, b, c, F;
	int expression;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter X first: ";
	cin >> Xf;
	cout << "Enter X last: ";
	cin >> Xl;
	cout << "Enter dX: ";
	cin >> dX;
	if (dX <= 0)
	{
		cout << "\nERROR!!\ndX < 0";
		return 99;
	}
	else if (Xf > Xl)
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
	for (; Xf <= Xl; Xf += dX)
	{
		cout << "|";
		cout.width(12);
		cout << Xf;
		cout << "      |";
		cout.width(12);
		if (Xf < 0 && !IsEqual(b, 0.0))
		{
			F = -a * pow(Xf, 2) + b;
		}
		else if (Xf > 0 && IsEqual(b, 0.0))
		{
			if (!IsEqual(Xf, c)) F = Xf / (Xf - c) + 5.5;
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
			F = Xf / -c;
		}
		if (expression != 0)
		{
			cout << F;
		}
		else
		{
			cout << static_cast<int>(F);
		}
		cout << "      |\n";
	}
	cout << "---------------------------------------\n";
	return 0;
}
