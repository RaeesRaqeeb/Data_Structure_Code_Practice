#include<iostream>


using namespace std;

class Nodes
{
    public:
            Nodes *Next;
            int info;

    Nodes(int value)
    {
        info= value;
        Next=NULL;
    }
            

};


class Linked_list
{
    private:
            int length;
            Nodes *head;

    public:
    Linked_list()
    {
        length=0;
        head=NULL;

    }

    void insertion(int value, int position)
    {
        //Position check
        if(position<0 || position>length+1)
        {
            cout<<"INvalid position entered !!!"<<endl;
            return;
        }
        
        Nodes *New_node= new Nodes(value);
        if(position==1)
        {
            if(head!=NULL)
                {
                    New_node->Next=head;
                    head=New_node;
                }
            else
            {
                head=New_node;
            }
        }
        else 
        {
            //For moving through the linked list we make tem ptr
            Nodes *Curr_ptr= head;
            for (int i=1;i<position-1;i++)
            {
                Curr_ptr=Curr_ptr->Next;
            }
            New_node->Next=Curr_ptr->Next;
            Curr_ptr->Next=New_node;
        }
        length+=1;


        }

    void Remove(int position)
    {
        //Position check
        if(position<0 or position>length+1)
        {
            cout<<"invalid position entered please enter the correct position"<<endl;
            return;
        }

        if(position==1)
        {
            Nodes *Curr_ptr=head;
            head = Curr_ptr->Next;
            delete Curr_ptr;

        }
        else
        {
            Nodes *Curr_ptr=head->Next;
            Nodes *Slow_ptr=head;

            for(int i=1 ; i<position-1; i++)
            {
                Slow_ptr=Curr_ptr;
                Curr_ptr= Curr_ptr->Next;
            }
            Slow_ptr->Next=Curr_ptr->Next;
            delete Curr_ptr;
        }
        length-=1;
        
    }
     void display_linked_list()
    {
        Nodes *Curr_ptr=head;
        cout<<"\nYaha aya mai?"<<endl;
        for(int i=0;i<length;i++)
        {
            cout<<Curr_ptr->info<<endl;
            if(Curr_ptr->Next!=NULL)
            Curr_ptr=Curr_ptr->Next;
        }
        
    }
    
    void Swape_values(int position1, int positino2)
    {
        //position checker
        if((position1 and positino2) < 0 || (positino2 and position1) > length+1 || positino2 == position1)
        {
            cout<<"\ninvalid position entered "<<endl;
            return;
        }


        if(position1 < positino2 and position1 == 1 )
        {
            Nodes *F1=head;
            Nodes *F2=head;
            Nodes *holder1=F1->Next;
            Nodes *slow=head;
            for (int i=1; i<positino2; i++)
            {
                slow=F2;
                F2=F2->Next;

            }
            Nodes *holder2=F2->Next;
            head=F2;
            F2->Next=holder1;
            F1->Next=holder2;
            slow->Next=F1;
        }
        else if(position1 > positino2 and positino2 == 1 )
        {
            Nodes *F1=head;
            Nodes *F2=head;
            Nodes *holder1=F1->Next;
            Nodes *slow=head;
            for (int i=1; i<position1; i++)
            {
                slow=F2;
                F2=F2->Next;

            }
            Nodes *holder2=F2->Next;
            head=F2;
            F2->Next=holder1;
            F1->Next=holder2;
            slow->Next=F1;
        }
        else 
        {
            int value1, value2;
            value1= Get_Value(position1);
            value2=Get_Value(positino2);
            Remove(positino2);
            Remove(position1);
            insertion(value2,position1);
            insertion(value1,positino2);


        }

    }

    int Get_Value(int position)
    {
        Nodes *Cur_ptr=head;
        for(int i=1;i<position;i++)
        {
            Cur_ptr=Cur_ptr->Next;
        }
        return Cur_ptr->info;
    }

