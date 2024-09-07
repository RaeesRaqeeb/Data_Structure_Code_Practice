#include<iostream>

//Question:Sort binary array in linear time without using variables

using namespace std;

void Binary_sorting(int *array)
{
    int *Inner_ptr=array;
    int*outer_ptr=array;
    int *current=array;

    cout<<"\nBinary sorted Array Before"<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<*(current+i)<<" ";
    }
    for(int i=0;i<10;i++)
    {
        Inner_ptr=array;
        for(int j=i;j<10;j++)
        {
            if(*outer_ptr>*(Inner_ptr+j))
            {
                
                *(Inner_ptr+j)=*(Inner_ptr+j)+*(outer_ptr);
                *(outer_ptr)=*(Inner_ptr+j)-*(outer_ptr);
                outer_ptr=array;
                j=i;
                
                

            }
        }
        outer_ptr++;
    }

    cout<<"\nBinary sorted Array After"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<*(current+i)<<" ";
    }
}

int main(void)
{
    int Binary_array[10]={1,1,1,0,0,0,1,1,0,1};

    Binary_sorting(Binary_array);




    return 0;
}