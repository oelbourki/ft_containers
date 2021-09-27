// C++ program to insert a node in AVL tree  
#include<bits/stdc++.h> 
using namespace std; 
#include <vector>

template<class K,class V,class compare>
class avl
{
	// class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	// {
	// 	friend class map<const Key,T>;
	// 	private:
	// 	Node *cur;
	// 	public:
	// 	iterator 		&operator++(){cur = cur->next;;return *this;}
	// 	iterator 		&operator--(){cur = cur->prev;return *this;}
	// 	iterator 		&operator--(int){iterator tmp = *this;(--this);return *this;}
	// 	iterator		operator++(int) {iterator copy = *this;++(*this);return copy;}
	// 	reference		operator*(){return cur->data;};
	// };
	public:
	struct Node
	{
		K key;
		V value;
		Node *right,*left,*parent;
		int height;
		Node(K key,V value)
		{
			this->key = key;
			this->value = value;
			this->parent = this->right = this->left = nullptr;
			this->height = 1;
		}
	};
	avl()
	{
		this->root = nullptr;
		this->size = 0;
	};
	~avl()
	{
		delete this->root;
	}
	Node* get_root(){return this->root;}
	void    insert(K key,V value);
	void    insert(std::pair<K,V> v);
	void preOrder(Node *root)  ;
	void get_vector(){
		typename std::vector<Node*>::iterator iter;
		for (iter = this->v.begin(); iter != this->v.end(); iter++)
		{
			std::cout << (*iter)->key<< std::endl;
		}
		
	}
	private:
	std::vector<Node*> v;
	compare cmp;
	typedef std::size_t size_t;
	Node *root;
	size_t size;
	int height(Node *N) ;
	Node *rightRotate(Node *y)  ;
	Node *leftRotate(Node *x)  ;
	Node* newNode(K key,V value) ;
	int getBalance(Node *N) ;
	Node* insert(Node* node, K key,V value)  ;
	void	push_stack(Node *root) ;
};
  template<class K,class V,class compare>
  void  avl<K,V,compare>::insert(K key,V value)
  {
	  this->root = insert(this->root,key,value);
  }
  template<class K,class V,class compare>
  void  avl<K,V,compare>::insert(std::pair<K,V> v)
  {
	  this->root = insert(this->root,v->first,v->second);
  }
// A utility function to get maximum 
// of two integers  
int max(int a, int b);  
  
// A utility function to get the  
// height of the tree  
template<class K,class V,class compare>
int avl<K,V,compare>::height(Node *N)  
{  
	if (N == NULL)  
		return 0;  
	return N->height;  
}  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b)  
{  
	return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
template<class K,class V,class compare>
typename avl<K,V,compare>::Node* avl<K,V,compare>::newNode(K key,V value)  
{  
	Node* node = new Node(key,value); 
	return(node);  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
template<class K,class V,class compare>
typename avl<K,V,compare>::Node *avl<K,V,compare>::rightRotate(Node *y)  
{  
	Node *x = y->left;  
	Node *T2 = x->right;  
  
	// Perform rotation  
	x->right = y;  
	y->left = T2;  
  
	// Update heights  
	y->height = max(height(y->left), 
					height(y->right)) + 1;  
	x->height = max(height(x->left), 
					height(x->right)) + 1;  
  
	// Return new root  
	return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above. 
template<class K,class V,class compare> 
typename avl<K,V,compare>::Node *avl<K,V,compare>::leftRotate(Node *x)  
{  
	Node *y = x->right;  
	Node *T2 = y->left;  
  
	// Perform rotation  
	y->left = x;  
	x->right = T2;  
  
	// Update heights  
	x->height = max(height(x->left),     
					height(x->right)) + 1;  
	y->height = max(height(y->left),  
					height(y->right)) + 1;  
  
	// Return new root  
	return y;  
}  
  
// Get Balance factor of node N 
template<class K,class V,class compare>
int avl<K,V,compare>::getBalance(Node *N)  
{  
	if (N == NULL)  
		return 0;  
	return height(N->left) - height(N->right);  
}  
  
// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree. 
template<class K,class V,class compare> 
typename avl<K,V,compare>::Node* avl<K,V,compare>::insert(Node* node, K key,V value)  
{  
	/* 1. Perform the normal BST insertion */
	if (node == NULL)  
		return(newNode(key,value));  
  
	if (key < node->key) 
		node->left = insert(node->left, key,value); 
	else if (key > node->key)  
		node->right = insert(node->right, key,value);  
	else // Equal keys are not allowed in BST  
		return node;  
  
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),  
						height(node->right));  
  
	/* 3. Get the balance factor of this ancestor  
		node to check whether this node became  
		unbalanced */
	int balance = getBalance(node);  
  
	// If this node becomes unbalanced, then  
	// there are 4 cases  
  
	// Left Left Case  
	if (balance > 1 && key < node->left->key)  
		return rightRotate(node);  
  
	// Right Right Case  
	if (balance < -1 && key > node->right->key)  
		return leftRotate(node);  
  
	// Left Right Case  
	if (balance > 1 && key > node->left->key)  
	{  
		node->left = leftRotate(node->left);  
		return rightRotate(node);  
	}  
  
	// Right Left Case  
	if (balance < -1 && key < node->right->key)  
	{  
		node->right = rightRotate(node->right);  
		return leftRotate(node);  
	}  
  
	push_stack(node);
	/* return the (unchanged) node pointer */
	return node;  
}  

template<class K,class V,class compare> 
void avl<K,V,compare>::push_stack(Node *root)  
{  
	if(root != NULL)  
	{  
		 push_stack(root->left);
		this->v.push_back(root); 
		push_stack(root->right);  
	}  
}  
// A utility function to print preorder  
// traversal of the tree.  
// The function also prints height  
// of every node  
template<class K,class V,class compare> 
void avl<K,V,compare>::preOrder(Node *root)  
{  
	if(root != NULL)  
	{  
		 preOrder(root->left);
		cout << root->key << " "<< root->value << " ";  
		preOrder(root->right);  
	}  
}  