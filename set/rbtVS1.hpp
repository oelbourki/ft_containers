/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTsetVS1.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:22:02 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/10 09:20:42 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <utility> 
#include <iostream>
#include "../utils/pair.hpp"
#include <queue>
#include "../vector/vector.hpp"
#include "iterator.hpp"
template < class value_type,                                    // map::value_type
            class Compare = std::less<value_type>,                     // map::key_compare
            class Alloc = std::allocator<value_type >  // map::allocator_type
           >
class RBTset
{
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference	reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::pointer	pointer;
    typedef typename allocator_type::const_pointer		const_pointer	;
    typedef size_t size_type;

    private:
    Compare _comp;
    Alloc _allocator;
    struct node
    {
        value_type* p;
        node *right,*left,*parent;
        bool black;
        bool isleftchild;
        bool doubleBlack;
        Alloc _allocator;
        node(value_type& _p)
        {
            this->p = _allocator.allocate(1);
            _allocator.construct(this->p,value_type(_p));
            this->parent = this->right = this->left = nullptr;
            this->black = false;
            this->isleftchild = false;
            this->doubleBlack = false;
        }
        node(const node& a)
        {
            this->p = _allocator.allocate(1);
            _allocator.construct(this->p,value_type(a.p));
            this->parent = a.parent;
            this->right = a.right;
            this->left = a.left;
            this->black = a.black;
            this->isleftchild = a.isleftchild;
            this->doubleBlack = a.doubleBlack;
        }
    node& operator =(const node& a)
    {
        this->p = a.p;
        this->parent = a.parent;
        this->right = a.right;
        this->left = a.left;
        this->black = a.black;
        this->isleftchild = a.isleftchild;
        this->doubleBlack = a.doubleBlack;
        return *this;
    }
    ~node()
    {
        delete this->p;
    }
    //check also second
    bool 			operator != (const node &v){return this->p != v.p;}
    bool 			operator== (const node &v){return this->p == v.p;}
    bool 			operator>(const node &v){return this->p > v.p;}
    bool 			operator>=(const node &v){return this->p >= v.p;}
    bool 			operator<(const node &v){return this->p < v.p;}
    bool 			operator<=(const node &v){return this->p <= v.p;}
    };
    typedef typename Alloc::template rebind<RBTset::node>::other        node_all;
    node_all _allocator_node;
    node *root;
    size_t _size;
    public:
    RBTset()
    {
        this->root = nullptr;
        this->_size = 0;
    };
    ~RBTset()
    {
    }
    node *get_root() const
    {
        return this->root;
    }
    //----------------------------
    node*    insert(value_type& m){
        node *new_node = _allocator_node.allocate(1);
        _allocator_node.construct(new_node,m);
        if (root == nullptr)
        {
            root = new_node;
            root->black = true;
            _size++;
            return root;
        }
        return insert(root,new_node);
}
    
    node*    insert(node *parent,node *new_node);
    void    checkcolor(node *new_node);
    void    print(node *root);
    void    correctTree(node *new_node);
    void    rotate(node *new_node);
    void    rightRotate(node *new_node);
    void    leftRotate(node *new_node);
    void    rightLeftRotate(node *new_node);
    void    leftRightRotate(node *new_node);
    typedef node T;
    typedef ft::iterator_tree_set<node,const value_type,RBTset> iterator; 
    typedef ft::iterator_tree_set<node,const value_type,RBTset> const_iterator;
    typedef ft::reverse_iterator_tree<iterator>
        reverse_iterator;
    typedef ft::reverse_iterator_tree<const_iterator>
        const_reverse_iterator;
    class value_compare : std::binary_function<value_type,value_type,bool>
    {  
    protected:
    Compare comp;
    value_compare (Compare c) : comp(c) {} 
    public:
    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;
    bool operator() (const value_type& x, const value_type& y) const
    {
        return comp(x.first, y.first);
    }
    };
    value_compare value_comp() const{
        return value_compare(_comp);
    }
    node* getMin(node* root)const {
        node* tmp = root;
        while(tmp && tmp->left)
            tmp = tmp->left;
        return tmp;
    }
    node* getMax(node* root)const{
    node* tmp = root;
    while(tmp && tmp->right)
        tmp = tmp->right;
    return tmp;
    }
    node *find(value_type index,node *root) const
    {
        if (!root)
            return NULL;
        if (_comp(index, *root->p))
            return find(index,root->left);
        else if (_comp(*root->p,index))
            return find(index,root->right);
        else 
            return root;
    }
    node *myFind(value_type index,node *root,node**p)  const
    {
        if (!root)
            return root;
        if (_comp(index, *root->p))
        {   
            *p = root;
            return myFind(index,root->left,p);
        }
        else if (_comp(*root->p,index))
        {   
            return myFind(index,root->right,p);
        }
        else 
            return root;
    }
    //-----------------------------
    //iterators
    iterator begin(){return iterator(getMin(this->root),this);}
    const_iterator begin() const{return const_iterator(getMin(this->root),this);}
    iterator end(){return iterator(NULL,this);}
    const_iterator end() const{return const_iterator(NULL,this);}

