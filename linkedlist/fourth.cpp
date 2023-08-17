

#include<iostream>

using namespace std;

// Create A class node

class node{
    public:
    int data;
    node* next;

    // Node Class Constructor
    node(int val){
        data=val;
        next=NULL;

    }
};

//detect cycle
bool detectCycle(node* &head){
    node* slow =head;
    node* fast=head;

    while(fast!=NULL&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
        else{
            return false;
        }
    }
}

//remove cycle :HARE AND TORTOISE ALGORITHM(FLOYDS ALGORITHM)
void removeCycle(node* &head){
    node* slow =head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
// Insert Element At Tail

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=n;
}

// Display All Element

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// Insert At Head


int main(){
    
    //reverse k nodes in a linked list
    node* head =NULL;
    insertAtTail(head,12);
    insertAtTail(head,178);
    insertAtTail(head,1788);
    display(head);

    return 0;
}