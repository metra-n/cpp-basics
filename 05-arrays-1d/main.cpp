#include <iostream>

using namespace std;

void SortArray(double* arr, const int n);

int main()
{
    const int n = 10;
    double arr[n] = { 0, -4, 3, -2, -1, 1, -1, 2, 3, -4 };
    cout << "Initial array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    double c;
    cout << "\nEnter C: ";
    cin >> c;

    int count = 0, max_addr = 0;
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > c) count++;
        if (abs(arr[i]) > max)
        {
            max = abs(arr[i]);
            max_addr = i;
        }
    }
    cout << "Number of elements greater than C: " << count << endl;
    if (max_addr + 1 < n)
    {
        double prod = 1;
        for (int i = max_addr + 1; i < n; i++)
            prod *= arr[i];

        cout << "Product of elements located after the absolute maximum element: ";
        cout << prod << endl;
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

void SortArray(double* arr, const int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] >= 0 && arr[j + 1] < 0)
                swap(arr[j], arr[j + 1]);
}
