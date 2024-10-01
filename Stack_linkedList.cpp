#include<iostream>

using namespace std;

class Nodes
{
    public:
    int info;
    Nodes *next; //It will point to the object of the class made in the main function

    Nodes(int value)
    {
        info= value;
        next=NULL;

    }

};

class Linked_List
{   
    private:
        Nodes *top;
        int length;

    public:
        Linked_List()
        {
            length=0;
            top =NULL;

        }

    void push(int value)
    {
        

        Nodes *n= new Nodes(value);
        Nodes *curr=top;
        if(top==NULL)
        {
            
            top=n;

        }
        else if(top!=NULL)
        {
            n->next=curr;
            top=n;
        }
        
        length++;
    }

    void pop()
    {
        if(length==0)
        {
            cout<<"the linkedlist stack is empty"<<endl;
            return;
        }
        Nodes *curr=top;
        top=curr->next;
        length-=1;
        cout<<curr->info<<endl;
        delete curr;

    }
    void display()
    {
        if(length!=0)
    {    Nodes *curr=top;
        for(int i=0;i<length;i++)
        {
            cout<<(curr)->info<<endl;
            curr=curr->next;
        }
        }
        else 
        {
            cout<<"\nThe linkedlist stack is empty"<<endl;
        }
    }

    

};



int main(void)
{
    Linked_List LD_1;
    LD_1.push(10);
    LD_1.push(11);
    LD_1.push(12);
    LD_1.push(13);
    LD_1.push(14);
    LD_1.push(15);

    cout<<"Output Stack:"<<endl;
    LD_1.display();

    cout<<"Poped values:"<<endl;
    LD_1.pop();
    LD_1.pop();
    LD_1.pop();
    LD_1.pop();
    LD_1.pop();
    LD_1.pop();
    LD_1.pop();

    LD_1.display();

    return 0;
}