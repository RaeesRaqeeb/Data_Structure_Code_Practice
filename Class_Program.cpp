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

            for (int i=length;i>=position;--i)
            {
                *(Curr_ptr+1)=*(Curr_ptr);
                --Curr_ptr;
            }
            *(Curr_ptr+1)=value;
            ++length;
        }

        void Display_The_Array()
        {
            Ptr_to_Start();
            for(int i=1;i<length-1;i++)
            {
                cout<<*(Curr_ptr);
                ++Curr_ptr;
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
            

            int Position_of_value;

                while(Position_of_value=(Find_position(value))!=0)
                {
                Ptr_to_Start();
                
                Position_of_value=(Find_position(value));
                cout<<"Position:"<<Position_of_value<<endl;
                Curr_ptr=Array_ptr+Position_of_value-1;
                cout<<"Value:"<<*Curr_ptr<<endl;
                
                for(int i=Position_of_value; i<length-1;i++)
                {
                    *(Curr_ptr)=*(Curr_ptr+1);
                    ++Curr_ptr;
                }

                
           
                     length--;
         

            
                }
   
            
        }

        int Getting_value_by_position(int position)
        {
            if(length==0)
            {
                cout<<"\nThe list is empty!!!"<<endl;
                return 0;
            }
            if(position<1 || position>length-1)
            {
                cout<<"\nInvalid position entered!!!!!!";
                return 0;
            }

            Curr_ptr=Array_ptr+position-1;

            return *(Curr_ptr);
        }

        void update(int value, int position)
        {
           if(position<1 || position >length-1)
           {
            return;
           }
           
           Ptr_to_Start();
           Curr_ptr=Array_ptr+position-1;
           *(Curr_ptr)=value;
        }

        void Copy_function(ArrayList &obj)
        {
        
            obj.Ptr_to_Start();
            Ptr_to_Start();
            for( int i=0;i<obj.length;i++)
            {
                *(Curr_ptr+i)=*(obj.Curr_ptr+i);
                length++;
            }


        }
};
 int main(void)
 {

    ArrayList Obj1(5);
    Obj1.Random_array_input();
    int position;

    while(1)
{
    cout<<"\nWhat you want to with the list?"<<endl;
    cout<<"1)Insert the new value\n2)Find position of value\n3)Remove the value\n4)Enter the Position to see the value\n5)Copying Array 1 value to another array\n0)Exit";
    cout<<"\nUser input:";
    int user_input;
    cin>>user_input;
    if(user_input==1)
    {
    cout<<"Enter value to insert:";
    cin>>user_input;
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
    else if(user_input==4)
    {
        
        cout<<"\nEnter the position to find the value at that position:";
        cin>>user_input;
        cout<<Obj1.Getting_value_by_position(user_input)<<" is the value at position :"<<user_input<<endl;

    }
    else if(user_input==5)
    {
        cout<<"\nEnter the value and position to change the current value at the position:";
        cout<<"Value:";
        cin>>user_input;
        cout<<"Position:";
        cin>>position;
        Obj1.update(user_input, position);
        Obj1.Display_The_Array();
    }
    else if(user_input==6)
    {
        ArrayList Obj2(5);
        Obj2.Copy_function(Obj1);
        cout<<"\nFUNCTION COPIED SUCCESSFULLY\n";
        Obj2.Display_The_Array();
    }
    else if(user_input==0)
    {
        cout<<"THank you for using this program";
        break;
    }
}

    return 0;
 }