#pragma once

#include <iostream>
#include <vector>
#include <memory>

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
    void    push_back(T v);
    void    pop_back();
    int     capacity() const;
    void    assign(int n,const T& val);
    T& back();
    ft_vector (const allocator_type& alloc = allocator_type());
};

template <class T>
void    ft_vector<T>::assign(int n,const T& val)
{
    this->_size = 0;
    for (size_t i = 0; i < n; i++)
    {
        this->push_back(val);
    }
}
template <class T>
T&    ft_vector<T>::back()
{
    return (this->_arr[this->size() - 1]);
}
template <class T>
void    ft_vector<T>::pop_back()
{
    if (this->size() <= 0)
        return ;
    else 
    {
        this->_size--;
    }
}
template <class T>
void    ft_vector<T>::push_back(T v)
{
    if (this->size() < this->_capacity)
    {
        this->_arr[this->size()] = v;
        this->_size++;
    }
    else 
    {
        T *new_arr = new T[this->_capacity * 2];
        this->_capacity = this->_capacity * 2;
        int i = -1;
        while (++i < this->_size)
        {
            new_arr[i] = this->_arr[i];
        }
        delete this->_arr;
        this->_arr = new_arr;
        this->_size++;
    }
}
template <class T>
ft_vector<T>::ft_vector() :_size(0),_capacity(100)
{
    this->_arr = new T[100]();
}
// template <class T>
// ft_vector<T>::ft_vector(const allocator_type& alloc = allocator_type()) :_size(0),_capacity(100)
// {
//     this->_arr = new T[100]();
// }
template <class T>
ft_vector<T>::ft_vector(unsigned int n)
{
    this->_arr = new T[n * 2]();
    this->_size = n;
    this->_capacity = this->_size * 2;
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
int ft_vector<T>::capacity() const
{
    return this->_capacity;
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