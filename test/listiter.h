
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
 *   Moved nested iterator classes to a separate file (this file, listiter.h)
 *   Moved special list memory management code to a separate class
 *     defined in file memman.h
 *   Rearranged the order of some of the member function definitions
 *
 * D. Musser, 3/14/96, revised 9/15/2000
 */


// Iterator types (class definitions nested inside class list):
  // class iterator;
  // class const_iterator;
  // class reverse_iterator;
  // class const_reverse_iterator;

    class const_iterator; // incomplete definition, for use in friend decl.

    class iterator : public std::iterator<bidirectional_iterator_tag,
                          value_type, difference_type, pointer, reference> {
        friend class list<T>;
        friend class const_iterator;
    protected:
	link_type current;
	iterator(link_type x) : current(x) {}
    public:
	iterator() {}
	bool operator==(const iterator& x) const { 
            return current == x.current; 
        }
	bool operator!=(const iterator& x) const { 
            return current != x.current; 
        }
	typename iterator::reference operator*() const { 
            return current->data; 
        }
	iterator& operator++() {          // prefix ++
	    current = current->next;
	    return *this;
	}
	iterator operator++(int) {        // postfix ++
	    iterator tmp = *this;
	    ++(*this);
	    return tmp;
	}
	iterator& operator--() {          // prefix --
	    current = current->prev;
	    return *this;
	}
	iterator operator--(int) {        // postfix --
	    iterator tmp = *this;
	    --(*this);
	    return tmp;
	}
    };

    class const_iterator : public std::iterator<bidirectional_iterator_tag,
                   value_type, difference_type, pointer, const_reference> {
      friend class list<T>;
    protected:
        link_type current;
	const_iterator(link_type x) : current(x) {}
    public:     
	const_iterator() {}
	const_iterator(const iterator& x) : current(x.current) {}
	bool operator==(const const_iterator& x) const { 
            return current == x.current; 
        } 
	bool operator!=(const const_iterator& x) const { 
            return current != x.current; 
        } 
	typename const_iterator::reference operator*() const { 
            return current->data; 
        }
	const_iterator& operator++() {       // prefix ++
	    current = current->next;
	    return *this;
	}
	const_iterator operator++(int) {     // postfix ++
	    const_iterator tmp = *this;
	    ++(*this);
	    return tmp;
	}
	const_iterator& operator--() {       // prefix --
	    current = current->prev;
	    return *this;
	}
	const_iterator operator--(int) {     // postfix --
	    const_iterator tmp = *this;
	    --(*this);
	    return tmp;
	}
    };

  // Define reverse iterators using reverse iterator adaptors:

    typedef std::reverse_iterator<iterator>
        reverse_iterator; 

    typedef std::reverse_iterator<const_iterator>
	const_reverse_iterator;

