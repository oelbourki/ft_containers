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

    l.insert(it,5);
    return 0;
}