    reverse_iterator rbegin(){return reverse_iterator(iterator(NULL,this));};
    const_reverse_iterator rbegin() const{return const_reverse_iterator(iterator(NULL,this));};
    reverse_iterator rend(){return reverse_iterator(iterator(getMin(this->root),this));};
    const_reverse_iterator rend() const{return const_reverse_iterator(iterator(getMin(this->root),this));};
    size_type count (const value_type& k) const{
        node* tmp = find(k, this->root);
        if (!tmp)
            return 0;
        else
        return 1;
    };
    bool empty() const{return this->root == nullptr;};
    size_type size() const{return this->_size;};
    size_type max_size() const{return _allocator.max_size();}
    //----first-----comapare
    key_compare key_comp() const{
        return this->_comp;
    }
//-----Element access----------
//------at--------------
    value_type& at( const value_type& first ){
        node *tmp = find(first,this->root);
        if (!tmp)
            throw std::out_of_range("out of range");
        else 
            return tmp->p->second;
    }
    const value_type& at( const value_type& first ) const{
        return this->at(first);
    }

    value_type& operator[] (const value_type& index)
    {
        node *root = find(index,this->root);
        if (!root)
        {
            value_type f(index,value_type());
            insert(f);
            node *tmp = find(index,this->root);
            return tmp->p->second;
        }
        return *root->p->second;
    }
    //---------
    void swap( RBTset& other ){
        this->swap(this->root,other.root);
        this->swap(this->_size,other._size);
    }

    template<class A>
    void swap(A& a,A& b){
        A tmp = a;
        a = b;
        b = tmp;
        }
    //-----------find-------
    iterator find( const value_type& first ){
        node *tmp = find(first,this->root);
        if (!tmp)
            return iterator(NULL,this);
        return iterator(tmp);
    }

    const_iterator find( const value_type& first ) const{
        node *tmp = find(first,this->root);
        if (!tmp)
            return const_iterator(NULL,this);
        return const_iterator(tmp);
    }
    //--------lower---bound------
    iterator lower_bound( const value_type& first ){
        node *p = NULL;
        node *tmp = myFind(first,this->root,&p);
        if (!tmp)
            return iterator(p,this);
        return iterator(tmp,this);
    }
    const_iterator lower_bound( const value_type& first ) const{
        node *p = NULL;
        node *tmp = myFind(first,this->root,&p);
        if (!tmp)
            return const_iterator(p,this);
        return const_iterator(tmp,this);
    }
    //--------upper---bound------
    iterator upper_bound( const value_type& first ){
        node *p = NULL;
        node *tmp = myFind(first,this->root,&p);
        if (!tmp)
            return iterator(p,this);
        return ++iterator(tmp,this);
    }
    const_iterator upper_bound( const value_type& first ) const {
        node *p = NULL;
        node *tmp = myFind(first,this->root,&p);
        if (!tmp)
            return const_iterator(p,this);
        return ++const_iterator(tmp,this);
    }
    //--------equal---range------------
    ft::pair<iterator,iterator> equal_range( const value_type& first ){
    typedef typename Alloc::template rebind<ft::pair<iterator,iterator> >::other        type;
    type _p_allocator;

        ft::pair<iterator,iterator> * tmp = _p_allocator.allocate(1);
        _p_allocator.construct(tmp,ft::pair<iterator,iterator>(this->lower_bound(first),this->upper_bound(first)));
        ft::pair<iterator,iterator> tmpt = *tmp;
        delete tmp;
        return tmpt;
    }
   ft::pair<const_iterator,const_iterator> equal_range( const value_type& first ) const{

        typedef typename Alloc::template rebind<ft::pair<const_iterator,const_iterator> >::other        type;
        type _p_allocator;
        ft::pair<const_iterator,const_iterator> * tmp = _p_allocator.allocate(1);
        _p_allocator.construct(tmp,ft::pair<const_iterator,const_iterator>(this->lower_bound(first),this->upper_bound(first)));
        ft::pair<const_iterator,const_iterator> tmpt = *tmp;
        delete tmp;
        return tmpt;
    }
    //------------insert------------------
    //-----std---or---ft------
    ft::pair<iterator, bool> insert( const value_type& second ){
        node *tmp = insert(const_cast<value_type&>(second));
        ft::pair<iterator, bool> p;
        if (tmp){
            p.first = iterator(tmp);
            p.second = false;
            return p;
        }else{
            p.first = iterator(tmp);
            p.second = true;
            return p;
        }
    }
    iterator insert( iterator hint, const value_type& second ){
        //-----hint-------
        hint = 0;
        insert(second);
        node *tmp = this->find(second,this->root);
        return iterator(tmp);
    }
    template< class InputIt >
    void insert( InputIt first, InputIt last ){
        for(InputIt it = first; it != last;++it){
            this->insert(*it);
        }
    }
    void erase (iterator position){
        this->erase(*position);
    }

