#include "./vector/vectorV2.hpp"



int main()
{
//   ft::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);

// //   typedef ft::vector<int>::iterator iter_type;
//   typedef ft::vector<int>::iterator iter_type;

//     std::cout << "begin:" << *myvector.begin()<<std::endl;
//     std::cout << "end:" << *myvector.end()<<std::endl;

//                                                              // ? 0 1 2 3 4 5 6 7 8 9 ?
//   iter_type from (myvector.begin());                     //   ^
//                                                          //         ------>
//   iter_type until (myvector.end());                      //                       ^
//                                                          //
//                                                          //         <------

//   std::cout << "myvector:";
//   while (from != until)
//     std::cout << ' ' << *from++;
//   std::cout << '\n';

ft::vector<int> myvector(2,100);
  std::vector<int> therevector(2,100);
  ft::vector<int>::const_iterator ft_it = myvector.begin();
  std::vector<int>::const_iterator std_it = therevector.begin();
std::cout << "------------------------------" << std::endl;
  std::cout << "    ::  dyalhoum ::   " << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "Capacity : " << therevector.capacity() << std::endl;
  std::cout << "Size : " << therevector.size() << std::endl;
  std::cout << "therevector contains:";
  for (std_it = therevector.begin(); std_it < therevector.end(); std_it++)
    std::cout << ' ' << *std_it;
  std::cout << '\n';
  std::cout << "------------------------------" << std::endl;
  std::cout << "       :: dyali ::    " << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "Capacity : " << myvector.capacity() << std::endl;
  std::cout << "Size : " << myvector.size() << std::endl;
  std::cout << "myvector contains:";
  for (ft_it = myvector.begin(); ft_it < myvector.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}