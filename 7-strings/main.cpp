#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void StrToLow(char* str, unsigned long long length);

int main()
{
	ifstream fin("input.txt", ios_base::ate | ios_base::binary);
	if (!fin)
	{
		cout << "ERROR!!\nCan't open file";
		return 100;
	}
	unsigned long long len = fin.tellg();
	char* str = new char[len];
	fin.seekg(0, ios::beg);
	fin.read(str, len);
	str[len] = '\0';
	StrToLow(str, len);
	char const delims[] = ",.!? \0\r\n";
	char* context = NULL;
	char* word;
	char* max_word = strtok_s(str, delims, &context);
	size_t l_maxword = strlen(max_word);
	while (word = strtok_s(NULL, delims, &context))
	{
		if (strlen(word) > l_maxword)
		{
			l_maxword = strlen(word);
			max_word = word;
		}
	}
	word = max_word;
	max_word = new char[l_maxword + 1];
	for (unsigned int i = 0; i < l_maxword; i++)
		max_word[i] = *(word + i);
	max_word[l_maxword] = '\0';
	fin.seekg(0, ios::beg);
	fin.read(str, len);
	fin.close();
	str[len] = '\0';
	StrToLow(str, len);
	int count = 0;
	char* p = str;
	while (p = strstr(p, max_word))
	{
		p += l_maxword;
		if (ispunct(*p) || isspace(*p) || (*p == '\0'))
			count++;
	}
	cout << "Max word is \"" << max_word << "\"\n";
	cout << "Count: " << count;
	return 0;
}

void StrToLow(char* str, unsigned long long length)
{
	for (unsigned long long i = 0; i < length; i++)
	{
		if (isupper(str[i])) str[i] = tolower(str[i]);
		if (str[i] == '\r' || str[i] == '\n') str[i] = ' ';
	}
}
