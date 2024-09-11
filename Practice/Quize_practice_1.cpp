#include<iostream>

using namespace std;


// int finder(int *MY_array, int position)
// {
//     return *(MY_array+position-1);
// }

// int Reverser(int *My_array)
// {
//     int *End_ptr=My_array+10-1;
//     int *Start_ptr=My_array;

//     for (int i=1; i<=(10/2);++i)
//     {
//         *(End_ptr)=*(End_ptr)+*(Start_ptr);
//         *(Start_ptr)=*(End_ptr)-*(Start_ptr);
//         *(End_ptr)=*(End_ptr)-*(Start_ptr);
//         --End_ptr;
//         ++Start_ptr;
//     }

//     return 0;
// }

class List_array
{
    public:
     int New_array[20]={0};
    int *New_ptr=New_array;

int *merger(int *ptr1, int *ptr2)
{
   

    if(*ptr1<*ptr2)
    {
        int i=0;
        for(;i<10;i++)
        {
            *(New_ptr+i)=*(ptr1+i);

        }
        cout<<"\n";
        for(int j=0;i<20;i++)
        {
            *(New_ptr+i)=*(ptr2+j);

            ++j;
        }

    }
    else
    {
        int i=0;
         for(;i<10;i++)
        {
            *(New_ptr+i)=*(ptr2+i);
       

            
        }
        cout<<"\n";
         for(int j=0;i<20;i++)
        {
            *(New_ptr+i)=*(ptr1+j);
       

            ++j;
        }

    }
      

   
    return New_ptr;

}

};
int main(void)
{
    int size=10;
    int my_array1[size]={1,2,3,4,5,6,7,8,9,10};
    int my_array2[size]={11,12,13,14,15,16,17,18,19,20};
    cout<<"\nTwo list before merge\n";
    for(int i=0;i<size;i++)
    {
        cout<<*(my_array1+i)<<" ";
    }
    cout<<"\n";
     for(int i=0;i<size;i++)
    {
        cout<<*(my_array2+i)<<" ";
    }
    cout<<"\n";
    // int user_input;
    // cout<<"\nInput the position to find the value at that position:";
    // cin>>user_input;

    // cout<<"Value at the required position is:"<<finder(my_array,user_input);
    // Reverser(my_array);
    // for(int i=0;i<10;i++)
    // {
    //     cout<<*(my_array+i);
    // }

    cout<<"\nMerged list is:";
    List_array obj1;
    int *ptr=obj1.merger(my_array1,my_array2);
    for(int i=0;i<20;i++)
    {
        cout<<*(ptr+i)<<" ";
    }

    return 0;
}