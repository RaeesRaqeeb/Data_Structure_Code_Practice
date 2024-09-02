#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


class ArrayList
{
    private:
        int *Array_ptr;
        int capacity;
        int length;
        int *Curr_ptr;

    public:

        ArrayList(int size)
        {
            Array_ptr= new int[size];
            capacity=size;
            length=0;
            Curr_ptr=NULL;
        }

        void Ptr_to_Start()
        {
            Curr_ptr=Array_ptr;
        }
        void Ptr_to_End()
        {
            Curr_ptr=Array_ptr+length-1;
        }
        void insert(int value, int position)
        {
            if(length==capacity)
            {
                cout<<"\nList is full. you cannot insert any other value in it"<<endl;
                return;
            }
            if (position<1 || position >length-1)
            {
                cout<<"\nYou have entered Invalid position"<<endl;
                return;
            }

            Ptr_to_End();

            for (int i=length;i>position;--i)
            {
                *(Curr_ptr+1)=*(Curr_ptr);
                --Curr_ptr;
            }
            *(Curr_ptr)=value;
            ++length;
        }

        void Display_The_Array()
        {
            Ptr_to_Start();
            for(int i=0;i<length;i++)
            {
                cout<<*(Curr_ptr+i);
            }
        }

        void Random_array_input()
    {
        Ptr_to_Start();
        srand(time(NULL));
        for(int i=0;i<capacity-1;i++)
        {
            
            *(Curr_ptr+i)=rand() %9 +1;
            ++length;
        }
    }

        void Find_position(int value)
        {
            if(length==0)
            {
                cout<<"\nThe list is empty!!!"<<endl;
                return;
            }

            Ptr_to_Start();
            for( int i=0; i<length-1; i++)
            {
                if(*(Curr_ptr+i)==value)
                {
                        
                }
            }
            
        }



};
 int main(void)
 {

    ArrayList Obj1(5);
    Obj1.Random_array_input();
    cout<<"\nWhat you want to with the list?"<<endl;
    cout<<"1)Insert the new value";
    cout<<"\nUser input:";
    int user_input;
    cin>>user_input;
    int position;
    cout<<"Position:";
    cin>>position;
    Obj1.insert(user_input, position);
    Obj1.Display_The_Array();


    return 0;
 }