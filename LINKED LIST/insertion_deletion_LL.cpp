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


void insertAtHead(Node*& head,int data){
   if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        return;
   }

   Node* newNode = new Node(data);
   newNode->next=head;
   head=newNode;
}

void insertAtTail(Node*& head,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node* newNode=new Node(data);

    temp->next=newNode;

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

void insertAtPosition(Node* &head,int position,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    if(position==1){
        insertAtHead(head, data);
        return;
    }

    if(position>getLength(head)){
        insertAtTail(head, data);
        return;
    }

    Node* temp=head;
    int i=1;
    while(i!=position-1){
        temp=temp->next;
        i++;
    }

    Node* newNode=new Node(data);

    newNode->next=temp->next;
    temp->next=newNode;
    
}

void print(Node*& head) {
   Node* temp=head;
   while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
   }
   cout<<endl;

}

void deleteNodeAtHead(Node* &head){
    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }

    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;

}

void deleteNodeAtTail(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    temp->next=NULL;
    delete temp->next;
}

void deleteNodeAtPosition(Node* &head,int position){
    if(head==NULL){
        return;
    }
    if(position==1){
        deleteNodeAtHead(head);
        return;
    }
    if(position==getLength(head)){
        deleteNodeAtTail(head);
        return;
    }

    Node* temp=head;
    int i=1;
    while(i!=position-1){
        temp=temp->next;
        i++;
    }
    Node* nodeToDelete = temp->next;
    temp->next=temp->next->next;
    nodeToDelete->next=NULL;
    delete nodeToDelete;

}


int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int position=5;

    print(head);

    // insertAtHead(head, 5);
    // insertAtTail(head, 60);
    // insertAtPosition(head,position,25);

    // deleteNodeAtHead(head);
    // deleteNodeAtTail(head);
    deleteNodeAtPosition(head, 3);

    print(head);
    return 0;
}