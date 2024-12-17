#include<iostream>


using namespace std;


class hashtable
{
    public:
            int *table;
            int capacity;
            float length;
    
    hashtable(int size)
    {
        capacity=size;
        length=0;
        table=new int[capacity];
        for(int i=0;i<size;i++)
        {
            table[i]=-1;
        }
    }

    int hash_function(int value)
    {
        return value % int(capacity);
    }

    int is_prime(int index)
    {
        int count=0;
        int i=1;
        while(i<=index)
        {
            if(index%i==0)
                count+=1;

            i++;
        }
        
        if(count==2)
        {
            return 1;
        }
        return 0;

         
    }
    void rehashing()
    {
        int index=capacity*2;
        int temp=capacity;

        // return;
        while(is_prime(index)!=1)
        {

        index+=1;

        }
        
        int *new_table=new int[index];

        for(int i=0;i<index;i++)
        {
            new_table[i]=-1;
        }
        
        for(int i=0;i<temp;i++)
        {
            if(table[i]!=-1)
            {
                int value=(table[i]%index);
                if(new_table[value] !=-1)
                {
                    while(new_table[value] != -1)
                    {

                        value++;
                    }
                    new_table[value]=table[i];
                }
                else 
                {
                    new_table[value]=table[i];
                    cout<<table[i]<<endl;
                }
            }
        }

        delete [] table;
        table=new_table;
        capacity=index;
        
    }
    
    void insertion(int value)
    {
        if(length==size)
            {
                cout<<"The hash table is full"<<endl;
                return;
            }
        int index=hash_function(value);
        //rehashing
        float temp=capacity;
        float per=length/(temp);
        if(((per)>=0.7))
        {
            
            rehashing();
        }
        //collision occured 
        if(table[index] != -1 )
        {
            cout<<"\n***COLLISION OCCORED******!!!!\n";
            //linear probing
            while(table[index] != -1)
            {
               
                
                index+=1;
                 if(index>=size)
                {
                    index=0;
                }
            }

            table[index]=value;
        }
        else  
        table[index]=value;

        length++;

    }

    void display()
    {
        cout<<"Hash values:"<<endl;
        for(int i=0;i<capacity;i++)
        {
            cout<<table[i]<<endl;
        }
    }

};



int main(void)
{
    hashtable obj(10);
    obj.insertion(10);
    obj.insertion(23);
    obj.insertion(24);
    obj.insertion(26);
    obj.insertion(27);
    obj.insertion(28);
    obj.insertion(29);
    obj.insertion(32);
    obj.insertion(35);
    obj.insertion(31);
   

    obj.display();


}