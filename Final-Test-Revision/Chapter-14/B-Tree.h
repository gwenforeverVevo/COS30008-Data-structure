#include <iostream>
#include <vector>

// Node structure for B-Tree
class BTreeNode {
public:
    std::vector<int> keys; // Vector of keys
    std::vector<BTreeNode*> children; // Vector of children pointers
    bool isLeaf; // Is true if this is a leaf node

    // Constructor
    BTreeNode(bool isLeaf) : isLeaf(isLeaf) {}

    // Function to insert a key into the node
    void insertNonFull(int key, int t) {
        int i = keys.size() - 1;

        if (isLeaf) {
            keys.push_back(0);
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
        } else {
            while (i >= 0 && keys[i] > key) {
                i--;
            }
            i++;
            if (children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, t);
                if (keys[i] < key) i++;
            }
            children[i]->insertNonFull(key, t);
        }
    }

    void splitChild(int i, int t) {
        BTreeNode* y = children[i];
        BTreeNode* z = new BTreeNode(y->isLeaf);
        z->keys.resize(t - 1);

        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }

        if (!y->isLeaf) {
            z->children.resize(t);
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }

        y->keys.resize(t - 1);
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }
};

// Class for B-Tree
class BTree {
private:
    BTreeNode* root;
    int t; // Minimum degree

public:
    BTree(int t) : root(nullptr), t(t) {}

    void insert(int key) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(false);
                s->children.push_back(root);
                s->splitChild(0, t);

                int i = 0;
                if (s->keys[0] < key) i++;
                s->children[i]->insertNonFull(key, t);

                root = s;
            } else {
                root->insertNonFull(key, t);
            }
        }
    }

    void display() {
        display(root, 0);
    }

    void display(BTreeNode* node, int depth) {
        if (!node) return;

        for (int i = 0; i < node->keys.size(); i++) {
            display(node->children.empty() ? nullptr : node->children[i], depth + 1);
            std::cout << std::string(depth * 4, ' ') << node->keys[i] << std::endl;
        }

        if (!node->children.empty()) {
            display(node->children.back(), depth + 1);
        }
    }
};

// Test B-Tree
int main() {
    BTree tree(2);

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    std::cout << "B-Tree structure:" << std::endl;
    tree.display();

    return 0;
}
