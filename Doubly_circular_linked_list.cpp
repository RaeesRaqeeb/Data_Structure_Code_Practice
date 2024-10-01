#include<iostream>

using namespace std;

class Nodes
{
    public:
            Nodes *next;
            Nodes *prev;
            int info;

    Nodes(int value)
    {
        info= value;
        next=NULL;
        prev=NULL;
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
                new_node->next=Curr_ptr;
                Curr_ptr->prev=new_node;
                head=new_node;
                for(int i=1;i<length;i++)
                {
                  Curr_ptr=Curr_ptr->next;
                
                
                  }
                  Curr_ptr->next=head;
                }
            else
            {
                head=new_node;
                new_node->next=new_node;
                new_node->prev=new_node;
            }
        }
       
        else if(position!=length+1)
        {
            Nodes *Curr_ptr=head;
            Nodes *slow2=head;
            for (int i=1;i<position;i++)
            {
                slow2=Curr_ptr;
                Curr_ptr=Curr_ptr->next;
            }
            new_node->next=Curr_ptr;
            slow2->next=new_node;
            Curr_ptr->prev=new_node;
            new_node->prev=slow2;   
        }
        else//For insertion at the end of the circular doubly linkedlist
        {   Nodes*Curr_ptr=head;
            Nodes *slow2=head;
            
            for (int i=1;i<position-1;i++)
            {
            
                Curr_ptr=Curr_ptr->next;
            }
            
                Curr_ptr->next=new_node;
                new_node->prev=Curr_ptr;
                new_node->next=slow2;
                slow2->prev=new_node;
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
            head= Curr_ptr->next;
            Nodes *end_ptr=head;
            for (int i=1;i<length;i++)
            {
                end_ptr=end_ptr->next;
            }
            head->prev=end_ptr;
            end_ptr->next=head;

            delete Curr_ptr;
        }
        if(position==length)
        {
            Nodes *Curr_ptr=head;
            Nodes *End=head;
            
            for(int i=1;i<length-1; i++)
            {
                End= End->next;
            }
            
            End->next=Curr_ptr;
            Curr_ptr->prev=End;
        }
        else
        {
            Nodes *Curr_ptr=head;
            Nodes *slow_ptr=head;

            for( int i=1;i<position;i++)
            {
                slow_ptr=Curr_ptr;
                Curr_ptr=Curr_ptr->next;
            }
           
            if(Curr_ptr->next!=NULL)
                {slow_ptr->next=Curr_ptr->next;
                Curr_ptr=Curr_ptr->next;
                Curr_ptr->prev=slow_ptr;}
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
            // if(Curr_ptr->next!=NULL)
                Curr_ptr= Curr_ptr->next;
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