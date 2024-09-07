#include<iostream>

using namespace std;

class Nodes
{
    public:
    int info;
    Nodes *Next; //It will point to the object of the class made in the main function

    Nodes(int value)
    {
        info= value;
        Next=NULL;

    }

};

class Linked_List
{   
    private:
        Nodes *head;
        int length;

    public:
        Linked_List()
        {
            length=0;
            head =NULL;

        }

    void insert(int value, int position)
    {
        if(position<1 || position>length+1)
        {
            cout<<"\nInvalid position input\n";
            return;
        }

        Nodes *n= new Nodes(value);

        if(position==1)
        {
            n->Next=head;
            head=n;
        }
        else //if the input position is between 1 and the length of the linked list
        {
            Nodes *Curr_ptr=head;

            for( int i=1; i<position-1;i++)
            {
                Curr_ptr=Curr_ptr->Next;
            }
            n->Next=Curr_ptr->Next;
            Curr_ptr->Next=n;
        }
        length++;
    }

};



int main(void)
{
    Linked_List LD_1;
    LD_1.insert(10);


    return 0;
}