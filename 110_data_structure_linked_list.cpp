#include <iostream>

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Define a linked list class
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = head; // Point the new node to the current head
        head = newNode; // Update the head to the new node
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head; // Start from the head
        while (current != nullptr) {
            std::cout << current->data << " "; // Print current node's data
            current = current->next; // Move to the next node
        }
        std::cout << std::endl;
    }

    // Destructor to free memory allocated for nodes
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    std::cout << "Linked List: ";
    list.display();

    return 0;
}
