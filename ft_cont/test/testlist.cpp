#include <iostream>
#include <algorithm>
#include "list.h"
using namespace list_presentation;
using namespace std;

int main() 
{
  list<int> x;
  x.push_back(5);
  x.push_back(7);
  x.pop_back();
  cout << x.back() << endl;

  const int N = 20;
  list<double> y(N);

  int k = 0;
  for (list<double>::iterator i = y.begin(); i != y.end(); ++i)
    *i = double(++k) + 0.1;

  //  std::copy(y.begin(), y.end(), 
  //	      std::ostream_iterator<double>(std::cout," "));
  //  std::cout << std::endl;

  copy(y.begin(), y.end(), 
        ostream_iterator<double>(cout," "));
  cout << endl;


  return 0;
}
