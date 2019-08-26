#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Simple_String.h"
///////////////////////////////////////////////
using std::cout;
using std::cin;
using std::endl;
///////////////////////////////////////////////
const int ArSize = 10;
const int MaxLen = 81;
///////////////////////////////////////////////
int main()
{
	Simple_String name;
	cout << "Hi, what's your name?\n";
	cin >> name;
	cout << name << ", please enter up to " << ArSize
		<< " short sayings <empty line to quit>:\n";
	Simple_String sayings[ArSize];
	char temp[MaxLen];

	int i;
	for(i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}
		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		cout << "First alphabetically:\n" << sayings[first] << endl;
		cout << "This program used " << Simple_String::HowMany()
			<< " Simple_String objects. Bye.\n";
	}
	else
		cout << "No input! Bye.\n";

	system("pause");
	return 0;
}