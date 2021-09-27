#pragma once
#include <utility> 
#include <iostream>
template<class K,class V>
class RBT
{
    private:
    struct node
    {
        K key;
        V value;
        node *right,*left,*parent;
        bool black;
        bool isleftchild;
        node(K key,V value)
        {
            this->key = key;
            this->value = value;
            this->parent = this->right = this->left = nullptr;
            this->black = false;
            this->isleftchild = false;
        }
    };
    typedef std::size_t size_t;
    node *root;
    size_t size;
    
    public:
    RBT()
    {
        this->root = nullptr;
        this->size = 0;
    };
    ~RBT()
    {
        delete this->root;
    }
    node *get_root()
    {
        return this->root;
    }
    void    insert(std::pair<K,V> m);
    void insert(node *parent,node *new_node);
    void    checkcolor(node *new_node);
    void    print(node *root);
    void    correctTree(node *new_node);
    void    rotate(node *new_node);
    void    rightRotate(node *new_node);
    void    leftRotate(node *new_node);
    void    rightLeftRotate(node *new_node);
    void    leftRightRotate(node *new_node);

};
template<class K,class V>
void RBT<K,V>::print(node *root)
{
    if (root == nullptr)
        return;

        print(root->left);
        std::cout <<"key " <<root->key << " value "<<root->value << "\n";
        print(root->right);
}
template<class K,class V>
void    RBT<K,V>::rightLeftRotate(node *new_node)
{
    rightRotate(new_node->right);
    leftRotate(new_node);
}
template<class K,class V>
void    RBT<K,V>::leftRightRotate(node *new_node)
{
    leftRotate(new_node->left);
    rightRotate(new_node);
}
template<class K,class V>
void    RBT<K,V>::rightRotate(node *new_node)
{
    node *tmp = new_node->left;
    new_node->left = tmp->right;
    if (new_node->left != nullptr)
    {
        new_node->left->parent = new_node;
        new_node->left->isleftchild = true;
    }
    if (new_node->parent  == nullptr)
    {
        this->root = tmp;
        tmp->parent = nullptr;
    }else 
    {
        tmp->parent = new_node->parent;
        if (new_node->isleftchild)
        {
            tmp->isleftchild = false;
            tmp->parent->right = tmp;
        }else 
        {
            tmp->isleftchild = true;
            tmp->parent->left = tmp;
        }
    }
    tmp->right = new_node;
    new_node->isleftchild = false;
    new_node->parent = tmp;

}
template<class K,class V>
void    RBT<K,V>::leftRotate(node *new_node)
{
    // puts("left");
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
template<class K,class V>
void RBT<K,V>::rotate(node *new_node)
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
template<class K,class V>
void RBT<K,V>::correctTree(node *new_node)
{
    // std::cout << "the key is " << new_node->parent->key << "  left child "<< new_node->parent->isleftchild<< "\n";
    if (new_node->parent->isleftchild)
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

    }else
    {
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
template<class K,class V>
void RBT<K,V>::checkcolor(node *new_node)
{
    // if (new_node == NULL)
    //     return ;
    if (new_node == this->root)
        return ;
    if (!new_node->black && !new_node->parent->black)
    {
        // puts("red");
        // std::cout << "the key" << new_node->key << "\n";
        correctTree(new_node);
    }
    if (new_node->parent != nullptr)
        checkcolor(new_node->parent);
}
template<class K,class V>
void RBT<K,V>::insert(node *parent,node *new_node)
{
    // std::cout << parent->key <<"  "<< new_node->key << "\n";
    if (parent->key < new_node->key)
    {
            // puts("right insert");
        if (parent->right == nullptr)
        {
            // puts("right");
            parent->right = new_node;
            new_node->parent = parent;
            new_node->isleftchild = false;
        }else 
             insert(parent->right,new_node);
    }
    else 
    {
        if (parent->left == nullptr)
        {
            // puts("left");
            parent->left = new_node;
            new_node->parent = parent;
            new_node->isleftchild = true;
        }
        else
            insert(parent->left,new_node);
    }
    checkcolor(new_node);
}

template<class K,class V>
void    RBT<K,V>::insert(std::pair<K,V> m)
{
    node *new_node = new node(m.first,m.second);
    // puts("try");
    if (root == nullptr)
    {
        // puts("good");
        root = new_node;
        root->black = true;
        size++;
        return;
    }
    insert(root,new_node);
    root->black = true;
    size++;
}
