// Impelementation of doubly linked list 
// key insight: add prev pointer in the node which points the left side of the node and enables backward traversal
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next,*prev;     
    Node(int value){
        data=value;
        next=prev=nullptr;
    }
};
class DLinkedList{
    Node * head;
    Node * tail;
    public:
    DLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertAtBeg(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            //newNode->next=nullptr;
        }
        else{
            newNode->next=head;
            head->prev=newNode;       // involvement of prev pointer 
            head=newNode;
        }
    }                                     //Time complexity:O(1)
    void deleteAtBeg(){
       if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
        else{
            if(head==tail){
                delete head;
                head=tail=nullptr;
                return;
            }
            Node *freeNode;
            freeNode=head;
            head=head->next;
            head->prev=nullptr;
            delete freeNode;
        }  
    }                                       //Time complexity:O(1)
    void insertAtEnd(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            //newNode->next=nullptr;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
           // newNode->next=nullptr;
        }
    }                                          //Time complexity:O(1)
    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
         if(head==tail){
             delete head;// this might be wrong 
             head=tail=nullptr;
             return;
         }
         Node *freeNode=tail;
         tail=tail->prev;
         tail->next=nullptr;
         delete freeNode;
    }                                    //Time complexity:O(1) UNLIKE IN SINGLY LINKEDLIST


    void insertAtPos(int value,int n){
        if(n<=0){
            cout<<"invalid position"<<endl;
            return;
        }
        if(n==1){
        this->insertAtBeg( value);
        return;
        }
        Node *temp;
        temp=head;
        for(int i=0;i<n-2&&temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"invalid position"<<endl;
            return;
        }
        if(temp->next==nullptr){
            this->insertAtEnd(value);
            return;
        }
        Node *newNode=new Node(value);
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
        
    }                                 //Time complexity:O(n) (worst case)
    void deleteAtPos(int n){
        if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
        if(n<=0){
            cout<<"invalid position"<<endl;
            return;
        }
        if(n==1){
            this->deleteAtBeg();
            return;
        }
        Node *temp;
        temp=head;
        for(int i=0;i<n-2&&temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"invalid position"<<endl;
            return;
        }
        if(temp->next==nullptr){
            this->deleteAtEnd();
            return;
        }
        Node *freeNode;
        freeNode=temp->next;
        temp->next=freeNode->next;
        temp->next->prev=temp;
        delete freeNode;
    }                                          //Time complexity:O(n) (worst case)
    void display(){
        Node *temp;
        temp=head;
        if(head==nullptr){
            cout<<"linked list is empty"<<endl;
            return;
        }
        while(temp!=nullptr){
            cout<<temp->data<<"<->"<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main() {
    DLinkedList  ll;
    ll.insertAtBeg(20);
    ll.insertAtBeg(10);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    ll.deleteAtBeg();
    ll.deleteAtBeg();
    ll.deleteAtEnd();
    ll.deleteAtEnd();
     ll.deleteAtEnd(); // underflow condition 
    ll.insertAtBeg(10);
    ll.insertAtEnd(40);
    ll.insertAtPos(20,2);
    ll.insertAtPos(30,3);
    ll.display();
    ll.deleteAtPos(3);
    ll.deleteAtPos(2);
    ll.display();
    ll.insertAtPos(40,4);   // invalid position
    ll.deleteAtPos(0);      // invalid position
    ll.insertAtPos(39,6);   // invalid position
    return 0;
 }

 // The main concept is to add the involvement of prev pointer in each node to create bidirectional link 