#include "./vector/vectorV2.hpp"


int main()
{
    // ft::vector<int> tmp(100,7);
    // ft::vector<int> f(100,7);
    // f.assign(x.begin(),  x.end());
    // std::cout << "capacity:" << f.capacity()<< std::endl;
    // std::cout << "size:" << f.size()<< std::endl;
    // x.push_back(5);
    // x.push_back(5);
    // std::cout << "maxsize:" << f.max_size()<< std::endl;
    // ft::vector<int> x(50,30);
    // ft::vector<int> f(25,99);
    // x.assign(50,5);
    // for(size_t i = 0;i < 100;i++)
    //   std::cout << "x["<<i<<"]:" << x[i]<< std::endl;
    // std::cout << "capacity:" << x.capacity()<< std::endl;
    // std::cout << "size:" << x.size()<< std::endl;
    // for (size_t i = 0; i < 20; i++)
    // {
    //     f.push_back(i);
    //     std::cout << "capacity:" << f.capacity()<< std::endl;
    //     std::cout << "size:" << f.size()<< std::endl;
    // }
    // for (size_t i = 0; i < 10; i++)
    // {
    //     std::cout << "f["<< i <<"]: " << f[i] << std::endl;
    // }
    // f.reserve(100);
    // std::cout << "capacity:" << f.capacity()<< std::endl;
    // for (size_t i = 0; i < 101; i++)
    // {
    //     f.push_back(i);
    // }
    // f.reserve(300);
    // std::cout << "capacity:" << f.capacity()<< std::endl;
    // std::cout << "capacity:" << x.capacity()<< std::endl;
    // std::cout << "size    :" << x.size()<< std::endl;
    // for (size_t i = 0; i < 115; i++)
    // {
    //     x.push_back(i);
    // }
    // std::cout << "front:" << x.front()<< std::endl;
    // std::cout << "back:" << x.back()<< std::endl;
    // std::cout << "at:" << x.at(10)<< std::endl;
    // std::cout << "capacity:" << x.capacity()<< std::endl;
    // std::cout << "size    :" << x.size()<< std::endl;
    // x.resize(250);
    // std::cout << "capacity:" << x.capacity()<< std::endl;
    // std::cout << "size    :" << x.size()<< std::endl;
    // std::cout << "----------------------------------"<< std::endl;
    // std::cout << "capacity:" << f.capacity()<< std::endl;
    // std::cout << "size    :" << f.size()<< std::endl;
    // for (size_t i = 0; i < 115; i++)
    // {
    //     f.push_back(i);
    // }
    // std::cout << "front:" << f.front()<< std::endl;
    // std::cout << "back:" << f.back()<< std::endl;
    // std::cout << "at:" << f.at(300)<< std::endl;


    // std::cout << "capacity:" << f.capacity()<< std::endl;
    // std::cout << "size    :" << f.size()<< std::endl;
    // f.resize(250);
    // std::cout << "capacity:" << f.capacity()<< std::endl;
    // std::cout << "size    :" << f.size()<< std::endl;
    std::cout << "----------------------------------"<< std::endl;

    //  std::vector<int> myvector;
    // for (int i=1; i<=5; i++) myvector.push_back(i);

    // std::cout << "myvector contains:";
    // for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // std::cout << "----------------------------------"<< std::endl;
    //  ft::vector<int> thevector;
    // for (int i=1; i<=5; i++) thevector.push_back(i);

    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = thevector.begin() ; it != thevector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // ft::vector<int> myvector (5);  // 5 default-constructed ints

    // int i=0;

    // ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    // for (; rit!= myvector.rend(); ++rit)
    //     *rit = ++i;

    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
  //   ft::vector<int> myvector;
  // int sum (0);
  // myvector.push_back (100);
  // myvector.push_back (200);
  // myvector.push_back (300);

  // while (!myvector.empty())
  // {
  //   sum+=myvector.back();
  //   myvector.pop_back();
  // }

  // std::cout << "The elements of myvector add up to " << sum << '\n';
  // ft::vector<int> first;
  // ft::vector<int> second;
  // ft::vector<int> third;

  // first.assign (7,100);             // 7 ints with a value of 100

  // ft::vector<int>::iterator it;
  // it=first.begin()+1;

  // second.assign (it,first.end()-1); // the 5 central values of first

  // int myints[] = {1776,7,4};
  // third.assign (myints,myints+3);   // assigning from array.

  // std::cout << "Size of first: " << int (first.size()) << '\n';
  // std::cout << "Size of second: " << int (second.size()) << '\n';
  // std::cout << "Size of third: " << int (third.size()) << '\n';
  //   ft::vector<int> myvector;
  // myvector.push_back (100);
  // myvector.push_back (200);
  // myvector.push_back (300);

  // std::cout << "myvector contains:";
  // for (unsigned i=0; i<myvector.size(); i++)
  //   std::cout << ' ' << myvector[i];
  // std::cout << '\n';

  // myvector.clear();
  // myvector.push_back (1101);
  // myvector.push_back (2202);

  // std::cout << "myvector contains:";
  // for (unsigned i=0; i<myvector.size(); i++)
  //   std::cout << ' ' << myvector[i];
  // std::cout << '\n';
  //  ft::vector<int> foo (3,100);   // three ints with a value of 100
  // ft::vector<int> bar (5,200);   // five ints with a value of 200
  //   std::cout << "foo>capacity:" << foo.capacity()<< std::endl;
  //   std::cout << "foo>size    :" << foo.size()<< std::endl;
  //   std::cout << "bar>capacity:" << bar.capacity()<< std::endl;
  //   std::cout << "bar>size    :" << bar.size()<< std::endl;
  // foo.swap(bar);

  // std::cout << "foo contains:";
  // for (unsigned i=0; i<foo.size(); i++)
  //   std::cout << ' ' << foo[i];
  // std::cout << '\n';

  // std::cout << "bar contains:";
  // for (unsigned i=0; i<bar.size(); i++)
  //   std::cout << ' ' << bar[i];
  // std::cout << '\n';
  //   std::cout << "foo>capacity:" << foo.capacity()<< std::endl;
  //   std::cout << "foo>size    :" << foo.size()<< std::endl;
  //   std::cout << "bar>capacity:" << bar.capacity()<< std::endl;
  //   std::cout << "bar>size    :" << bar.size()<< std::endl;


    ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  // myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
    return 0;
}