/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:28:09 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/22 17:28:10 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>

template <class T>
class Array
{
private:
    T *_arr;
    int _size;
public:
    Array();
    Array(unsigned int n);
    Array(Array const &arr);
    ~Array();
    Array<T> &operator=(Array <T>const &arr);
    T &operator[](int i) const;
    int size() const;
};
