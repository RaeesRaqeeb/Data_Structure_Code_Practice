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
        if(length==capacity)
        {
            cout<<"the queue is full no more enqueue is possible\n";
            return;
        }

        if (rear==0)
                rear=capacity-1;
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
        int value;
        if(front -1 > 0)
            value=array[front-1];
        
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
        return array[front-1];
    }


    void display()
    {
        int index=front-1;
        for(int i=capacity-1;i>=(capacity-length);i--)
        {
            cout<<array[index];
            index-=1;
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
    // Q_array1.enqueue(5);


cout<<"\nAfter calling the dequeue function\n";
    Q_array1.display();

    cout<<"\nAgain\n"<<endl;
    Q_array1.enqueue(6);
    Q_array1.enqueue(7);
    Q_array1.enqueue(8);

    Q_array1.display();


    cout<<"\n"<<Q_array1.front_value()<<endl;

    return 0;
}