#include<iostream>

using namespace std;

void Equilibrium_finder(int *My_ptr)
{


    int *current_ptr=My_ptr;
    int *Forward_ptr=current_ptr;
    int *Backward_ptr=current_ptr;
    int sum_forward=0;
    int sum_backward=0;


    for( int i=0;i<8;i++)
    {
             Forward_ptr=current_ptr;
             Backward_ptr=current_ptr;

        for(int j=i;j<8;j++)
        {
            if(i==0)
            {
                sum_forward+=*(Forward_ptr+j);
            }
            else
            {
                if(Backward_ptr-j)
                sum_backward+=*(Backward_ptr-j);
                
                if(j!=8)
                sum_forward+=*(Forward_ptr+j);
            }
        }
        cout<<"\n"<<i<<"Sum forward:"<<sum_forward<<endl<<"Sum backward:"<<sum_backward<<endl;
        if(sum_backward==sum_forward)
        {
            cout<<"\n"<<i<<endl;
        }
        sum_backward=0;
        sum_forward=0;
        ++current_ptr;
    }



}


int main(void)
{
    int Input_Equilibrium_index;
    int MY_Array[8]={0, -3, 5, -4, -2, 3, 1, 0};
    int *My_ptr=MY_Array;

    for(int i=0;i<8;i++)
    {   
        cout<<*(My_ptr+i)<<" ";
    
    }

    cout<<"\n";




    Equilibrium_finder(My_ptr);


    return 0;
}