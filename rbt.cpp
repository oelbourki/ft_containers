#include "rbt.hpp"

int main()
{
    RBT<char,int> r;
    std::pair<char,int> a('a',1);
    std::pair<char,int> b('b',2);
    std::pair<char,int> c('c',3);
    std::pair<char,int> d('d',4);
     std::pair<char,int> e('e',40);
    //   std::pair<char,int> f('f',6);
       std::pair<char,int> g('g',7);
        std::pair<char,int> x('f',8);
         std::pair<char,int> z('z',66);
          std::pair<char,int> w('w',10);
    r.insert(d);
    r.insert(b);
    r.insert(c);
    r.insert(a);
    // r.insert(f);
    r.insert(z);
    r.insert(g);
    r.insert(w);
    r.insert(x);
    r.print(r.get_root());
    return 0;
}