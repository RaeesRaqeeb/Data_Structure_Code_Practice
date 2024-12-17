// #include<iostream>
// #include<queue>

// using namespace std;



// //Node for linked list
// class Node
// {
//     public:
//             int info;
//             Node *left;
//             Node *right;
//             Node *parent;

//     Node(int info)
//     {
//         this->info=info;
//         left=NULL;
//         right=NULL;
//         parent=NULL;
//     }

// };


// class Heap
// {
//     public:
//             Node *root;

//     Heap()
//     {
//         root=NULL;
//     }
//     Node* find_parent(Node *new_be)
//     {
//         Node *curr=root;
//         queue<Node*>q;
//         q.push(curr);
//         while(!q.empty())
//         {
//             Node *parent=q.front();
//             q.pop();
//             if(!parent->left || !parent->right)return parent;

//             if(parent->left) q.push(parent->left);

//             if(parent->right) q.push(parent->right);
//         }

//         return nullptr;
//     }

//  // Helper function to heapify up
//     void heapifyUp(Node* node) {
//         if (node->parent && node->info > node->parent->info) {
//             swap(node, node->parent);
//             heapifyUp(node->parent);
//         }
//     }

//     // Helper function to heapify down
//     void heapifyDown(Node* node) {
//         Node* largest = node;
//         if (node->left && node->left->info > largest->info) {
//             largest = node->left;
//         }
//         if (node->right && node->right->info > largest->info) {
//             largest = node->right;
//         }
//         if (largest != node) {
//             swap(node, largest);
//             heapifyDown(largest);
//         }
//     }


//     void insertion(int value)
//     {
//         Node *new_node= new Node(value);
//         if(root==NULL)
//         {
//             root=new_node;
//         }

//         Node *parent=find_parent(new_node);
//         new_node->parent=parent;
//         if(!parent->left)
//         {
//             parent->left=new_node;

//         }
//         else if(!parent->right)
//             parent->right=new_node;

//         heapifyUp(new_node);

//     }

//     Node* level_traversal(Node *curr, int position)
//     {
//         if (curr == nullptr) {
//             return nullptr;
//         }

//         queue<Node*> q;
//         q.push(curr);
//         int current_position = 0;

//         while (!q.empty()) {
//             Node* node = q.front();
//             q.pop();

//             if (current_position == position) {
//                 return node;
//             }

//             current_position++;

//             if (node->left) {
//                 q.push(node->left);
//             }

//             if (node->right) {
//                 q.push(node->right);
//             }
//         }

//         return nullptr;
//     }

//     void update(int position, int value)
//     {
//         Node *curr=root;
//         if(curr==NULL)
//         {
//             cout<<"the heap is empty."<<endl;
//             return;
//         }
//         curr=level_traversal(curr,position);
//         curr->info=value;
//         heapifyUp(curr);
//          heapifyDown(curr);
//     }

//     void display() 
//     {
//         if (root == nullptr) {
//             cout << "Heap is empty" << endl;
//             return;
//         }

//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) 
//         {
//             Node* node = q.front();
//             q.pop();
//             cout << node->info << " ";
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         cout << endl;
//     }
// };


// int main() {
//     Heap heap;

//     // Insert elements into the heap
//     heap.insertion(10);
//     heap.insertion(20);
//     heap.insertion(15);
//     heap.insertion(30);
//     heap.insertion(25);

//     // Display the heap
//     cout << "Heap: ";
//     heap.display();

//     // Find node by position
//     int position = 3;
//     // Node* node = heap.level_traversal(node, position);
//     // if (node) {
//     //     cout << "Node at position " << position << ": " << node->info << endl;
//     // } else {
//     //     cout << "Node not found at position " << position << endl;
//     // }

//     // Update node value at position
//     heap.update(position, 35);
//     cout << "Heap after update: ";
//     // heap.display();

//     return 0;
// }


// #include <iostream>
// #include <queue>

// using namespace std;

// // Node for linked list
// class Node {
// public:
//     int info;
//     Node* left;
//     Node* right;
//     Node* parent;

//     Node(int info) {
//         this->info = info;
//         left = nullptr;
//         right = nullptr;
//         parent = nullptr;
//     }
// };

// class Heap {
// public:
//     Node* root;

//     Heap() {
//         root = nullptr;
//     }

//     // Helper function to swap values of two nodes
//     void swap(Node* a, Node* b) {
//         int temp = a->info;
//         a->info = b->info;
//         b->info = temp;
//     }

//     // Helper function to heapify up
//     void heapifyUp(Node* node) {
//         if (node->parent && node->info > node->parent->info) {
//             swap(node, node->parent);
//             heapifyUp(node->parent);
//         }
//     }

//     // Helper function to heapify down
//     void heapifyDown(Node* node) {
//         Node* largest = node;
//         if (node->left && node->left->info > largest->info) {
//             largest = node->left;
//         }
//         if (node->right && node->right->info > largest->info) {
//             largest = node->right;
//         }
//         if (largest != node) {
//             swap(node, largest);
//             heapifyDown(largest);
//         }
//     }

//     // Helper function to find the parent of the next insertion point
//     Node* findInsertionParent() {
//         if (!root) return nullptr;
//         Node* curr = root;
//         while (true) {
//             if (!curr->left) return curr;
//             if (!curr->right) return curr;
//             if (!curr->left->left || !curr->left->right) {
//                 curr = curr->left;
//             } else {
//                 curr = curr->right;
//             }
//         }
//         return nullptr;
//     }

