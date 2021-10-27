#pragma once
#include <utility> 
#include <iostream>
#include "pair.hpp"
#include <queue>
#include "vector/vectorV2.hpp"
// #include "iterator.hpp"
template < class value_type,                                    // map::mapped_type
            class Compare = std::less<typename value_type::key_type>,                     // map::key_compare
            class Alloc = std::allocator<value_type >  // map::allocator_type
           >
class RBT
{
    typedef typename value_type::key_type key_type;
    typedef typename value_type::mapped_type mapped_type;

    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference	reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::pointer	pointer;
    typedef typename allocator_type::const_pointer		const_pointer	;
	// 	typedef ft::iterator_tree<node> iterator; 

    // typedef ft::iterator_tree<const value_type> const_iterator;


    typedef size_t size_type;

    private:
    Compare _comp;
    Alloc _allocator;
    struct node
    {
        value_type p;
        node *right,*left,*parent;
        bool black;
        bool isleftchild;
        bool doubleBlack;
        
        node(value_type& p) :p(p)
        {
            this->parent = this->right = this->left = nullptr;
            this->black = false;
            this->isleftchild = false;
            this->doubleBlack = false;
        }
    
        node(const node& a) :p(a.p)
        {
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
    //check also second
bool 			operator != (const node &v){return this->p != v.p;}
    bool 			operator== (const node &v){return this->p == v.p;}
    bool 			operator>(const node &v){return this->p > v.p;}
    bool 			operator>=(const node &v){return this->p >= v.p;}
    bool 			operator<(const node &v){return this->p < v.p;}
    bool 			operator<=(const node &v){return this->p <= v.p;}
    };
    typedef std::size_t size_t;
    node *root;
    size_t _size;
    
    public:
    RBT()
    {
        this->root = nullptr;
        this->_size = 0;
    };
    ~RBT()
    {
        delete this->root;
    }
    node *get_root()
    {
        return this->root;
    }
    //----------------------------

    //--------------------
    // void    insert(ft::pair<key_type, mapped_type> m);
    // void    insert(ft::pair<key_type, mapped_type>& m);
    void    insert(value_type& m);