    size_type erase(const value_type& k){
    if (!_size)
        return 0;

        node *tmp = find(k,this->root);
        node* tmpM = NULL;
         if (tmp)
        {
            _size--;
            if (tmp->left != NULL)
            {
                delete tmp->p;
                tmpM = getMax(tmp->left);
            }
            else if (tmp->left == NULL && tmp->right != NULL)
            {
                delete tmp->p;
                tmpM = getMin(tmp->right);
            }
            else 
            {
            if (tmp->black == true)
                tmp->doubleBlack = true;
                delete_node(&tmp);
                delete_the_node(&tmp);
                return 1;
            }
            if (tmpM)
            {
            tmp->p = _allocator.allocate(1);
            _allocator.construct(tmp->p,value_type(*tmpM->p));
            if (tmpM->black == true)
                tmpM->doubleBlack = true;
            delete_node(&tmpM);
            delete_the_node(&tmpM);
            }
            return 1;
    }
        return 0;
    }
    //-----------delete----------------------
   
    int     sib_black_child_black(node *root){
        if (root == NULL)
            return -1;
        else if (root->isleftchild == true)
        {
            node *tmp = root->parent->right;
            if ((!tmp || tmp->black == true) && (tmp->right == NULL || tmp->right->black == true)
            && (tmp->left== NULL || tmp->left->black == true))
                return 1;
        }
        else 
        {
            node *tmp = root->parent->left;
            if ((!tmp || tmp->black == true) && tmp && (tmp->right == NULL || tmp->right->black == true)
            && (tmp->left== NULL || tmp->left->black == true))
                return 1;
        }
        return 0;
    }
    int     sib_red(node *root){
        if (root == NULL)
            return -1;
        else if (root->isleftchild == true)
        {
            node *tmp = root->parent->right;
            if ((tmp && tmp->black == false))
                return 1;
        }
        else 
        {
            node *tmp = root->parent->left;
            if ((tmp && tmp->black == false))
                return 1;
        }
        return 0;
    }
    node*     get_sib(node *root){
        if (root == NULL)
            return NULL;
        else if (root->isleftchild == true)
        {
            node *tmp = root->parent->right;
            return tmp;
        }
        else 
        {
            node *tmp = root->parent->left;
            return tmp;
        }
        return NULL;
    }
    int     sib_black_farChild_black_nearChild_red(node *root){
        if (root == NULL)
            return -1;
        else if (root->isleftchild == true)
        {
            node *tmp = root->parent->right;
            if ((!tmp || tmp->black == true) && (tmp->right == NULL || tmp->right->black == true)
             && (tmp->left != NULL && tmp->left->black == false))
                return 1;
        }
        else 
        {
            node *tmp = root->parent->left;
            if ((!tmp || tmp->black == true) && tmp && (tmp->right != NULL && tmp->right->black == false) && (tmp->left == NULL || tmp->left->black == true))
                return 1;
        }
        return 0;
    }  
    int     sib_black_farChild_red(node *root){
        if (root == NULL)
            return -1;
        else if (root->isleftchild == true)
        {
            node *tmp = root->parent->right;
            if ((!tmp || tmp->black == true) && tmp &&  tmp->right->black == false)
                return 1;
        }
        else 
        {
            node *tmp = root->parent->left;
            if ((!tmp || tmp->black == true) && tmp && tmp->left->black == false)
                return 1;
        }
        return 0;
    }
    int     check_case(node *root){
        if (root == NULL)
            return -1;
        else if (root->black == false)
            return 1;
        else if (this->root == root && root->doubleBlack == true)
            return 2;
        else if (root->doubleBlack == true && sib_black_child_black(root) == 1)
            return 3;
        else if (root->doubleBlack == true && sib_red(root) == 1)
            return 4;
        else if (root->doubleBlack == true && sib_black_farChild_black_nearChild_red(root) == 1)
            return 5;
        else if (root->doubleBlack == true && sib_black_farChild_red(root) == 1)
            return 6;
        return 0;
    }

