/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:39:16 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/13 11:19:29 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
// #include <time.h>
#include <sys/time.h>
#if NS
#define NAMESPACE "FT  : "
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"
#include "set/set.hpp"
#include "utils/pair.hpp"
#else
#define NAMESPACE "STD : "
#include <vector>
#include <stack>
#include <map>
#include <set>
namespace ft = std;
#endif

	// helper functions 
bool mypredicate (int i, int j)
	{return (i==j);}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }


void print_vector(ft::vector<int>::iterator ft_it_b, ft::vector<int>::iterator ft_it_e)
{
	std::cout << "ft  :: ";
	for(; ft_it_b != ft_it_e ; ++ft_it_b)
	 {
		std:: cout << *ft_it_b << " ";
	 }
	std::cout << std::endl;
}


int main(void)
{
	

	ft::vector<int>v1(100, 42);
	
	
	clock_t start = clock();
    	std::cout << "	======================>\033[1;31m init and iterators tests \033[0m<============================ " << std::endl;
	// Creating vects of diffrent types

	ft::vector<int> ft_vect_int; // call default constructor 
	ft::vector<int> vect_1(1e6, 5); // call fill constructor
	ft::vector<char> ft_vect_char(1e6, 'a');
	ft::vector<float> ft_vect_float;ft::vector<int>::iterator ft_it;
	ft::vector<char>::iterator ft_it_char(ft_vect_char.begin());
	ft::vector<int>::const_iterator ft_itc(vect_1.end());

	(void)ft_it_char;
	ft_itc = ft_it;


	std::cout << (ft_itc == ft_it) << std::endl;
	std::cout << (ft_itc != ft_it) << std::endl << std::endl;

	for(int i = 0; i < 10; ++i)
		ft_vect_int.push_back(i);
	ft::vector<int> ft_vect_int1(ft_vect_int.begin(), ft_vect_int.end()); // call range constructor 

	ft_it = ft_vect_int1.begin();
	for(ft_it = ft_vect_int1.begin(); ft_it != ft_vect_int1.end(); ++ft_it)
		std::cout << *ft_it << std::endl;


	std::cout << "	======================>\033[1;31m member functions tests \033[0m<============================ " << std::endl;

	std::cout << ft_vect_int.max_size() << std::endl;

	ft::vector<int> ft_vect_int2; 
	for(int i = 0; i < 100; i += 20)
		ft_vect_int2.push_back(i);
	std::cout << "Capacity: " << ft_vect_int2.capacity() << std::endl;
	
	print_vector(ft_vect_int2.begin(), ft_vect_int2.end());

	ft_vect_int2.reserve(50);

	std::cout << "Capacity: " << ft_vect_int2.capacity() << std::endl;
	
	print_vector(ft_vect_int2.begin(), ft_vect_int2.end());
	try
	{
	// ft_vect_int2.reserve(4611686018427387999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Capacity:  " << ft_vect_int2.capacity() << std::endl;

	ft_vect_int1[8] = 19;
	std::cout << ft_vect_int1[8] << std::endl;
	
	ft_vect_int1[0] = 100;
	std::cout << ft_vect_int1.back() << std::endl;

	ft::vector<int> ft_new(25, 0);
	
	std::cout << "vect 2 Capacity : " << ft_vect_int2.capacity() << std::endl;
	std::cout << "vect 2 size: " << ft_vect_int2.size() << std::endl;

	ft_new.assign(ft_vect_int2.begin(), ft_vect_int2.end());

	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;

	print_vector(ft_new.begin(), ft_new.end());

	ft_new.assign(10, 0);

	print_vector(ft_new.begin(), ft_new.end());
	
	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;
	
	ft_new.assign(20, 1);
	
	print_vector(ft_new.begin(), ft_new.end());
	
	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;

	ft::vector<int> ft_new1(10, 0);

	for (int i = 0; i < 2; ++i)
		ft_new1.push_back(i);
	print_vector(ft_new1.begin(), ft_new1.end());
	std::cout << "Capacity:  : " << ft_new1.capacity() << std::endl;
	std::cout << "Size: " << ft_new1.size() << std::endl;

	ft::vector<int> ft_new2;
	std::cout << std::endl;
	// ft_new2.reserve(1);
	ft::vector<int>::iterator ft_it2(ft_new2.begin());

	ft_new2.insert(ft_it2, 900);
	ft_it2++;
	std::cout << std::endl;
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 100);
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 10);
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 20);
	ft_it2 = ft_new2.end();

	std::cout << *(ft_new2.insert(ft_it2, 800))<< std::endl;
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity : " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :" << ft_new2.size() << std::endl << std::endl;

	print_vector(ft_new2.begin(), ft_new2.end());
	ft_it2 = ft_new2.begin();

	ft_new2.insert(ft_it2, 1, 55);
		print_vector(ft_new2.begin(), ft_new2.end());
	ft_it2 = ft_new2.begin();
	ft_it2++;
	ft_new2.insert(ft_it2, 190);
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity :  " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :      " << ft_new2.size() << std::endl << std::endl;
	

	ft::vector<int> ft_new3(1, 0);
	ft_new3.reserve(10);
	ft_new3.push_back(10);
	ft_new3.push_back(20);
	ft_new3.push_back(30);
	ft_new3.push_back(40);
	ft_new3.insert(ft_new3.begin(), ft_new2.begin(), ft_new2.end());

	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl << std::endl;

	std::cout << *(ft_new3.erase(ft_new3.end()  - 3)) << std::endl;
	std::cout << *(ft_new3.erase(ft_new3.begin() + 3, ft_new3.end())) << std::endl;

	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl << std::endl;

	std::cout << "iter " << ft_new3.end() - ft_new3.begin() << std::endl;

	ft::vector<int> ft_new4(20, 0);
	ft_new4 = ft_new3;
	std::cout << "print new4" << std::endl << std::endl;
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;

	ft_new3.push_back(3333);
	ft_new3.push_back(20);
	ft_new3.push_back(30);
	ft_new3.push_back(3333);
	ft_new3.swap(ft_new4);
	std::cout << std::endl;
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;
	std::cout << "print new3" << std::endl << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl;

	ft_new4.clear();
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;
	
	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	print_vector(ft_new2.begin(), ft_new2.end());
	ft::swap(ft_new3, ft_new2);
	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout <<  "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;
	ft_new3.resize(12, 10);
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout <<  "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;
	ft_new3.resize(13, 6);
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;

