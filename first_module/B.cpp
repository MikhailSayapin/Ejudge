#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

bool check_value_for_set_size(string &command)
{
	if (command.find(' ') == command.length() - 1)
		return false;

	for (int i = command.find(' '); i < command.length() - 1; i++)
	{
		if (command[i + 1] != '0' && command[i + 1] != '1' && command[i + 1] != '2' && command[i + 1] != '3' && command[i + 1] != '4' &&
			command[i + 1] != '5' && command[i + 1] != '6' && command[i + 1] != '7' && command[i + 1] != '8' && command[i + 1] != '9')
			return false;
	}
	return true;
}

bool check_value(string &command)
{
	if (command.find(' ') == command.length() - 1)
		return false;

	for (int i = command.find(' '); i < command.length() - 1; i++)
	{
		if (command[i + 1] == ' ')
			return false;
	}
	return true;
}

bool check_command_set_size(string &command)
{
	if (command.find("set_size") != 0 || command.find("set_size") == string::npos || command.find(' ') != 8)
		return false;
	return true;
}

bool check_command_push(string &command)
{
	if (command.find("push") != 0 || command.find("push") == string::npos || command.find(' ') != 4)
		return false;
	return true;
}

bool check_command_pop(string &command)
{
	if (command.find("pop") != 0 || command.find("pop") == string::npos || command.length() != 3)
		return false;
	return true;
}

bool check_command_print(string &command)
{
	if (command.find("print") != 0 || command.find("print") == string::npos || command.length() != 5)
		return false;
	return true;
}

int main()
{
	string command;
	string temp;
	int size;
	vector<string> v;

	while (!cin.eof())
	{
		getline(cin, command);
		if (command == "")
			continue;
		else if (!check_command_set_size(command))
			cout << "error" << endl;
		else if (!check_value_for_set_size(command))
			cout << "error" << endl;
		else
			break;
	}
	command.erase(0, 9); //�� 0 �� ����� ����� "set_size "
	size = atoi(command.c_str());
	v.reserve(size);
	while (!cin.eof())
	{
		command.clear();
		getline(cin, command);
		if (command.find("push") != string::npos)
		{
			if (!check_command_push(command))
				cout << "error" << endl;
			else if (!check_value(command))
				cout << "error" << endl;
			else
			{
				command.erase(0, 5); //�� 0 �� ����� ����� "push "
				if (v.size() == size)
					cout << "overflow" << endl;
				else
					v.push_back(command);
			}
		}

		else if (command.find("pop") != string::npos)
		{
			if (!check_command_pop(command))
				cout << "error" << endl;
			else if (v.size() == 0)
				cout << "underflow" << endl;
			else
			{
				cout << v.back() << endl;
				v.pop_back();
			}
		}

		else if (command.find("print") != string::npos)
		{
			if (!check_command_print(command))
				cout << "error" << endl;
			else if (v.size() == 0)
				cout << "empty" << endl;
			else
			{
				for (int i = 0; i < v.size() - 1; i++)
					cout << v.at(i) << ' ';
				cout << v.at(v.size() - 1) << endl;
			}
		}

		else if (command == "")
			continue;

		else
		{
			if (!cin.eof())
				cout << "error" << endl;
		}
	}
}
