#include "xmap.hpp"
#include <algorithm>
#include <map>
#include "stl.hpp"
using namespace std;

// int     main()
// {
//     ft::map<char,int> m;
//     ft::list<std::pair<char,int>> l;
//     pair<char,int> p1('a',1);
//     pair<char,int> p2('b',2);
//     pair<char,int> p3('c',3);
//     pair<char,int> p4('d',4);
//     pair<char,int> p5('e',5);
//     pair<char,int> p6('f',6);
//     // std::cout << p1.first << endl;
//     // ft::lower_bound(l.begin(),l.end(),p1);
//     l.insert(l.begin(),p1);
//     l.insert(l.begin(),p2);
//     l.insert(l.begin(),p3);
//     l.insert(l.begin(),p4);
//     l.insert(l.begin(),p5);
//  ft::list<std::pair<char,int>>::iterator iter1;
// //  iter1 = l.begin();
// //  iter1++;
// //  for (iter = l.begin(); iter !=  l.end(); iter++)
// //  {
// //      std::cout << (*iter).first << endl;
// //  }
 
//     m.insert(m.begin(),p1);
//     m.insert(m.begin(),p2);
//     m.insert(m.begin(),p3);
//     m.insert(m.begin(),p4);
//     m.insert(m.begin(),p5);
//     m['f'] = 32;
//     // pair<char,int> *p0 = &p1;
//     // std::cout << "  ???"<<p0->first << endl;
//  ft::map<char,int>::iterator iter;
// //  iter = m.begin();
// //  std::cout << (*iter).first << endl;
// // p1 = m.begin1();
// // p1 = *iter;
// // cout << p1.first << endl;
//      for (iter = m.begin(); iter !=  m.end(); ++iter)
//  {
//      std::cout << iter->first << " "<<iter->second  << endl;
//  }
//     return 0;
// }

// int main ()
// {
//   ft::map<char,std::string> mymap;

//   mymap['a']="an element";
//   mymap['b']="another element";
//   //   ft::map<char,int> mymap1;

//   // mymap1['a'] = 55;
//   // mymap1['b']= 10;
// //   mymap['c']=mymap['b'];

//   std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//   std::cout << "mymap['b'] is " << mymap['b'] << '\n';
// //   std::cout << "mymap['c'] is " << mymap['c'] << '\n';
// //   std::cout << "mymap['d'] is " << mymap['d'] << '\n';
//   // std::cout << "mymap1['a'] is " << mymap1['a'] << '\n';
//   // std::cout << "mymap1['b'] is " << mymap1['b'] << '\n';
//   // std::cout << "mymap now contains " << mymap.size() << " elements.\n";

//   return 0;
// }

// struct classcomp {
//   template<class T>
//   bool operator() (const T& lhs, const T& rhs) const
//   {return lhs.first < rhs.first;}
// };
// int main ()
// {
//   ft::map<char,int> mymap;
// std::pair<char,int> p('z',66);
// std::pair<char,int> p1('a',20);
// // if (f(p.first,p1.first))
// //   std::cout << "good\n";
// // else 
// //     std::cout << "bad\n";
// mymap['z'] = 66;
//   mymap['a']=10;
//   mymap['c']=30;
//   mymap['b']=20;
// ft::map<char,int>::iterator iter;
// for (iter =  mymap.begin(); iter != mymap.end(); iter++)
// {
//   std::cout << iter->first << " " << iter->second << std::endl;
// }
// // for (iter =  mymap.begin(); iter != mymap.end(); iter++)
// // {
// //   std::cout << iter->first << " " << iter->second << std::endl;
// // }
// iter = ft::lower_bound(mymap.begin(),mymap.end(),p);
//   std::cout << iter->first << " " << iter->second << std::endl;

// // std::cout << mymap['c'] << std::endl;
// // std::pair<char,int> p('b',20);
// // std::pair<char,int> p1('b',20);
// // iter =  ft::lower_bound(mymap.begin(),mymap.end(),p);
// //  std::cout <<"lower bound" << iter->first << " " << iter->second << std::endl;
// // iter = ft::upper_bound(mymap.begin(),mymap.end(),p);
// //  std::cout <<"upper bound" << iter->first << " " << iter->second << std::endl;
// //   std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
// //   ret = mymap.equal_range('b');

// //   std::cout << "lower bound points to: ";
// //   std::cout << ret.first->first << " => " << ret.first->second << '\n';

// //   std::cout << "upper bound points to: ";
// //   std::cout << ret.second->first << " => " << ret.second->second << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::map<char,int> mymap;

//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;

//   std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
//   ret = mymap.equal_range('b');

//   std::cout << "lower bound points to: ";
//   std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';

//   return 0;
// }
// int main ()
// {
//   ft::map<char,int> first;
//   ft::map<char,int> second;
// ft::map<char,std::string> first1;
//   first['x']=8;
//   first['y']=16;
//   first['z']=32;
// first1['a'] = "gfdg";
//   second=first;                // second now contains 3 ints
//   // first=ft::map<char,int>();  // and first is now empty

//   std::cout << "Size of first: " << first.size() << '\n';
//   std::cout << "Size of second: " << second.size() << '\n';
//   std::cout << "Sihgnd: " << second['z'] <<" " <<first['z'] << '\n';
//   return 0;
// }


// int main ()
// {
//   ft::map<char,int> mymap;
//   ft::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;

//   itlow=mymap.lower_bound ('b');  // itlow points to b
//   itup=mymap.upper_bound ('d');   // itup points to e (not d!)

//   mymap.erase(itlow,itup);        // erases [itlow,itup)

//   // print content:
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

// int main ()
// {
//   ft::map<char,int> mymap;
//   char c;

//   mymap ['a']=101;
//   mymap ['c']=202;
//   mymap ['f']=303;

//   for (c='a'; c<'h'; c++)
//   {
//     std::cout << c;
//     if (mymap.count(c)>0)
//       std::cout << " is an element of mymap.\n";
//     else 
//       std::cout << " is not an element of mymap.\n";
//   }

//   return 0;
// }


int main ()
{
  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}