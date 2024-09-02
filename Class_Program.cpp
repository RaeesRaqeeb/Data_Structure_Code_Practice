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
            for(int i=0;i<length-1;i++)
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

        int Find_position(int value)
        {
            if(length==0)
            {
                cout<<"\nThe list is empty!!!"<<endl;
                return 0;
            }

            Ptr_to_Start();
            for( int i=0; i<length; i++)
            {
                if(*(Curr_ptr+i)==value)
                {
                        return i+1;
                }
            }

            return 0;
            
        }

        void Remove_by_value(int value)
        {
            if(length==0)
            {
                cout<<"\nthe list is empty\n";
                return;
            }
            

            int Position_of_value=Find_position(value);

            while(1)
            {
                Ptr_to_Start();
                Curr_ptr=Array_ptr+Position_of_value-1;
                Position_of_value=Find_position(value);
                for(int i=Position_of_value; i<capacity-1;i++)
                {
                    *(Curr_ptr)=*(Curr_ptr+1);
                    ++Curr_ptr;
                }
                
                     --length;
            if(Position_of_value=(Find_position(value))==0)
                break;

            }

            
        }


};
 int main(void)
 {

    ArrayList Obj1(5);
    Obj1.Random_array_input();
    while(1)
{
    cout<<"\nWhat you want to with the list?"<<endl;
    cout<<"1)Insert the new value\n2)Find position of value\n3)Remove the value\n";
    cout<<"\nUser input:";
    int user_input;
    cin>>user_input;
    if(user_input==1)
    {
    cout<<"Enter value to insert:";
    cin>>user_input;
    int position;
    cout<<"Position:";
    cin>>position;
    Obj1.insert(user_input, position);
    Obj1.Display_The_Array();
    }
    else if(user_input==2)
    {
        cout<<"\nEnter value to find its position:";
        cin>>user_input;
        
        if(Obj1.Find_position(user_input) !=0)
        {
            cout<<"Position of the value"<<user_input<<" is "<< Obj1.Find_position(user_input)<<endl;
            Obj1.Display_The_Array();
        }
        else if(Obj1.Find_position(user_input)==0)
        {
            cout<<"\nList is empty or the value is not in the list\n"<<endl;
        }
    }
    else if(user_input==3)
    {
        cout<<"\nEnter the value to remove it from the Array list:";
        cin>>user_input;
        Obj1.Remove_by_value(user_input);
        Obj1.Display_The_Array();
    }
    else if(user_input==0)
    {
        cout<<"THank you for using this program";
        break;
    }
}

    return 0;
 }