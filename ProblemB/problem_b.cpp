#if 0

#define DEBUG 0

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#if DEBUG
int runs = 1;
ifstream input("ProblemB/in.txt");
ofstream output("ProblemB/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif

typedef long long ll;
const ll MOD = (ll)1e9 + 7;

int main()
{
	while (runs-- > 0)
	{
		ll P = 29;


		string str1, str2;
		input >> str1 >> str2;

		vector<ll> pPow(max(str1.size(), str2.size()));

		pPow[0] = 1;
		for (int i = 1; i < max(str1.size(), str2.size()); i++)
			pPow[i] = pPow[i - 1] * P % MOD;

		ll hash2 = 0;
		for (int i = 0; i < str2.size(); i++)
		{
			hash2 += (str2[i] - 'a') * pPow[i];
			hash2 %= MOD;
		}

		vector<int> ans;

		vector<ll> hash1(str1.size() + 1);
		for (int i = 0; i < str1.size(); i++)
		{
			hash1[i + 1] = (str1[i] - 'a') * pPow[i] + (i > 0 ? hash1[i] : 0);
			hash1[i + 1] %= MOD;

			if (i >= str2.size() - 1 && (hash1[i + 1] - hash1[i + 1 - str2.size()] + MOD) % MOD == hash2 * pPow[i - str2.size() + 1] % MOD)
				ans.push_back(i - str2.size() + 1);
		}

		for (int i = 0; i < ans.size(); i++)
			output << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}
}


#endif
