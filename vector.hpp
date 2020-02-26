#pragma once

#include <iostream>

template <class T>
class ft_vector
{
private:
    T *_arr;
    int _size;
    int _capacity;
public:
    ft_vector();
    ft_vector(unsigned int n);
    ft_vector(ft_vector const &arr);
    ~ft_vector();
    ft_vector<T> &operator=(ft_vector <T>const &arr);
    T &operator[](int i) const;
    int size() const;
    bool empty() const;
};

template <class T>
ft_vector<T>::ft_vector() : _arr(NULL),_size(0),_capacity(100)
{
}
template <class T>
ft_vector<T>::ft_vector(unsigned int n)
{
    this->_arr = new T[n]();
    this->_size = n;
}

template <class T>
ft_vector<T>::~ft_vector()
{
    delete this->_arr;
    this->_size = 0;
}
template <class T>
ft_vector<T> &ft_vector<T>::operator=(ft_vector <T>const &arr)
{
    delete this->_arr;
    this->_size = arr._capacity;
    this->_arr = new T[this->_capacity]();
    int i = -1;
    while (++i < this->_capacity)
    {
        this->_arr[i] = arr[i];
    }
    return *this;
}
template <class T>
T &ft_vector<T>::operator[](int i) const
{
    if (i >= this->_size)
        throw std::exception();
    else 
        return this->_arr[i];
}
template <class T>
int ft_vector<T>::size() const
{
    return this->_size;
}
template <class T>
ft_vector<T>::ft_vector(ft_vector const &arr)
{
    this->_size = arr._size;
    this->_arr = new T[this->_size]();
    int i = -1;
    while (++i < this->_size)
    {
        this->_arr[i] = arr[i];
    }
}

template <class T>
bool ft_vector<T>::empty() const
{
    if (this->_size > 0)
        return 0;
    else 
        return 1;
}