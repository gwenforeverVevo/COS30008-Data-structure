#ifndef NARY_TREE_H
#define NARY_TREE_H

#include <iostream>
#include <vector>
#include <queue>

// Node structure for N-ary Tree
template <typename T>
struct NaryTreeNode {
    T data;                          // Data stored in the node
    std::vector<NaryTreeNode*> children;  // Vector of children nodes

    // Constructor
    NaryTreeNode(const T& value) : data(value) {}
};

// Class for N-ary Tree
template <typename T>
class NaryTree {
private:
    NaryTreeNode<T>* root; // Root node of the tree

    // Helper function for level order traversal
    void levelOrderTraversal(NaryTreeNode<T>* node) const {
        if (node == nullptr) return;

        std::queue<NaryTreeNode<T>*> q;
        q.push(node);

        while (!q.empty()) {
            NaryTreeNode<T>* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            // Push all children of the current node to the queue
            for (NaryTreeNode<T>* child : current->children) {
                q.push(child);
            }
        }
    }

public:
    // Constructor
    NaryTree() : root(nullptr) {}

    // Destructor: Clean up the tree
    ~NaryTree() {
        deleteTree(root);
    }

    // Function to delete the tree
    void deleteTree(NaryTreeNode<T>* node) {
        if (node == nullptr) return;
        
        for (auto child : node->children) {
            deleteTree(child); // Recursively delete all children
        }

        delete node; // Delete the current node
    }

    // Set the root of the tree
    void setRoot(const T& value) {
        if (root == nullptr) {
            root = new NaryTreeNode<T>(value);
        }
    }

    // Add a child to a specific node
    void addChild(const T& parentValue, const T& childValue) {
        if (root == nullptr) return;

        std::queue<NaryTreeNode<T>*> q;
        q.push(root);

        // Perform BFS to find the parent node
        while (!q.empty()) {
            NaryTreeNode<T>* current = q.front();
            q.pop();

            if (current->data == parentValue) {
                NaryTreeNode<T>* childNode = new NaryTreeNode<T>(childValue);
                current->children.push_back(childNode);
                return;
            }

            // Enqueue children of the current node
            for (NaryTreeNode<T>* child : current->children) {
                q.push(child);
            }
        }
    }

    // Display the tree in level order
    void displayLevelOrder() const {
        levelOrderTraversal(root);
        std::cout << std::endl;
    }

    // Iterator class for the tree traversal
    class Iterator {
    private:
        std::queue<NaryTreeNode<T>*> nodeQueue;

    public:
        // Constructor
        Iterator(NaryTreeNode<T>* root) {
            if (root != nullptr) {
                nodeQueue.push(root);
            }
        }

        // Check if there are more nodes
        bool hasNext() {
            return !nodeQueue.empty();
        }

        // Get the next node and move the iterator forward
        T next() {
            if (nodeQueue.empty()) {
                throw std::out_of_range("No more elements.");
            }

            NaryTreeNode<T>* node = nodeQueue.front();
            nodeQueue.pop();

            // Add children to the queue
            for (auto child : node->children) {
                nodeQueue.push(child);
            }

            return node->data;
        }
    };

    // Begin and end methods for the iterator
    Iterator begin() {
        return Iterator(root);
    }
    Iterator end() {
        return Iterator(nullptr);  // End is when the queue is empty
    }
};

#endif // NARY_TREE_H
