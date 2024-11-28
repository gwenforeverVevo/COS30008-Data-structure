#include <iostream>
#include <queue>

// Node structure for Binary Tree
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    // Constructor
    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for Binary Tree
class BinaryTree
{
private:
    BinaryTreeNode *root;

    // Helper function for inorder traversal
    void inorderTraversal(BinaryTreeNode *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Function to insert a node in the binary tree
    void insert(int value)
    {
        if (root == nullptr)
        {
            root = new BinaryTreeNode(value);
        }
        else
        {
            std::queue<BinaryTreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                BinaryTreeNode *temp = q.front();
                q.pop();
                if (temp->left == nullptr)
                {
                    temp->left = new BinaryTreeNode(value);
                    break;
                }
                else
                {
                    q.push(temp->left);
                }
                if (temp->right == nullptr)
                {
                    temp->right = new BinaryTreeNode(value);
                    break;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
    }

    // Function to display the tree in Inorder
    void displayInorder()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

