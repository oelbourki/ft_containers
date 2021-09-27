#include "pair.hpp"
#include "xmap.hpp"

int main()
{

    ft::Pair<char,int> p('a',20);
    ft::map<char,int> m;
    std::pair<char,int> p1('a',20);
    m['a'] = 20;
    return 0;
}