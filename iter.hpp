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