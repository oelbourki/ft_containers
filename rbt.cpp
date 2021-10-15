#include "rbtV2.hpp"
#include "pair.hpp"

// pass the root node of your binary tree
int main()
{
    RBT<char,int> r;
    // std::pair<char,int> a('a',1);
    // std::pair<char,int> b('b',2);
    // std::pair<char,int> c('c',3);
    // std::pair<char,int> d('d',4);
    // std::pair<char,int> e('e',40);
    // std::pair<char,int> f('f',6);
    // std::pair<char,int> g('g',7);
    // std::pair<char,int> z('z',66);
    // std::pair<char,int> w('w',10);
    // std::pair<char,int> x('m',8);
    // std::pair<char,int> q('m',8);
    // std::pair<char,int> t('m',8);
    // std::pair<char,int> i('m',8);
    ft::pair<char,int> a('a',1);
    ft::pair<char,int> b('b',2);
    ft::pair<char,int> c('c',3);
    ft::pair<char,int> d('d',4);
    ft::pair<char,int> e('e',5);
    ft::pair<char,int> f('f',6);
    ft::pair<char,int> g('g',7);
    ft::pair<char,int> h('h',8);
    ft::pair<char,int> i('i',9);
    ft::pair<char,int> j('j',10);
    ft::pair<char,int> k('k',11);
    ft::pair<char,int> l('l',12);
    ft::pair<char,int> z('z',66);
    ft::pair<char,int> w('w',10);
    ft::pair<char,int> x('x',8);
    ft::pair<char,int> q('q',8);
    ft::pair<char,int> t('t',8);
    // std::cout << "empty: "<< r.empty() << std::endl;


    r.insert(a);
    r.insert(b);
    r.insert(c); 
    r.insert(d);    
    r.insert(e);
    r.insert(f);
    r.insert(g);
    r.insert(h);
    r.insert(i);
    // r.insert(j);
    // r.insert(k);
    // r.insert(l);
    // r.insert(e);

    // r.print(r.get_root());
    // r.printLevelOrder(r.get_root());
    // std::cout << std::endl;
    r.printBT(r.get_root());
    std::cout << std::endl;
    r.erase('d');
    r.printBT(r.get_root());
    r.erase('f');
    r.printBT(r.get_root());

    return 0;
}





 // std::cout << "root key: "<<r.get_root()->key << std::endl;
    // std::cout << "root value: "<<r.get_root()->value << std::endl;
    // std::cout << "inckey: "<<r.increment(r.increment(r.get_root()))->key << std::endl;
    // std::cout << "incvalue: "<<r.increment(r.increment(r.get_root()))->value << std::endl;
    //  std::cout << "deckey: "<<r.decrement(r.decrement(r.get_root()))->key << std::endl;
    // std::cout << "decvalue: "<<r.decrement(r.decrement(r.get_root()))->value << std::endl;

    // std::cout << "root key: "<<r.geMin(r.get_root())->key << std::endl;
    // std::cout << "root value: "<<r.geMin(r.get_root())->value << std::endl;
    // RBT<char,int>::iterator iter;
    // iter = r.begin();
    // std::cout << "iter key: "<<iter->key << std::endl;
    // std::cout << "iter value: "<<iter->value << std::endl;
    // ++iter;
    // std::cout << "iter key: "<<iter->key << std::endl;
    // std::cout << "iter value: "<<iter->value << std::endl;
    // ++iter;
    // std::cout << "iter key: "<<iter->key << std::endl;
    // std::cout << "iter value: "<<iter->value << std::endl;

    // ++iter;

    // std::cout << "iter key: "<<iter->key << std::endl;
    // std::cout << "iter value: "<<iter->value << std::endl;
    // for (RBT<char,int>::iterator it=r.begin(); it!=r.end(); ++it)
    // {
    //     std::cout << it->key << " => " << it->value << '\n';
    // }
    
    // std::cout << "val: "<< r['c'] << std::endl;
    // r['c'] = 99;
    // std::cout << "val: "<< r['c'] << std::endl;
    
    // std::cout << "count: "<< r.count('e') << std::endl;
    // std::cout << "empty: "<< r.empty() << std::endl;