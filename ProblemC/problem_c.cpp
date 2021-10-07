#if 1

#define DEBUG 1

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#if DEBUG
int runs = 1;
ifstream input("ProblemC/in.txt");
ofstream output("ProblemC/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif


void getPrefixFunc(string &str, vector<int> &pref)
{
	pref.resize(str.size());
	pref[0] = 0;
	for (int i = 1; i < str.size(); i++)
	{
		int k = pref[i - 1];

		while (k > 0 && str[i] != str[k])
			k = pref[k - 1];

		if (str[i] == str[k])
			k++;

		pref[i] = k;
	}
}


int main()
{
	while (runs-- > 0)
	{
		string str1, str2, str0;

		input >> str1;
		input >> str2;

		str0 = str1 + "#" + str2;

		vector<int> pref;
		getPrefixFunc(str0, pref);

		bool cond = true;
		for (int i = 0; i < str1.size() - pref[pref.size() - 1]; i++)
			if (str2[i] != str1[pref[pref.size() - 1] + i])
			{
				cond = false;
				break;
			}

		if (cond)
			output << str1.size() - pref[pref.size() - 1] << endl;
		else
			output << -1 << "\n";
	}

	return 0;

}

#endif
