#if 1

#define DEBUG 0

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#if DEBUG
int runs = 1;
ifstream input("ProblemH/in.txt");
ofstream output("ProblemH/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif

void getZFunc(vector<int> &zF, vector<int> &str)
{
	zF.resize(str.size());

	zF[0] = 0;
	int R = 0, L = 0;

	for (int i = 1; i < str.size(); i++)
	{
		if (i <= R)
			zF[i] = min(R - i + 1, zF[i - L]);

		while (zF[i] + i < str.size() && str[i + zF[i]] == str[zF[i]])
			zF[i]++;

		if (R < i + zF[i] - 1)
		{
			R = i + zF[i] - 1;
			L = i;
		}
	}
}

int main()
{
	while (runs-- > 0)
	{
		int N, tmp;
		input >> N >> tmp;
		vector<int> str(N);

		for (int i = 0; i < N; i++)
		{
			int c;
			input >> c;
			str[i] = c;
		}

		vector<int> str2 = str;
		reverse(str2.begin(), str2.end());
		str.push_back(-1);

		str.insert(str.end(), str2.begin(), str2.end());

		vector<int> zF;
		getZFunc(zF, str);

		vector<int> ans;
		int len = N * 2 + 1;
		for (int i = N + 1; i < len; i++)
		{
			if (i + 2 * zF[i] >= len && (len - i) % 2 == 0)
				ans.push_back(i - (N + 1) + (len - i) / 2);
		}

		ans.push_back(N);
		for (int i = 0; i < ans.size(); i++)
			output << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}

	return 0;
}



#endif
