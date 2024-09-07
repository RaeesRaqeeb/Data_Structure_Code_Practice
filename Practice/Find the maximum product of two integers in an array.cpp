#include<iostream>

using namespace std;

void Maximum_Product(int *My_array)
{
    int *Max_value= new int;
    int *inner_ptr=My_array;
    int *Outer_ptr=My_array;
    int *Pairs1=new int;
    int *Pairs2= new int;


    *Max_value=*My_array;
    bool show=false;
    for(int i=0; i<6;i++)
    {
        inner_ptr=My_array;
        for(int j=i;j<6;j++)
        {
            if(*Max_value<= (*(Outer_ptr+i)* *(inner_ptr+j)) && *(Outer_ptr+i)!=*(inner_ptr+j)  )
            {
                *Max_value=(*(Outer_ptr+i) * *(inner_ptr+j));
                *Pairs1=*(Outer_ptr+i);
                *Pairs2=*(inner_ptr+j);
                show=true;
            }
        }
        if(show==true)
        {
              cout<<"Pairs:"<<*Pairs1<<" "<<*Pairs2<<endl;
              show=false;
        }
    }

}

int main(void)
{
    int My_array[6]={-10,-3,5,10,-2,-5};
    Maximum_Product(My_array);


    return 0;
}