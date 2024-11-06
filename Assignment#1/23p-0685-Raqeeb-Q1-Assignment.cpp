#include<iostream>
#include<string.h>
using namespace std;

class Nodes
{
    public:
    string info;
    Nodes *next; //It will point to the object of the class made in the main function

    Nodes(string value)
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

    void push(string value)
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

    string pop()
    {
        if(length==0)
        {
            cout<<"the linkedlist stack is empty"<<endl;
            return 0;
        }
        Nodes *curr=top;
        top=curr->next;
        length-=1;
        string value;
        value=curr->info;
        delete curr;

        return value;

    }

string peek()
{
    return top->info;
}
 
 string post_fix_expression()
 {
    //another stack for calculation
    Linked_List Stack_1;
    int i=1;
    int value=length;
    do
    {
        string temp=peek();
        int checker=0;
        for(int i=0;i<temp.length();i++)
        {
            if(isdigit(temp[i]))
            {
                checker+=1;
            }
        }
    if(checker==temp.length())
    {
        Stack_1.push(pop());

    }
    else 
    {
        //Float datatypes for accurate results
        float value1=stof(Stack_1.pop());
        float value2=stof(Stack_1.pop());
        
       if(peek()=="+")
       {
        value1=value1+value2;
        Stack_1.push(to_string(value1));
       pop();

       }
       else if(peek()=="-")
       {
        Stack_1.push(to_string(value2-value1));
       pop();

       }
       else if(peek()=="*")
       {
        Stack_1.push(to_string(value1*value2));
        pop();
       }
       else if(peek()=="/")
       {
        Stack_1.push(to_string(value2/value1));
       pop();
        
       }
       else if(peek()=="%")
       {
        Stack_1.push(to_string(int(value2)%int(value1)));
        pop();
       }

    }
    i+=1;
    }while(i!=value+1);

    return Stack_1.pop();
 }


string Infix_to_postfix(string expre)
{
    
}
};

int main() 
{
    Linked_List LD_1;
    string user_input;

    //I first put the post fix to stack and then perform the calculation
    //Test case 1
    LD_1.push("+");
    LD_1.push("2");
    LD_1.push("+");
    LD_1.push("/");
    LD_1.push("31");
    LD_1.push("*");
    LD_1.push("6");
    LD_1.push("2");
    LD_1.push("6");
    //The post fix expression is 626*31/+2+ 

   cout<<"Result1:"<< LD_1.post_fix_expression();

    //Test case 2
    LD_1.push("+");
    LD_1.push("3");
    LD_1.push("-");
    LD_1.push("*");
    LD_1.push("8");
    LD_1.push("/");
    LD_1.push("2");
    LD_1.push("5");
    LD_1.push("+");
    LD_1.push("3");
    LD_1.push("2");

    //Post fix expression 23+52/8*-3+
    //infix expression 2+3-5/2*8+3

   cout<<"\nResult2:"<< LD_1.post_fix_expression();


    //Test case 3
    LD_1.push("+");
    LD_1.push("%");
    LD_1.push("5");
    LD_1.push("15");
    LD_1.push("-");
    LD_1.push("20");
    LD_1.push("-");
    LD_1.push("19");
    LD_1.push("+");
    LD_1.push("5");
    LD_1.push("2");
   cout<<"\nResult3:"<< LD_1.post_fix_expression();

         //post fix expression 25+19-20-155%+
         //infix 2+5-19-20+15%5

    
    return 0;
}
