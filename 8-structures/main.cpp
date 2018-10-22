#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Znak
{
	string f_name;
	string l_name;
	string zodiak;
	int birth[3];
};

int days_of_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool FirstDateIsHigher(Znak* arr, int index);
bool IsBissextile(int year);
void SortArray(Znak* arr, int len);
void OutputArray(Znak* arr, int index);

int main()
{
	const int len = 8;
	struct Znak arr[len];
	for (int i = 0; i < len; i++)
	{
		cout << "Enter first name: ";
		cin >> arr[i].f_name;
		cout << "Enter last name: ";
		cin >> arr[i].l_name;
		cout << "Enter zodiak sign: ";
		cin >> arr[i].zodiak;
		cout << "Enter day of birth: ";
		cin >> arr[i].birth[0];
		cout << "Enter month of birth: ";
		cin >> arr[i].birth[1];
		cout << "Enter year of birth: ";
		cin >> arr[i].birth[2];
		cout << endl;
		if (arr[i].birth[1] < 1 || arr[i].birth[1] > 12)
		{
			cout << "ERROR!!!\nMonth of birth is incorrect\n";
			return 100;
		}
		if (arr[i].birth[2] < 0)
		{
			cout << "ERROR!!!\nYear of birth is incorrect\n";
			return 100;
		}
		if (arr[i].birth[0] < 1 ||
			arr[i].birth[0] > (days_of_month[arr[i].birth[1] - 1] + IsBissextile(arr[i].birth[2])))
		{
			cout << "ERROR!!!\nDay of birth is incorrect\n";
			return 100;
		}
	}
	SortArray(arr, len);
	cout << "ARRAY's VALUES: \n\n";
	for (int i = 0; i < len; i++)
	{
		OutputArray(arr, i);
		cout << endl;
	}
	string search_human;
	cout << endl << "Enter last name of serchable human: ";
	cin >> search_human;
	bool is_found = false;
	for (int i = 0; i < len; i++)
	{
		if (search_human == arr[i].l_name) is_found = true;
		if (is_found)
		{
			cout << "\nHuman is found!\n";
			OutputArray(arr, i);
			break;
		}
	}
	if (!is_found) cout << "\nArray don't have information about this human.\n";
	return 0;
}

bool FirstDateIsHigher(Znak* arr, int index)
{
	int date1 = 0, date2 = 0;
	for (int i = 0; i <= arr[index].birth[2]; i++)
	{
		date1 += IsBissextile(i) ? 366 : 365;
	}
	for (int j = 0; j < arr[index].birth[1] - 1; j++) date1 += days_of_month[j];
	date1 += arr[index].birth[0];
	for (int i = 0; i <= arr[index + 1].birth[2]; i++)
	{
		date2 += IsBissextile(i) ? 366 : 365;
	}
	for (int j = 0; j < arr[index + 1].birth[1] - 1; j++) date2 += days_of_month[j];
	date2 += arr[index + 1].birth[0];
	return (date1 - date2) > 0 ? 1 : 0;
}

bool IsBissextile(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}

void SortArray(Znak* arr, int len)
{
	int i = 0;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (FirstDateIsHigher(arr, j))
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		i++;
	}
}

void OutputArray(Znak* arr, int index)
{
	cout << "First name: " << arr[index].f_name << endl;
	cout << "Last name: " << arr[index].l_name << endl;
	cout << "Zodiak: " << arr[index].zodiak << endl;
	cout << "Day of birth:" << arr[index].birth[0] << endl;
	cout << "Month of birth:" << arr[index].birth[1] << endl;
	cout << "Year of birth:" << arr[index].birth[2] << endl;
}
