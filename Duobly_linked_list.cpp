#include<iostream>

using namespace std;

class Nodes
{
    public:
            Nodes *Next;
            Nodes *Prev;
            int info;

    Nodes(int value)
    {
        info= value;
        Next=NULL;
        Prev=NULL;
    }
            

};


class Double_Linked_list
{
    private:
            int length;
            Nodes *head;

    public:
    Double_Linked_list()
    {
        length=0;
        head=NULL;

    }

    void insertion(int value, int position)
    {
        //Position check
        if(position<0 || position> length+1)
        {
            cout<<"\nInvalid Position entered!!!!!"<<endl;
            return;
        }

        Nodes *new_node= new Nodes(value);
        if(position==1)
        {
            if(head!=NULL)
                {Nodes *Curr_ptr=head;
                new_node->Next=Curr_ptr;
                Curr_ptr->Prev=new_node;
                head=new_node;}
            else
            {
                head=new_node;
               
            }
        }
        else
        {
            Nodes *Curr_ptr=head;
            Nodes *slow2=head;
            for (int i=1;i<position;i++)
            {
                slow2=Curr_ptr;
                Curr_ptr=Curr_ptr->Next;
            }
            new_node->Next=Curr_ptr;
            slow2->Next=new_node;
            Curr_ptr->Prev=new_node;
            new_node->Prev=slow2;
             
        }

        length+=1;
    }

    void remove(int position)
    {
        //Position Checker
        if(position< 0)
        {
            cout<<"\nInvalid Position"<<endl;
            return;
        }

        if(position==1)
        {
            Nodes *Curr_ptr=head;
            head= Curr_ptr->Next;
            delete Curr_ptr;
        }
        else
        {
            Nodes *Curr_ptr=head;
            Nodes *slow_ptr=head;

            for( int i=1;i<position;i++)
            {
                slow_ptr=Curr_ptr;
                Curr_ptr=Curr_ptr->Next;
            }
           
            if(Curr_ptr->Next!=NULL)
                {slow_ptr->Next=Curr_ptr->Next;
                Curr_ptr=Curr_ptr->Next;
                Curr_ptr->Prev=slow_ptr;}
            else
            {
                delete Curr_ptr;
            }
            
            
        }
        length-=1;
        
    }

    void Doubly_display()
    {
        Nodes *Curr_ptr=head;
        // cout<<"You reached here?"<<endl;
        // cout<<length<<endl;
        for (int i=1; i<=length;i++)
        {   
            // cout<<i<<endl;
            cout<<Curr_ptr->info<<endl;
            // if(Curr_ptr->Next!=NULL)
                Curr_ptr= Curr_ptr->Next;
        }
        

    }
    

};


int main(void)
{

    Double_Linked_list DL1;
    DL1.insertion(4,1);
    DL1.insertion(2,1);
    DL1.insertion(3,1);

    DL1.Doubly_display();
    cout<<"\n";
    DL1.insertion(5,2);
    DL1.Doubly_display();

    cout<<endl;

    DL1.remove(1);
    DL1.Doubly_display();

    cout<<endl;
    DL1.remove(3);
    DL1.Doubly_display();
    DL1.insertion(4,1);
    DL1.insertion(2,1);
    DL1.insertion(3,1);
    DL1.insertion(5,1);
    DL1.insertion(6,1);
    DL1.insertion(7,3);

    // DL1.insertion(7,2);
    cout<<endl;
    DL1.Doubly_display();

    cout<<endl;
    DL1.remove(2);

    DL1.Doubly_display();
}