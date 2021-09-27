// #include "vector.hpp"
#include "ft_vectorx.hpp"
#include <vector>
using namespace std;
template<class T>
void    print(ft_vector<T> &f)
{
    for (size_t i = 0; i < f.size(); i++)
    {
        cout << "<> " << f[i] << '\n';
    }
}
int     main()
{
    ft_vector <int> f;
    ft_vector <int> c;
    // f.assign(10,0);
    // c.assign(10,1);
    vector <int> v;
    vector <int> x;
 
    for (size_t i = 0; i < 50; i++)
    {
        cout << "x capacity"<<x.capacity() << endl;
        cout << "x size"<<x.size() << endl;
        x.push_back(i);
    }
    for (size_t i = 0; i < 1000; i++)
    {
        cout << "f capacity"<<x.capacity() << endl;
        cout << "f size"<<x.size() << endl;
        f.push_back(i);
    }
    // cout << f.at(95) << endl;
    // cout << x.at(95) << endl; 
    // cout <<"capacity" <<f.capacity()  << endl; 
    // cout <<"capacity" <<x.capacity()  << endl; 
    // cout <<"size()" <<f.size()  << endl; 
    // cout <<"size()" <<x.size()  << endl; 
    // x.reserve(10);
    // f.assign(100,99);
    // v.push_back(5);
    // for (size_t i = 0; i < 1000; i++)
    // {
    //     f.push_back(i);
    // }
    ft_vector<int>::iterator y = f.erase(&f[995],&f[997]);
    // vector<int>::iterator iter;
    // // iter - 10;
    // ft_vector<int>::iterator y ;
    // y - 10;
    // for (size_t i = 0; i < 500; i++)
    // {
    //     f.pop_back();
    // }
    for (size_t i = 0; i < f.size(); i++)
    {
        cout << "f " << f[i] << '\n';
    }
    // cout << "f " << f.empty() << endl;
    // cout <<  "v " << v.capacity() << endl;
    // cout <<  "x " << x.capacity() << endl;
    // // cout << "f " << f[0] << endl;
    // cout << "f " << f.capacity() << endl;
    // for (size_t i = 0; i < f.size(); i++)
    // {
    //     cout << "f " << i << " " << f[i] << '\n';
    // }
    // for (size_t i = 0; i < c.size(); i++)
    // {
    //     cout << "c " << i << " " << c[i] << '\n';
    // }
    // f.swap(c);
    // cout << "after\n";
    // for (size_t i = 0; i < f.size(); i++)
    // {
    //     cout << "f " << i << " " << f[i] << '\n';
    // }
    // for (size_t i = 0; i < c.size(); i++)
    // {
    //     cout << "c " << i << " " << c[i] << '\n';
    // }
    // cout <<  "f " << f.capacity() << endl;
    // cout <<  "x " << x.back() << endl;
    // cout <<  "x " << x.front() << endl;
    // cout <<  "x " << x.max_size() << endl;
    // cout <<  "f " << f.max_size() << endl;
    // f.resize(20,9);
    //     for (size_t i = 0; i < f.size(); i++)
    // {
    //     cout << "f " << i << " " << f[i] << '\n';
    // }
    // ft_vector<int>::iterator i;
    // for (i = f.begin(); i  != f.end(); i++)
    // {
    //     cout << "f " << " " << *i << '\n';
    // }
    
    //---------
        vector<int> l;
    vector<int> l1;
   for (size_t i = 0; i < 50; i++)
    {
        l.push_back(i);
    }
    vector<int>::iterator it = l.begin();
    vector<int>::iterator end = l.end();
    l.insert(it,10);
    for (it = l.begin(); it != end; it++)
    {
       cout<< *it << endl;
    }
    vector<int>::iterator it1 = l1.begin();
    l1.insert(it1+8,9);
    for (it = l1.begin(); it != l1.end(); it++)
    {
       cout<< *it << endl;
    }
    //-----
    return 0;
}