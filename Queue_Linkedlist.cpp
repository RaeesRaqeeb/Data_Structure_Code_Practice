#include<iostream>


using namespace std;

class Nodes
{
    public:
    int info;
    Nodes *Next; //It will point to the object of the class made in the main function

    Nodes(int value)
    {
        info= value;
        Next=NULL;

    }

};


class Queue
{
    private:
            Nodes *front;
            Nodes *rear;
            int capacity;
            int length;
    
    public:
        Queue(int size)
        {
            capacity=size;
            length=0;
            front=NULL;
            rear=NULL;
        }

    void enqueue(int value)
    {
        
        Nodes *new_node= new Nodes(value);
        if(rear==NULL)
        {
            front=new_node;
            rear=new_node;
            
        }
        else
        {
            rear->Next=new_node;
            rear=new_node;
        }
        length++;

    }

    int dequeue()
    {
        if(front==NULL)
        {
            cout<<"THe queue is empty!!\n";
            return -1;
        }
        
        Nodes *curr=front;
        front=front->Next;
        int value=curr->info;
        delete curr;
        length--;
        return value;
    }

   


    void display()
    {
        Nodes *curr=front;
        for(int i=0;i<length;i++)
        {
            cout<<curr->info;
            curr=curr->Next;
        }
    }

};


int main(void)
{
    Queue Q_array1(5);
    Q_array1.enqueue(1);
    Q_array1.enqueue(2);
    Q_array1.enqueue(3);
    Q_array1.enqueue(4);
    Q_array1.enqueue(5);

cout<<"\nbefore calling the dequeue function\n";

    Q_array1.display();
    Q_array1.dequeue();
    Q_array1.dequeue();
    Q_array1.dequeue();
    Q_array1.dequeue();

cout<<"\nAfter calling the dequeue function\n";
    Q_array1.display();


    return 0;
}