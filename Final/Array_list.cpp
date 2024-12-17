#include <iostream>


using namespace std;


class array_list
{   
    public:
            int *arr;
            int size;
            int length;

    array_list(int size)
    {
        this->size=size;
        arr=new int(size);
        length=0;
    }


    void insertion(int value)
    {
        if(length==size)
            return;


        *(arr+length)=value;
        length++;
    }

    void removeer(int value)
    {
        if(length==0)
            return;

        int i=0;
        while(*(arr+i)!=value)
        {

            i++;

        }
        
        while(i!=length)
            {
                *(arr+i)=*(arr+i+1);
                i++;
            }
        
        length--;

        
    }

    bool resize(int new_size)
    {
        if(new_size < 0)
        {
            return false;
        }

        if(new_size > size)
        {
            int *arr2 = new int[new_size];

            for(int i = 0; i < length; i++)
            {
                *(arr2+i) =*(arr+i);
            }
            
            delete[] arr;
            arr = arr2;
            size = new_size;
            return true;
        }
        else
        {
            if(length > new_size)
            {
                cout << "\nWe cannot reduce it because it will cause the loss of data\n" << endl;
                return false;
            }
            size = new_size;
            return true;
        }
    }

    int* intersection_sort(int *arr1, int len1, int *arr2, int len2)
    {

        int new_size=len1+len2;
        int new_len=0;

        int i=0;

        int *arr3= new int(new_size);
        while(i<len1)
        {
            int j=0;
            while(j<len2)
            {
                if(*(arr1+i)==*(arr2+j))
                {
                    if(new_len==0)
                    {
                        *(arr3+i)=*(arr1+i);
                        new_len++;

                    }
                    else 
                    {
                        int k=new_len-1;
                        bool temp=false;
                        while(k>=0)
                        {
                            if(*(arr1+i)>*(arr3+k))
                            {
                                *(arr3+k+1)=*(arr3+k);
                                *(arr3+k)=*(arr1+i);
                                --k;
                                temp=false;
                            }
                            else
                            {
                                temp=true;
                                --k;
                            }
                        }
                        if(temp)
                            *(arr3+new_len)=*(arr1+i);
                        new_len++;
                    }
                    break;
                }
                j++;
            }
            i++;
        }

        return arr3;
    }


    void display()
    {
        int i=0;
      while(i!=length)
        {
            cout<<*(arr+i)<<endl;
            i++;
        }
    }

};


int main(void)
{
    array_list obj(5);
    obj.insertion(10);
    obj.insertion(5);
    obj.insertion(1);
    obj.insertion(2);
    obj.insertion(3);

    obj.display();
    cout<<endl;
    obj.removeer(1);
    cout<<endl;

    obj.display();

    obj.resize(9);

    obj.insertion(11);
    // obj.insertion(12);
    // obj.insertion(13);
    // obj.insertion(14);
    cout<<endl;
    // obj.display();

    obj.resize(7);
    // obj.display();

    int arr1[4]={9,3,6,10};
    int arr2[4]={9,0,10,6};

    // int *arr3=obj.intersection_sort(arr1,arr2);

    int *arr3=obj.intersection_sort(arr1, 4, arr2, 4);
    for(int i=0;i<3;i++)
    {
        cout<<*(arr3+i)<<" ";
    }
    return 0;

}