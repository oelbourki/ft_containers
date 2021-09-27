
/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 */

/*
 * Adapted for tutorial purposes from the 10/31/95 HP STL release:
 *   Removed all dependence on allocators
 *   Moved nested iterator classes to a separate file (listiter.h)
 *   Moved special list memory management code to a separate class
 *     defined in file memman.h
 *   Rearranged the order of some of the member function definitions
 *
 * D. Musser, 3/14/96, revised 9/15/2000
 */


#ifndef LIST_H
#define LIST_H

#include <functional>
#include <algorithm>
#include <iterator>
#include <climits>
#include "memman.h"

#ifdef __ITERATOR_NEEDED
namespace std {    

  // According to ANSI C++ this should be defined but it is missing
  // from current GNU C++. So we add it here, if __ITERATOR_NEEDED is defined.
  // (MSVC++ 6.0 defines it, but incorrectly.)

  template <class _Category, class _Tp, class _Distance = ptrdiff_t,
            class _Pointer = _Tp*, class _Reference = _Tp&>
  struct iterator {
    typedef _Category  iterator_category;
    typedef _Tp        value_type;
    typedef _Distance  difference_type;
    typedef _Pointer   pointer;
    typedef _Reference reference;
  };
};
#endif

// Open a new namespace, to avoid conflict with std::list
namespace list_presentation {

using namespace std;

template <class T>
class list {

 protected:
  // Representation (doubly linked):
    struct list_node {
	list_node* next;
	list_node* prev;
	T data;
    };

 public:      

  // Types:

    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

 private:
    typedef T* pointer;
    typedef list_node* link_type;
    typedef list_memory_manager<list_node> list_memory_manager_type;

 protected:
    link_type node;
    size_type length;
    static size_type number_of_lists;
    static list_memory_manager_type manager;

 public:

  // Iterator types (defined by nested classes and typedefs)
  // class iterator;
  // class const_iterator;
  // class reverse_iterator;
  // class const_reverse_iterator;
#include "listiter.h"

  // Constructors:
    list();
    list(size_type n, const T& value = T());
    list(const T* first, const T* last);
    list(const list<T>& x);

  // Destructor:
    ~list();

  // Assignment and swap:
    list<T>& operator=(const list<T>& x);
    void swap(list<T>& x);

  // Queries:
    iterator begin() { return node->next; }
    iterator end() { return node; }
    bool empty() const { return length == 0; }
    size_type size() const { return length; }
    size_type max_size() const { 
       return max(size_type(1), size_type(UINT_MAX/sizeof(T)));
    }
    reference front() { return *begin(); }
    reference back() { return *(--end()); }

  // Queries on constant lists:
    const_iterator begin() const { return node->next; }
    const_iterator end() const { return node; }
    const_reference front() const { return *begin(); }
    const_reference back() const { return *(--end()); }

  // Queries for reverse traversal:
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }

  // Queries for reverse traversal of constant lists:
    const_reverse_iterator rbegin() const { 
        return const_reverse_iterator(end()); 
    }
    const_reverse_iterator rend() const { 
        return const_reverse_iterator(begin());
    } 

  // Insertion:
    iterator insert(iterator position, const T& x);
    void insert(iterator position, const T* first, const T* last);
    void insert(iterator position, const_iterator first,
		const_iterator last);
    void insert(iterator position, size_type n, const T& x);
    void push_front(const T& x) { insert(begin(), x); }
    void push_back(const T& x) { insert(end(), x); }

  // Erasure (deletion):
    void erase(iterator position);
    void erase(iterator first, iterator last);
    void pop_front() { erase(begin()); }
    void pop_back() { iterator tmp = end(); erase(--tmp); }

 protected:
  // Auxiliary function for implementing splice functions:
    void transfer(iterator position, iterator first, iterator last);

 public:
  // Splicing elements or ranges from one list to another (or same) list:
    void splice(iterator position, list<T>& x);
    void splice(iterator position, list<T>& x, iterator i);
    void splice(iterator position, list<T>& x, 
                iterator first, iterator last);

  // Remove all occurrences of a value:
    void remove(const T& value);

  // Remove all consecutive duplicate values:
    void unique();

  // Merge a list with the current list:
    void merge(list<T>& x);

  // Reverse the current list:
    void reverse();

  // Sort the current list:
    void sort();

};  // end class list;

// Equality and less-than operations:

template <class T>
inline bool operator==(const list<T>& x, const list<T>& y) {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class T>
inline bool operator<(const list<T>& x, const list<T>& y) {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

#include "list.C"

}; // close namespace list_presentation 

#endif

