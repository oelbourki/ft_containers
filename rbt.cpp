#include "rbtV6.hpp"
#include "pair.hpp"
#include "map.hpp"
// void    print(RBT<char,int> r,ft::pair<char,int> a){
//     std::cout <<"--------------------------" <<std::endl;
//     r.erase(a.first);
//     std::cout <<"-----------Tree-----------" <<std::endl;
//     r.printBT(r.get_root());
//     std::cout <<"--------------------------" <<std::endl;

// }
// // pass the root node of your binary tree
int main()
{
  // std::map<char,int> mymap;
  // std::map<char,int> mymap1;


    RBT<ft::pair<char, int> > r;
  //   RBT<char,int> r1;
    // ft::pair<std::string, int> a;
    // m.insert(ft::make_pair("hello", 1));
    // std::cout << a.first << " "  << a.second << std::endl;
    ft::pair<char, int> b('b',2);
    ft::pair<char, int> c('c',3);
    ft::pair<char, int> d('d',4);
    ft::pair<char, int> e('e',5);
    ft::pair<char, int> f('f',6);
    ft::pair<char, int> g('g',7);
    ft::pair<char, int> h('h',8);
    ft::pair<char, int> i('i',9);
    ft::pair<char, int> j('j',10);
    ft::pair<char, int> k('k',11);
    ft::pair<char, int> l('l',12);
    ft::pair<char, int> z('z',66);
    ft::pair<char, int> w('w',10);
    ft::pair<char, int> x('x',8);
    ft::pair<char, int> q('q',8);
    ft::pair<char, int> t('t',8);
    ft::pair<char, int> m('m',8);
    ft::pair<char, int> n('n',8);
    r.insert(z);
    r.insert(w);
    r.insert(x);
    r.insert(q);
    r.insert(t);
    r.insert(m);
    r.insert(n);
    r.insert(b);
    r.insert(c); 
    r.insert(d);    
    r.insert(e);
    r.insert(f);
    r.insert(g);
    r.insert(h);
    r.insert(i);
    r.insert(j);
    r.insert(k);
    r.print_node(r.insert(l));
    r.print_node(r.insert(l));

    // r.clear();
    // ft::pair<const char, int> a =ft::make_pair('a',8);
    // r1.insert(d);    
    // r1.insert(e);
    // r1.insert(f);
    // r1.insert(g);
    // r1.insert(h);
    // r1.insert(i);
    // r1.insert(j);
    // r1.insert(k);
    // r1.insert(l);
    // r.insert(ft::make_pair('s',5));
    // RBT<char,int>::iterator it=r.begin();
    // RBT<char,int>::iterator it3=r.begin();

    // mymap['a'] = 99;
    // mymap1['a'] = 9;

    // std::map<char,int>::iterator it1 = mymap.begin();
    // std::map<char,int>::iterator it2 = mymap1.begin();
    // std::cout << "first: "<< it->first << std::endl;
    // // std::cout << "*first: "<< (*it).first << std::endl;
    // // std::cout << "*first: "<< (*it1).first << std::endl;
    // // std::cout << "bool: "<< (mymap == mymap1) << std::endl;
    // // std::cout << "bool: "<< (*it1 == *it2) << std::endl;
    // std::cout << "bool: "<< (*it).first << std::endl;
    // std::cout << "bool: "<< (*it == *it3) << std::endl;

//   r['v'] = 5;
//   r['a'] = 5;
//   r['b'] = 5;
// RBT<ft::pair<char, int> >::reverse_iterator rit;
// // rit=r.rbegin();
// // std::cout << rit->first << std::endl;
//   for (rit=r.rbegin(); rit!=r.rend(); ++rit)
//     std::cout << rit->first << " => " << rit->second << '\n';
// RBT<ft::pair<char, int> >::iterator rit;
//   for (rit=r.begin(); rit!=r.end(); ++rit)
//     std::cout << rit->first << " => " << rit->second << '\n';

    // RBT<ft::pair<char, int> >::const_reverse_iterator c_it = r.rbegin();
    // for (RBT<ft::pair<char, int> >::iterator it=r.begin(); it!=r.end(); ++it)
    // {
    //   // if (it != NULL)
    //     std::cout << it->first<< " => " << it->second << '\n';
    // }
    // RBT<ft::pair<char, int> >::iterator it=r.begin();
    // RBT<ft::pair<char, int> >::const_iterator it1=r.begin();
    // it = it1;

  // puts("r");
  // r.printBT(r.get_root());
  // puts("r1");
  // r1.printBT(r1.get_root());
  // r.swap(r1);
  //   puts("r");
  // r.printBT(r.get_root());
  // puts("r1");
  // r1.printBT(r1.get_root());

  // r['a']=10;
  // r['b']=20;
  // r['c']=30;

  // while (!r.empty())
  // {
  //   std::cout << r.begin()->first << " => " << r.begin()->second << '\n';
  //   r.erase(r.begin());
  // }

//     RBT<ft::pair<char, int> > mymap;

//   //   // ft::map<char,int> mymap;

//   // mymap['a']=10;
//   // mymap['b']=20;
//   // mymap['c']=30;

//   ft::pair<RBT<ft::pair<char, int> > ::iterator,bool > ::iterator> ret;
//   // ret = mymap.equal_range('b');

//   // std::cout << "lower bound points to: ";
//   // std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   // std::cout << "upper bound points to: ";
//   // std::cout << ret.second->first << " => " << ret.second->second << '\n';

//     // ft::map<char,int> mymap;

//   // first insert function version (single parameter):
//   // ft::pair<char,int>tt(ft::pair<char,int>('z',200));
//   // ft::pair<char,int>ttt('z',200);
//   // mymap.insert ( ft::pair<char,int>('a',100) );
//   // mymap.insert ( ft::pair<char,int>('z',200) );
//     mymap.insert ( ft::pair<char,int>('z',200));
//   // mymap.insert ( ttt );
// RBT<ft::pair<char, int> >::iterator ret = mymap.begin();
// // std::cout << "***: " << (*it).first << std::endl;

// std::cout << "first: " << it.first->first << std::endl;
// // std::cout << "second: " << it->second << std::endl;


//  RBT<ft::pair<char, int> > mymap;
//   RBT<ft::pair<char, int> >::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key
//   mymap.erase ('f');                  // erasing by key


//   it=mymap.find ('e');
//   // mymap.erase ( it, mymap.end() );    // erasing by range
//   mymap.erase(it);

//   mymap.printBT(mymap.get_root());
// it=++mymap.begin();
//         std::cout << "must be deleted: "<<it->first << std::endl;

  // ft::vector<char> tmp;
  //   for (it=mymap.begin(); it!=mymap.end(); ++it)
  //     tmp.push_back(it->first);
  // for (ft::vector<char>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
  //       std::cout << "must be deleted: "<<*it << std::endl;
  // std::cout << "-------------------------" << std::endl;
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
  // std::cout << "-------------------------" << std::endl;
  // // mymap.erase(it);
  // mymap.printBT(mymap.get_root());
  // for (ft::vector<char>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
  //     mymap.erase(*it);
  // r.printBT(r.get_root());
    
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  return 0;
}

  // ft::map<char,int> mymap;
  // ft::map<char,int>::iterator it;
  // ft::map<char,int>::iterator it1;


  // // insert some values:
  // mymap['a']=10;
  // mymap['b']=20;
  // mymap['c']=30;
  // mymap['d']=40;
  // mymap['e']=50;
  // mymap['f']=60;

  // it=mymap.find('b');
  // // it1 = it;
  // // ++it1;
  // // mymap.erase ( it, mymap.end() );    // erasing by range

  // mymap.erase (it);                   // erasing by iterator

  // mymap.erase ('c');                  // erasing by key
  // // // mymap.erase ('f');                  // erasing by key


  // it=mymap.find ('e');
  // // mymap.erase ( it, mymap.end() );    // erasing by range

  // // // // show content:
  // ft::vector<char> tmp;
  //   for (it=it; it!=mymap.end(); ++it)
  //     tmp.push_back(it->first);
  //     for (ft::vector<char>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
  //       std::cout << *it << std::endl;
  // std::cout << "-------------------------" << std::endl;
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
  // std::cout << "-------------------------" << std::endl;
  // for (ft::vector<char>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
  //     mymap.erase(*it);
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';


    // r.print(r.get_root());
    // r.printLevelOrder(r.get_root());
    // std::cout << std::endl;
  //   r.printBT(r.get_root());
  //    r.erase('j');
  //   r.printBT(r.get_root());
    // std::cout <<"--------------------------" <<std::endl;
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('d');
  //   std::cout <<"-----------Tree-----------" <<std::endl;
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;

  //   r.erase('f');
  //   std::cout <<"-----------Tree-----------" <<std::endl;
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;

  //   r.erase('h');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;

  //   r.erase('e');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('i');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('k');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('b');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('c');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('g');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
  //   r.erase('l');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;
   
  // r.erase('z');
  //   r.printBT(r.get_root());
  //   std::cout <<"--------------------------" <<std::endl;

    // print(r,i);
    // r.printBT(r.get_root());
  //   int index = 0;
  //  for (RBT<char,int>::iterator it=r.begin(); it!=r.end(); ++it)
  //   {
  //       std::cout << it->key << " => " << it->value << '\n';  
  //   }

    // for (int i = 0; i < )
    // --it1;
    // std::cout <<"--------------------------" <<std::endl;
    // it = r.begin();
    // std::cout << "key: "<<it->key << std::endl;

  // r.printBT(r.get_root());
  // r.clear();
  // r.printBT(r.get_root());
    // std::cout << "val:" << r['f'] << std::endl;
    // ft::pair<char,int> s = ft::make_pair('f',5);
    // ft::pair<char,int> s(ft::make_pair('f',5));
    // s = ft::make_pair('f',5);
    // std::cout << "val:" << s.first << std::endl;

    // return 0;
// }





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