    void delete_the_node(node **rt)
    {
        if (!rt || !(*rt))
            return;
        node *P = (*rt)->parent;
        bool tmp = (*rt)->isleftchild;
        if (!P && !(*rt)->left && !(*rt)->right)
        {
            delete *rt;
            *rt = NULL;
            this->root = NULL;
            return;
        }
        if (tmp)
            P->left = NULL;
        else 
            P->right = NULL;
        delete *rt;
        *rt = NULL;
    }
    void   delete_node(node **rt){
        node *root = *rt;
        int cas = check_case(root);
        if (cas == -1)
        {
            std::cout << "NULL" << std::endl;
            return;
        }
        else if (cas == 2)
            (*rt)->doubleBlack = false;
        else if (cas == 3)
        {
            (*rt)->doubleBlack = false;
            node *P = (*rt)->parent;
            if (P->black == false)
                P->black = true;
            else
                P->doubleBlack = true;
            node *sib = get_sib(root);
            sib->black = false;
            delete_node(&P);
        }
        else if (cas == 4)
        {
            node *P = (*rt)->parent;
            node *sib = get_sib(root);
            swap(P->black,sib->black);
            if (!sib->right && !sib->left)
                return;
            if (root->isleftchild == true)
                leftRotate(P);
            else
                rightRotate(P);
            delete_node(&root);
        }
        else if (cas == 5)
        {
            node *sib = get_sib(root);
            if (root->isleftchild == true)
            {
                swap(sib->black,sib->left->black);
                rightRotate(sib);
            }
            else
            {
                swap(sib->black,sib->right->black);
                leftRotate(sib);
            }
            delete_node(&root);
        }
        else if (cas == 6)
        {
            node *P = (*rt)->parent;
            node *sib = get_sib(*rt);
            swap(P->black,sib->black);
            root->doubleBlack = false;
            if (root->isleftchild == true)
            {
                sib->right->black = true;
                leftRotate(P);
            }
            else
            {
                sib->left->black = true;
                rightRotate(P);
            }
        }
    }
    bool operator==(RBTset<value_type ,Compare,Alloc>& rhs ){
                        return ft::equal(begin(),end(),rhs.begin());
                    }
    bool operator!=(RBTset<value_type ,Compare,Alloc>& rhs ){
                        return !ft::equal(begin(),end(),rhs.begin());

                    }
    bool operator<( RBTset<value_type ,Compare,Alloc>& rhs ){
                        return ft::lexicographical_compare(begin(),end(),rhs.begin(),rhs.end());                        
                    }
    bool operator<=(RBTset<value_type ,Compare,Alloc>& rhs ){
                        return (*this < rhs) || (*this == rhs); 
                    }
    bool operator>( RBTset<value_type ,Compare,Alloc>& rhs ){
                        return !(*this < rhs) && (*this != rhs);
                    }
    bool operator>=(RBTset<value_type ,Compare,Alloc>& rhs ){
                        return !(*this < rhs) || (*this == rhs);
                    } 
};

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBTset<value_type,Compare,Alloc>::rightLeftRotate(node *new_node)
{
    rightRotate(new_node->right);
    leftRotate(new_node);
}

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBTset<value_type,Compare,Alloc>::leftRightRotate(node *new_node)
{
    leftRotate(new_node->left);
    rightRotate(new_node);
}

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBTset<value_type,Compare,Alloc>::rightRotate(node *new_node)
{
    // std::cout << "RightRotation" << std::endl;
    node *tmp = new_node->left;
    new_node->left = tmp->right;
    if (new_node->left != nullptr)
    {
        new_node->left->parent = new_node;
        new_node->left->isleftchild = true;

    }
    if (new_node->parent == nullptr)
    {
        this->root = tmp;
        tmp->parent = nullptr;
    }
    else 
    {
        tmp->parent = new_node->parent;
        if (new_node->isleftchild)
        {
            tmp->isleftchild = true;
            tmp->parent->left = tmp;
        }else 
        {
            tmp->isleftchild = false;
            tmp->parent->right = tmp;
        }
    }
    tmp->right = new_node;
    new_node->isleftchild = false;
    new_node->parent = tmp; 
}
template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBTset<value_type,Compare,Alloc>::leftRotate(node *new_node)
{
    // std::cout << "LeftRotation" << std::endl;
    node *tmp = new_node->right;
    new_node->right = tmp->left;
    if (new_node->right != nullptr)
    {
        new_node->right->parent = new_node;
        new_node->right->isleftchild = false;
    }
    if (new_node->parent == nullptr)
    {
        this->root = tmp;
        tmp->parent = nullptr;
    }
    else 
    {
        tmp->parent = new_node->parent;
        if (new_node->isleftchild)
        {
            tmp->isleftchild = true;
            tmp->parent->left = tmp;
        }else 
        {
            tmp->isleftchild = false;
            tmp->parent->right = tmp;
        }
    }
    tmp->left = new_node;
    new_node->isleftchild = true;
    new_node->parent = tmp; 
}

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBTset<value_type,Compare,Alloc>::rotate(node *new_node)
{
    if (new_node->isleftchild)
    {
        if (new_node->parent->isleftchild)
        {
            rightRotate(new_node->parent->parent);
            new_node->black = false;
            new_node->parent->black = true;
            if (new_node->parent->right != nullptr)
                new_node->parent->right->black = false;
        }
        else 
        {
            rightLeftRotate(new_node->parent->parent); 
            new_node->black = true;
             if (new_node->right)
                new_node->right->black = false;
            if (new_node->left)
                new_node->left->black = false;
        }
    }else 
    {
        if (!new_node->parent->isleftchild)
        {
            leftRotate(new_node->parent->parent);
            new_node->black = false;
            new_node->parent->black = true;
            if (new_node->parent->left != nullptr)
                new_node->parent->left->black = false;
        }
        else 
        {
            leftRightRotate(new_node->parent->parent);
            new_node->black = true;
            if (new_node->right)
                new_node->right->black = false;
            if (new_node->left)
                 new_node->left->black = false;
        }
    }
}

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBTset<value_type,Compare,Alloc>::correctTree(node *new_node)
{
    if (new_node->parent->isleftchild)
    {
        if (new_node->parent->parent != nullptr)
        {
            if (new_node->parent->parent->right == nullptr ||
            new_node->parent->parent->right->black)
                rotate(new_node);
            else
            {
                
                if (new_node->parent->parent->right != nullptr)
                    new_node->parent->parent->right->black = true;
                new_node->parent->parent->black = false;
                new_node->parent->black = true;
            }
        }

    }else
    {
        if (new_node->parent->parent != nullptr)
        {
            // std::cout << "right" << std::endl;
            if (new_node->parent->parent->left == nullptr ||
            new_node->parent->parent->left->black)
                rotate(new_node);
            else 
            {
                if (new_node->parent->parent->left != nullptr)
                    new_node->parent->parent->left->black = true;
                new_node->parent->parent->black = false;
                new_node->parent->black = true;
            }
        }
    }
    
}

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBTset<value_type,Compare,Alloc>::checkcolor(node *new_node)
{
    if (!new_node || (new_node == this->root))
        return ;
    this->root->black = true;
    if (!new_node->black && !new_node->parent->black)
    {
        correctTree(new_node);
    }
    checkcolor(new_node->parent);
}

template < class value_type ,                                    // map::value_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
typename RBTset<value_type,Compare,Alloc>::node* RBTset<value_type,Compare,Alloc>::insert(node *parent,node *new_node)
{   
    if (_comp(*parent->p , *new_node->p))
    {
        if (parent->right == nullptr)
        {
            parent->right = new_node;
            new_node->parent = parent;
            new_node->isleftchild = false;
            _size++;

        }else 
             return insert(parent->right,new_node);
    }
    else if (_comp(*new_node->p, *parent->p ))
    {
        if (parent->left == nullptr)
        {
            parent->left = new_node;
            new_node->parent = parent;
            new_node->isleftchild = true;
            _size++;

        }
        else
            return insert(parent->left,new_node);
    }
    else
    {
        delete new_node;
        return parent;
    }
    checkcolor(new_node);
    return NULL;
}