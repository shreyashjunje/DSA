#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node*& head) {
   Node* temp=head;
   while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
   }
}

int getLength(Node*& head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
}



int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);

    head->next=second;
    second->next=third;
    third->next=NULL;

    // print(head);
    cout<<"Length of linked list: "<<getLength(head)<<endl;

    return 0;
}