#if 1

#define DEBUG 1

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

const int MOD = (int)1e9 + 7;

int main()
{
  while (runs-- > 0)
  {
    int P = 29;


    string str1, str2;
    input >> str1 >> str2;

    vector<int> pPow(str2.size());

    pPow[0] = 1;
    for (int i = 1; i < str1.size(); i++)
      pPow[i] = pPow[i - 1] * P % MOD;

    int hash2 = 0;
    for (int i = 0; i < str2.size(); i++)
    {
      hash2 += (str2[i] - 'a') * pPow[i];
      hash2 %= MOD;
    }


    vector<int> hash1;
    for (int i = 0; i < str1.size(); i++)
    {
      hash1[i + 1] = (str1[i] - 'a') * pPow[i] + (i > 1 ? hash1[i] : 0);
      hash1[i + 1] %= MOD;

      if (i >= str2.size() - 1)
        if (hash1[i + 1] - hash1[i + 1 - str2.size()] == hash2 * pPow[])
    }

  }
}


#endif
