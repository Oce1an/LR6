#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
	const int maxlength = 81;
	char ch;
	int l = 0;

	char* string = new char[maxlength];
	char* floatNum = new char[maxlength];

	cout << "Input string:\n";
	while ((ch = getchar()) != '\n' && l < maxlength - 1)
	{
		string[l] = ch;
		l++;
	}
	string[l] = '\0';

	int count = 0;
	int dotCount = 0;

	for (int i = 0; i < l; i++)
	{
		if (isdigit(string[i]))
		{
			floatNum[count] = string[i];
			count++;
		}
		else if (string[i] == '.' && dotCount == 0)
		{
			floatNum[count] = string[i];
			count++;
			dotCount++;
		}
	}
	floatNum[count] = '\0';

	cout << "Initial input: " << string << endl;
	cout << "Double number =  " << floatNum << endl;

	delete[] string;
	delete[] floatNum;
	return 0;
}