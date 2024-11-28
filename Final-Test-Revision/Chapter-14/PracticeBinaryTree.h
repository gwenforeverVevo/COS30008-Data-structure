#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

// Node structure for Binary Tree
template <typename T>
struct BinaryTreeNode
{
    T data;                // Data stored in the node
    BinaryTreeNode *left;  // Pointer to the left child
    BinaryTreeNode *right; // Pointer to the right child

    // Constructor
    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for Binary Tree
template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *root; // Root node of the binary tree

    // Helper functions
    void inorderTraversal(BinaryTreeNode<T> *node) const;
    void preorderTraversal(BinaryTreeNode<T> *node) const;
    void postorderTraversal(BinaryTreeNode<T> *node) const;
    BinaryTreeNode<T> *insert(BinaryTreeNode<T> *node, T value);
    void destroyTree(BinaryTreeNode<T> *node);

public:
    // Constructor
    template <typename T>
    BinaryTree<T>::BinaryTree() : root(nullptr)
    {
    }

    // Destructor
    template <typename T>
    BinaryTree<T>::~BinaryTree()
    {
        destroyTree(root);
    }

    // Insert a node
    template <typename T>
    void BinaryTree<T>::insert(T value)
    {

        if (node == nullptr)
        {
            return new BinaryTree<t>(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value)
        }
        else
        {
            node->right = insert(node->right, value)
        }
        return node
    }

    // Traversal methods
    template <typename T>
    void BinaryTree<T>::preorderTraversal(BinaryTreeNode<T> *node) const
    {
        if (node != nullptr)
        {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    template <typename T>
    void BinaryTree<T>::displayPostorder() const
    {
        postorderTraversal(root);
        std::cout << std::endl;
    }

    template <typename T>
    void BinaryTree<T>::postorderTraversal(BinaryTreeNode<T> *node) const
    {
        if (node != nullptr)
        {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    };

#endif // BINARY_TREE_H
