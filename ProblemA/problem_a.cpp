#if 0

#define DEBUG 0

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#if DEBUG
int runs = 1;
ifstream input("ProblemA/in.txt");
ofstream output("ProblemA/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif

int main()
{
	while (runs-- > 0)
	{

		vector<int> words;

		string str;
		input >> str;

		bool flag = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '.' && flag)
			{
				flag = false;
				words.push_back(i);
			}
			if (str[i] == '.')
				flag = true;
		}

		sort(words.begin(), words.end(),
			[&](int &A, int &B)
			{
				int i = 0;
				for (; A + i < str.size() && B + i < str.size() &&
					str[A + i] != '.' && str[B + i] != '.' && str[A + i] == str[B + i]; i++) {}

				if (A + i >= str.size())
					return true;

				if (B + i >= str.size())
					return false;

				if (str[A + i] == str[B + i])
					return false;

				if (str[A + i] == '.')
					return true;

				if (str[B + i] == '.')
					return false;

				return str[A + i] < str[B + i];
			});

		int j = 0;
		int i = 0;
		while (true)
		{
			for (; i < str.size() && str[i] == '.'; i++)
				output << '.';

			if (i >= str.size())
				break;

			for (int ind = words[j]; ind < str.size() && str[ind] != '.'; ind++)
				output << str[ind];
			j++;

			for (; i < str.size() && str[i] != '.'; i++) {}
		}
		output << "\n";
	}
}


#endif
