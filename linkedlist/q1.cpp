//APPEND LAST K NODES IN LINKED LIST



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

int length(node* head){
    node* temp = head;
    int l=0;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

node* kappend(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail;
        }
        if(count ==l-k+1){
            newHead = tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next=head;
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

int main(){
    
    node* head =NULL;
    insertAtTail(head,12);
    insertAtTail(head,178);
    insertAtTail(head,1788);
    display(head);
    return 0;
}