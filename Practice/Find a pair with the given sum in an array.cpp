#include<iostream>

//Find a pair with the given sum in an array
using namespace std;

bool Finding_Sum_Pairs(int Sum_value, int *Array_Ptr)
{
    int *Outer_ptr=Array_Ptr;
    int *inner_ptr=Array_Ptr;
    bool found=false;
    for(int i=0;i<5;i++)
    {
        inner_ptr=Array_Ptr;
        for (int j=0;j<5;j++)
        {
            if(*Outer_ptr+*inner_ptr == Sum_value)
            {
                cout<<"\n"<<*Outer_ptr<<","<<*inner_ptr<<endl;
                found=true;
            }
            ++inner_ptr;
        }
        Outer_ptr++;    
    }

    return found;
}
int main(void)
{
    int My_Array[5]={1,2,3,4,5};
    cout<<"\nEnter the Sum value whose pairs you want to find:";
    int user_input;
    cin>>user_input;
    if(!(Finding_Sum_Pairs(user_input,My_Array)))
    {
        cout<<"\nNo pair found"<<endl;
    }

    return 0;
}