//     // Insert a new value into the heap
//     void insert(int value) 
//     {
//         Node* newNode = new Node(value);
//         if (!root) {
//             root = newNode;
//         } else {
//             Node* parent = findInsertionParent();
//             newNode->parent = parent;
//             if (!parent->left) {
//                 parent->left = newNode;
//             } else {
//                 parent->right = newNode;
//             }
//             heapifyUp(newNode);
//         }
//     }

//     // Find the node at a given position using level-order traversal
//     Node* findNodeByPosition(int position) {
//         if (!root) return nullptr;
//         queue<Node*> q;
//         q.push(root);
//         int current_position = 0;
//         while (!q.empty()) 
//         {
//             Node* node = q.front();
//             q.pop();
//             if (current_position == position) {
//                 return node;
//             }
//             current_position++;
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         return nullptr;
//     }

//     // Update the value of the node at a given position
//     void update(int position, int value) {
//         Node* node = findNodeByPosition(position);
//         if (!node) {
//             cout << "Node not found at position " << position << endl;
//             return;
//         }
//         node->info = value;
//         heapifyUp(node);
//         heapifyDown(node);
//     }

//     // Display the heap using level-order traversal
//     void display() {
//         if (!root) {
//             cout << "Heap is empty" << endl;
//             return;
//         }
//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) {
//             Node* node = q.front();
//             q.pop();
//             cout << node->info << " ";
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Heap heap;

//     // Insert elements into the heap
//     heap.insert(10);
//     heap.insert(20);
//     heap.insert(15);
//     heap.insert(30);
//     heap.insert(25);

//     // Display the heap
//     cout << "Heap: ";
//     heap.display();

//     // Find node by position
//     int position = 3;
//     Node* node = heap.findNodeByPosition(position);
//     if (node) {
//         cout << "Node at position " << position << ": " << node->info << endl;
//     } else {
//         cout << "Node not found at position " << position << endl;
//     }

//     // Update node value at position
//     heap.update(position, 35);
//     cout << "Heap after update: ";
//     heap.display();

//     return 0;
// }

#include <iostream>
#include <queue>
using namespace std;

// Node structure for the Max-Heap
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class MaxHeap {
private:
    Node* root;

    // Helper function to perform heapify-up (bubble up)
    void heapifyUp(Node* current) {
        if (!current || !parentMap[current]) return;

        Node* parent = parentMap[current];

        if (parent->data < current->data) 
        {
            swap(parent->data, current->data);
            heapifyUp(parent);
        }
    }

    // Helper function to perform heapify-down (bubble down)
    void heapifyDown(Node* current)
    {
        if (!current) return;

        Node* largest = current;
        if (current->left && current->left->data > largest->data)
            largest = current->left;
        if (current->right && current->right->data > largest->data)
            largest = current->right;

        if (largest != current) {
            swap(largest->data, current->data);
            heapifyDown(largest);
        }
    }

    // Map to keep track of parents during insertion
    Node* parentMap[100]; // For simplicity, we assume a fixed size.

    // Function to find the next available position for insertion
    Node* findInsertPosition() 
    {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) 
        {
            Node* current = q.front();
            q.pop();

            if (!current->left) 
            {
                parentMap[current->left] = current; // Save parent
                return current;
            }
             else if (!current->right)
             {
                parentMap[current->right] = current; // Save parent
                return current;
            } 
            else 
            {
                q.push(current->left);
                q.push(current->right);
            }
        }
        return nullptr;
    }

    // Function to find the last node for removal
    Node* findLastNode() {
        queue<Node*> q;
        q.push(root);
        Node* last = nullptr;

        while (!q.empty()) {
            last = q.front();
            q.pop();

            if (last->left) q.push(last->left);
            if (last->right) q.push(last->right);
        }
        return last;
    }

public:
    MaxHeap() : root(nullptr) {}

    // Insert a new value into the Max-Heap
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        Node* insertPosition = findInsertPosition();
        if (!insertPosition->left) {
            insertPosition->left = newNode;
            parentMap[newNode] = insertPosition;
        } else {
            insertPosition->right = newNode;
            parentMap[newNode] = insertPosition;
        }

        // Restore heap property
        heapifyUp(newNode);
    }

    // Remove and return the maximum value (root) from the Max-Heap
    int removeMax() {
        if (!root) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int maxValue = root->data;

        Node* lastNode = findLastNode();
        if (lastNode == root) {
            delete root;
            root = nullptr;
            return maxValue;
        }

        // Replace root data with last node data
        root->data = lastNode->data;

        // Remove the last node
        Node* parent = parentMap[lastNode];
        if (parent->left == lastNode) parent->left = nullptr;
        else parent->right = nullptr;

        delete lastNode;

        // Restore heap property
        heapifyDown(root);

        return maxValue;
    }

    // Display the heap level-wise
    void display() {
        if (!root) {
            cout << "Heap is empty!" << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    // Insert elements
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);
    heap.insert(8);
    heap.insert(9);

    cout << "Heap elements (level-wise): ";
    heap.display();

    // Remove maximum elements
    cout << "Removed Max: " << heap.removeMax() << endl;
    cout << "Heap elements after removing max: ";
    heap.display();

    cout << "Removed Max: " << heap.removeMax() << endl;
    cout << "Heap elements after removing max: ";
    heap.display();

    return 0;
}
