#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	if (!fin)
	{
		cout << "ERROR! Can't open file: input.txt!\n";
		return 100;
	}

	string word;
	string longest_word;
	int longest_word_len = 0;
	int longest_word_occurrences;
	while (fin >> word)
	{
		transform(word.begin(), word.end(), word.begin(), tolower);

		int word_length = word.length();
		char word_ending = word[word_length - 1];
		if (word_ending == '.' || word_ending == ',' ||
			word_ending == '!' || word_ending == '?')
		{
			word = word.substr(0, word_length - 1);
			word_length--;
		}

		if (word_length > longest_word_len)
		{
			longest_word = word;
			longest_word_occurrences = 0;
			longest_word_len = word_length;
		}

		if (word == longest_word)
			longest_word_occurrences++;
	}

	if (longest_word != "")
	{
		cout << "The longest word is \"" << longest_word << "\".\n";
		cout << "Number of occurrences: " << longest_word_occurrences << ".\n";
	}
	else
	{
		cout << "ERROR! Empty file: input.txt!\n";
	}

	fin.close();
	return 0;
}