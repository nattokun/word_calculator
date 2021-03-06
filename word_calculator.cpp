# include<iostream>
#include <string>
#include <math.h> 

using namespace std;

string numbers_words_singledigit[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
int numbers_singledigit[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
string numbers_words_teendigit[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eightteen", "nineteen" };
int numbers_teendigit[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
string numbers_words_doubledigit[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
int numbers_doubledigit[8] = { 20, 30, 40, 50, 60, 70, 80, 90 };
string numbers_word_multidigit[] = { "hundred", "thousand", "million", "billion" };
int numbers_multidigit[] = {100, 1000, 1000000, 1000000000};

int convertNumber(string word_number);
int convertDigit(string word);
string convertNumber(int num);

int main() {
	string firstNumber;
	string secondNumber;
	int firstNumConverted, secondNumberConverted;
	int mathType;
	int result;
	string finalProduct;

	cout << "Enter first number: ";
	getline(cin, firstNumber);
	firstNumConverted = convertNumber(firstNumber);
	cout << " 1 for +, 2 for -, 3 for *, 4 for /" << endl;
	cin >> mathType;
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "Enter second number: ";
	getline(cin, secondNumber);
	secondNumberConverted = convertNumber(secondNumber);

	if (mathType == 1)
	{
		result = firstNumConverted + secondNumberConverted;
		finalProduct = convertNumber(result);
		cout << firstNumber << " Plus " << secondNumber << " equals " << finalProduct << endl;
	}
	else if (mathType == 2)
	{
		result = firstNumConverted - secondNumberConverted;
		finalProduct = convertNumber(result);
		cout << firstNumber << " minus " << secondNumber << " equals " << finalProduct << endl;
	}
	else if (mathType == 3)
	{
		result = firstNumConverted * secondNumberConverted;
		finalProduct = convertNumber(result);
		cout << firstNumber << " times " << secondNumber << " equals " << finalProduct << endl;
	}
	else if (mathType == 4)
	{
		result = firstNumConverted / secondNumberConverted;
		finalProduct = convertNumber(result);
		cout << firstNumber << " divided by " << secondNumber << " equals " << finalProduct << endl;
	}
	return 0;
}

int convertNumber(string word_number) {

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		int convertedDigit = convertDigit(word_number);
	}
	return result;
}

int convertDigit(string word) {
	int result = 0;
	int foundDigit = 0;
	int location = 0;
	bool checkedSingle = false;
	bool checkedTeen = false;
	bool checkedDouble = false;
	bool checkedMulti = false;

	// 1 = single 10 = teen 11 = double 111 = multi 0 = no results

	for (int i = 0; i < 11; i++)
	{
		
		if (word == numbers_words_singledigit[i])
		{
			location = i;
			foundDigit = 1;
		}
		checkedSingle = true;
	}

	if (foundDigit == 0 && checkedSingle == true)
	{
		for (int i = 0; i < sizeof(numbers_words_teendigit); i++)
		{
			if (word == numbers_words_teendigit[i])
			{
				location = i;
				foundDigit = 10;
			}
		}
		checkedTeen = true;
	}

	if (foundDigit == 0 && checkedTeen == true)
	{
		for (int i = 0; i < sizeof(numbers_words_doubledigit); i++)
		{
			if (word == numbers_words_doubledigit[i])
			{
				location = i;
				foundDigit = 11;
			}
		}
		checkedDouble = true;
	}

	if (foundDigit == 0 && checkedDouble == true)
	{
		for (int i = 0; i < sizeof(numbers_word_multidigit); i++)
		{
			if (word == numbers_word_multidigit[i])
			{
				location = i;
				foundDigit = 111;
			}
		}
		checkedMulti = true;
	}

	if (foundDigit == 1)
		return numbers_singledigit[location];
	if (foundDigit == 10)
		return numbers_teendigit[location];
	if (foundDigit == 11)
		return numbers_doubledigit[location];
	if (foundDigit == 111)
		return numbers_multidigit[location];
	else
		return 0;
}

string convertNumber(int num) {
	string finalWord;
	int number[12];
	string digitWord[12];
	string digitValue;
	int lengthCount = 0;
	for (int num = 0; num /= 10;  lengthCount++);

	for (int i = 0; i < lengthCount; i++)
	{
		number[12 - i] = num - (num / pow(10, i + 1));
	}

	if (num <= 19)
	{
		if (num == 10)
			finalWord = "ten";
		else if (num >= 11 && num <= 19)
			finalWord = numbers_words_singledigit[num - 11];
		else
			finalWord = numbers_words_singledigit[num - 1];
		
	}

	else
	{
		for (int j = 0; j < sizeof(number); j++)
		{
			string currentWord;
			if (number[j] == 0)
				continue;
			else if (number[j] != 0)
				digitWord[j] = numbers_words_singledigit[number[j] - 1];
			else
				digitWord[j] = "";
		}
		for (int k = 0; k < sizeof(digitWord); k++)
		{
			if (digitWord[k] == "" && finalWord.empty())
				continue;

			else
			{
				if (k == 0 || k == 3 || k == 6 || k == 9)
					digitWord[k] = digitWord[k] + " hundred";
				if (k == 1 || k == 4 || k == 7 || k == 10)
				{
					if (digitWord[k] == "one")
						digitWord[k] = "ten";
					else {
						int convertedNum = convertDigit(digitWord[k]);
						digitWord[k] = numbers_words_doubledigit[convertedNum - 1];
					}
				}
				if (k == 2 && digitWord[k] != "")
					digitWord[k] += "billion";
				if (k == 5 && digitWord[k] != "")
					digitWord[k] += "million";
				if (k == 8 && digitWord[k] != "")
					digitWord[k] += "thousand";
				finalWord += digitWord[k];
			}
		}
	}
	return finalWord;
}
