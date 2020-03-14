#include "ft_list.hpp"
// #include <iostream>
// #include <iterator>
// #include <vector>
using namespace std;

int     main()
{
    ft::list<int> l;

    // list<int> l;
    // list<int> l1;
    // l.assign(20,9);
    ft::list<int>::iterator it = l.begin();
    // l.insert(it,10);

    // l.insert(it,5);
    for (size_t i = 0; i < 5; i++)
    {
        l.insert(it,9);
        it++;
    }
    ft::list<int>::iterator it1 = l.begin();
    ft::list<int>::iterator end = l.end();
    for (; it1 != end; it1++)
    {
       cout << *it << endl;
    }
    // l.~list();
    // list<int> t;
    // t.insert()
    return 0;
}