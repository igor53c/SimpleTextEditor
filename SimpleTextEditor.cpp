// SimpleTextEditor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;


int main() 
{
	int q;
	string s;
	string input;

	getline(cin, input);

	q = stoi(input);

	stack<string> stapel;

	for (int i = 0; i < q; i++)
	{
		getline(cin, input);

		auto num = stoi(input.substr(0, 1));

		switch (num)
		{
		case 1:
		{
			if (input.length() > 2)
				s += input.substr(2);
			
			stapel.push(s);

			break;
		}
		case 2:
		{
			auto k = stoi(input.substr(2));

			s = s.substr(0, s.length() - k);

			stapel.push(s);

			break;
		}
		case 3:
		{
			auto k = stoi(input.substr(2));

			if (s.length() > k - 1)
				cout << s[k - 1] << endl;
			else cout << endl;

			break;
		}
		case 4:
		{
			if (!stapel.empty())
			{
				stapel.pop();

				if (!stapel.empty())
					s = stapel.top();
				else
					s = "";
			}
				
			break;
		}
		default: break;
		}
	}

	return EXIT_SUCCESS;
}
