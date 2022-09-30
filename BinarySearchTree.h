//
// Created by Juan-Fernando Prado Morales on 5/27/21.
//

#ifndef ASGMT5_BINARYSEARCHTREE_H
#define ASGMT5_BINARYSEARCHTREE_H

template <class KeyType, class ValueType>
struct TreeNode{
    KeyType key;
    ValueType value;
    TreeNode<KeyType, ValueType>* parent;
    TreeNode<KeyType, ValueType>* right;
    TreeNode<KeyType, ValueType>* left;
    TreeNode() :key(), value(), parent(nullptr), right(nullptr), left(nullptr){}
};

template <class KeyType, class ValueType>
class BinarySearchTree {
public:
    BinarySearchTree();

    void destroy(TreeNode<KeyType, ValueType>* t);
    ~BinarySearchTree(){destroy(root);}

    void insert(KeyType key, ValueType value){insert_helper(root, key, value);}

    KeyType min_key();

    KeyType max_key();

    bool search(KeyType key);
    const TreeNode<KeyType, ValueType>* findRoot();
    void addRoot(KeyType key, ValueType value);
    void print_inorder() {inorder(root);}
    void print_posorder() {postorder(root);}
    void print_preorder() {preorder(root);}
private:

    void inorder(TreeNode<KeyType, ValueType>* n);

    void postorder(TreeNode<KeyType, ValueType>* n);

    void preorder(TreeNode<KeyType, ValueType>* n);

    void insert_helper(TreeNode<KeyType, ValueType>* node, KeyType K, ValueType V);

    TreeNode<KeyType, ValueType>* root = nullptr;
    int count = 0;

};


#endif //ASGMT5_BINARYSEARCHTREE_H
