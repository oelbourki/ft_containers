#include "ft_list.hpp"
// #include <iostream>
// #include <iterator>
// #include <vector>
using namespace std;
#include <list>
// int     main()
// {
//     // ft::list<int> l;
//     list<int> l;
//     list<int> l1;
//     for (size_t i = 0; i < 100; i++)
//     {
//         l.push_back(i);
//     }
//     for (size_t i = 0; i < 100; i++)
//     {
//         l1.push_front(i);
//     }
//     // list<int> l;
//     // list<int> l1;
//     // l.assign(20,9);
//     // ft::list<int>::iterator it = l.begin();
//     // l.insert(it,10);

//     // l.insert(it,5);
//     // for (size_t i = 0; i < 5; i++)
//     // {
//     //     l.insert(it,9);
//     //     it++;
//     // }
//     // ft::list<int>::iterator it1 = l.begin();
//     // ft::list<int>::iterator end = l.end();
//     // for (; it1 != end; it1++)
//     // {
//     //    cout << *it << endl;
//     // }
//     // l.~list();
//     // list<int> t;
//     // t.insert()
//     return 0;
// }

// int main ()
// {
//   std::list<int> first;
//   std::list<int> second;

//   first.assign (7,100);                      // 7 ints with value 100

//   second.assign (first.begin(),first.end()); // a copy of first

//   int myints[]={1776,7,4};
//   first.assign (myints,myints+3);            // assigning from array

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   return 0;
// }


// int main ()
// {
//   ft::list<int> mylist;

//   mylist.push_back(10);

//   while (mylist.back() != 0)
//   {
//     mylist.push_back ( mylist.back() -1 );
//   }

    
//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }
// int main ()
// {
//   int myints[] = {75,23,65,42,13};
//   ft::list<int> mylist (myints,myints+5);

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::list<int> mylist;
//   ft::list<int>::iterator it;

//   mylist.push_back (100);
//   mylist.push_back (200);
//   mylist.push_back (300);

//   std::cout << "mylist contains:";
//   for (it=mylist.begin(); it!=mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   mylist.clear();
//   mylist.push_back (1101);
//   mylist.push_back (2202);

//   std::cout << "mylist contains:";
//   for (it=mylist.begin(); it!=mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::list<int> mylist;
//   int sum (0);

//   for (int i=1;i<=10;++i) mylist.push_back(i);

//   while (!mylist.empty())
//   {
//      sum += mylist.front();
//      mylist.pop_front();
//   }

//   std::cout << "total: " << sum << '\n';
  
//   return 0;
// }

// int main ()
// {
//   int myints[] = {75,23,65,42,13};
//   ft::list<int> mylist (myints,myints+5);

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

//   return 0;
// }


int main ()
{
  ft::list<int> mylist;
  ft::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  return 0;
}