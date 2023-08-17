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
//recursive

node* reverse(node* &head){
    //not written any code
}

//iterative
// node* reverse(node* &head){
//         node* prevptr = NULL;
//         node* currptr = head;
//         node* nextptr;

//         while(currptr!=NULL){
//             nextptr=currptr->next;
//             currptr->next=prevptr;

//             prevptr=currptr;
//             currptr=nextptr;
//         }
//         return prevptr; //Because prevptr is new head at the end
// }


//PRACTICE:- 1
// node* reverse(node* &head){
//     node* prevptr=NULL;
//     node* currptr=head;
//     node* nextptr;

//     while(currptr!=NULL){
//         nextptr = currptr->next;
//         currptr->next=prevptr;
//         prevptr=currptr;
//         currptr=nextptr;
//     }
//     return prevptr;
// }

int main(){
    
    node* head =NULL;
    insertAtTail(head,12);
    insertAtTail(head,178);
    insertAtTail(head,1788);
    display(head);
    node* newhead = reverse(head);
    display(newhead);
    return 0;
}