    void    insert(node *parent,node *new_node);
    void    checkcolor(node *new_node);
    void    print(node *root);
    void    correctTree(node *new_node);
    void    rotate(node *new_node);
    void    rightRotate(node *new_node);
    void    leftRotate(node *new_node);
    void    rightLeftRotate(node *new_node);
    void    leftRightRotate(node *new_node);
    typedef node T;
    //----------------------------
    class const_iterator;
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
        friend class RBT<value_type>;
		private:
			T* z;
		public:
        typedef ft::pair<key_type, mapped_type> val;
		typedef val& reference;
		typedef const val& const_refernce;
		typedef val* pointer;
        // node* getMax(node* root){
        // node* tmp = root;
        // while(tmp && tmp->right)
        //     tmp = tmp->right;
        // return tmp;
        // }
		iterator(T* init){z = init;};
		// iterator(const iterator&a){z=a;};
        operator const_iterator () {return z;}
		iterator(){z = NULL;}
		bool 			operator != (const iterator &v){return this->z != v.z;}
		bool 			operator== (const iterator &v){return this->z == v.z;}
        // -- null
		iterator 		&operator++(){
            this->z = increment(this->z);return *this;}
		iterator 		&operator--(){this->z = decrement(this->z);return *this;}
		iterator 		operator--(int){iterator tmp = *this;this->z = decrement(this->z);return tmp;}
		iterator		operator++(int) {
            iterator copy = *this;this->z = increment(this->z);return copy;}
		value_type &	operator*(){
            return z->p;};
		value_type *			operator->(){
            return &z->p;}
        iterator& operator =(const iterator& a)
        {
            this->z = a.z;
            return *this;
        }
	};
    class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		private:
			T* z;
		public:
        typedef ft::pair<key_type, mapped_type> val;
		typedef val& reference;
		typedef const val& const_refernce;
		typedef val* pointer;
		const_iterator(T* init){z = init;};
		const_iterator(){z = NULL;}
        // const_iterator(const const_iterator&a){z=a;};
        operator iterator () {return z;}
		bool 			operator != (const const_iterator &v){return this->z != v.z;}
		bool 			operator== (const const_iterator &v){return this->z == v.z;}
		const_iterator 		&operator++(){this->z = increment(this->z);return *this;}
		const_iterator 		&operator--(){this->z = decrement(this->z);return *this;}
		const_iterator 		&operator--(int){const_iterator tmp = *this;decrement(this->z);return *this;}
		const_iterator		operator++(int) {const_iterator copy = *this;increment(this->z);return copy;}
		val&	operator*(){
            return z->p;};
		val*			operator->(){return &z->p;}
        const_iterator& operator =(const const_iterator& a)
        {
            this->z = a.z;
            return *this;
        }
	};
    typedef ft::reverse_iterator<iterator>
        reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>
        const_reverse_iterator;
    class value_compare
    {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
    friend class map;
    protected:
    Compare comp;
    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
    public:
    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;
    bool operator() (const value_type& x, const value_type& y) const
    {
        return comp(x.first, y.first);
    }
    };
    node* getMin(node* root){
        node* tmp = root;
        while(tmp && tmp->left)
            tmp = tmp->left;
        return tmp;
    }
    node* getMax(node* root){
    node* tmp = root;
    while(tmp && tmp->right)
        tmp = tmp->right;
    return tmp;
    }
    node *find(key_type index,node *root) const
    {
        if (!root)
            return root;
        if (_comp(index, root->p.first))
        {
            return find(index,root->left);
        }
        else if (_comp(root->p.first,index))
            return find(index,root->right);
        else 
            return root;
    }
    //---------------------------------
    void printBT(const std::string& prefix, const node* node1, bool isLeft)
    {
        if( node1 != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the second of the node1
            std::cout << "( "<<node1->p.first <<", "<<node1->p.second<<", "<<node1->black<<", "<<node1->isleftchild<< " )" <<std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), node1->left, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node1->right, false);
        }
    }

    void printBT(const node* node1)
    {
        printBT("", node1, false);    
    }

    static node*
    increment(node* x)
    {
        // std::cout << "1NUll" << std::endl;
    if (x->right != 0)
        {
        // std::cout << "2NUll" << std::endl;
        x = x->right;
        while (x->left != 0)
            x = x->left;
        }
    else
        {
        // std::cout << "3NUll" << std::endl;
        node* y = x->parent;
        while (y && x && x == y->right)
            {
            // std::cout << "lllllNUll" << std::endl;
            x = y;
            y = y->parent;
            }
        // std::cout << "4NUll" << std::endl;
        if (x->right != y)
            x = y;
        }
        // std::cout << "5NUll" << std::endl;

    return x;
    }
    static node*
    decrement(node* x)
    {
    if (x->left != 0)
        {
        x = x->left;
        while (x->right != 0)
            x = x->right;
        }
    else
        {
        node* y = x->parent;
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
    // Iterative method to find height of Binary Tree
    void printLevelOrder(node* root)
    {
        // Base Case
        if (root == NULL)
            return;
    
        // Create an empty queue for level order traversal
        std::queue<node*> q;
    
        // Enqueue Root and initialize height
        q.push(root);
    
        while (q.empty() == false) {
            std::cout << "\n";
            // Print front of queue and remove it from queue
            node* node1 = q.front();
            // std::cout << "( "<<node1->first <<" : "<<node1->second <<" )"<< " ";
            q.pop();
    
            /* Enqueue left child */
            if (node1->left != NULL)
                q.push(node1->left);
    
            /*Enqueue right child */
            if (node1->right != NULL)
                q.push(node1->right);
        }
    }
    //---------------------------

    int height(node* root)
    {
        // Base case: empty tree has a height of 0
        if (root == nullptr) {
            return 0;
        }
    
        // recur for the left and right subtree and consider maximum depth
        return 1 + max(height(root->left), height(root->right));
    }
    size_t myCount(const key_type& k,node* root) const{
        if (root == 0)
            return 0;
        if (k < root->p.first)
        {
            return myCount(k,root->left);
        }
        else if (k > root->p.first)
            return myCount(k,root->right);
        else 
            return 1;
    }
    void    print_node(node* tmp)
    {
        if (!tmp)
            std::cout << "node is null\n";
        else 
            std::cout << "node: first: " << tmp->first << " black: "<< tmp->black<< std::endl;
    }
    //-----------------------------
    //iterators
    iterator begin(){return getMin(this->root);}
    const_iterator begin() const{return getMin(this->root);}
    iterator end(){return NULL;}
    const_iterator end() const{return NULL;}
    reverse_iterator rbegin(){return reverse_iterator(getMax(this->root));};
    const_reverse_iterator rbegin() const{return reverse_iterator(getMax(this->root));};
    reverse_iterator rend(){return reverse_iterator(NULL);};
    const_reverse_iterator rend() const{return reverse_iterator(NULL);};
    size_type count (const key_type& k) const{
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
    mapped_type& at( const key_type& first ){
        node *tmp = find(first,this->root);
        if (!tmp)
            throw std::out_of_range("out of range");
        else 
            return tmp->p.second;
    }
    const mapped_type& at( const key_type& first ) const{
        return this->at(first);
    }

    mapped_type& operator[] (const key_type& index)
    {
        node *root = find(index,this->root);
        if (!root)
        {
            value_type f(index,mapped_type());
            insert(f);
            node *tmp = find(index,this->root);
            return tmp->p.second;
        }
        return root->p.second;
    }
    //---------
    void swap( RBT& other ){
        // this->swap()
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
    iterator find( const key_type& first ){
        node *tmp = find(first,this->root);
        if (!tmp)
            return this->end();
        return iterator(tmp);
    }
    // const_iterator find( const key_type& first ) const;
    //--------lower---bound------
    iterator lower_bound( const key_type& first ){
        node *tmp = find(first,this->root);
        if (!tmp)
            return this->end();
        return ++iterator(tmp);
    }
    // const_iterator lower_bound( const key_type& first ) const;
    //--------upper---bound------
    iterator upper_bound( const key_type& first ){
        node *tmp = find(first,this->root);
        if (!tmp)
            return this->end();
        return --iterator(tmp);
    }
    // const_iterator upper_bound( const key_type& first ) const;
    //--------equal---range------------
    ft::pair<iterator,iterator> equal_range( const key_type& first ){
        // ft::pair<iterator,iterator> p;
        // p.first = this->lower_bound(first);
        // p.second = this->upper_bound(first);
        return make_pair(this->lower_bound(first),this->upper_bound(first));
    }
   ft::pair<const_iterator,const_iterator> equal_range( const key_type& first ) const{
        return make_pair(this->lower_bound(first),this->upper_bound(first));
    }
    //------------insert------------------
    //-----std---or---ft------
    ft::pair<iterator, bool> insert( const value_type& second ){
        // puts("******");
        node *tmp = find(second.first,this->root);
        ft::pair<iterator, bool> p;
        if (tmp){
            p.first = iterator(tmp);
            p.second = false;
            return p;
        }else{
            insert(const_cast<value_type&>(second));
            node *tmp = find(second.first,this->root);
            p.first = iterator(tmp);
            p.second = true;
            return p;

        }
    }
    iterator insert( iterator hint, const value_type& second ){
        //-----hint-------
        insert(second);
        node *tmp = this->find(second.first,this->root);
        return iterator(tmp);
    }
    template< class InputIt >
    void insert( InputIt first, InputIt last ){
        for(InputIt it = first; it != last;++it){
            this->insert(*it);
        }
    }
    //------------clear--------------
    void    clear(node *root)
    {
        this->erase(this->begin(),this->end());
    }
    void clear(){
        clear(this->root);
    }
    //--------erase----------
    void erase (iterator first, iterator last){
    //     ft::vector<value_type> tmp;
    // for (iterator it=first; it!=last; ++it)
    // {
    //     // std::cout << it->first << std::endl;
    //     tmp.push_back(ft::make_pair(it->first,it->second));
    // }
    // for (typename ft::vector<value_type>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
    //     this->erase((*it).first);
    }
    void erase (iterator position){
        //exception
        std::cout << "tes:"<<position->first << std::endl;
        printBT(this->root);
        this->erase(position->first);
        printBT(this->root);


    }
node*   swapNode(node **tmp,node *tmp1){
    node *tmpT = new node(*tmp1);
    std::cout << "first:" << tmpT->p.first << std::endl;
    std::cout << "second:" << tmpT->p.second << std::endl;

    tmpT->p.first = tmp1->p.first;
    tmpT->p.second = tmp1->p.first;
    tmpT->black = (*tmp)->black;
    tmpT->isleftchild = (*tmp)->isleftchild;
    tmpT->doubleBlack = (*tmp)->doubleBlack;
    tmpT->parent= (*tmp)->parent;
    tmpT->right = (*tmp)->right;
    tmpT->left = (*tmp)->left;
    // delete tmp;
    *tmp = tmpT;
    return tmpT;
}
    size_type erase(const key_type& k){
        _size--;
        std::cout << "Erase" << std::endl;
        node *tmp = find(k,this->root);
        node* tmpM = NULL;
         node *tmpT = NULL;
        if (tmp->left != NULL)
            tmpM = getMax(tmp->left);
        else if (tmp->left == NULL && tmp->right != NULL)
            tmpM = getMin(tmp->right);
        else 
            tmpM = tmp;
        // tmpT = tmp;
        // tmp = tmpM;

        // tmp = swapNode(&tmp,tmpM);
        // tmp->p.first = tmpM->p.first;
        // tmp->p.second = tmpM->p.second;
        tmp->p = ft::make_pair(tmpM->p.first,tmpM->p.second);

           std::cout << "tmp first:" << tmp->p.first << std::endl;
    std::cout << "tmp second:" << tmp->p.second << std::endl;
        if (tmpM->black == true)
            tmpM->doubleBlack = true;
        delete_node(&tmpM);
        delete_the_node(&tmpM);
        return 1;//For the first-based version (2), the function returns the number of elements erased.

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
    bool operator==(RBT<value_type ,Compare,Alloc>& rhs ){
                        // return lhs.r == rhs.r;
                        return ft::equal(begin(),end(),rhs.begin());
                    }
    bool operator!=(RBT<value_type ,Compare,Alloc>& rhs ){
                        // return rhs.r != lhs.r;
                        return !ft::equal(begin(),end(),rhs.begin());

                    }
    bool operator<( RBT<value_type ,Compare,Alloc>& rhs ){
                        // return rhs.r < lhs.r;
                        return ft::lexicographical_compare(begin(),end(),rhs.begin(),rhs.end());                        
                    }
    bool operator<=(RBT<value_type ,Compare,Alloc>& rhs ){
                        // return rhs.r <= lhs.r;
                        return (*this < rhs) || (*this == rhs); 
                    }
    bool operator>( RBT<value_type ,Compare,Alloc>& rhs ){
                        // return rhs.r > lhs.r;
                        return !(*this < rhs) && (*this != rhs);
                    }
    bool operator>=(RBT<value_type ,Compare,Alloc>& rhs ){
                        // return rhs.r >= lhs.r;
                        return !(*this < rhs) || (*this == rhs);
                    }
    // bool operator==(const RBT<value_type,Compare,Alloc>& rhs ){
    //                     // return lhs.r == rhs.r;
    //                     return 1;
    //                 }
    // bool operator!=(const RBT<value_type,Compare,Alloc>& rhs ){
    //                     // return rhs.r != lhs.r;
    //                     return 1;
    //                 }
    // bool operator<( const RBT<value_type,Compare,Alloc>& rhs ){
    //                     // return rhs.r < lhs.r;
    //                     return 1;                        
    //                 }
    // bool operator<=(const RBT<value_type,Compare,Alloc>& rhs ){
    //                     // return rhs.r <= lhs.r;
    //                     return 1;
    //                 }
    // bool operator>( const RBT<value_type,Compare,Alloc>& rhs ){
    //                     // return rhs.r > lhs.r;
    //                     return 1;
    //                 }
    // bool operator>=(const RBT<value_type,Compare,Alloc>& rhs ){
    //                     // return rhs.r >= lhs.r;
    //                     return 1;
    //                 }
    
};
//------------------------

//------------------------
template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<value_type,Compare,Alloc>::print(node *root)
{
    if (root == nullptr)
        return;

        print(root->left);
        std::cout <<"first " <<root->p.first << " second "<<root->second << "\n";
        print(root->right);
}

































































template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<value_type,Compare,Alloc>::rightLeftRotate(node *new_node)
{
    rightRotate(new_node->right);
    leftRotate(new_node);
}

template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<value_type,Compare,Alloc>::leftRightRotate(node *new_node)
{
    leftRotate(new_node->left);
    rightRotate(new_node);
}

template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<value_type,Compare,Alloc>::rightRotate(node *new_node)
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
template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<value_type,Compare,Alloc>::leftRotate(node *new_node)
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

template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<value_type,Compare,Alloc>::rotate(node *new_node)
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

template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<value_type,Compare,Alloc>::correctTree(node *new_node)
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

template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<value_type,Compare,Alloc>::checkcolor(node *new_node)
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

template < class value_type ,                                    // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<value_type,Compare,Alloc>::insert(node *parent,node *new_node)
{   
    if (_comp(parent->p.first , new_node->p.first))
    {
        if (parent->right == nullptr)
        {
            parent->right = new_node;
            new_node->parent = parent;
            new_node->isleftchild = false;
        }else 
             insert(parent->right,new_node);
    }
    else if (_comp(new_node->p.first, parent->p.first ))
    {
        if (parent->left == nullptr)
        {
            parent->left = new_node;
            new_node->parent = parent;
            new_node->isleftchild = true;
        }
        else
            insert(parent->left,new_node);
    }
    else
        return;
    checkcolor(new_node);
}

// template < class value_type ,                                    // map::mapped_type
//         class Compare,                     // map::key_compare
//         class Alloc    // map::allocator_type
//         >
// void    RBT<value_type,Compare,Alloc>::insert(ft::pair<key_type, mapped_type>& m)
// {
//     // std::cout <<"insert" << std::endl;
//     node *new_node = new node(m.first,m.second);
    
//     if (root == nullptr)
//     {
//         root = new_node;
//         root->black = true;
//         _size++;
//         return;
//     }
//     insert(root,new_node);
//     _size++;
// }
// template < class value_type ,                                       // map::mapped_type
//         class Compare,                     // map::key_compare
//         class Alloc    // map::allocator_type
//         >
// void    RBT<value_type,Compare,Alloc>::insert(const value_type& m)
// {
//     std::cout << "insert" << std::endl;
//     node *new_node = new node(m);
//     // fix duplicate
//     if (root == nullptr)
//     {
//         root = new_node;
//         root->black = true;
//         _size++;
//         return;
//     }
//     insert(root,new_node);
//     _size++;
// }

template < class value_type ,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<value_type,Compare,Alloc>::insert(value_type& m)
{
    // std::cout << "insert" << std::endl;
    node *new_node = new node(m);
    // fix duplicate
    if (root == nullptr)
    {
        root = new_node;
        root->black = true;
        _size++;
        return;
    }
    insert(root,new_node);
    _size++;
}

