#pragma once
#include <iostream>


namespace ft{
    template<class T,class value_type,class Tree>
 class iterator_tree : public std::iterator<std::bidirectional_iterator_tag, value_type>
	{
		private:
			T* z;
            Tree const *_r;
		public:
        typedef typename value_type::key_type key_type;
        typedef typename value_type::mapped_type mapped_type;
        typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;
        typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer   pointer;
        


        typedef ft::pair<key_type, mapped_type> val;
		// typedef val& reference;
		// typedef const val& const_refernce;
		// typedef val* pointer;
		
		iterator_tree(T* init,Tree const *r):z(init),_r(r){};
		// iterator_tree(const T* init,const Tree* r):z(init),_r(r){};
		iterator_tree(T* init):z(init){};
		iterator_tree():z(NULL),_r(NULL){};

        iterator_tree(iterator_tree const& rit){ 
            
            *this = rit;
         }

        iterator_tree& operator =(const iterator_tree& a)
            {
                this->z = a.z;
                this->_r = a._r;
                
                //  std::cout << "copy constructor" << std::endl;
                return *this;
            }

        operator iterator_tree<T,const value_type,Tree>() const{ return iterator_tree<T,const value_type,Tree>(z,_r);}
		bool 			operator != (const iterator_tree &v){return this->z != v.z;}
		bool 			operator== (const iterator_tree &v){return this->z == v.z;}
        // -- null
		iterator_tree 		&operator++(){
            this->z = increment(this->z);return *this;}
		iterator_tree 		&operator--(){this->z = decrement(this->z);return *this;}
		iterator_tree 		operator--(int){iterator_tree tmp = *this;this->z = decrement(this->z);return tmp;}
		iterator_tree		operator++(int) {
            iterator_tree copy = *this;this->z = increment(this->z);return copy;}
		value_type &	operator*() const{
            return *z->p;};
		value_type *			operator->()const {
            return z->p;}
     T*
    increment(T* x)
    {
        // if ()
        if (x == NULL)
        {
            return _r->getMin(_r->get_root());
        }
        if (!x->parent && !x->right)
            return NULL;
    if (x->right != 0)
        {
        x = x->right;
        while (x->left != 0)
            x = x->left;
        }
    else
        {
        T* y = x->parent;
        while (y && x && x == y->right)
            {
            x = y;
            y = y->parent;
            }
        if (x->right != y)
            x = y;
        }

    return x;
    }
    T*
    decrement(T* x)
    {
        if (x == NULL)
        {
            // std::cout << "i am here" << std::endl;
            return _r->getMax(_r->get_root());
        }
    if (x->left != 0)
        {
        x = x->left;
        while (x->right != 0)
            x = x->right;
        }
    else
        {
        T* y = x->parent;
        while (y && x && x == y->left)
        // while (x == y->left)
            {
            x = y;
            y = y->parent;
            }
        if (x->left != y)
            x = y;
        }
    return x;
    }
	};
}