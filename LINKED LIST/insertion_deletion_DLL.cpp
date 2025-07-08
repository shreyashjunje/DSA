#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        return;
    }

    Node* newNode=new Node(data);

    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void insertAtTail(Node* &head,int data){
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
    newNode->prev=temp;
}

int getLength(Node* &head){
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
        Node* newNode=new Node(data);
        head=newNode;
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
    Node* temp=head;;
    int i=1;
    while(i!=position-1){
        temp=temp->next;
        i++;
    }
    Node* newNode=new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    temp->next->prev=newNode;

}
void print(Node* &head) {
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNodeAtHead(Node*& head){
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
    head->prev=NULL;
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
    temp->next->prev=NULL;
    temp->next=NULL;
    delete temp->next;
}

void deleteNodeAtPosition(Node* &head,int position){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
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

    Node* nodeToDelete=temp->next;
    if(temp->next->next !=NULL){
        temp->next=nodeToDelete->next;
        nodeToDelete->next->prev=temp;
        nodeToDelete->next=NULL;
        nodeToDelete->prev=NULL;
        delete nodeToDelete;
    }

}



int main(){
    Node* head=NULL;
    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtPosition(head, 2, 15);

    print(head);

    // deleteNodeAtHead(head);
    // deleteNodeAtTail(head); 
    deleteNodeAtPosition(head, 2);

    print(head);
    
    return 0;
}