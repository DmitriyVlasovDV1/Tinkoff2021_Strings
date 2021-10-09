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
ifstream input("ProblemD/in.txt");
ofstream output("ProblemD/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif

struct Vert
{
  int ind[2];
  int cnt;
  int dist;
};

struct Bor
{
  vector<Vert> vert;

  Bor() : vert(1, {{-1, -1}, 0, 0})
  {
    add(0);
  }

  void add(int num)
  {
    int v = 0;
    while (num != 0)
    {
      int dig = num % 2;
      num /= 2;

      if (vert[v].ind[dig] == -1)
      {
        vert.push_back({{-1, -1}, 0, vert[v].dist + 1});
        vert[v].ind[dig] = vert.size() - 1;
      }

      v = vert[v].ind[dig];
    }

    vert[v].cnt++;
  }

  void remove(int num)
  {
    int v = 0;

    while (num != 0)
    {
      int dig = num % 2;
      num /= 2;

      v = vert[v].ind[dig];
    }

    vert[v].cnt--;
  }

  int count(int num)
  {
    int v = 0;

    while (num != 0)
    {
      int dig = num % 2;
      num /= 2;

      if (vert[v].ind[dig] == -1)
        return 0;

      v = vert[v].ind[dig];
    }

    return vert[v].cnt;
  }

  void maxXOR(int &max, int mask, int v, int res)
  {
    if (vert[v].cnt && max < res + ((mask >> vert[v].dist ^ 0) << vert[v].dist))
      max = res + ((mask >> vert[v].dist ^ 0) << vert[v].dist);

    int dig = (mask >> vert[v].dist) & 1;

    if (vert[v].ind[0] != -1)
    {
      int newDig = dig ^ 0;
      maxXOR(max, mask, vert[v].ind[0], res + (newDig << vert[v].dist));
    }

    if (vert[v].ind[1] != -1)
    {
      int newDig = dig ^ 1;
      maxXOR(max, mask, vert[v].ind[1], res + (newDig << vert[v].dist));
    }
  }

};

int main()
{
  while (runs-- > 0)
  {
    int N;
    input >> N;


    Bor bor;

    for (int i = 0; i < N; i++)
    {
      char ch;
      int num;
      input >> ch >> num;
      if (ch == '+')
        bor.add(num);
      else if (ch == '-')
        bor.remove(num);
      else if (ch == '*')
        output << "Res: " << bor.count(num) << "\n";
      else if (ch == '?')
      {
        int max = -1;
        bor.maxXOR(max, num, 0, 0);
        output << max << "\n";
      }

    }

  }
  return 0;


}


#endif
