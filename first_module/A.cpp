#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	string str;
	string temp;
	long long rezult = 0;

	while (!cin.eof())
	{
		getline(cin, str);

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' ||
				str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
			{
				if (i != 0 && str[i - 1] == '-')
				{
					temp += str[i - 1];
				}

				temp += str[i];

				if (i == str.length() - 1)
				{
					rezult += atoi(temp.c_str());
					temp.clear();
				}
			}

			else
			{
				if (i != 0 && (str[i - 1] == '1' || str[i - 1] == '2' ||
					str[i - 1] == '3' || str[i - 1] == '4' || str[i - 1] == '5' || str[i - 1] == '6' ||
					str[i - 1] == '7' || str[i - 1] == '8' || str[i - 1] == '9' || str[i - 1] == '0'))
				{
					rezult += atoi(temp.c_str());
					temp.clear();
				}
			}
		}
		str.clear();
	}

	if (cin.get() == EOF)
	{
		cout << rezult << endl;
	}
	return 0;
}
