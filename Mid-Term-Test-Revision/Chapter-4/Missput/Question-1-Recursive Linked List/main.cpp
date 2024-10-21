#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Recursive function to insert a node at the end of the list
void insert(Node*& head, int value) {
    if (head == nullptr) {
        head = new Node(value);
        return;
    }
    insert(head->next, value);
    
}

// Recursive function to display the list
void display(Node* head) {
    if (head == nullptr)
        return;
    std::cout << head->data << " ";
    display(head->next);  // Recursive step
}

int main() {
    Node* head = nullptr;

    // Insert values into the list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    // Display the list
    std::cout << "Linked List: ";
    display(head);

    return 0;
}
