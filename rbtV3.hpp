#pragma once
#include <utility> 
#include <iostream>
#include "pair.hpp"
#include <queue>
template < class Key,                                     // map::key_type
           class V,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,V> >    // map::allocator_type
           >
class RBT
{
    private:
    Compare _comp;
    Alloc _allocator;
    struct node
    {
        Key key;
        V value;
        node *right,*left,*parent;
        bool black;
        bool isleftchild;
        bool doubleBlack;
        node(Key key,V value)
        {
            this->key = key;
            this->value = value;
            this->parent = this->right = this->left = nullptr;
            this->black = false;
            this->isleftchild = false;
            this->doubleBlack = false;

        }
        node(const node& a)
        {
            this->key = a.key;
            this->value = a.value;
            this->parent = a.parent;
            this->right = a.right;
            this->left = a.left;
            this->black = a.black;
            this->isleftchild = a.isleftchild;
            this->doubleBlack = a.doubleBlack;
        }
    node& operator =(const node& a)
    {
        this->key = a.key;
        this->value = a.value;
        this->parent = a.parent;
        this->right = a.right;
        this->left = a.left;
        this->black = a.black;
        this->isleftchild = a.isleftchild;
        this->doubleBlack = a.doubleBlack;
        return *this;
    }
        bool 			operator== (const node &v)
    {return this->key == v.key;}
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
    void    insert(ft::pair<Key,V> m);
    void insert(node *parent,node *new_node);
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
    typedef ft::pair<const Key, T> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef size_t size_type;
    typedef Key key_type;
    typedef T mapped_type;
    //----------------------------
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
        friend class RBT<Key,V,Compare,Alloc>;
		private:
			T* z;
		public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_refernce;
		typedef T* pointer;
		iterator(T* init){z = init;};
		iterator(){z = NULL;}
		bool 			operator != (const iterator &v){return this->z != v.z;}
		bool 			operator== (const iterator &v){return this->z == v.z;}
		iterator 		&operator++(){this->z = increment(this->z);
        return *this;}
		iterator 		&operator--(){this->z = decrement(this->z);return *this;}
		iterator 		&operator--(int){iterator tmp = *this;(this->z)--;return *this;}
		iterator		operator++(int) {iterator copy = *this;this->z++;return copy;}
		reference	operator*(){return *z;};
		pointer			operator->(){return z;}
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
        node*
    increment(node* x) throw ()
    {

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
            // std::cout << "endd" << std::endl;
        }
        std::cout << x->key << std::endl;
        // std::cout << "5NUll" << std::endl;
        // if (!x->parent && !x->right && !x->left)
        // {
        //     std::cout << "here" << std::endl;
        //     this->tmp = 1;
        //     // node *min = this->getMin(x->right);
        //     // std::cout << x->key << "-" << std::endl;
        //     // std::cout << x->right->key << "-" << std::endl
        // }
        return x;
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
    node *find(Key index,node *root) const
    {
        if (!root)
            return root;
        if (_comp(index, root->key))
        {
            return find(index,root->left);
        }
        else if (_comp(root->key,index))
            return find(index,root->right);
        else 
            return root;
    }
    V& operator[](Key index)
    {
        node *root = find(index,this->root);
        if (!root)
            std::cout <<"error" << std::endl;
        return root->value;
    }
    //---------------------------------
    void printBT(const std::string& prefix, const node* node1, bool isLeft)
    {
        if( node1 != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value of the node1
            std::cout << "( "<<node1->key <<", "<<node1->black<<", "<<node1->isleftchild<< " )" <<std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), node1->left, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node1->right, false);
        }
    }

    void printBT(const node* node1)
    {
        printBT("", node1, false);    
    }

    node*
    increment(node* x) throw ()
    {
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
            // std::cout << "endd" << std::endl;
        }
        // std::cout << "5NUll" << std::endl;
    return x;
    }
    node*
    decrement(node* x) throw ()
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
            std::cout << "( "<<node1->key <<" : "<<node1->value <<" )"<< " ";
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
        if (k < root->key)
        {
            return myCount(k,root->left);
        }
        else if (k > root->key)
            return myCount(k,root->right);
        else 
            return 1;
    }
    //-----------------------------
    //iterators
    iterator begin(){return getMin(this->root);}
    iterator end(){return NULL;}
    size_type count (const key_type& k) const{
        node* tmp = find(k, this->root);
        if (!tmp)
            return 0;
        else
        return 1;
    };
    void    print_node(node* tmp)
    {
        if (!tmp)
            std::cout << "node is null\n";
        else 
            std::cout << "node: key: " << tmp->key << " black: "<< tmp->black<< std::endl;
    }
    bool empty() const{return this->root == nullptr;};
    size_type size() const{return this->size;};
    size_type max_size() const{return _allocator.max_size();}







    //------------clear--------------
    void clear(){
        for (iterator it=this->begin(); it!=this->end(); ++it)
            this->erase(it->key);
    }
    //--------erase----------
    void erase (iterator first, iterator last){
        std::cout << "erase pois last" << std::endl;
    for (iterator it=this->begin(); it!=this->end(); ++it)
    {
        std::cout << it->key << " => " << it->value  <<'\n';
        if (it == NULL)
            std::cout << "null" << std::endl;
        this->erase(it);
    }
    }
    void erase (iterator position){
        //exception
        this->erase(position->key);
    }
    size_type erase(const key_type& k){
    
        _size--;
        // std::cout << "Erase" << std::endl;
        node *tmp = find(k,this->root);
        // if (!tmp->parent)
        // {
        //     print_node(tmp);
        //     return 1;
        // }
        node* tmpM = NULL;
         node *tmpT = NULL;
        if (tmp->left != NULL)
            tmpM = getMax(tmp->left);
        else if (tmp->left == NULL && tmp->right != NULL)
            tmpM = getMin(tmp->right);
        else 
            tmpM = tmp;
        tmp->key = tmpM->key;
        tmp->value = tmpM->value;
        if (tmpM->black == true)
            tmpM->doubleBlack = true;

        delete_node(&tmpM);
        delete_the_node(&tmpM);
        return 1;//For the key-based version (2), the function returns the number of elements erased.

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
    void swap(bool& a,bool& b){
        bool tmp = a;
        a = b;
        b = tmp;
    }
    void delete_the_node(node **rt)
    {
        if (!rt || !(*rt))
            return;
        node *P = (*rt)->parent;
        if ((*rt)->isleftchild)
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
};
//------------------------

//------------------------
template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<Key,V,Compare,Alloc>::print(node *root)
{
    if (root == nullptr)
        return;

        print(root->left);
        std::cout <<"key " <<root->key << " value "<<root->value << "\n";
        print(root->right);
}

































































template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<Key,V,Compare,Alloc>::rightLeftRotate(node *new_node)
{
    rightRotate(new_node->right);
    leftRotate(new_node);
}

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<Key,V,Compare,Alloc>::leftRightRotate(node *new_node)
{
    leftRotate(new_node->left);
    rightRotate(new_node);
}

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<Key,V,Compare,Alloc>::rightRotate(node *new_node)
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
template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<Key,V,Compare,Alloc>::leftRotate(node *new_node)
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

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<Key,V,Compare,Alloc>::rotate(node *new_node)
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

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<Key,V,Compare,Alloc>::correctTree(node *new_node)
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

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<Key,V,Compare,Alloc>::checkcolor(node *new_node)
{
    // std::cout << "check color" << std::endl;
    if (new_node == this->root)
        return ;
    this->root->black = true;
    if (!new_node->black && !new_node->parent->black)
    {
        correctTree(new_node);
    }
    checkcolor(new_node->parent);
}

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void RBT<Key,V,Compare,Alloc>::insert(node *parent,node *new_node)
{   
    if (_comp(parent->key , new_node->key))
    {
        if (parent->right == nullptr)
        {
            parent->right = new_node;
            new_node->parent = parent;
            new_node->isleftchild = false;
        }else 
             insert(parent->right,new_node);
    }
    else if (_comp(new_node->key, parent->key ))
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

template < class Key,                                     // map::key_type
        class V,                                       // map::mapped_type
        class Compare,                     // map::key_compare
        class Alloc    // map::allocator_type
        >
void    RBT<Key,V,Compare,Alloc>::insert(ft::pair<Key,V> m)
{
    node *new_node = new node(m.first,m.second);
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
