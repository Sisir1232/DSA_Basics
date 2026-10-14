// Implementation of circular linked list 
// Key insight: As name suggests , we need to link tail node's next to head node instead null in singly linked list 
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};
class CLinkedList{
    Node * head;
    Node * tail;
    public:
    CLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertAtBeg(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            tail->next=head;
            //newNode->next=nullptr;
        }
        else{
            newNode->next=head;
            head=newNode;
            tail->next=newNode;   // circular wrap
        }
    }
    void deleteAtBeg(){
       if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
        else if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }
        else{
            Node *freeNode;
            freeNode=head;
            head=head->next;
            tail->next=head;       // tail must point to new head 
            delete freeNode;
        }
        
    }
    void insertAtEnd(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            newNode->next=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
           // newNode->next=nullptr;
        }
    }
    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
         if(head==tail){
             tail=nullptr;
             delete head;
             head=nullptr;
             return;
         }
         
         Node *temp;
            temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            Node *freeNode;
            freeNode=temp->next;
            tail=temp;
            temp->next=head;
            delete freeNode;
    }
    void insertAtPos(int value,int n){
        if(n<=0){
            cout<<"invalid position"<<endl;
            return;
        }
        if(n==1){
            this->insertAtBeg( value);
            return;
        }
        Node *temp=head;
        for(int i=1;i<n-1;i++){
            temp=temp->next;
            if(temp==head){                     // HERE IS THE CHANGE!!! Tail never points to null
                cout<<"invalid interval"<<endl; // if we check it after the loop , due to wrap condition , sequence or order is repeated
                return;
            }
        }
        if(temp==tail){
            this->insertAtEnd(value);
            return;
        }
        Node *newNode= new Node(value);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void deleteAtPos(int n){
        if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
        if(n==1){
            this->deleteAtBeg();
            return;
        }
        Node *temp;
        temp=head;
        for(int i=1;i<n-1;i++){
            temp=temp->next;
            if(temp==tail){
                cout<<"invalid position"<<endl;
                return;
            }
        }
        if(temp->next==tail){
                this->deleteAtEnd();
                return;
            }
        Node *freeNode;
        freeNode=temp->next;
        temp->next=temp->next->next;
        delete freeNode;
    }
    void display(){      
        Node *temp;
        temp=head;
        if(head==nullptr){
            cout<<"linked list is empty"<<endl;
            return;
        }
        do{                               // or you can use while(temp!=head) d0 {} and print tail and head again separately
            cout<<temp->data<<"->"<<" ";   
            temp=temp->next;
        }while(temp!=head);
        
        cout<<head->data<<endl;     // to show circular wrap 
    }
};
int main() {
    CLinkedList  ll;
    ll.insertAtBeg(20);
    ll.insertAtBeg(10);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    ll.deleteAtBeg();
    ll.deleteAtBeg();
    ll.deleteAtEnd();
    ll.deleteAtEnd();
     ll.deleteAtEnd();

    ll.insertAtBeg(10);
    ll.insertAtEnd(40);
    ll.insertAtPos(20,2);
    ll.insertAtPos(15,2);
    ll.insertAtPos(25,4);
    ll.display();
    ll.insertAtPos(22,9);
    ll.deleteAtPos(2);
    ll.deleteAtPos(3);
    ll.insertAtPos(5,1);
    ll.deleteAtPos(4);
    ll.display();
    return 0;
}
// tail not pointing to null changes the condition in insertAtPos() and display() method , so little bit of change is needed