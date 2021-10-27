#pragma once
#include <iostream>


namespace ft{
    template<class T>
    	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T* z;
		public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		// typedef T& reference;
		// typedef const T& const_refernce;
		// typedef T* pointer;

		// typedef typename value_type::key_type key_type;
        // typedef typename value_type::mapped_type mapped_type;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::reference reference;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::pointer   pointer;
		iterator(T* init):z(init){
		}
		iterator():z(NULL){}
		iterator(iterator &t):z(t.z){}

		~iterator(){}
		operator iterator<const T>() const{ return iterator<const T>(z);}
        iterator(iterator const& rit){ 
            *this = rit;
         }
		iterator base(void) { iterator tmp = z;return --tmp; }
		bool 			operator != (const iterator &v){return this->z != v.z;}
		bool 			operator== (const iterator &v){return this->z == v.z;}
		bool 			operator>(const iterator &v){return this->z > v.z;}
		bool 			operator>=(const iterator &v){return this->z >= v.z;}
		bool 			operator<(const iterator &v){return this->z < v.z;}
		bool 			operator<=(const iterator &v){return this->z <= v.z;}
		difference_type 		operator-(const iterator &v){
			 return (this->z - v.z);}
		iterator 		operator-(size_t v)const {iterator tmp(*this); tmp.z -= v; return tmp;}
		iterator 		operator+(size_t v) const {iterator tmp(*this); tmp.z += v; return tmp;}
		iterator 		&operator++(){this->z++;return *this;}
		iterator 		&operator--(){(this->z)--;return *this;}
		iterator 		operator--(int){iterator tmp = *this;(this->z)--;return tmp;}
		iterator		operator++(int) {iterator copy = *this;this->z++;return copy;}
		iterator& operator+=(const int& rhs){
			this->z += rhs;
			return *this;}
		iterator& operator-=(const int& rhs){
			this->z -= rhs;
			return *this;}
		reference	operator*(){
			return *z;};
		pointer			operator->(){return z;}
		reference operator[] (size_t n){return z[n];}
		friend iterator operator + (size_t l,const iterator& r)
		{
  			return r + l;   
		}
	iterator& operator =(const iterator& a)
        {
            this->z = a.z;
            return *this;
        }
		// operator const_iterator () {return z;}


	};

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


		// operator reverse_iterator<const T>() const{ return reverse_iterator<const T>(z);}

         template<typename rit>
        reverse_iterator(const reverse_iterator<rit>& it)
        {
			// std::cout << "here" << std::endl;
            this->z = --it.base();
        }
		// reverse_iterator(Iterator init){z = init.base();};
		reverse_iterator(Iterator init){
			// std::cout << "here" << std::endl;

			z = --init;};//must work
        // operator
		reverse_iterator(){z = NULL;}
        reverse_iterator(reverse_iterator const& rit){ 
            *this = rit;
         }

        Iterator base(void) const{ Iterator tmp = z;return ++tmp; }
        size_t 		operator-(const reverse_iterator &v){size_t t = (size_t)(z - v.z); return t;}
		bool 			operator>(const reverse_iterator &v){return this->z > v.z;}
		bool 			operator>=(const reverse_iterator &v){return this->z >= v.z;}
		bool 			operator<(const reverse_iterator &v){return this->z < v.z;}
		bool 			operator<=(const reverse_iterator &v){return this->z <= v.z;}
		bool 			operator != (const reverse_iterator &v){return this->z != v.z;}
		bool 			operator== (const reverse_iterator &v){return this->z == v.z;}
		reverse_iterator 		&operator++(){this->z = --this->z;return *this;}
		reverse_iterator 		&operator--(){this->z = ++this->z;return *this;}
        reverse_iterator operator--(int) {reverse_iterator temp = *this;--(*this);return temp;}
        reverse_iterator operator++(int) {reverse_iterator temp = *this;++(*this);return temp;}
        reverse_iterator 		operator-(int v){return reverse_iterator (z + v);}
		reverse_iterator 		operator+(int v){return reverse_iterator (z - v);}
		reference	operator*(){return *z;};
		pointer			operator->(){return &(*z);}
        reverse_iterator& operator =(const reverse_iterator& a)
        {
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
                //    return rhs.base() < lhs.base();
                   return lhs.base() >  rhs.base();

                   }
template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return !(rhs > lhs);
                   }
template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                   return (lhs.base() <  rhs.base());
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
                
    // template< class Iterator >
    // class const_reverse_iterator
	// {
	// 	private:
	// 		Iterator z;
	// 	public:
    //     typedef Iterator iterator_type;
	// 	typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
	// 	typedef typename ft::iterator_traits<Iterator>::value_type	 value_type	;
	// 	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	// 	typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	// 	typedef typename ft::iterator_traits<Iterator>::reference reference;
    //     // typedef ft::pair<const Key, V> val;
	// 	const_reverse_iterator(Iterator init){z = init;};
	// 	const_reverse_iterator(){z = NULL;}
    //     operator iterator_type() {return z;}
    //     operator reverse_iterator<const Iterator>() {return z;}
	// 	bool 			operator != (const const_reverse_iterator &v){return this->z != v.z;}
	// 	bool 			operator== (const const_reverse_iterator &v){return this->z == v.z;}
	// 	const_reverse_iterator 		&operator++(){this->z = --this->z;return *this;}
	// 	const_reverse_iterator 		&operator--(){this->z = ++this->z;return *this;}
	// 	const_reverse_iterator 		&operator--(int){const_reverse_iterator tmp = *this;++this->z;return *this;}
	// 	const_reverse_iterator		operator++(int) {const_reverse_iterator copy = *this;--this->z;return copy;}
	// 	reference	operator*(){return *z;};
	// 	pointer			operator->(){return z;}
    //     const_reverse_iterator& operator =(const const_reverse_iterator& a)
    //     {
    //         this->z = a.z;
    //         return *this;
    //     }
	// };
}