// Impelementation of  circular doubly linked list 
// key insight: combines both circular and doubly linked list 
#include<iostream>
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
class CDLinkedList{
    Node * head;
    Node * tail;
    public:
    CDLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertAtBeg(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            tail->next= head;
            
        }
        else{
            newNode->next=head;
            head->prev=newNode;       
            head=newNode;
            tail->next=head;
        }
    }                                    
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
            tail->next=head;
            head->prev=tail;
            delete freeNode;
        }  
    }                                       
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
            tail->next=head;
            head->prev=tail;
        }
    }                                       
    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
         if(head==tail){
             delete head;
             head=tail=nullptr;
             return;
         }
         Node *freeNode=tail;
         tail=tail->prev;
         tail->next= head;
         head->prev=tail;
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
        Node *temp;
        temp=head;
        for(int i=0;i<n-2;i++){
            temp=temp->next;
            if(temp==head){
            cout<<"invalid position"<<endl;
            return;
        }
        }
        
        if(temp->next==head){
            this->insertAtEnd(value);
            return;
        }
        Node *newNode=new Node(value);
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
        
    }                                 
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
        for(int i=0;i<n-2;i++){
            temp=temp->next;
            if(temp==head){
            cout<<"invalid position"<<endl;
            return;
        }
        }
        if(temp->next==head){
            this->deleteAtEnd();
            return;
        }
        Node *freeNode;
        freeNode=temp->next;
        temp->next=freeNode->next;
        temp->next->prev=temp;
        delete freeNode;
    }
    void display(){      
        Node *temp;
        temp=head;
        if(head==nullptr){
            cout<<"linked list is empty"<<endl;
            return;
        }
        do{                               
            cout<<temp->data<<"<->"<<" ";   
            temp=temp->next;
        }while(temp!=head);
        
        cout<<head->data<<endl;     
    }                                          
    
};
int main() {
    CDLinkedList  ll;
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
