#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	int M, m_temp=0, c_temp=0;
	vector<int>ci; 
	vector<int>mi; 
	vector<int>rezult;
	
	vector<int> taken_items;
	cin >> M;

	while (!cin.eof())
	{
		mi.push_back(m_temp); ci.push_back(c_temp);
		cin >> m_temp >> c_temp;
	}
	vector<int> temp;
	vector<vector<int>> A;
	for (int i = 0; i <= M; i++)
		temp.push_back(0);
	for (int i = 0; i < mi.size(); i++)
		A.push_back(temp);
	temp.clear();

	for (int i = 0; i < M; i++) A[0][i] = 0;
	for (int i = 0; i < mi.size(); i++) A[i][0] = 0;

	for (int i = 1; i < mi.size(); i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j >= mi.at(i))
				A[i][j] = max(A[i - 1][j], A[i - 1][j - mi[i]] + ci[i]);
			else
				A[i][j] = A[i - 1][j];
		}
	}

	m_temp = c_temp = 0;
	int k = mi.size() - 1; //����� ���������
	int m = M;

	while (true)
	{
		if (A[k][m] == 0)
			break;
		if (A[k][m] != A[k - 1][m])
		{
			rezult.push_back(k);
			m -= mi[k]; k--;
		}
		else k--;
	}

	sort(rezult.begin(), rezult.end());

	for (auto el : rezult)
		m_temp += mi[el];

	cout << m_temp << " " << A[mi.size() - 1][M] << endl;

	for (auto el : rezult)
		cout << el << endl;
}
