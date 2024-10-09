#include<iostream>


using namespace std;


class Queue
{
    private:
            int front;
            int rear;
            int *array;
            int capacity;
            int length;
    
    public:
        Queue(int size)
        {
            capacity=size;
            length=0;
            front=capacity;
            rear=capacity;
            array= new int(size);
        }

    void enqueue(int value)
    {
        if(is_full())
        {
            cout<<"the queue is full no more enqueue is possible\n";
            return;
        }
        if(rear -1 == 0)
        {
            rear=capacity;
        }
        else rear--;

        array[rear]=value;
        length++;

    }

    bool is_empty()
    {
        return (front==0)? true: false;
    }
    bool is_full()
    {
        return (rear==0)? true: false;
    }

    int dequeue()
    {
        if(is_empty())
        {
            cout<<"\nThe queue is empty\n";
            return -1;
        }
        int value=array[front-1];
        if(front==0)
        {
            front=capacity;
        }
        else 
        front--;
        length--;
        return value;
    }

    int front_value()
    {
        return array[front];
    }


    void display()
    {
        for(int i=0;i<length;i++)
        {
            cout<<array[i];
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
    Q_array1.enqueue(5);


cout<<"\nAfter calling the dequeue function\n";
    Q_array1.display();

    cout<<"\n"<<Q_array1.front_value()<<endl;

    return 0;
}