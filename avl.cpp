#include "ft_map.hpp"

position = ft::lower_bound(this->begin(),this->end(),val);
class compare
{

};
int     main()
{

    avl<char,int,compare> v;
    std::map<char,int> m;
    v.insert('a',1);
    v.insert('b',1);
    v.insert('c',1);
    v.insert('d',1);
    v.insert('e',1);
    v.insert('f',1);
    v.preOrder(v.get_root());
    v.get_vector();
    return 0;
}