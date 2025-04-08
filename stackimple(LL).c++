#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Stack {
    public:
    Node* top;
    Stack(){
        top=NULL;
    }
    void push(int element){
        Node* newnode=new Node(element);
        newnode->next=top;
        top=newnode;
    }
    void pop(){
        if(top!=NULL){
            Node* temp=top;
            top=top->next;
            delete temp;
        }
        else{
            cout<<"Stack Uunderflow"<<endl;
        }
    }
    int peek(){
        if(top!=NULL){
            return top->data;
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Stack s;
    s.push(11);
    s.push(12);
    s.push(20);
    cout<<"The topmost element is:"<<s.peek()<<endl;
return 0;}