   void reversing()
    {
        Nodes *Holder;
        Nodes *Curr_ptr=head;
        Nodes *C3=head;
        head=head->Next;
        Curr_ptr->Next=NULL;
        for ( int i=1; i<length;i++)
        {
        Holder=head;
        if(head->Next==NULL)
            {
              head->Next=C3;
              break;
            }

        head=head->Next;
        C3=Holder;
        C3->Next=Curr_ptr;
        Curr_ptr=C3;
        
        
        }
    }

  
   void KReverse(int value)
   {

        int counter=0;
        Nodes *ptr1=head;
        Nodes *ptr2=head;
        Nodes *temp=head;
        Nodes *tem2;
        Nodes *tem3;
        int checker=0;
        int size=value;
        while (checker<(length/value))
        {
            cout<<"idar aya"<<endl;

            while (1 )
            {
            cout<<"idar aya2"<<endl;

                for(int i=1; i<size;i++)
                {
                    tem3=ptr2;
                    ptr2=ptr2->Next;
                }
                tem2=ptr2->Next;
                ptr2->Next=ptr1->Next;
                tem3->Next=ptr1;
                ptr1->Next=tem2;
                if(checker==0)
                head=ptr2;

                // ptr2->info=ptr2->info+ptr1->info;
                // ptr1->info=ptr2->info-ptr1->info;
                // ptr2->info=ptr2->info-ptr1->info;

                // ptr1=ptr1->Next;
                // ptr2=temp;
                size-=1;
                counter+=2;
                if(value%2==0)
                {
                    if(size == (value/2))
                    break;
                }
                else
                {
                    if((size-1)==(value/2))
                    break;
                }
                
            }
            checker+=2;
            size=value;
            if(value%2 !=0)
            {
                counter+=1;
            }
            ptr1=head;
            ptr2=head;
            cout<<"Counter value"<<endl;
            cout<<counter<<endl;
            if(checker < (length/value))
            {
                for(int i=1; i<=(counter*2);i++)
            {
                ptr1=ptr1->Next;
                ptr2=ptr2->Next;
            }   
            temp=ptr1;}
            
        }
        
   }

   bool is_ascending()
   {
        if(head==NULL)
            return false;

        Nodes *curr=head;
        if(curr->info <curr->Next->info)
            return true;
        else
            return false;
   }

    void insertion_sort(int value)
    {
        if(head==NULL)
        {
            return;
        }
        if(is_ascending())
        {
            Nodes *new_node=new Nodes(value);
            Nodes *curr=head;
            Nodes *prev=curr;
            while(curr->info<value)
            {
                prev=curr;
                curr=cur->Next;
            }
            new_node->Next=curr;
            prev->Next=new_node;
        }
        else 
        {
            Nodes *new_node=new Nodes(value);
            Nodes *curr=head;
            Nodes *prev=curr;
            while(curr->info>value)
            {
                prev=curr;
                curr=cur->Next;
            }
            new_node->Next=curr;
            prev->Next=new_node;
        }
    }
};

int main(void)
{

    Linked_list L1;
    L1.insertion(10,1);
    L1.insertion(20,2);
    L1.insertion(30,3);
    L1.insertion(40,4);
    L1.insertion(50,5);
    L1.insertion(60,6);
    L1.insertion(70,7);
    L1.insertion(80,8);
    L1.insertion(90,9);
    L1.insertion(100,10);
    L1.insertion(110,11);
    L1.insertion(120,12);

  
    // L1.display_linked_list();cl
    // cout<<endl<<"removed 2"<<endl;
    // L1.Remove(2);



    // L1.display_linked_list();
    // L1.Remove(2);
    // cout<<endl;
    // L1.display_linked_list();

    // cout<<endl;
    // L1.Remove(1);
    // L1.display_linked_list();
    // cout<<endl;
    // L1.Remove(1);

    // L1.display_linked_list();
    // cout<<endl;
    // L1.Remove(1);
    // L1.display_linked_list();
    cout<<endl;
    // L1.Swape_values(3,1);
    // L1.display_linked_list();

    // cout<<endl;

    // L1.Swape_values(2,3);
    // L1.display_linked_list();

    cout<<endl;
    
    
    // L1.reversing();

    // L1.display_linked_list();

    // L1.KReverse(4);
    cout<<"\n**************\n";
    L1.display_linked_list();

    L1.insertion_sort(55);

    return 0;


 }