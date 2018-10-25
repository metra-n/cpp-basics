#include "functions.h"

void SortArray(double* arr, const int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] >= 0 && arr[j + 1] < 0)
                std::swap(arr[j], arr[j + 1]);
}

int FindAbsoluteMaxAddr(double* arr, const int n)
{
    int abs_max_addr = 0;
    double abs_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) > abs_max)
        {
            abs_max = abs(arr[i]);
            abs_max_addr = i;
        }
    }

    return abs_max_addr;
}

double MultiplyElements(double* arr, const int n, int abs_max_addr)
{
    double prod = 1;
    for (int i = abs_max_addr + 1; i < n; i++)
        prod *= arr[i];

    return prod;
}

int CountElements(double * arr, double c, const int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > c) count++;
    }
    return count;
}