# include "./vector/vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;
  std::cout << "the size:" << myvector.size() << std::endl;
  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  std::cout << "the size:" << myvector.size() << std::endl;

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());
  std::cout << "the size:" << myvector.size() << std::endl;

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}