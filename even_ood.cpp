#include<iostream>
using namespace std;

int main(void) {
    int size = 9;
    int *arr = new int[size];
    
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 9;
    arr[3] = 4;
    arr[4] = 7;
    arr[5] = 6;
    arr[6] = 1;
    arr[7] = 3;
    arr[8] = 8;
    int* curr=arr;
  	for (int i = 0; i <9; i++)
    {
            if(*curr%2==0 && i%2==0 ||*curr%2==1 && i%2==1){
                 curr++;  
                }
            else{
                int temp= *curr;
                int * tempptr=curr;
                for (int j= i;j <9-1; j++){
                    tempptr=(tempptr+1);
                    tempptr++;
                }
               
                *tempptr=temp;
                curr++;
            }
    	}
        for(int i=0;i<9;i++){
            cout<<*(arr+i)<<" ";
        }
    delete[] arr;
    return 0;
}