// map::begin/end
#include <iostream>
#include <map>
#include "map.hpp"
#include "pair.hpp"
// #include "r"


int main ()
{
    // std::map<int, char> alice{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    // std::map<int, char> bob{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};
    // std::map<int, char> eve{{1, 'a'}, {2, 'b'}, {3, 'c'}};
 
    // std::cout << std::boolalpha;
 
    // // Compare non equal containers
    // std::cout << "alice == bob returns " << (alice == bob) << '\n';
    // std::cout << "alice != bob returns " << (alice != bob) << '\n';
    // std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    // std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    // std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    // std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    // std::cout << '\n';
 
    // // Compare equal containers
    // std::cout << "alice == eve returns " << (alice == eve) << '\n';
    // std::cout << "alice != eve returns " << (alice != eve) << '\n';
    // std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    // std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    // std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    // std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
ft::map<char,int> foo,bar;
  foo['a']=100;
  foo['b']=100;
  bar['a']=100;
  bar['b']=100;
  std::map<char,int> foo1,bar1;
  foo1['a']=100;
  foo1['b']=100;
  bar1['a']=100;
  bar1['b']=100;
  ft::map<char,int>::iterator eit = --foo.end();
  std::cout << eit->first << std::endl;
  // std::pair<char,int> p('f',9);
  // std::pair<char,int> p1('g',9);
  // ft::pair<char,int> p2('f',9);
  // ft::pair<char,int> p3('g',9);
  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// std::cout << "-------------------------------\n";

//   if (foo1==bar1) std::cout << "foo1 and bar1 are equal\n";
//   if (foo1!=bar1) std::cout << "foo1 and bar1 are not equal\n";
//   if (foo1< bar1) std::cout << "foo1 is less than bar1\n";
//   if (foo1> bar1) std::cout << "foo1 is greater than bar1\n";
//   if (foo1<=bar1) std::cout << "foo1 is less than or equal to bar1\n";
//   if (foo1>=bar1) std::cout << "foo1 is greater than or equal to bar1\n";
//     if (p==p1) std::cout << "p and p1 are equal\n";
//   if (p!=p1) std::cout << "p and p1 are not equal\n";
//   if (p< p1) std::cout << "p is less than p1\n";
//   if (p> p1) std::cout << "p is greater than p1\n";
//   if (p<=p1) std::cout << "p is less than or equal to p1\n";
//   if (p>=p1) std::cout << "p is greater than or equal to p1\n";
// std::cout << "-------------------------------\n";
//   if (p2==p3) std::cout << "p2 and p3 are equal\n";
//   if (p2!=p3) std::cout << "p2 and p3 are not equal\n";
//   if (p2< p3) std::cout << "p2 is less than p3\n";
//   if (p2> p3) std::cout << "p2 is greater than p3\n";
//   if (p2<=p3) std::cout << "p2 is less than or equal to p3\n";
//   if (p2>=p3) std::cout << "p2 is greater than or equal to p3\n";
  return 0;
}