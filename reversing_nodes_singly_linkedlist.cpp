#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;
        int length;
        

        SinglyLinkedList() {
            length=0;
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
            length++;
        }


 void display_linked_list()
    {
        SinglyLinkedListNode *Curr_ptr=head;
        cout<<"\nYaha aya mai?"<<endl;
        for(int i=0;i<length;i++)
        {
            cout<<Curr_ptr->data<<endl;
            if(Curr_ptr->next!=NULL)
            Curr_ptr=Curr_ptr->next;
        }
        
    }

void reverse()
{
    SinglyLinkedListNode *ptr1=head;
    SinglyLinkedListNode *ptr2=head;
    SinglyLinkedListNode *ptr3=head;
    
    int j=length;
    int i=0;
    while(j>1)
    {
        if(i==0)
            {
            ptr2=ptr2->next;
            head=ptr2;
            ptr1->next=NULL;
            }
            
        
        head=ptr2;
        if(ptr2->next!=NULL)
        ptr3=ptr2->next;
        ptr2->next=ptr1;
        head=ptr3;
        ptr1=ptr2;
        ptr2=ptr3;
        
        
        i++;
        j--;
        
    }
        // head=ptr2;
        // if(ptr2->next!=NULL)
        //     ptr3=ptr2->next;
        // ptr2->next=ptr1;
        // head=ptr3;
        // ptr1=ptr2;
        // ptr2=ptr3;
    


}
};
int main()
{
    SinglyLinkedList l1;
    l1.insert_node(1);
    l1.insert_node(2);
    l1.insert_node(3);
    l1.insert_node(4);
    l1.insert_node(5);
    l1.insert_node(6);
    l1.insert_node(7);
    cout<<"Before reverse:"<<endl;
    l1.display_linked_list();    
    l1.reverse();
    l1.display_linked_list();
    }