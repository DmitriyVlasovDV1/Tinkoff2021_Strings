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
ifstream input("ProblemE/in.txt");
ofstream output("ProblemE/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif


void getZF(string &str, vector<int> &zFunc)
{
  zFunc.resize(str.size());

  int R = 0, L = 0;
  zFunc[0] = 0;

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

    int N;
    input >> N;

    string str;
    input >> str;

    string rStr = str;
    reverse(rStr.begin(), rStr.end());

    string str2 = str + "#" + rStr;

    vector<int> zFunc;
    getZF(str2, zFunc);

    for (int i = str2.size() - 1; i > str.size(); i--)
      output << zFunc[i] << (i == str.size() + 1 ? "\n" : " ");

  }

  return 0;
}

#endif
