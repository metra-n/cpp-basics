#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin)
    {
        cout << "\nERROR!!\nCan't open file: input.txt";
        return 99;
    }

    int num_rows, num_cols;
    fin >> num_rows;
    fin >> num_cols;

    if (num_rows <= 0)
    {
        cout << "\nERROR!!\nNumber of rows <= 0";
        return 100;
    }
    if (num_cols <= 0)
    {
        cout << "\nERROR!!\nNumber of columns <= 0";
        return 101;
    }

    int** matrix = new int*[num_rows];
    if (!matrix)
    {
        cout << "\nERROR!!\nMemory for rows is not allocated!";
        return 102;
    }
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new int[num_cols];
        if (!matrix[i])
        {
            cout << "\nERROR!!\nMemory for columns is not allocated!";
            return 103;
        }
    }

    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];

    fin.close();

    for (int j = 0; j < num_cols; j++)
    {
        bool have_null = 0;
        for (int i = 0; i < num_rows; i++)
        {
            if (matrix[i][j] == 0)
            {
                have_null = 1;
                break;
            }
        }
        if (have_null)
        {
            cout << "The first column containing at least one zero element is ";
            cout << j + 1 << endl;
            break;
        }
        else if (j == num_cols - 1)
        {
            cout << "Matrix doesn't have columns containing ";
            cout << "at least one zero element.\n";
        }
    }

    long long* arr_spec = new long long[num_rows];
    if (!arr_spec)
    {
        cout << "\nERROR!!\nMemory for array with specifications is not allocated!";
        return 104;
    }
    for (int i = 0; i < num_rows; i++)
    {
        arr_spec[i] = 0;
        for (int j = 0; j < num_cols; j++)
            if (matrix[i][j] < 0 && matrix[i][j] % 2 == 0)
                arr_spec[i] += matrix[i][j];
    }
    //Print matrix with specifications
    cout << "\nMatrix:" << string(5 * num_cols - 4, ' ');
    cout << "|Specifications:\n";
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
            cout << setw(4) << matrix[i][j] << " ";
        cout << "   |" << setw(4) << arr_spec[i];
        cout << endl;
    }
    cout << endl;

    //Ordering matrix
    for (int i = 0; i < num_rows - 1; i++)
    {
        int n_max = i;
        for (int j = i + 1; j < num_rows; j++)
            if (arr_spec[j] > arr_spec[n_max])
                n_max = j;

        swap(arr_spec[i], arr_spec[n_max]);
        swap(matrix[i], matrix[n_max]);
    }

    cout << "Matrix after ordering:\n";
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
            cout << setw(4) << matrix[i][j] << " ";
        cout << endl;
    }

    delete[] arr_spec;
    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}
