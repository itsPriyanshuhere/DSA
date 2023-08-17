#include<iostream>

using namespace std;

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

void deletion(node* &head, int val){
    if(head == NULL){
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;

    delete(todelete);
}

int main(){
    
    node* head =NULL;
    insertAtTail(head,12);
    insertAtTail(head,178);
    insertAtTail(head,1788);
    deletion(head,178);
    display(head);
    return 0;
}