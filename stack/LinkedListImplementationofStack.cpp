#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct MyStack
{
    Node* head;
    int sz;
    MyStack(){
        head = NULL;
        sz = 0;
    }
    void push(int x){
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop(){
        if(head == NULL){
            return INT_MAX;
        }
        int res = head->data;
        Node* temp = head;
        head = head->next;
        delete(temp);
        sz--;
        return res;
    }
    int size(){
        return sz;
    }
    bool isEmpty(){
        return (head == NULL);
    }
    int peek(){
        if(head == NULL){
            return INT_MAX;
        }
        return head->data;
    }
};