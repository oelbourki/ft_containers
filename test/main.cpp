#include <iostream>
#include <algorithm>
#include "list.h"
#include "../ft_list.hpp"
using namespace list_presentation;
using namespace std;
int main ()
{
  ft::list<int> mylist;
   ft::list<int>::iterator it;
    list<int> l;
    list<int>::iterator it1;
  // set some initial values:
//   for (int i=5; i<=10; ++i) mylist.push_back(i); // 1 2 3 4 5
// cout << "front>>>>"<< mylist.front() << endl;
int i = 1;
for ( it = mylist.begin(); i < 10; i++)
{
    mylist.push_back(i);
}
i = 1;
for ( it1 = l.begin(); i < 10; i++)
{
    l.push_back(i);
}
cout <<"<><>"<< *l.begin() << endl;
//   it = mylist.begin();
//   ++it;       // it points now to number 2           ^

//   mylist.insert (it,10);                        // 1 10 2 3 4 5

//   // "it" still points to number 2                      ^
//   mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

//   --it;       // it points now to the second 20            ^

//   std::vector<int> myvector (2,30);
//   mylist.insert (it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "mylist contains:";
  
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  for (it1=l.begin(); it1!=l.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';
  return 0;
}