#pragma once
#include <iostream>
#include <map>
namespace ft
{
    template <class T1, class T2> struct pair
{
    public:
    typedef T1    key_type;
    typedef T2    mapped_type;
    key_type first;
    mapped_type second;

    pair():first(),second()
    {};
    template<class U, class V> 
    pair (const pair<U,V>& pr):first(pr.first),second(pr.second)
    {};
    pair (const key_type& a, const mapped_type& b):first(a),second(b)
    {};
    pair& operator= (const pair& pr)
    {
        if(this == &pr)
            return *this;
        this->first = pr.first;
        this->second = pr.second;
        return *this;
    }
};
template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ std::cout << "i am here" << std::endl;
  return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

template <class T1,class T2>
  ft::pair< T1,T2> make_pair (T1 x, T2 y)
  {
    return ( ft::pair< T1,T2>(x,y) );
  }

template<class A>
void swap(A& a,A& b){
    A tmp = a;
    a = b;
    b = tmp;
    }
template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
    while (first1!=last1) {
        if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
        return false;
        ++first1; ++first2;
    }
    return true;
    }
    template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false;
        else if (*first1<*first2) return true;
        ++first1; ++first2;
    }
    return (first2!=last2);
    }

        template <class Iterator>
    class iterator_traits{
        public:
        	typedef typename Iterator::difference_type       difference_type;
        	typedef typename Iterator::value_type	        value_type;
        	typedef typename Iterator::pointer               pointer;
        	typedef typename Iterator::reference             reference;
        	typedef typename Iterator::iterator_category	    iterator_category;
    };
    template <class T>
    class iterator_traits<T*>{
         public:
        	typedef ptrdiff_t                           difference_type;
        	typedef T	                                value_type;
        	typedef T*                                  pointer;
        	typedef T&                                  reference;
        	typedef std::random_access_iterator_tag	    iterator_category;
    };
    template <class T>
    class iterator_traits<const T*>{
           public:
        	typedef ptrdiff_t                           difference_type;
        	typedef T	                                value_type;
        	typedef const T*                            pointer;
        	typedef const T&                            reference;
        	typedef std::random_access_iterator_tag	    iterator_category;
    };
    // template< class Iterator >
    // class const_reverse_iterator;
    template< class Iterator >
    class reverse_iterator
	{
		private:
			Iterator z;
		public:
        typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type	 value_type	;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		operator reverse_iterator<const Iterator>() const{ return reverse_iterator<const Iterator>(z);}

        template<typename rit>
        reverse_iterator(const reverse_iterator<rit>& it)
        {
          std::cout << "i am here" << std::endl;
            *this = it;
        }
		// reverse_iterator(Iterator init){z = init.base();};
		reverse_iterator(Iterator init){z = init;};//must work
        // operator
		reverse_iterator(){z = NULL;}
        reverse_iterator(reverse_iterator const& rit){ 
            *this = rit;
         }

        Iterator base(void) const { Iterator tmp = z;return ++tmp; }
        size_t 		operator-(const reverse_iterator &v){size_t t = (size_t)(z - v.z); return t;}
		bool 			operator>(const reverse_iterator &v){return this->z > v.z;}
		bool 			operator>=(const reverse_iterator &v){return this->z >= v.z;}
		bool 			operator<(const reverse_iterator &v){return this->z < v.z;}
		bool 			operator<=(const reverse_iterator &v){return this->z <= v.z;}
		bool 			operator != (const reverse_iterator &v){return this->z != v.z;}
		bool 			operator== (const reverse_iterator &v){ std::cout << "from here" << std::endl;
      return this->z == v.z;}
		reverse_iterator 		&operator++(){this->z = --this->z;return *this;}
		reverse_iterator 		&operator--(){this->z = ++this->z;return *this;}
        reverse_iterator operator--(int) {reverse_iterator temp = *this;--(*this);return temp;}
        reverse_iterator operator++(int) {reverse_iterator temp = *this;++(*this);return temp;}
        reverse_iterator 		operator-(int v){return reverse_iterator (z + v);}
		reverse_iterator 		operator+(int v){return reverse_iterator (z - v);}
		reference	operator*() const {return *z;};
		pointer			operator->() const {return &(operator*());}
        reverse_iterator& operator =(const reverse_iterator& a)
        {
          std::cout << "copyyy" << std::endl;
            this->z = a.z;
            return *this;
        }
        reverse_iterator& operator+=(const int& rhs){
            // puts("also");
			this->z -= rhs;
			return *this;}
		reverse_iterator& operator-=(const int& rhs){
			this->z += rhs;
			return *this;}
		reference operator[] (size_t n){return z[n];}

	};
    template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                     std::cout << "*****" << std::endl;
                   return lhs.base() == rhs.base();
                   }
template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return !(lhs == rhs);
                   }
template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return rhs.base() < lhs.base();
                   }
template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return !(rhs > lhs);
                   }
template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return (rhs < lhs);
                   }
template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return !(lhs < rhs);
                   }
template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){
        return rhs.base() - lhs.base();
    }
    template <class Iterator>
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it){
                 return reverse_iterator<Iterator>(rev_it.base() - n);
             }
                
    template< class Iterator >
    class const_reverse_iterator
	{
		private:
			Iterator z;
		public:
        typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type	 value_type	;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
        // typedef ft::pair<const Key, V> val;
		const_reverse_iterator(Iterator init){z = init;};
		const_reverse_iterator(){z = NULL;}
        operator iterator_type() {return z;}
        operator reverse_iterator<const Iterator>() {return z;}
		bool 			operator != (const const_reverse_iterator &v){return this->z != v.z;}
		bool 			operator== (const const_reverse_iterator &v){return this->z == v.z;}
		const_reverse_iterator 		&operator++(){this->z = --this->z;return *this;}
		const_reverse_iterator 		&operator--(){this->z = ++this->z;return *this;}
		const_reverse_iterator 		&operator--(int){const_reverse_iterator tmp = *this;++this->z;return *this;}
		const_reverse_iterator		operator++(int) {const_reverse_iterator copy = *this;--this->z;return copy;}
		reference	operator*(){return *z;};
		pointer			operator->(){return z;}
        const_reverse_iterator& operator =(const const_reverse_iterator& a)
        {
            this->z = a.z;
            return *this;
        }
	};

    // class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	// {
	// 	private:
	// 		T* z;
	// 	public:
	// 	typedef T value_type;
	// 	typedef T& reference;
	// 	typedef const T& const_refernce;
	// 	typedef T* pointer;
	// 	const_iterator(T* init){z = init;};
	// 	const_iterator(){z = NULL;}
	// 	bool 			operator != (const const_iterator &v){return this->z != v.z;}
	// 	bool 			operator== (const const_iterator &v){return this->z == v.z;}
	// 	const_iterator 		&operator++(){this->z = increment(this->z);return *this;}
	// 	const_iterator 		&operator--(){this->z = decrement(this->z);return *this;}
	// 	const_iterator 		&operator--(int){const_iterator tmp = *this;(this->z)--;return *this;}
	// 	const_iterator		operator++(int) {const_iterator copy = *this;this->z++;return copy;}
	// 	value_type&	operator*(){return *z;};
	// 	pointer			operator->(){return z;}
	// };
}