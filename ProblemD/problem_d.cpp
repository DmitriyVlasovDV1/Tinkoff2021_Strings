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

struct vert
{
  int ind[2];
  int ends;
};

vector<vert> bor(1, {-1, -1, 0});

void addNumber(vector<vert> bor, int num)
{
  int v = 0;
  while (num != 0)
  {
    int dig = num % 2;
    num /= 2;

    if (bor[v].ind[dig] == -1)
    {
      bor.push_back({-1, -1, 0});
      bor[v].ind[dig] = bor.size() - 1;
    }

    v = bor[v].ind[dig];
  }

  bor[v].ends++;
}


int main()
{
  while (runs-- > 0)
  {

  }
  return 0;


}


#endif
