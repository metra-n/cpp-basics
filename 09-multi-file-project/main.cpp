#include "functions.h"

int main()
{
    const int n = 10;
    double arr[n] = { 0, -4, 3, -2, -1, 1, -1, 2, 3, -4 };
    cout << "Initial array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    double c;
    cout << "\nEnter C: ";
    cin >> c;

    int count = CountElements(arr, c, n);
    cout << "Number of elements greater than C: " << count << endl;
 
    if (int abs_max_addr = FindAbsoluteMaxAddr(arr, n) + 1 < n)
    {
        cout << "Product of elements located after the absolute maximum element: ";
        cout << MultiplyElements(arr, n, abs_max_addr) << endl;
    }
    else
    {
        cout << "The absolute maximum element is last.\n";
    }

    SortArray(arr, n);
    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
