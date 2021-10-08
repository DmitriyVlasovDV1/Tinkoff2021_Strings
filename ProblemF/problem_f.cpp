#if 1

#define DEBUG 1

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#if DEBUG
int runs = 1;
ifstream input("ProblemF/in.txt");
ofstream output("ProblemF/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif


void getZF(string &str, vector<int> &ZF, int delta)
{
  ZF.resize(str.size());

  int R = delta, L = delta;
  ZF[delta] = 0;
  for (int i = delta + 1; i < str.size() - delta; i++)
  {
    if (i <= R)
      ZF[i] = min(ZF[i - L], R - i + 1);

    while (ZF[i] + i < str.size() - delta && str[ZF[i]] == str[ZF[i] + i])
      ZF[i]++;

    if (ZF[i] + i - 1 > R)
    {
      L = i;
      R = ZF[i] + i - 1;
    }
  }
}

int main()
{
  while (runs-- > 0)
  {

    string str;
    input >> str;
    string str2 = str;
    reverse(str2.begin(), str2.end());
    string str3 = str + "#" + str2;

    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
      vector<int> ZF;
      getZF(str3, ZF, i);

      for (int j = str.size() + 1; j < str3.size() - i; j++)
        if (j + ZF[j] == str3.size() - i)
        {
          ans++;
        }
    }

    output << ans << endl;
  }

  return 0;
}


#endif
