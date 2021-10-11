#if 1

#define DEBUG 1

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#if DEBUG
int runs = 0;
ifstream input("ProblemI/in.txt");
ofstream output("ProblemI/out.txt");
#else
int runs = 0;
istream &input = std::cin;
ostream &output = std::cout;
#endif

typedef pair<bool, string> vec2;

struct Vert
{
  int ind[26];
  int cnt;
};


struct Bor
{
  vector<Vert> vert;
  
  Bor() :
    vert(1, {{-1}, 0})
  {
    
  }
  
  void addStr(string &str)
  {
    int v = 0;
    
    for (int i = 0; i < str.size(); i++)
    {
      char ch = str[i];
      
      if (vert[v].ind[ch] == 0)
        vert.push_back( { {} , 0} );
        
      vert[v].ind[ch] = vert.size() - 1;
    }
    vert[v].cnt++;
  }
  
  bool assembleStr(string &str)
  {
    int v = 0;
    for (int i = 0; i < str.size(); i++)
    {
      if (vert[v].cnt != 0)
      {
        if (i == str.size() - 1)
          return true;
        v = 0;
        continue;
      }
      
      char ch = str[i]
      if (vert[v].ind[ch] == 0)
        return false;
        
      v = vert[v].ind[ch];
    }
    return false;
  }
};



int main()
{
  while (runs-- > 0)
  {
    int N = 0;
    input >> N;
    
    vector<vec2> stock;
    
    Bor bor;
    int prevK = -1;
    for (int i = 0; i < N; i++)
    {
      char ch;
      char str;
      input >> ch; 
      input >> str;
      
      if (ch == "+")
      {
        bor.addStr(str);
        int k = 0;
        for (auto &item : stock)
          if (item.first == false)
            k += bor.assembleStr(item.second);
        prevK = k;
      }
      else if (ch == "?")
      {
        stock.push_back({false, str});
        prevK = bor.assembleStr(str);
      }
      
    }
    
  }
  
}


#endif
