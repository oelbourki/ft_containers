 // node*    delete_bst(node *root,const key_type& k){
    //     if (root == NULL)
    //         return root;
    //     if (k < root->key)
    //         root->left = delete_bst(root->left,k);
    //     else if (k > root->key)
    //         root->right = delete_bst(root->right,k);
    //     else if (root->right == NULL && root->left == NULL)
    //     {    
    //         std::cout << "case 1" << std::endl;
            
    //         // print_node(root->parent);
    //         // print_node(root);
    //         delete_node(&root);
    //         std::cout << "root1" << std::endl;
    //         print_node(root);
    //         std::cout << "root2" << std::endl;

    //         // this->printBT(this->root);
    //         // return root;
    //         // std::cout << "end" << std::endl;
    //     }
    //     else if (root->left == NULL)
    //     {
    //         std::cout << "case 2" << std::endl;
    //         node *tmp = root;
    //         root = root->right;
    //         // print_node(tmp);
    //         delete_node(&tmp);
    //         // delete tmp;
    //     }
    //     else if (root->right == NULL)
    //     {
    //         std::cout << "case 3" << std::endl;
    //         node *tmp = root;
    //         root = root->left;
    //         // print_node(tmp);
    //         delete_node(&tmp);
    //         // delete tmp;
    //     }
    //     else
    //     {
    //         std::cout << "case 4" << std::endl;
    //         // node* min = getMin(root->right);
    //         // root->key = min->key;
    //         // root->value = min->value;
    //         // root->right = delete_bst(root->right,min->key);
    //         node* max = getMax(root->left);
    //         root->key = max->key;
    //         root->value = max->value;
    //     std::cout << "rooe left before 1" << std::endl;
    //         print_node(root->left);
    //         root->left = delete_bst(root->left,max->key);
    //     std::cout << "rooe left after 1" << std::endl;
    //         print_node(root->left);

    //     }
    //     // std::cout << "return1" << std::endl;
    //     // print_node(root);
    //     // std::cout << "return2" << std::endl;

    //     return root;
    // }