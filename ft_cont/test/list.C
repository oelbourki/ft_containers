
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


///////////////////////////List Operation Implementations/////////////////

// Constructors:

// Default constructor:
template <class T>
inline list<T>::list() : length(0) {
  ++number_of_lists;
  node = manager.get_node();
  node->next = node;
  node->prev = node; 
}

// Construct a list of n elements, each a copy of a given value:
template <class T>
inline list<T>::list(size_type n, const T& value) : length(0) {
  ++number_of_lists;
  node = manager.get_node();
  node->next = node;
  node->prev = node; 
  insert(begin(), n, value);
}

// Construct a list initialized to a given range of values:
template <class T>
inline list<T>::list(const T* first, const T* last) : length(0) {
  ++number_of_lists;
  node = manager.get_node();
  node->next = node;
  node->prev = node; 
  insert(begin(), first, last);
}

// Copy constructor:
template <class T>
inline list<T>::list(const list<T>& x) : length(0) {
  ++number_of_lists;
  node = manager.get_node();
  node->next = node;
  node->prev = node; 
  insert(begin(), x.begin(), x.end());
}

// Destructor:

template <class T>
inline list<T>::~list() {
  erase(begin(), end());
  manager.put_node(node);
  if (--number_of_lists == 0) 
    manager.deallocate_buffers();
}

// Assignment and swap:

template <class T>
list<T>& list<T>::operator=(const list<T>& x) {
    if (this != &x) {
      iterator first1 = begin();
      iterator last1 = end();
      const_iterator first2 = x.begin();
      const_iterator last2 = x.end();
      while (first1 != last1 && first2 != last2) 
	*first1++ = *first2++;
      if (first2 == last2)
	erase(first1, last1);
      else
	insert(last1, first2, last2);
    }
    return *this;
}

template <class T>
inline void list<T>::swap(list<T>& x) {
  ::swap(node, x.node);
  ::swap(length, x.length);
}

// Insertion:

template <class T>
inline typename list<T>::iterator list<T>::insert(iterator position, const T& x) {
  link_type tmp = manager.get_node();
  new (&(tmp->data)) T(x);
  tmp->next = position.current;
  tmp->prev = (position.current)->prev;
  (position.current)->prev->next = tmp;
  (position.current)->prev = tmp;
  ++length;
  return tmp;
}

template <class T>
void list<T>::insert(iterator position, const T* first, const T* last) {
    while (first != last) insert(position, *first++);
}
	 
template <class T>
void list<T>::insert(iterator position, const_iterator first,
		     const_iterator last) {
    while (first != last) insert(position, *first++);
}

template <class T>
void list<T>::insert(iterator position, size_type n, const T& x) {
    while (n--) insert(position, x);
}

// Erasure (deletion):

template <class T>
inline void list<T>::erase(iterator position) {
  (position.current)->prev->next = (position.current)->next;
  (position.current)->next->prev = (position.current)->prev;
  (position.current)->data.~T();
  manager.put_node(position.current);
  --length;
}

template <class T>
void list<T>::erase(iterator first, iterator last) {
    while (first != last) erase(first++);
}

// Auxiliary function for implementing special list operations:

template <class T>
inline void list<T>::transfer(iterator position, 
			      iterator first, iterator last) {
  (last.current)->prev->next = position.current;
  (first.current)->prev->next = last.current;
  (position.current)->prev->next = first.current;  
  link_type tmp = (position.current)->prev;
  (position.current)->prev = (last.current)->prev;
  (last.current)->prev = (first.current)->prev; 
  (first.current)->prev = tmp;
}

// Splicing elements or ranges from one list to another (or same) list:

template <class T>
inline void list<T>::splice(iterator position, list<T>& x) {
  if (!x.empty()) {
    transfer(position, x.begin(), x.end());
    length += x.length;
    x.length = 0;
  }
}

template <class T>
inline void list<T>::splice(iterator position, list<T>& x, iterator i) {
  iterator j = i;
  if (position == i || position == ++j) return;
  transfer(position, i, j);
  ++length;
  --x.length;
}

template <class T>
inline void list<T>::splice(iterator position, list<T>& x, 
                            iterator first, iterator last) {
  if (first != last) {
    if (&x != this) {
      difference_type n = 0;
      distance(first, last, n);
      x.length -= n;
      length += n;
    }
    transfer(position, first, last);
  }
}

// Remove all occurrences of a value:

template <class T>
void list<T>::remove(const T& value) {
    iterator first = begin();
    iterator last = end();
    while (first != last) {
	iterator next = first;
	++next;
	if (*first == value) erase(first);
	first = next;
    }
}

// Remove all consecutive duplicate values:

template <class T>
void list<T>::unique() {
    iterator first = begin();
    iterator last = end();
    if (first == last) return;
    iterator next = first;
    while (++next != last) {
	if (*first == *next)
	    erase(next);
	else
	    first = next;
	next = first;
    }
}

// Merge a list with the current list:

template <class T>
void list<T>::merge(list<T>& x) {
    iterator first1 = begin();
    iterator last1 = end();
    iterator first2 = x.begin();
    iterator last2 = x.end();
    while (first1 != last1 && first2 != last2)
	if (*first2 < *first1) {
	    iterator next = first2;
	    transfer(first1, first2, ++next);
	    first2 = next;
	} else
	    ++first1;
    if (first2 != last2) transfer(last1, first2, last2);
    length += x.length;
    x.length= 0;
}

// Reverse the current list:

template <class T>
void list<T>::reverse() {
    if (size() < 2) return;
    for (iterator first = ++begin(); first != end();) {
	iterator old = first++;
	transfer(begin(), old, first);
    }
}    

// Sort the current list:

template <class T>
void list<T>::sort() {
    if (size() < 2) return;
    list<T> carry;
    list<T> counter[64];
    int fill = 0;
    while (!empty()) {
	carry.splice(carry.begin(), *this, begin());
	int i = 0;
	while(i < fill && !counter[i].empty()) {
	    counter[i].merge(carry);
	    carry.swap(counter[i++]);
	}
	carry.swap(counter[i]);         
	if (i == fill) ++fill;
    } 

    for (int i = 1; i < fill; ++i) counter[i].merge(counter[i-1]);
    swap(counter[fill-1]);
}

// Initialize static members:

template <class T>
typename list<T>::size_type list<T>::number_of_lists = 0;

template <class T>
typename list<T>::list_memory_manager_type list<T>::manager;

