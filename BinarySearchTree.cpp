//
// Created by Juan-Fernando Prado Morales on 5/27/21.
//

#include "BinarySearchTree.h"
#include <iostream>

template <class KeyType, class ValueType>
BinarySearchTree<KeyType, ValueType>::BinarySearchTree() {
    root = new TreeNode<KeyType, ValueType>();
}

template <class KeyType, class ValueType>
const TreeNode<KeyType, ValueType>* BinarySearchTree<KeyType, ValueType>::findRoot() {
    return root;
}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::addRoot(KeyType key, ValueType value) {
    TreeNode<KeyType, ValueType>* temp = new TreeNode<KeyType, ValueType>();
    temp->key = key; temp->value = value;
    temp->left = root->left;
    temp->right = root->right;
    if(root->left != nullptr)
        root->left->parent = temp;
    if(root->right != nullptr)
        root->right->parent = temp;
    delete root;
    root = temp;


}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::destroy(TreeNode<KeyType, ValueType>*t) {
    if(t == nullptr)
        return;
    destroy(t->left);
    destroy(t->right);
    delete t;
}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::insert_helper(TreeNode<KeyType, ValueType>* node, KeyType K, ValueType V){

        if (node->key > K) {
            if (node->left == nullptr) {
                node->left = new TreeNode<KeyType, ValueType>();
                node->left->key = K;
                node->left->value = V;
                node->left->parent = node;
            } else {
                insert_helper(node->left, K, V);
            }
        }
        if (node->key < K) {
            if (node->right == nullptr) {
                node->right = new TreeNode<KeyType, ValueType>();
                node->right->key = K;
                node->right->value = V;
                node->right->parent = node;
            } else {
                insert_helper(node->right, K, V);
            }
        }
}

template <class KeyType, class ValueType>
KeyType BinarySearchTree<KeyType, ValueType>::min_key() {
    TreeNode<KeyType, ValueType>* pos = root;
    while (pos->left != nullptr){
        pos = pos->left;
    }
    return pos->key;
}

template <class KeyType, class ValueType>
KeyType BinarySearchTree<KeyType, ValueType>::max_key(){
    TreeNode<KeyType, ValueType>* pos = root;
    while (pos->right != nullptr){
        pos = pos->right;
    }
    return pos->key;
}

template <class KeyType, class ValueType>
bool BinarySearchTree<KeyType, ValueType>::search(KeyType key){
    TreeNode<KeyType, ValueType>* pos = root;
    while (pos != nullptr){
        if(pos->key < key){
            pos = pos->right;
        }
        else if(key < pos->key){
            pos = pos->left;
        }else{
            return true;
        }
    }
    return false;
}

template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::preorder(TreeNode<KeyType, ValueType>* n){
    std::cout << n->key;
    if (n->left != nullptr){
        std::cout << ' ';
        preorder(n->left);
    }
    if(n->right != nullptr){
        std::cout << ' ';
        preorder(n->right);
    }
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::postorder(TreeNode<KeyType, ValueType>* n){
    if (n == nullptr)
        return;
    postorder(n->left);
    postorder(n->right);
    std::cout << n->key << ' ';
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::inorder(TreeNode<KeyType, ValueType>* n){
    if (n == nullptr)
        return;
    inorder(n->left);
    std::cout << n->key << ' ';
    if (n == nullptr)
        return;
    inorder(n->right);
}