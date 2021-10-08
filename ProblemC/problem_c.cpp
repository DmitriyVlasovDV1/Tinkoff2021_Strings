#if 0

#define DEBUG 0

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


void getZFunc(string &str, vector<int> &zFunc)
{
	zFunc.resize(str.size());
	zFunc[0] = 0;

	int L = 0, R = 0;
	for (int i = 1; i < str.size(); i++)
	{
		if (i <= R)
			zFunc[i] = min(R - i + 1, zFunc[i - L]);

		while (i + zFunc[i] < str.size() && str[zFunc[i]] == str[i + zFunc[i]])
			zFunc[i]++;

		if (i + zFunc[i] - 1 > R)
		{
			L = i;
			R = i + zFunc[i] - 1;
		}
	}
}


int main()
{
	while (runs-- > 0)
	{
		string str1, str2, str12, str21;

		input >> str1;
		input >> str2;

		if (str1 == str2)
		{
			output << 0 << endl;
			return 0;
		}


		str12 = str1 + "#" + str2;
		str21 = str2 + "#" + str1;

		vector<int> z12;
		vector<int> z21;
		getZFunc(str12, z12);
		getZFunc(str21, z21);

		bool cond = false;
		int ans = 0;
		for (int i = 0; i < str1.size() - 1; i++)
			if (z21[str12.size() - 1 - i] == i + 1 && z12[str1.size() + 1 + i + 1] == str1.size() - i - 1)
			{
				ans = i + 1;
				cond = true;
				break;
			}

		if (cond)
			output << ans << endl;
		else
			output << -1 << endl;
	}

	return 0;

}

#endif
