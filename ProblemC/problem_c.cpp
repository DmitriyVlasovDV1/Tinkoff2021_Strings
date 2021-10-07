#if 1

#define DEBUG 1

#include <iostream>
#include <fstream>
#include <vector>

#if DEBUG 1
int runs = 1;
ifstream input("ProblemC/in.txt");
ofstream output("ProblemC/out.txt");
#else
int runs = 1;
istream &input = std::cin;
ostream &output = std::cout;
#endif


void (string &str, vector<int> &pF)
{
  for (int i = 1; i < str.size(); i++)
  {
    int k = pF[i - 1];
    while k > 0 && str[k] != str[i]:
      k = pF[k - 1];
      
    if (str[k] == str[i]):
      k++;
      
    pF[i] = k;
  }
}


int main()
{
  while (runs-- > 0)
  {
    
  }
  
}

#endif
