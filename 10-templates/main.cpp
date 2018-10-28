#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib> //exit()

using namespace std;

template <class T>
void Execute(int num_rows, int num_cols, ifstream& fin);

int main()
{
    setlocale(LC_ALL, "");// for em dash "—"
    ifstream fin("input.txt");
    if (!fin)
    {
        cout << "\nERROR!!\nCan't open file: input.txt";
        return 99;
    }

    int num_rows;
    fin >> num_rows;
    int num_cols;
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

    string option;
selection:
    cout << "Select the data type (0 — integer, 1 — double, 2 — float): ";
    cin >> option;
    if (option == "0")
    {
        Execute<int>(num_rows, num_cols, fin);
    }
    else if (option == "1")
    {
        Execute<double>(num_rows, num_cols, fin);
    }
    else if (option == "2")
    {
        Execute<float>(num_rows, num_cols, fin);
    }
    else
    {
        cout << "Wrong input!\n\n";
        goto selection;
    }

    return 0;
}

template <class T>
bool IsEqual(T a, int b)
{
    if (abs(a - b) < 1e-15)
        return 1;
    else
        return 0;
}

template <class T>
bool IsEven(T number)
{
    if (IsEqual(fmod(number, 2), 0))
        return 1;
    else
        return 0;
}

template <class T>
void OrderMatrix(T** matrix, T* arr_spec, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows - 1; i++)
    {
        int n_max = i;
        for (int j = i + 1; j < num_rows; j++)
            if (arr_spec[j] > arr_spec[n_max])
                n_max = j;

        swap(arr_spec[i], arr_spec[n_max]);
        swap(matrix[i], matrix[n_max]);
    }
}

template <class T>
void PrintMatrix(T** matrix, T* arr_spec, int num_rows, int num_cols)
{
    streamsize print_precision = cout.precision();
    cout.precision(4);
    cout << "\nMatrix:" << string(7 * num_cols, ' ');
    cout << "|Specifications:\n";
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
            cout << setw(7) << matrix[i][j] << " ";
        cout << "   |" << setw(4) << arr_spec[i] << endl;
    }
    cout << endl;
    cout.precision(print_precision);
}

template <class T>
T* ComputeSpecificators(T** matrix, int num_rows, int num_cols)
{
    T* arr_spec = new T[num_rows];
    if (!arr_spec)
    {
        cout << "\nERROR!!\nMemory for array with specifications is not allocated!";
        exit(104);
    }
    for (int i = 0; i < num_rows; i++)
    {
        arr_spec[i] = 0;
        for (int j = 0; j < num_cols; j++)
            if (matrix[i][j] < 0 && IsEven(matrix[i][j]))
                arr_spec[i] += matrix[i][j];
    }
    return arr_spec;
}

template <class T>
int FindColumnWithZero(T** matrix, int num_rows, int num_cols)
{
    bool have_null = 0;
    for (int j = 0; j < num_cols; j++)
    {
        for (int i = 0; i < num_rows; i++)
        {
            if (IsEqual(matrix[i][j], 0))
            {
                have_null = 1;
                break;
            }
        }
        if (have_null) return j;
    }
    return -1;
}

template <class T>
void ReadArray(T** matrix, ifstream& file, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            file >> matrix[i][j];
    file.close();
}

template <class T>
T** AllocateMemory(int num_rows, int num_cols)
{
    T** matrix = new T*[num_rows];
    if (!matrix)
    {
        cout << "\nERROR!!\n Memory for rows is not allocated!";
        exit(102);
    }
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new T[num_cols];
        if (!matrix[i])
        {
            cout << "\nERROR!!\n Memory for columns is not allocated!";
            exit(103);
        }
    }
    return matrix;
}

template <class T>
void DeleteAllocatedMemory(T** matrix, T* arr_spec, int num_rows)
{
    delete[] arr_spec;
    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;
}

template <class T>
void Execute(int num_rows, int num_cols, ifstream& fin)
{
    T** matrix = AllocateMemory<T>(num_rows, num_cols);
    ReadArray(matrix, fin, num_rows, num_cols);

    int column_with_zero = FindColumnWithZero(matrix, num_rows, num_cols);
    if (column_with_zero != -1)
    {
        cout << "\nThe first column containing at least one zero element is ";
        cout << column_with_zero + 1 << endl;
    }
    else
    {
        cout << "\nMatrix doesn't have columns containing zero.\n";
    }

    T* arr_spec = ComputeSpecificators(matrix, num_rows, num_cols);
    PrintMatrix(matrix, arr_spec, num_rows, num_cols);
    OrderMatrix(matrix, arr_spec, num_rows, num_cols);
    cout << "After ordering:\n";
    PrintMatrix(matrix, arr_spec, num_rows, num_cols);
    DeleteAllocatedMemory(matrix, arr_spec, num_rows);
}