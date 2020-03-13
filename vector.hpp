#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

// template <> class allocator<void> {
// public:
//   typedef void* pointer;
//   typedef const void* const_pointer;
//   typedef void value_type;
//   template <class U> struct rebind { typedef allocator<U> other; };
// };
// template < class T, class Alloc = std::allocator<T> > class ft_vector1;
template <class T>
class ft_vector
{
private:
    void    expand();
    void    expand(size_t n);
    T *_arr;
    int _size;
    int _capacity;
    static const size_t _max_size = 4611686018427387903;
public:

    typedef int size_type;

    // class iterator
    // {
    //     public:
    //         typedef iterator self_type;
    //         typedef T value_type;
    //         typedef T& reference;
    //         typedef T* pointer;
    //         typedef std::forward_iterator_tag iterator_category;
    //         typedef int difference_type;
    //         iterator(pointer ptr) : ptr_(ptr) { }
    //         self_type operator++() { self_type i = *this; ptr_++; return i; }
    //         self_type operator++(int junk) { ptr_++; return *this; }
    //         reference operator*() { return *ptr_; }
    //         pointer operator->() { return ptr_; }
    //         bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
    //         bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
    //     private:
    //         pointer ptr_;
    // };

    typedef T* iterator;
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
    T& front();
    void    clear();
    size_t  max_size();
    void    swap(ft_vector<T> &);
    void reserve(size_t);
    void resize (size_t n, T val = 0);
    iterator   begin()
    {
        return iterator(this->_arr);
    }
    iterator    end()
{
    return iterator(this->_arr + this->_size);
}
    iterator erase (iterator position);
    iterator erase (iterator first, iterator last);
};
template <class T >
T*  ft_vector<T>::erase(T* first, T* last)
{
    int copy = this->_size;
    T *new_arr = new T[this->_capacity]();
    ft_vector<T>::iterator i,end,ret;
    int j = 0;
    end = this->end();
    for (i = this->begin(); i != end; i++)
    {
        if (i >= first && i <= last)
        {
            this->_size--;
            continue;
        }
        if ((i - 1) == last)
            ret = &new_arr[j];
        new_arr[j] = *i;
        j++;
    }
    delete this->_arr;
    this->_arr = new_arr;
    return ret;
}
template <class T >
T*  ft_vector<T>::erase(T* position)
{
    T *new_arr = new T[this->_capacity]();
    ft_vector<T>::iterator i,ret;
    int j = 0;
    for (i = this->begin(); i != this->end(); i++)
    {
        if (i == position)
            continue;
        if ((i - 1) == position)
            ret = &new_arr[j];
        new_arr[j] = *i;
        j++;
    }
    delete this->_arr;
    this->_arr = new_arr;
    this->_size--;
    return ret;
}
template <class T >
void    ft_vector<T>::expand(size_t n)
{
    T *new_arr = new T[n]();
    int i = -1;
    while (++i < this->_size)
    {
        new_arr[i] = this->_arr[i];
    }
    delete this->_arr;
    this->_arr = new_arr;
    this->_capacity = n;
}
template <class T >
void    ft_vector<T>::expand()
{
    size_t n = this->_capacity * 2;
    T *new_arr = new T[n]();
    int i = -1;
    while (++i < this->_size)
    {
        new_arr[i] = this->_arr[i];
    }
    delete this->_arr;
    this->_arr = new_arr;
    this->_capacity = n;
}

// template <class T>
// iterator    ft_vector<T>::end()
// {
//     return iterator(this->_arr + this->_size);
// }
// template <class T>
// iterator    ft_vector<T>::begin()
// {
//     return iterator(this->_arr);
// }
// template <class T>
// T*    ft_vector<T>::begin()
// {
//     return &this->_arr[0];
// }
template <class T>
void    ft_vector<T>::resize(size_t n,T val)
{
    if (n < this->size())
    {
        this->_size = n;
        return ;
    }
    int range =  n - this->size();
    for (size_t i = 0;i < range ; i++)
    {
        this->push_back(val);
    }
}
template <class T>
void    ft_vector<T>::reserve(size_t n)
{
    if (n <= this->_capacity)
        return;
    else 
    {
        expand(n);
        // T *new_arr = new T[n]();
        // int i = -1;
        // while (++i < this->_size)
        // {
        //     new_arr[i] = this->_arr[i];
        // }
        // delete this->_arr;
        // this->_arr = new_arr;
        // this->_capacity = n;
    }
}
template <class T>
void    ft_vector<T>::swap(ft_vector<T> &v)
{
    ft_vector f(v);
    v = *this;
    *this = f;
}
template <class T>
void    ft_vector<T>::clear()
{
    this->_size = 0;
}
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
size_t    ft_vector<T>::max_size()
{
    return (this->_max_size);
}
template <class T>
T&    ft_vector<T>::back()
{
    return (this->_arr[this->size() - 1]);
}
template <class T>
T&    ft_vector<T>::front()
{
    return (this->_arr[0]);
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
    if (this->size() == this->_capacity)
        expand();
        this->_arr[this->size()] = v;
        this->_size++;
    // if (this->size() < this->_capacity)
    // {
    //     this->_arr[this->size()] = v;
    //     this->_size++;
    // }
    // else 
    // {
    //     T *new_arr = new T[this->_capacity * 2];
    //     this->_capacity = this->_capacity * 2;
    //     int i = -1;
    //     while (++i < this->_size)
    //     {
    //         new_arr[i] = this->_arr[i];
    //     }
    //     delete this->_arr;
    //     this->_arr = new_arr;
    //     this->_size++;
    // }
}
template <class T>
ft_vector<T>::ft_vector() :_size(0),_capacity(100)
{
    this->_arr = new T[100]();
}
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
    this->_capacity = arr._capacity;
    this->_size = arr.size();
    this->_arr = new T[this->_capacity]();
    // if (this->_arr == NULL)
    //     puts("NULL");
    int i = -1;
    while (++i < this->_size)
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