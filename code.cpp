
#include <iostream>

using namespace std;

class node{
    public:
int info;
node *next;
node(){
    info=0;
    next=NULL;
}
node(int val){
    info=val;
    next=NULL;
}
};
class list{
node * head;
node * tail;
node * current;
int listsize=0;
public:
list(){
    head=current=tail=NULL;
}
bool isEmpty(){
    return listsize==0;
}

void add(int val){
node * newnode= new node(val);
newnode->next=NULL;
if(head==NULL){
    head=current=tail=newnode;
    listsize++;
}
else{
    current->next=newnode;
    tail=current->next;
    current=newnode;
    tail->next=NULL;
    listsize++;
}
}

void printList() {
node* temp = head;
while (temp != NULL) {
cout << temp->info << " ";
temp = temp->next; 
}
cout << endl;
}

 node *kAltReverse( int k) {

     node *prevTail = NULL; 
     int   skip = 1;
     node *curr = head;

    while (curr != NULL) {
      
        if (skip == 1) {

             node *segmentHead = curr;
             node *prev = NULL;

            for (int i = 0; i < k && curr != NULL; i++) {
                 node *nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

           
            if (prevTail == NULL) {
                head = prev;
            }
            else {
              
                prevTail->next = prev;
            }

          
            prevTail = segmentHead;
            skip = 0;
        }
        else {
            
            prevTail->next = curr;
            for (int i = 0; i < k && curr != NULL; i++) {
                prevTail = curr;
                curr = curr->next;
            }
            skip = 1;
        }
    }

    return head;
}

};

int main(void){
list obj;
obj.add(1);
obj.add(2);
obj.add(3);
obj.add(4);
obj.add(5);
obj.add(6);
obj.add(7);
obj.add(8);
obj.add(9);



node* temp=obj.kAltReverse(3);
while(temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->next;
}

}