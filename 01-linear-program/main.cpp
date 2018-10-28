#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double b;
    double z1, z2;
    cout << "Enter b: ";
    cin >> b;
    z1 = sqrt(2 * b + 2 * sqrt(pow(b, 2) - 4)) / (sqrt(pow(b, 2) - 4) + b + 2);
    z2 = 1 / sqrt(b + 2);
    cout << "z1 = " << z1 << "\nz2 = " << z2;
    return 0;
}