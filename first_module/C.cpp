#include <iostream>
#include <fstream>
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

int main(int argc, char* argv[])
{
	ofstream fout;
	ifstream fin;
	string command;
	string temp;
	int size;
	vector<string> v;

	fout.open(argv[2]);
	if (!fout.is_open())
		cout << "error" << endl;
	
	fin.open(argv[1]);
	if (!fin.is_open())
		fout << "error" << endl;

	while (!fin.eof())
	{
		getline(fin, command);
		if (command == "")
			continue;
		else if (!check_command_set_size(command))
			fout << "error" << endl;
		else if (!check_value_for_set_size(command))
			fout << "error" << endl;
		else
			break;
	}
	command.erase(0, 9); //от 0 до длины слова "set_size "
	size = atoi(command.c_str());
	v.reserve(size);
	while (!fin.eof())
	{
		command.clear();
		getline(fin, command);
		if (command.find("push") != string::npos)
		{
			if (!check_command_push(command))
				fout << "error" << endl;
			else if (!check_value(command))
				fout << "error" << endl;
			else
			{
				command.erase(0, 5); //от 0 до длины слова "push "
				if (v.size() == size)
					fout << "overflow" << endl;
				else
					v.push_back(command);
			}
		}

		else if (command.find("pop") != string::npos)
		{
			if (!check_command_pop(command))
				fout << "error" << endl;
			else if (v.size() == 0)
				fout << "underflow" << endl;
			else
			{
				fout << v.front() << endl;
				v.erase(v.begin());
			}
		}

		else if (command.find("print") != string::npos)
		{
			if (!check_command_print(command))
				fout << "error" << endl;
			else if (v.size() == 0)
				fout << "empty" << endl;
			else
			{
				for (int i = 0; i < v.size() - 1; i++)
					fout << v.at(i) << ' ';
				fout << v.at(v.size() - 1) << endl;
			}
		}

		else if (command == "")
			continue;

		else
		{
			if (!fin.eof())
				fout << "error" << endl;
		}
	}
	fin.close();
	fout.close();
}
