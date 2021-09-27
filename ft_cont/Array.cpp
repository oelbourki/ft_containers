/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:28:06 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/22 17:28:07 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array() : _arr(NULL),_size(0)
{
}
template <class T>
Array<T>::Array(unsigned int n)
{
    this->_arr = new T[n]();
    this->_size = n;
}

template <class T>
Array<T>::~Array()
{
    delete this->_arr;
    this->_size = 0;
}
template <class T>
Array<T> &Array<T>::operator=(Array <T>const &arr)
{
    delete this->_arr;
    this->_size = arr._size;
    this->_arr = new T[this->_size]();
    int i = -1;
    while (++i < this->_size)
    {
        this->_arr[i] = arr[i];
    }
    return *this;
}
template <class T>
T &Array<T>::operator[](int i) const
{
    if (i >= this->_size)
        throw std::exception();
    else 
        return this->_arr[i];
}
template <class T>
int Array<T>::size() const
{
    return this->_size;
}
template <class T>
Array<T>::Array(Array const &arr)
{
    *this = arr;
}
int     main()
{
    Array <int> f(10);
    Array <int> c(f);
    c[2] = 5;
    std::cout << c[2] << std::endl;
    return 0;
}