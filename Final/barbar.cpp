// #include<iostream>
// #include<vector>
// #include<set>

// using namespace std;

// class Client
// {
//     public:
//             int client_id;
//             string client_name;
//             char gender;
        
//     public:
//     Client(int id, string name, char Gen)
//     {
//         client_id=id;
//         client_name=name;
//         gender=Gen;
//     }
// };

// class Node
// {
//     public:
//     Client *client;
//     Node *next;

//     Node(Client *client)
//     {
//         this->client=client;
//         next=NULL;
//     }

//     ~Node()
//     {
//         delete client;
//     }
// };

// class HashTable
// {
//     public:

//     vector<Node*> table;
//     int capacity;
//     set<int> BST;

//     HashTable(int size)
//     {
//         capacity=size;
//         table.resize(size,nullptr);
//     }

//     ~HashTable()
//     {
//         for (int i = 0; i < capacity; ++i)
//         {
//             Node *curr = table[i];
//             while (curr != nullptr)
//             {
//                 Node *temp = curr;
//                 curr = curr->next;
//                 delete temp;
//             }
//         }
//     }

//     int hashFunction(int id)
//     {
//         return id % capacity;
//     }

//     void insertion(int id, string name, char G)
//     {
//         Client *new_client= new Client(id,name,G);
//         Node *new_node=new Node(new_client);
//         BST.insert(new_client->client_id);
//         int index=hashFunction(id);
//         new_node->next=table[index];
//         table[index]=new_node;
//     }

//     void update(int id, string name)
//     {
//         int index=hashFunction(id);
        
//         Node *curr=table[index];
//         bool found=false;
//         while(curr!= NULL)
//         {
//             if(curr->client->client_id == id)
//             {
//                 curr->client->client_name=name;
//                 found=true;
//             }
//             curr=curr->next;
//         }
//         if(!found)
//         {
//             cout<<"No such ID exist in the data"<<endl;
//         }
//     }

//     int getClientsLessThanID(int id)
//     {
//         int male = 0, female = 0;

//         for (auto it = BST.begin(); it != BST.end() && *it < id; ++it)
//         {
//             int index = hashFunction(*it);
//             Node *curr = table[index];
//             while (curr != NULL)
//             {
//                 if (curr->client->client_id == *it)
//                 {
//                     if (curr->client->gender == 'M')
//                         male++;
//                     else if (curr->client->gender == 'F')
//                         female++;
//                 }
//                 curr = curr->next;
//             }
//         }
//         return abs(male - female);
//     }

//   void deleteClient(int id) 
//   {
//         int index = hashFunction(id);
//         Node* curr = table[index];
//         Node* prev = nullptr;

//         while (curr != nullptr && curr->client->client_id != id) {
//             prev = curr;
//             curr = curr->next;
//         }

//         if (curr == nullptr) {
//             cout << "Client with ID " << id << " not found." << endl;
//             return;
//         }

//         if (prev == nullptr) {
//             table[index] = curr->next;
//         } else {
//             prev->next = curr->next;
//         }

//         BST.erase(id);
//         delete curr;
//         cout << "Client with ID " << id << " deleted successfully." << endl;
//     }


// void display()
//     {
//         for(int i=0;i<capacity;i++)
//         {
//             Node *curr=table[i];
//             while(curr !=NULL)
//             {   
//                 cout<<"\n***************************************************\n";
//                 cout<<"Client Name:"<<curr->client->client_name<<endl;
//                 cout<<"Client ID:"<<curr->client->client_id<<endl;
//                 cout<<"Client Gender:"<<curr->client->gender<<endl;
//                 curr=curr->next;
//             }
//         }
//     }
// };

// int main(void)
// {
//     HashTable obj1(5);
//     obj1.insertion(9,"raees",'M');
//     obj1.insertion(10,"qwe",'F');
//     obj1.insertion(20,"kah",'F');
//     obj1.insertion(7,"asd",'M');
//     obj1.insertion(1,"zxcv",'F');

//     cout<<"Difference between male and female:"<<obj1.getClientsLessThanID(11)<<endl;
//     cout<<"\nBefore changing:"<<endl;
//     obj1.display();

//     obj1.update(10,"Fatima");
//     cout<<"\nAfter changing:"<<endl;

//     obj1.display();

//     obj1.deleteClient(20);
//     cout << "\nAfter deleting client with ID 20:" << endl;
//     obj1.display();

//     return 0;
// }



//Second method using linkedlist


#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct ClientNode {
    int client_id;
    string name;
    char gender; // 'M' for Male, 'F' for Female
    ClientNode* next;

    ClientNode(int id, string n, char g) {
        client_id = id;
        name = n;
        gender = g;
        next = nullptr;
    }
};

class BarberShop {
private:
    ClientNode* head;

public:
    BarberShop() {
        head = nullptr;
    }

    ~BarberShop() {
        ClientNode* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a new client
    void Insert(int client_id, string name, char gender) 
    {
        ClientNode* newClient = new ClientNode(client_id, name, gender);
        
        // Insert at the beginning of the linked list
        newClient->next = head;
        head = newClient;

        cout << "Client added: " << name << ", Gender: " << gender << endl;
    }

    // Update the name of the client with the given client_id
    void Update(int client_id, string name) {
        ClientNode* temp = head;
        while (temp) {
            if (temp->client_id == client_id) {
                temp->name = name;
                cout << "Client updated: " << client_id << " -> " << name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Client ID not found!" << endl;
    }

    // Calculate the difference between the number of men and women with ID < client_id
    int ClientDiff(int client_id) {
        int menCount = 0, womenCount = 0;
        ClientNode* temp = head;

        while (temp) {
            if (temp->client_id < client_id) {
                if (temp->gender == 'M')
                    menCount++;
                else if (temp->gender == 'F')
                    womenCount++;
            }
            temp = temp->next;
        }

        return menCount - womenCount;
    }

    // Display all clients
    void DisplayClients() {
        ClientNode* temp = head;
        while (temp) {
            cout << "Client ID: " << temp->client_id << ", Name: " << temp->name << ", Gender: " << temp->gender << endl;
            temp = temp->next;
        }
    }
};

int main() {
    BarberShop shop;

    // Insert clients
    shop.Insert(1, "Alice", 'F');
    shop.Insert(2, "Bob", 'M');
    shop.Insert(3, "Charlie", 'M');
    shop.Insert(4, "Diana", 'F');

    // Update a client name
    shop.Update(3, "Charles");

    // Calculate gender difference for client_id < 4
    int diff = shop.ClientDiff(4);
    cout << "Difference (Men - Women) with ID < 4: " << diff << endl;

    // Display all clients
    shop.DisplayClients();

    return 0;
}