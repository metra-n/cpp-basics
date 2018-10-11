#include<iostream>

using namespace std;

void qsort_my(double* arr, int low, int hi)
{
	int h = hi, l = low;
	double vr, mid = arr[(hi + low) / 2];
	do
	{
		while (arr[l] < mid) l++;
		while (arr[h] > mid) h--;
		if (l <= h)
		{
			vr = arr[l];
			arr[l] = arr[h];
			arr[h] = vr;
			l++;
			h--;
		}
	} while (l < h);
	if (low < h) qsort_my(arr, low, h);
	if (l < hi) qsort_my(arr, l, hi);
}

int main()
{
	int max_addr = 0, n, i = 0, count = 0;
	double c, max = 0, prod = 1;
	double* arr;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter C: ";
	cin >> c;
	arr = new double[n];
	if (!arr)
	{
		cout << "\nERROR!!\n Memory not allocated!";
		return 100;
	}
	for (; i < n; i++)
	{
		cout << "Enter array's value: ";
		cin >> arr[i];
		if (arr[i] > c) count++;
	}
	qsort_my(arr, 0, n - 1);
	//temp
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	//temp
	for (i = 0; i < n; i++)
	{
		if (abs(arr[i]) >= max)
		{
			max = abs(arr[i]);
			max_addr = i;
		}
	}
	if (max_addr + 1 < n)
	{
		for (i = max_addr + 1; i < n; i++)
		{
			prod *= arr[i];
		}
	}
	else
	{
		prod = 0;
	}
	cout << "Count of elements > C: " << count << endl;
	cout << "Product of elements after max of modulus element: " << prod << endl;
	delete[] arr;
	return 0;
}
