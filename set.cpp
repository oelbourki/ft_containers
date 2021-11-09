#include <iostream>
#include <set>
#include "set/set.hpp"

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
//   ft::set<int> first;                           // empty set of ints

//   int myints[]= {10,20,30,40,50};
//   ft::set<int> second (myints,myints+5);        // range

//   ft::set<int> third (second);                  // a copy of second

//   ft::set<int> fourth (second.begin(), second.end());  // iterator ctor.

//   ft::set<int,classcomp> fifth;                 // class as Compare

//   bool(*fn_pt)(int,int) = fncomp;
//   ft::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
 ft::set<int> myset;
 ft::set<int> const c_myset;

  for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

  ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret;
  ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> c_ret;

  c_ret = myset.equal_range(30);
ret = c_myset.equal_range(30);
  std::cout << "the lower bound points to: " << *ret.first << '\n';
  std::cout << "the upper bound points to: " << *ret.second << '\n';
  return 0;
}