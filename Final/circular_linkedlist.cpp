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


class Circular_singly_Linked_list
{
    public:
            int length;
            Nodes *head;

    public:
    Circular_singly_Linked_list()
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
                    Nodes *curr_ptr= head;
                    for (int i=1;i<length;i++)
                    {
                        curr_ptr=curr_ptr->Next;
                    }
                    curr_ptr->Next=New_node;
                }
            else
            {
                head=New_node;
                New_node->Next=head;
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

     void display_linked_list()
    {
        Nodes *Curr_ptr=head;
        for(int i=0;i<length;i++)
        {
            cout<<Curr_ptr->info<<endl;
            if(Curr_ptr->Next!=NULL)
            Curr_ptr=Curr_ptr->Next;
        }
        
    }

    bool Palindrome()
    {
        Nodes *ptr1=head;
        Nodes *ptr2=head;
        int count=0;
        int size=length;

        while ((size-1)!=length/2)
        {
            for(int i=1;i<size;i++)
            {
                ptr2=ptr2->Next;

            }
            if(ptr2->info == ptr1->info)
            {
                count+=1;
            }
            ptr2=head;
            ptr1=ptr1->Next;
            size-=1;
        }
        if(count==(length/2))
        {
            return true;
        }
        else 
        {
            return false;
        }
        
    }

    void change()
    {
        Nodes *curr=head;
        for(int i=0;i<length-4;i++) 
        {
            curr=curr->Next;
        }
        Nodes *curr2=head;

         while(curr2->Next != head)
        {
            curr2=curr2->Next;
        }
        curr2->Next=curr;
    }


    int cycle_count()
    {
        int length_counter=0,jump=0;
        Nodes *first=head;
        Nodes *motion=head;
        cout<<length<<endl;
        for(int i=1;i<length;i++)
        {
            for(int j=1;j<length;j++)
            {
                jump+=1;

                if(motion->Next==first)
                {
                    length_counter=jump;
                }
                motion=motion->Next;

            }
            jump=0;
            first=first->Next;
            motion=first->Next;
        }
        return length_counter;
    }

    int printing(Nodes *passed_root, int count)
    {
        if(passed_root==NULL)
        {
            return -1;
        }

        if(count==length)
            return passed_root->info;

        
        int value = printing(passed_root->Next,count+1);

        cout<<value<<" ";

        return passed_root->info;
    }

bool is_prime(int value)
{
    int factor=0;

    for(int i=1; i<=value;i++)
    {
        if(value%i==0)
        {
            factor++;
        }
    }
    if(factor==2)
        return true;

    return false;
}

    int count_prime_combinations()
    {
        if(length==0)return 0;

        int i=0;

        Nodes *curr=head;
        Nodes *starter=curr;
        int *arr= new int(length);
        int index=0;
        do{
            if(is_prime(i))
            {
                arr[index]=curr->info;
                index++;
            }
            i++;
            curr=curr->Next;
        }while(curr!=starter);

        int count=0;

        for(int i=0;i<index+1;i++)
        {
            for(int j=i;j<index;j++)
            {
                if(is_prime(arr[i]+arr[j]))
                {
                    count++;
                }
            }
        }

        return count;
    }
};


int main(void)
{
    Circular_singly_Linked_list CSL1;
    srand(time(0)); // Seed for random number generation
    for (int i = 1; i <= 10; ++i) {
        int value = rand() % 20 + 1; // Random value between 1 and 100
        CSL1.insertion(value, i);
    }
    CSL1.display_linked_list();

    // if(CSL1.Palindrome())
    // {
    //     cout<<"The circular linked list is palindrome";
    // }
    // else{
    //     cout<<"The given circular linked list is not palindrome";
    // }
    // CSL1.change();
//    cout<<CSL1.cycle_count()<<endl;


   cout<<"All nodes:"<<endl;
//    cout<<CSL1.printing(CSL1.head,1);

   cout<<"Number of prime combination at the prime index:"<<CSL1.count_prime_combinations();

   return 0;
   
}