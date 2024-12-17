#include<iostream>
#include<vector>

using namespace std;


void mergeSort(int arr[],int l, int mid, int r)
{
    //We make two temporary array to insert the leftmost index to mid in one array and mid to right most index in the second array
    int i,j,k;
    //Finding the size of arrays
    int size_1=mid-l+1;
    int size_2=r-(mid);

    //declaring array
    int L1[size_1];
    int R1[size_2];


    //Putting starting half in l1 and ending half in R2

    for(i=0;i<size_1; i++)
    {

        L1[i]=arr[l+i];

    }

    for(j=0;j<size_2; j++)
    {

        R1[j]=arr[mid+1+j];

    }


     i=0;
     j=0;
     k=l;

    //Merging
    while(i < size_1 && j < size_2)
    {
        if(L1[i]<=R1[j])
        {
            arr[k]=L1[i];
            i++;
        }
        else
        {
            arr[k]=R1[j];
            j++;
        }
        k++;

    }

    //if one sub array is travers completely 

    while(i<size_1)
    {
        arr[k]=L1[i];
        k++;
        i++;
    }

   while(j<size_2)
    {
        arr[k]=R1[j];
        k++;
        j++;
    }



}

void merge(int arr[],int l,int r)
{
    if(l<r)//when l equal to the r then it means only 1 element left in the array
    {
        //we will find middle index of each sub array as we divide
        int mid=(l+r)/2;

        //using recusion logic to get to the last sub array and sort them
        merge(arr,l,mid);
        merge(arr,mid+1,r);

        //Then merging each sub array 
        mergeSort(arr,l,mid,r);
    }
}


void printarr(int *arr)
{
    for (int i = 0; i <6; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Bubble Sort
void Bubble_sort(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int temp=i;
        i=0;
        for(int j=1;j<len;j++)
        {
            
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
                // printarr(arr);

                i++;
            }
            else
            {
                i++;
            }
        }
        i=temp;
    }
}

//Selection sort

void selection_sort(int arr[],int len)
{
    int min_index;
    for(int i=0;i<len;i++)
    {
    int min=INT8_MAX;

        for(int j=i;j<len;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                min_index=j;
            }
        }
        if(i!=min_index)
            swap(arr[i],arr[min_index]);
    }
}

//quick sort select a pivot on the array and put the small one to the left for acending order.
int partitions(int arr[], int low, int high)
{
    int pivot=arr[high];


int i=low-1;

for(int j=low; j<=high-1;j++)
{
    if(arr[j]<pivot)
    {
        i++;
        swap(arr[j],arr[i]);
    }

}

swap(arr[i+1],arr[high]);

return i+1;


}
void quick_sort(int arr[],int low, int high )
{
    if(low<high)
    {
        int pivot_index=partitions(arr,low,high);

        quick_sort(arr,low,pivot_index-1);
        quick_sort(arr,pivot_index+1,high);
    }

    

}

//insertion sort

void insertion_sort(int arr[], int len)
{
    bool end=false;
    int i;
    for( i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
                end=true;
            }
        }
    }
    if(!end)
    {
        swap(arr[i],arr[len-1]);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };

    cout << "Given Array is \n";
    printarr(arr);

    merge(arr, 0, 5);

    cout << "\nMerged Sorted array is \n";
    printarr(arr);
cout<<"\n****************************************************"<<endl;


    int arr2[] = { 12, 11, 13, 5, 6, 7 };
    cout<<"\nBefore bubble soring"<<endl;
    printarr(arr2);

    Bubble_sort(arr2,6);
    cout<<"\nAfter bubble soring"<<endl;
    printarr(arr2);
cout<<"\n****************************************************"<<endl;
    int arr3[] = { 12, 11, 13, 5, 6, 7 };
    cout<<"\nBefore selection soring"<<endl;
    printarr(arr3);
    selection_sort(arr3,6);
    cout<<"\nAfter selection soring"<<endl;
    printarr(arr3);

cout<<"\n****************************************************"<<endl;
    int arr4[] = { 12, 11, 13, 5, 6, 7 };
    cout<<"\nBefore quick soring"<<endl;
    printarr(arr4);
    quick_sort(arr4,0,5);
    cout<<"\nAfter quick soring"<<endl;
    printarr(arr4);


cout<<"\n****************************************************"<<endl;
    int arr5[] = { 12, 11, 13, 5, 6, 7 };
    cout<<"\nBefore insertion soring"<<endl;
    printarr(arr5);
    insertion_sort(arr5,6);
    cout<<"\nAfter Insertion soring"<<endl;
    printarr(arr5);
    return 0;
}