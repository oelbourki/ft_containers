#pragma once
#include <iostream>
#include <map>
namespace ft
{
template<class U1,class U2>
class pair
{

    public:
    U1 first;
    U2 second;
    pair();
    pair(U1 _key,U2 _val)
    {
        this->first = _key;
        this->second = _val;
    }
    pair(pair &p)
    {
        *this = p;
    }
    ~pair(){}
    pair& operator= (const pair& x){
        this->first = x.first;
        this->second = x.second;
        return *this;
    }
    bool 			operator != (const pair &v){return this->first != v.first;}
    bool 			operator== (const pair &v){return this->first == v.first;}
    bool 			operator>(const pair &v){return this->first > v.first;}
    bool 			operator>=(const pair &v){return this->first >= v.first;}
    bool 			operator<(const pair &v){return this->first < v.first;}
    bool 			operator<=(const pair &v){return this->first <= v.first;}
};
}