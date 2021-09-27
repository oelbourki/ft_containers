#pragma once
//remove uneeded ; after function
#include <iostream>
#include <memory>
namespace ft
{
	template < class T >
	class list
	{
		public:
		struct Node
		{
			T data;
			struct Node *next;
			struct Node *prev;
		};
		typedef int size_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef Node* link_type;
		typedef ptrdiff_t difference_type;
		class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
		};
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			friend class list<T>;
			private:
				Node* z;
			public:
			typedef T value_type;
			typedef T& reference;
			typedef const T& const_refernce;
			typedef T* pointer;
			iterator(Node* init){z = init;};
			iterator(){z = NULL;}
			bool 			operator != (const iterator &v){return this->z != v.z;}
			bool 			operator== (const iterator &v){return this->z == v.z;}
			bool 			operator>(const iterator &v){return this->z > v.z;}
			bool 			operator>=(const iterator &v){return this->z >= v.z;}
			bool 			operator<(const iterator &v){return this->z < v.z;}
			bool 			operator<=(const iterator &v){return this->z <= v.z;}
			iterator 		&operator++(){z = z->next;;return *this;}
			iterator 		&operator--(){z = z->prev;return *this;}
			iterator 		&operator--(int){iterator tmp = *this;(--this);return *this;}
			iterator		operator++(int) {iterator copy = *this;++(*this);return copy;}
			reference		operator*(){return z->data;};
		};
		typedef std::reverse_iterator<iterator>
			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>
			const_reverse_iterator;
		explicit list (){
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
		}//default
		explicit list (size_type n, const value_type& val = value_type()){
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
			insert(begin(),n,val);
		}/// fill
		template <class InputIterator>
		list (InputIterator first, InputIterator last)
		{
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
			insert(begin(),first,last);
		}// range
		list (const list& x)
		{
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
			insert(begin(),x.first,x.last);
		}//copy
		~list(){
			erase(begin(),end());
			delete node;
		};
		/*--------------------------------*/
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last);//range//done
		void assign (size_type n, const value_type& val);//fill/done
		reference back() { return *(--end()); };//done
		const_reference back() const{ return *(--end()); }//done
		iterator begin(){return node->next;};//done
		const_iterator begin() const{return node->next;};//done
		void clear(){erase(begin(),end());length = 0;}//done
		bool empty() const {return this->length == 0;};//done
		iterator end() {return node;};//done
		const_iterator end() const{return node;};//done
		iterator erase (iterator position);//done
		iterator erase (iterator first, iterator last);//done
		reference front(){return *begin();};//done
		const_reference front() const{return *begin();};//done
		iterator insert (iterator position, const value_type& val);//single element (1)//done
		void insert (iterator position, size_type n, const value_type& val);//fill (2)//done
		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);//range (3)//done
		size_type max_size() const{return this->length;};//done
		void merge (list& x);//done
		template <class Compare>
			void merge (list& x, Compare comp);//done
		list& operator= (const list& x);//copy (1)//done
		void pop_front() { erase(begin()); }
		void pop_back() { iterator tmp = end(); erase(--tmp); }
		void push_back (const value_type& val){insert(end(),val);}//done
		void push_front (const value_type& val){insert(begin(),val);}//done
		reverse_iterator rbegin(){return reverse_iterator(end());};//done
		const_reverse_iterator rbegin() const{return const_reverse_iterator(end());}//done
		void remove (const value_type& val);//done
		template <class Predicate>
			void remove_if (Predicate pred);//done
		reverse_iterator rend(){return const_reverse_iterator(begin());};//done
		const_reverse_iterator rend() const{return const_reverse_iterator(begin());};//done
		void resize (size_type n, value_type val = value_type());
		void reverse();//done
		size_type size() const{return this->length;};//done
		void sort();
		template <class Compare>
			void sort (Compare comp);
		void splice (iterator position, list& x);//entire list (1)	//done
		void splice (iterator position, list& x, iterator i);//single element (2)	//done
		void splice (iterator position, list& x, iterator first, iterator last);//element range (3)	//done
		void swap (list& x);//done
		void unique();//done
		template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred);
		// template <class T>
		// 	bool operator== (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator!= (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator<  (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator<= (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator>  (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator>= (const list<T>& lhs, const list<T>& rhs);
		/*----------------------------*/
		private:
			size_t length;
			link_type node;
			link_type creat_node()
			{
				link_type tmp = new Node;
				tmp->next = tmp;
				tmp->prev = tmp;
				return tmp;
			};
			// value_type value_type(){return 0;}
			void	transfer(iterator position,iterator first,iterator last)
			{
				(last.z)->prev->next = position.z;
				(first.z)->prev->next = last.z;
				(position.z)->prev->next = first.z;
				link_type tmp = (position.z)->prev;
				(position.z)->prev = (last.z)->prev;
				(last.z)->prev = (first.z)->prev;
				(first.z)->prev = tmp;
			}
			template <class InputIterator>
			void distance(InputIterator first,InputIterator last,difference_type& n)
			{
				if (first == last)
					return ;
				for ( n = 0; first != last; n++)
				{
					first++;
				}
				return ;
			}

				

	};
	template<class T>
	typename list<T>::iterator list<T>::insert(iterator position, const value_type& val)
	{
		Node* tmp = creat_node();
		tmp->data = val;
		new (&(tmp->data)) T(val);
		tmp->next = position.z;
		tmp->prev = (position.z)->prev;
		(position.z)->prev->next = tmp;
		(position.z)->prev = tmp;
		++length;
		return tmp;
	}
	template<class T>
	void list<T>::insert (iterator position, size_type n, const value_type& val)
	{
		while (n--)
			insert(position,val);
	}
	template<class T>
	template <class InputIterator>
		void list<T>::insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
				insert(position,*(first++));			
		}
	template<class T>
	typename list<T>::iterator list<T>::erase (iterator position)
	{
		link_type tmp = position.z;
		position.z->prev->next = position.z->next;
		position.z->next->prev = position.z->prev;
		// position.z.~T();
		// delete tmp;
		// position.z->next = NULL;
		// p->next = free_list;
		// free_list = p;
		--length;
		return ++position;
	}
	template<class T>
	typename list<T>::iterator list<T>::erase (iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
		return first;
	}
	template<class T>
	list<T>& list<T>::operator= (const list<T>& x)
	{
		if (this != &x)
		{
			iterator f1 = begin();
			iterator e1 = end();
			const_iterator f2 = x.begin();
			const_iterator e2 = x.end();
			while (f1 != e1 && f2 != e2)
				*f1++ = *f2++;
			if (f2 == e2)
				erase(f1,e1);
			else 
				insert(e1,f2,e2);
			return *this;			

		}
	}
	template <class T>
		void swap (list<T>& x, list<T>& y)
		{
			T tmp;
			tmp = x;
			x = y;
			y = x;
		}
	template <class T>
		void list<T>::swap (list<T>& x)
		{
			swap(node,x.node);
			swap(length,x.length);
		}
	template <class T>
		void list<T>::splice (iterator position, list& x)
		{
			if (!x.empty())
			{
				transfer(position,x.begin(),x.end());
				length += x.length;
				x.length = 0;
			}
		}
	template <class T>
		void list<T>::splice (iterator position, list& x, iterator i)
		{
			iterator j = i;
			if (position == i || position == ++j)
				return ;
			transfer(position,i,j);
			++length;
			--x.length;
		}
	template <class T>	
		void list<T>::splice (iterator position, list& x, iterator first, iterator last)
		{
			if (first != last)
			{
				if (this != &x)
				{
					difference_type n = 0;
					distance(first,last,n);
					x.length -= n;
					length += n;
				}
				transfer(position,first,last);
			}
		}
	template<class T>
		void list<T>::remove (const value_type& val)
		{
			iterator begin = begin();
			iterator end = end();
			while (begin != end)
			{
				iterator next = begin;
				++next;
				if (*begin == val)
					erase(begin);
				begin = next;
			}
		}
	template<class T>
		void list<T>::unique()
		{
			iterator first = begin();
			iterator last = end();
			if (first == last)
				return;
			iterator next = first;
			while (++next != last)
			{
				if (*first == *next)
					erase(next);
				else 
					first = next;
				next = first; 
			}
		}
	template<class T>
		template <class BinaryPredicate>
			void list<T>::unique (BinaryPredicate binary_pred)
			{
				iterator first = begin();
				iterator last = end();
				if (first == last)
					return;
				iterator next = first;
				while (++next != last)
				{
					if (binary_pred(*first,*next))
						erase(next);
					else 
						first = next;
					next = first; 
				}
			}
	template<class T>
		void list<T>::reverse()
		{
			if (size() < 2)
				return;
			for (iterator first = ++begin(); first != end();)
			{
				iterator old = first++;
				transfer(begin(),old,first);
			}
		}
	template<class T>
		void list<T>::merge (list& x)
		{
			iterator f1 = begin();
			iterator l1 = end();
			iterator f2 = x.begin();
			iterator l2 = x.end();
			while (f1 != l1 && f2 != l2)
			{
				if (*f2 < *f1)
				{
					iterator next = f2;
					transfer(f1,f2,++next);
					f2 = next;
				}else 
					++f1;
			}
			if (f1 != l2)
				transfer(f1,f2,l2);
			length += x.length;
			x.length = 0;
		}
	template<class T>
		template <class Compare>
			void list<T>::merge (list& x, Compare comp)
			{
				iterator f1 = begin();
				iterator l1 = end();
				iterator f2 = x.begin();
				iterator l2 = x.end();
				while (f1 != l1 && f2 != l2)
				{
					if (comp(*f2,*f1))//comp
					{
						iterator next = f2;
						transfer(f1,f2,++next);
						f2 = next;
					}else 
						++f1;
				}
				if (f1 != l2)
					transfer(f1,f2,l2);
				length += x.length;
				x.length = 0;
		}
	template<class T>
	template <class InputIterator>
		void list<T>::assign (InputIterator first, InputIterator last)
		{
			if(first != last)
			{
				this->clear();
				difference_type n = 0;
				distance(first,last,n);
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
				
				length = n;
			}
		}
	template<class T>
		void list<T>::assign (size_type n, const value_type& val)
		{
			while (n--)
				push_front(val);
		}
	template<class T>
		template <class Predicate>
			void list<T>::remove_if (Predicate pred)
			{
			iterator begin = begin();
			iterator end = end();
			while (begin != end)
			{
				iterator next = begin;
				++next;
				if (pred(*begin))
					erase(begin);
				begin = next;
			}
		}
	template<class T>
	void list<T>::resize (size_type n, value_type val)
	{
		iterator f= begin();
		iterator l = end();
		while (f != l && n--)
			f++;
		if (f == l)
		{
			while (n--)
				push_back(val);
		}else if (n == 0)
		{
			erase(f,l);
		}
	}
};