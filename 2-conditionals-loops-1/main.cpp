#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char i = 0;
	float Xf, Xl, dX, a, b, c, F;
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
	if (Xf > Xl || dX == 0)
	{
		cout << "ERROR!!";
		return 99;
	}
	expression = ~((int)a | (int)b | (int)c);
	while (expression < 0)
	{
		i++;
		expression = expression << 1;
	}
	expression = expression >> i;
	cout << "---------------------------------------\n";
	cout << "|        X         |         F        |\n";
	cout << "---------------------------------------\n";
	cout.fill(' ');
	cout.precision(3);
	for (; Xf <= Xl; Xf += dX)
	{
		if (Xf < 0 && b != 0)
		{
			F = -a * pow(Xf, 2) + b;
		}
		else if (Xf > 0 && b == 0)
		{
			F = Xf / (Xf - c) + 5.5;
		}
		else
		{
			F = Xf / -c;
		}
		cout << "|";
		cout.width(12);
		cout << fixed << right << Xf;
		cout << "      |";
		cout.width(12);
		if (expression != 0)
		{
			if ((isnan(F)) != 0 || (isinf(F)) != 0)
			{
				cout << " inf or NaN";
			}
			else
			{
				cout << fixed << right << F;
			}
		}
		else
		{
			if ((isnan(F)) != 0 || (isinf(F)) != 0)
			{
				cout << " inf or NaN";
			}
			else
			{
				cout << fixed << right << floor(F);
			}
		}
		cout << "      |\n";
	}
	cout << "---------------------------------------\n";
	return 0;
}