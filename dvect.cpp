#include <iostream>
#include <vector>
#include "vector/vectorV2.hpp"
#include "pair.hpp"




// int main ()
// {
//   ft::vector<int>::size_type sz;

//   ft::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   ft::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "cap" << bar.capacity() << std::endl;
//   std::cout << "making bar grow:\n";
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }
//   return 0;
// }

// int main ()
// {
//   ft::vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";
//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//   std::cout << "myvector stores " << int(myvector.capacity()) << " numbers.\n";
// for (size_t i = 0; i < 100; ++i)
// {
//     myvector.push_back (i);
//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//   std::cout << "myvector stores " << int(myvector.capacity()) << " numbers.\n";
// }

//   // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//   // std::cout << "myvector stores " << int(myvector.capacity()) << " numbers.\n";


//   return 0;
// }


// int main ()
// {
//   // ft::vector<int> myvector (3,100);
//   // // std::vector<int> myvector (3,100);
//   // ft::vector<int>::iterator it;
//   // ft::vector<int>::iterator it1;

//   // // std::cout << "capacity = > " << 
//   // it = myvector.begin();
//   // it1 = myvector.begin();

//   // // std::cout << "it b:" << &(*it)<< std::endl;
//   // it = myvector.insert ( it , 200 );
//         std::string str, ft_str;
//         /*
//             * var to store the size and the capacity
//             */
//   ft::vector<std::string>::size_type  s, ft_s;
//   ft::vector<std::string>::size_type  c, ft_c;
//   ft::vector<std::string>::iterator   ft_it;
//   std::vector<std::string>::iterator  it;
//   std::vector<std::string>    v;
//   ft::vector<std::string>     ft_v;
//   it = v.insert(v.begin(), "hello");
//   ft_it = ft_v.insert(ft_v.begin(), "hello");
//   // std::cout << "it:" << *it << std::endl;
//   // std::cout << "ft:" << *ft_it << std::endl;

//   // ft_it->length();

//   // s = v.size();
//   // ft_s = ft_v.size();
//   // c = v.capacity();
//   // ft_c = ft_v.capacity();
//   // for (size_t i = 0; i < v.size(); ++i)
//   //     str += v[i];
//   // for (size_t i = 0; i < ft_v.size(); ++i)
//   //     ft_str += ft_v[i];
//   // std::cout 
//   // myvector.insert (it,2,300);

//   // // "it" no longer valid, get a new one:
//   // it = myvector.begin();

//   // ft::vector<int> anothervector (2,400);
//   // myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   // int myarray [] = { 501,502,503 };
//   // myvector.insert (myvector.begin(), myarray, myarray+3);

//   // std::cout << "myvector contains:";
//   // for (it=myvector.begin(); it<myvector.end(); it++)
//   //   std::cout << ' ' << *it;
//   // std::cout << '\n';

//   return 0;
// }


int main ()
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;
  std::cout << "cap:" << myvector.capacity()<<std::endl;
  std::cout << "size:" << myvector.size()<<std::endl;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  std::cout << "cap:" << myvector.capacity()<<std::endl;
  std::cout << "size:" << myvector.size()<<std::endl;
  myvector.insert (it,6,300);
  std::cout << "cap:" << myvector.capacity()<<std::endl;
  std::cout << "size:" << myvector.size()<<std::endl;
  //"it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}