#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void SwapRows(int n_col, int* first_row, int* second_row);

int main()
{
	bool file = 0;
	cout << "Choose input method:\nEnter 0 for console input or 1 for file input\n";
	cin >> file;
	int n_rows, n_col;
	ifstream fin("input.txt");
	if (file)
	{
		if (!fin)
		{
			cout << "\nERROR!!\n Can't open file";
			return 99;
		}
		fin >> n_rows;
		fin >> n_col;
	}
	else
	{
		cout << "Enter number of rows: ";
		cin >> n_rows;
		cout << "Enter number of columns: ";
		cin >> n_col;
	}
	if (n_rows <= 0)
	{
		cout << "\nERROR!!\n Number of rows <= 0";
		return 100;
	}
	if (n_col <= 0)
	{
		cout << "\nERROR!!\n Number of columns <= 0";
		return 101;
	}
	int** matrix = new int*[n_rows];
	if (!matrix)
	{
		cout << "\nERROR!!\n Memory for rows not allocated!";
		return 102;
	}
	for (int i = 0; i < n_rows; i++)
	{
		matrix[i] = new int[n_col];
		if (!matrix[i])
		{
			cout << "\nERROR!!\n Memmory for columns not allocated!";
			return 103;
		}
	}
	if (file)
	{
		for (int i = 0; i < n_rows; i++)
		{
			for (int j = 0; j < n_col; j++)
				fin >> matrix[i][j];
		}
	}
	else
	{
		for (int i = 0; i < n_rows; i++)
		{
			for (int j = 0; j < n_col; j++)
			{
				cout << "Enter matrix value in " << i + 1 << " row ";
				cout << j + 1 << " column: ";
				cin >> matrix[i][j];
			}
		}
	}
	fin.close();
	for (int j = 0; j < n_col; j++)
	{
		bool have_null = 0;
		int null_col;
		for (int i = 0; i < n_rows; i++)
		{
			if (matrix[i][j] == 0)
			{
				have_null = 1;
				null_col = j;
			}
		}
		if (have_null)
		{
			cout << "\nThe number of the first column containing at least one zero element is ";
			cout << null_col + 1 << endl;
			break;
		}
		else if (j == n_col - 1)
			cout << "\nMatrix haven't columns containing at least one zero element" << endl;
	}
	long* arr_spec = new long[n_rows];
	if (!arr_spec)
	{
		cout << "\nERROR!!\n Memmory for array with specifications not allocated!";
		return 104;
	}
	for (int i = 0; i < n_rows; i++)
	{
		arr_spec[i] = 0;
		for (int j = 0; j < n_col; j++)
			if (matrix[i][j] < 0 && matrix[i][j] % 2 == 0) arr_spec[i] += matrix[i][j];
	}
	//Output matrix with specifications on console
	cout << "\nMatrix:" << string(5 * n_col - 4, ' ');
	cout << "|Specifications:\n";
	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < n_col; j++)
			cout << setw(4) << matrix[i][j] << " ";
		cout << "   |" << setw(4) << arr_spec[i];
		cout << endl;
	}
	cout << endl;
	//Ordering matrix
	for (int i = 0; i < n_rows - 1; i++)
	{
		int n_max = i;
		for (int j = i + 1; j < n_rows; j++)
			if (arr_spec[j] > arr_spec[n_max])n_max = j;
		swap(arr_spec[i], arr_spec[n_max]);
		SwapRows(n_col, matrix[i], matrix[n_max]);
	}
	cout << "Matrix after ordering:\n";
	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < n_col; j++)
			cout << setw(4) << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	delete[] arr_spec;
	for (int i = 0; i < n_rows; i++) delete[] matrix[i];
	delete[] matrix;
	return 0;
}

void SwapRows(int n_col, int* first_row, int* second_row)
{
	for (int i = 0; i < n_col; i++)	swap(first_row[i], second_row[i]);
}
