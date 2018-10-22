#include <iostream>

using namespace std;

void SortArray(double* arr, int low, int hi);

int main()
{
	int n;
	double c;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter C: ";
	cin >> c;
	if (n <= 0)
	{
		cout << "\nERROR!!\n N <= 0";
		return 100;
	}
	double* arr = new double[n];
	if (!arr)
	{
		cout << "\nERROR!!\n Memory not allocated!";
		return 101;
	}
	int i = 0, count = 0, max_addr = 0;
	double max = 0;
	for (; i < n; i++)
	{
		cout << "Enter array's value: ";
		cin >> arr[i];
		if (arr[i] > c) count++;
		if (abs(arr[i]) >= max)
		{
			max = abs(arr[i]);
			max_addr = i;
		}
	}
	if (max_addr + 1 < n)
	{
		double prod = 1;
		for (i = max_addr + 1; i < n; i++)
		{
			prod *= arr[i];
		}
		cout << "Product of elements located after the absolute maximum element: ";
		cout << prod << endl;
	}
	else
	{
		cout << "The absolute maximum element is last\n";
	}
	cout << "Number of elements greater than C: " << count << endl;
	SortArray(arr, 0, n - 1);
	cout << "Array's values:\n";
	for (i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
	return 0;
}

void SortArray(double* arr, int low, int hi)
{
	int h = hi, l = low;
	double mid = arr[(hi + low) / 2];
	while (l <= h)
	{
		while (arr[l] < mid) l++;
		while (arr[h] > mid) h--;
		if (l <= h)
		{
			swap(arr[l], arr[h]);
			l++;
			h--;
		}
	}
	if (low < h) SortArray(arr, low, h);
	if (l < hi) SortArray(arr, l, hi);
}
