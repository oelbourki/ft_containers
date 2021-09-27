#pragma once
#include <iostream>
#include <map>
namespace ft
{
template<class U1,class U2>
class Pair
{
    private:
    U1 first;
    U2 second;
    public:
    Pair();
    Pair(U1 _key,U2 _val)
    {
        this->first = _key;
        this->second = _val;
    }
    Pair(Pair &p)
    {
        *this = p;
    }
    ~Pair(){}
    Pair& operator= (const Pair& x){
        this->first = x.first;
        this->second = x.second;
        return *this;
    }
    bool 			operator != (const Pair &v){return this->first != v.first;}
    bool 			operator== (const Pair &v){return this->first == v.first;}
    bool 			operator>(const Pair &v){return this->first > v.first;}
    bool 			operator>=(const Pair &v){return this->first >= v.first;}
    bool 			operator<(const Pair &v){return this->first < v.first;}
    bool 			operator<=(const Pair &v){return this->first <= v.first;}
};
}