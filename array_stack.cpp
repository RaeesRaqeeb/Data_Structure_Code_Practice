#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


class ArrayList
{
    private:
        int *Array_ptr;
        int capacity;
        int top;

    public:

        ArrayList(int size)
        {
            Array_ptr= new int[size];
            capacity=size;
            top=-1;
        }

       
       bool IsFull()
       {
            if(top +1== capacity)
            {
                return true;
            }
            else 
                 return false;
       }
        bool IsEmpty()
       {
            if(top ==-1)
            {
                return true;
            }
            else 
            return false;
       }
        
        bool push(int value)
        {
            if(IsFull())
            {
                cout<<"\nStack is full. you cannot push any other value in it"<<endl;
                return false;
            }
            
            
            Array_ptr[top+1]=value;
            top+=1;
           
        }

        void Display_The_Array()
        {
            for(int i=top;i>=0;i--)
            {
                cout<<Array_ptr[i]<<endl;
            }
        }

 
       
    int pop()
    {
        if(IsEmpty())
        {
            cout<<"The stack is empty ";
            return -1;
        }
        else
        {
        int value=Array_ptr[top];
        top-=1;
        return value;
        }
        
    }

    int peek()
    {
        if(!IsEmpty())
        {
            return Array_ptr[top];
        }
        else
        {
            cout<<"\nThe stack is empty\n";
            return -1;
        }
    }
      

        
};
 int main(void)
 {

    ArrayList Obj1(5);

int value;
for(int i=0;i<5;i++)
{
    value=Obj1.pop();
   if(value!=-1)
   {
        cout<<value<< " is poped from the stack"<<endl;
   }
   else if(value==-1)
   {
    break;
   }
}
    Obj1.push(1);
    Obj1.push(2);
    Obj1.push(3);
    Obj1.push(4);
    Obj1.push(5);

cout<<"\nThe values are reversed:"<<endl;
Obj1.Display_The_Array();


cout<<endl;
cout<<"Peek value:";
cout<<Obj1.peek()<<endl;

cout<<"The values are reversed:"<<endl;

Obj1.Display_The_Array();

    return 0;
 }