std::cout << "	======================>\033[1;31m Non-member functions tests \033[0m<============================ " << std::endl << std::endl;
	ft::vector<int> foo (3,200);
	ft::vector<int> bar (3,300);

	if (foo == bar)
		std::cout << "equal\n";
	if (foo != bar)
		std::cout << "not equal \n";
	if (foo < bar)
		std::cout << "foo is less than bar" << std::endl;
	if (foo <= bar)
		std::cout << "foo is less than or equal bar" << std::endl;
	if (bar > foo)
		std::cout << "bar is greater than foo" << std::endl;
	if (foo >= bar)
		std::cout << "foo is greater than or equal bar" << std::endl;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	ft::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n"<< std::endl;
  char foo1[]="Apple";
  char bar1[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo1 and bar1 lexicographically (foo1<bar1):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << ft::lexicographical_compare(foo1,foo1+5,bar1,bar1+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << ft::lexicographical_compare(foo1,foo1+5,bar1,bar1+9,mycomp);
  std::cout << std::endl;

std::cout << "	======================>\033[1;31m iteartors && rev_iterators arithmetic operations tests \033[0m<============================ " << std::endl << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft::size  :" <<ft_new3.size() << " ft::capacity  :" << ft_new3.capacity() << std::endl<< std::endl;

	ft::vector<int>::iterator ft_it3(ft_new3.begin());
	ft::vector<int>::const_iterator ft_it30(ft_new3.begin());
	if (ft_it30 == ft_it3)
		std::cout << "equal \n";

	std::cout << *(4 + ft_it3) << std::endl;
	std::cout << *ft_it3++ << std::endl;
	std::cout << *(ft_it3 + 2) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	std::cout << *(ft_it3 += 1) << std::endl;	
	std::cout << *ft_it3 << std::endl;

	
	std::cout << std::endl;
	ft_it3 = ft_new3.end();
	--ft_it3;
	ft_it3--;
	std::cout << *ft_it3-- << std::endl;
	std::cout << *(ft_it3 - 6) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	std::cout << *(ft_it3 -= 9) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	ft_it3 = ft_new3.begin();
	std::cout << (ft_new3.end() - ft_it3) << std::endl;
	
	std::cout << std::endl;
	std::cout << (ft_it3 < ft_new3.end()) << std::endl;
	std::cout << (ft_it3 > ft_new3.end()) << std::endl;
	std::cout << (ft_it3 <= ft_new3.end()) << std::endl;
	std::cout << (ft_it3 >= ft_new3.end()) << std::endl;
	std::cout << *(ft_it3.base()) << std::endl;
	std::cout << ft_it3[4] << std::endl;


	std::cout << std::endl;
	ft::vector<int>::reverse_iterator ft_rit3(ft_new3.end() - 1);
	ft::vector<int>::const_reverse_iterator ft_crit13(ft_new3.rend());
	if (ft_crit13 == ft_new3.rend())
		std::cout << "equal \n";
	std::cout << *ft_rit3 << std::endl;
	ft_rit3 = ft_new3.rbegin();
	std::cout << *ft_rit3 << std::endl;	
	std::cout << *(ft_rit3 + 8) << std::endl;
	++ft_rit3;
	ft_rit3++;
	std::cout << *ft_rit3 << std::endl;
	ft_rit3 += 5;
	std::cout << *ft_rit3 << std::endl;
	std::cout << *(ft_rit3 - 1) << std::endl;	
	std::cout << *ft_rit3-- << std::endl;
	std::cout << *--ft_rit3 << std::endl;
	std::cout << *ft_rit3 << std::endl;
	std::cout << *(ft_rit3 -= 5) << std::endl;

	std::cout << std::endl;

	ft_rit3 = ft_new3.rend();
	std::cout << ft_rit3[2] << std::endl;
	std::cout << ft_rit3[1] << std::endl;
	std::cout << ft_rit3[0] << std::endl;
	std::cout << "problem" << std::endl;
	std::cout << *(ft_new3.rend() - 2) << std::endl;
	ft::vector<int>::const_reverse_iterator ft_crit3(ft_new3.end() - 1);

	std::cout << *ft_crit3 << std::endl;


	std::cout << std::endl;

	std::cout << (ft_rit3 < ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 <= ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 > ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 >= ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 != ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 == ft_new3.rend()) << std::endl;

	ft_rit3 = ft_new3.rbegin();
	std::cout << *(8 + ft_rit3) << std::endl;

	std::cout << ft_new3.rbegin() - ft_new3.rend() << std::endl;


	


	std::cout << "	======================>\033[1;31m STACK tests \033[0m<============================ " << std::endl << std::endl;

	ft::stack<int> st;
	ft::stack<int> st2(st);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	for(size_t i = 0; i < st.size(); ++i)
	{
		std::cout << st.top() << std::endl;
	}

	std::cout << st2.empty() << std::endl;

	st.pop();
	st.pop();
	st.pop();
	
	st.push(200);
	st.push(300);
	st.push(400);

	for(size_t i = 0; i < st.size(); ++i)
		std::cout << st.top()<< std::endl;

	std::cout << std::endl;

	std::cout << (st2 == st) << std::endl;

	std::cout << (st2 != st) << std::endl;

	std::cout << (st2 > st) << std::endl;
	std::cout << (st2 >= st) << std::endl;
	std::cout << (st2 < st) << std::endl;
	std::cout << (st2 <= st) << std::endl;

	std::cout << (st > st2) << std::endl;
	std::cout << (st >= st2) << std::endl;
	std::cout << (st < st2) << std::endl;
	std::cout << (st <= st2) << std::endl;

	std::cout << "	======================>\033[1;31m MAP tests \033[0m<============================ " << std::endl << std::endl;


	ft::map<int, std::string> ft_map;

	for(int i = 0; i < 1e5; ++i)
		ft_map.insert(ft::make_pair<int, std::string>(i, "value"));
	ft::map<int, std::string>::iterator ft_iter(ft_map.begin());
	ft::map<int, std::string>::iterator ft_iter1(ft_map.end());
	std::cout << (ft_map.insert(ft_iter1, ft::make_pair<int, std::string>(50, "value")))->first << std::endl;

	ft::map<int, std::string> ft_map1(ft_iter, ft_iter1);

	ft::map<int, std::string> ft_map6;
	ft_map6.insert(ft_map.begin(), ft_map.end());
	
	ft_iter = ft_map1.begin();
	ft_iter1 = ft_map1.end();
	for(;ft_iter != ft_iter1; ++ft_iter)
		std::cout << ft_iter->first << " ";
	std::cout << std::endl;

	ft_iter = ft_map6.begin();
	ft_iter1 = ft_map6.end();
	for(;ft_iter != ft_iter1; ++ft_iter)
		std::cout << ft_iter->first << " ";
	std::cout << std::endl;

	ft::map<int, std::string> ft_map3(ft_map1);
	ft_iter = ft_map3.begin();
	ft_iter1 = ft_map3.end();
	for(;ft_iter != ft_iter1; ++ft_iter)
		std::cout << ft_iter->first << " ";
	std::cout << std::endl;
	
	ft_iter = ft_map.end();
	--ft_iter;
	ft::map<int, std::string>::const_iterator ft_citer(ft_iter);
	const ft::map<int, std::string>::iterator ft_citer1(ft_map.end());
	// ft_citer++;
	// ft_citer1--;
	// (void)ft_citer;
	(void)ft_citer1;
	std::cout << ft_citer->first << std::endl;
	
	std::cout << ft_map.empty() << std::endl;

	ft_iter = ft_map3.begin();
	ft_iter1 = ft_map3.end();

	std::cout << ft_iter->first << std::endl;
	ft_map3.erase(ft_iter);
	ft_iter = ft_map3.begin();
	std::cout << ft_iter->first << std::endl;

	
	std::cout << (ft_map3.erase(1)) << std::endl;
	std::cout << (ft_map3.erase(2)) << std::endl;
	std::cout << ft_map.size() << std::endl;

	ft_iter1 = ft_map.end();
	--ft_iter1;

	std::cout << ft_map.size() << std::endl;
	ft_map.erase(ft_map.begin(), ft_map.end());
	std::cout << ft_map.size() << std::endl;

	ft_iter = ft_map.begin();
	ft_iter1 = ft_map.end();

	ft::map<char,std::string> mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	
	ft::map<char,int> foo12,bar12;

	foo12['x']=100;
	foo12['y']=200;

	bar12['a']=11;
	bar12['b']=22;
	bar12['c']=33;

	foo12.swap(bar12);

	std::cout << "foo12 contains:\n";
	for (ft::map<char,int>::iterator it=foo12.begin(); it!=foo12.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar12 contains:\n";
	for (ft::map<char,int>::iterator it=bar12.begin(); it!=bar12.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	  ft::map<char,int> mymap5;

  mymap5['x']=100;
  mymap5['y']=200;
  mymap5['z']=300;

  std::cout << "mymap5 contains:\n";
  for (ft::map<char,int>::iterator it=mymap5.begin(); it!=mymap5.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap5.clear();
  mymap5['a']=1101;
  mymap5['b']=2202;

  std::cout << "mymap5 contains:\n";
  for (ft::map<char,int>::iterator it=mymap5.begin(); it!=mymap5.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	std::cout << mymap5.size() << std::endl;


 ft::map<char,int> mymap10;


  mymap10['a']=100;
  mymap10['b']=200;
  mymap10['c']=300;

  std::cout << "mymap10 contains:\n";

ft::map<char, int>::reverse_iterator rev_iter(mymap10.rbegin());
(void)rev_iter;
  char highest = (--mymap10.end())->first;     // key value of last element
  ft::map<char,int>::iterator it = mymap10.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

{
  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

	ft::map<char,int>::iterator iter(mymap.end());
	iter--;
  ft::pair<char,int> highest = *iter;          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()((*it++), highest) );

}	

	ft::map<char,int> mymap99;
	ft::map<char,int>::iterator it99;

	mymap99['a']=50;
	mymap99['b']=100;
	mymap99['c']=150;
	mymap99['d']=200;

	it99 = mymap99.find('b');
	if (it99 != mymap99.end())
	mymap99.erase (it99);

	// print content:
	std::cout << "elements in mymap99:" << '\n';
	std::cout << "a => " << mymap99.find('a')->second << '\n';
	std::cout << "c => " << mymap99.find('c')->second << '\n';
	std::cout << "d => " << mymap99.find('d')->second << '\n';

{
  ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
}
{
  int psize;
  ft::map<char,int> mymap;
  ft::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);

}
{
   ft::map<char,int> foo,bar;
  foo['a']=100;
  foo['b']=200;
  bar['a']=10;
  bar['z']=1000;
  
  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}

{
  ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  swap(foo,bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	ft::map<char, int>::reverse_iterator rev_it(foo.rbegin());
	ft::map<char, int>::reverse_iterator rev_it1(foo.rend());

	const ft::map<char,int> foo1;

	ft::map<char, int>::const_reverse_iterator rev_itc(foo1.rbegin());
	// ft::map<char, int>::const_reverse_iterator rev_it1c(rev_itc);

// if (rev_itc == foo.rbegin())
// 	std::cout << "equal \n";
// 	for(; rev_itc != foo.rend();rev_it1++)
		// std::cout << rev_itc->first << std::endl;
	(void)rev_itc;
	// (void)rev_it1c;
	for(; rev_it != rev_it1 ; ++rev_it)
		std::cout << rev_it->first << " ";
	std::cout << std::endl;

}
		ft::map<int, std::string> m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(ft::make_pair(i, "value"));
            }
	for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
                ;

	{ int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
                std::cout << it->first;
	}

	{
		ft::map<int, std::string> ft_m1;
		ft::map<int, std::string> ft_m_range;
		for (size_t i = 0; i < 1e5; i++)
                ft_m1.insert(ft::make_pair(i, "string2"));
		ft_m_range.insert(ft_m1.begin(), ft_m1.end());
	}
	{
		int tmp;
	  	int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
            tmp = eit->first;
            m.erase(eit);
            for (; it != m.end(); ++it)
            {
                std::cout << it->first << " ";
            }
			std::cout << std::endl;
	}

	{
		ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
		std::cout << (ft_m.lower_bound(15)->first) << std::endl;
		std::cout << (ft_m.lower_bound(65)->first) << std::endl;
		std::cout << (ft_m.lower_bound(63)->first) << std::endl;
		std::cout << (ft_m.lower_bound(120)->first) << std::endl;
		std::cout << (ft_m.lower_bound(70)->first) << std::endl;
		std::cout << (ft_m.lower_bound(150)->first) << std::endl;

	}
	{
		int myints[] = {75,23,65,42,13};
		ft::set<int> myset (myints,myints+5);

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';

	}
	{
		 ft::set<int> myset;

		myset.insert (100);
		myset.insert (200);
		myset.insert (300);

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myset.clear();
		myset.insert (1101);
		myset.insert (2202);

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		ft::set<int> myset;

		// set some initial values:
		for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

		for (int i=0; i<10; ++i)
		{
			std::cout << i;
			if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
			else
			std::cout << " is not an element of myset.\n";
		}

	}
	{
		ft::set<int> myset;

		myset.insert(20);
		myset.insert(30);
		myset.insert(10);

		std::cout << "myset contains:";
		while (!myset.empty())
		{
			std::cout << ' ' << *myset.begin();
			myset.erase(myset.begin());
		}
		std::cout << '\n';
	}
	{
		int myints[] = {75,23,65,42,13};
		ft::set<int> myset (myints,myints+5);

		std::cout << "myset contains:";
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	{
		ft::set<int> myset;

		for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

		ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ret;
		ret = myset.equal_range(30);

		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
	{
		 ft::set<int> myset;
		ft::set<int>::iterator it;

		// insert some values:
		for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

		it = myset.begin();
		++it;                                         // "it" points now to 20

		myset.erase (it);

		myset.erase (40);

		it = myset.find (60);
		myset.erase (it, myset.end());

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout.precision(10);
	std::cout << NAMESPACE << std::fixed <<  float(clock() - start)/CLOCKS_PER_SEC  << std::endl;
}
