#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Znak
{
    string name;
    string zodiac;
    int birth_date[3]; // [0] — day, [1] — month, [2] — year
};

bool IsLeap(int year);
void SortArray(Znak* person, const int kNumPeople);
void OutputArray(Znak person);
bool IsValidDate(int* birth_date);
bool IsFirstPersonYounger(int* birth_date_1, int* birth_date_2);

int main()
{
    const int kNumPeople = 8;
    struct Znak person[kNumPeople];
    for (int i = 0; i < kNumPeople; i++)
    {
        cout << "Enter full name (e.g., Ivanov Ivan): ";
        getline(cin, person[i].name);
        cout << "Enter zodiac sign (e.g., Taurus): ";
        cin >> person[i].zodiac;
    date_check:
        cout << "Enter day of birth: ";
        cin >> person[i].birth_date[0];
        cout << "Enter month of birth: ";
        cin >> person[i].birth_date[1];
        cout << "Enter year of birth >= 1000: ";
        cin >> person[i].birth_date[2];
        cout << endl;
        cin.ignore();

        if (!IsValidDate(person[i].birth_date))
        {
            cout << "Invalid date:";
            for (int j = 0; j < 3; j++)
                cout << " " << person[i].birth_date[j];
            cout << ". Try again.\n";
            goto date_check;
        }
    }

    SortArray(person, kNumPeople);
    cout << string(33, '#');
    cout << "\n\nData entered : \n\n";
    for (int i = 0; i < kNumPeople; i++)
    {
        OutputArray(person[i]);
        cout << endl;
    }

    string last_name_to_search;
    cout << string(33, '#');
    cout << "\n\nEnter person's last name to search: ";
    cin >> last_name_to_search;
    bool is_found = false;
    for (int i = 0; i < kNumPeople; i++)
    {
        stringstream full_name(person[i].name);
        string last_name;
        full_name >> last_name;
        if (last_name_to_search == last_name)
        {
            if (!is_found)
            {
                cout << "\nPeople found:\n\n";
                is_found = true;
            }
            OutputArray(person[i]);
            cout << endl;
        }
    }
    if (!is_found) cout << "\nNo people with this last name.\n";
    return 0;
}

bool IsFirstPersonYounger(int* birth_date_1, int* birth_date_2)
{
    // -1 — first person is older than second
    //  0 — equal
    //  1 — younger

    string first_date = to_string(birth_date_1[2] * 10000 +
        birth_date_1[1] * 100 + birth_date_1[0]);
    string second_date = to_string(birth_date_2[2] * 10000 +
        birth_date_2[1] * 100 + birth_date_2[0]);

    return first_date.compare(second_date) == 1;
}

void SortArray(Znak* person, const int kNumPeople)
{
    int i = 0;
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int j = 0; j < kNumPeople - i - 1; j++)
        {
            if (IsFirstPersonYounger(person[j].birth_date, person[j + 1].birth_date))
            {
                swap(person[j], person[j + 1]);
                swapped = true;
            }
        }
        i++;
    }
}

void OutputArray(Znak person)
{
    cout << "Name: " << person.name << endl;
    cout << "Zodiac: " << person.zodiac << endl;
    cout << "Day of birth: " << person.birth_date[0] << endl;
    cout << "Month of birth: " << person.birth_date[1] << endl;
    cout << "Year of birth: " << person.birth_date[2] << endl;
}

bool IsLeap(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

bool IsValidDate(int* birth_date)
{
    int day = birth_date[0];
    int month = birth_date[1];
    int year = birth_date[2];

    // Month and year check.
    if (month >= 1 && month <= 12 && year >= 1000)
    {
        // Days check.
        if (day >= 1 && day <= 31)
        {
            // Check February.
            if (month == 2)
            {
                if (day <= 28)
                    return 1;
                else if (day == 29 && IsLeap(year))
                    return 1;
                else
                    return 0;
            }

            // Check April, June, September and November.
            if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                return day <= 30;
            }

            // For other months.
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
