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


class Double_Circular_Linked_list
{
    private:
            int length;
            Nodes *head;

    public:
    Double_Circular_Linked_list()
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
                {
                Nodes *Curr_ptr=head;
                new_node->Next=Curr_ptr;
                Curr_ptr->Prev=new_node;
                head=new_node;
                
                }
            else
            {
                head=new_node;
                new_node->Next=new_node;
                new_node->Prev=new_node;
            }
        }
        else if(position!=length+1)
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
        else
        {   Nodes*Curr_ptr=head;
            Nodes *slow2=head;
            
            for (int i=1;i<position;i++)
            {
            
                Curr_ptr=Curr_ptr->Next;
            }
            
                Curr_ptr->Next=new_node;
                new_node->Prev=Curr_ptr;
                new_node->Next=slow2;
                slow2->Prev=new_node;
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
            Nodes *end_ptr=head;
            for (int i=1;i<length;i++)
            {
                end_ptr=end_ptr->Next;
            }
            head->Prev=end_ptr;
            end_ptr->Next=head;

            delete Curr_ptr;
        }
        if(position==length)
        {
            Nodes *Curr_ptr=head;
            Nodes *End=head;
            
            for(int i=1;i<length-1; i++)
            {
                End= End->Next;
            }
            
            End->Next=Curr_ptr;
            Curr_ptr->Prev=End;
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

    Double_Circular_Linked_list DCL1;
    DCL1.insertion(10,1);
    DCL1.insertion(20,1);
    DCL1.insertion(30,1);

    DCL1.insertion(90,2);
    DCL1.insertion(80,7);
    DCL1.Doubly_display();

    DCL1.remove(1);

    cout<<endl;
    DCL1.Doubly_display();

    cout<<endl;

    DCL1.remove(4);

    DCL1.Doubly_display();

    DCL1.insertion(10,1);
    DCL1.insertion(20,1);
    DCL1.insertion(30,1);

    cout<<endl;

    DCL1.Doubly_display();

    cout<<endl;
    DCL1.remove(3);

    DCL1.Doubly_display();






}