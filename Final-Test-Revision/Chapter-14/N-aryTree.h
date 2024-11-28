#include <iostream>
#include <vector>
#include <queue>

// Node structure for N-ary Tree
struct NaryTreeNode {
    int data;
    std::vector<NaryTreeNode*> children;

    // Constructor
    NaryTreeNode(int value) : data(value) {}
};

// Class for N-ary Tree
class NaryTree {
private:
    NaryTreeNode* root;

    // Helper function for level order traversal
    void levelOrderTraversal(NaryTreeNode* node) {
        if (node == nullptr) return;

        std::queue<NaryTreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            NaryTreeNode* temp = q.front();
            q.pop();
            std::cout << temp->data << " ";

            for (NaryTreeNode* child : temp->children) {
                q.push(child);
            }
        }
    }

public:
    // Constructor
    NaryTree() : root(nullptr) {}

    // Function to set the root
    void setRoot(int value) {
        root = new NaryTreeNode(value);
    }

    // Function to add a child to a node
    void addChild(int parentValue, int childValue) {
        if (root == nullptr) return;

        std::queue<NaryTreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            NaryTreeNode* temp = q.front();
            q.pop();
            if (temp->data == parentValue) {
                temp->children.push_back(new NaryTreeNode(childValue));
                return;
            }

            for (NaryTreeNode* child : temp->children) {
                q.push(child);
            }
        }
    }

    // Function to display the tree in level order
    void displayLevelOrder() {
        levelOrderTraversal(root);
        std::cout << std::endl;
    }
};

// Test N-ary Tree
int main() {
    NaryTree tree;
    tree.setRoot(1);
    tree.addChild(1, 2);
    tree.addChild(1, 3);
    tree.addChild(1, 4);
    tree.addChild(2, 5);
    tree.addChild(2, 6);

    std::cout << "Level Order Traversal: ";
    tree.displayLevelOrder();

    return 0;
}
