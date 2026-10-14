// Implementation of linked list 
// key insight: we aim to to add or delete the elements in the runtime without the need to allocate the reserved memory of data elements in compile time 
            // For this purpose: Along side with data , there needs to be pointer pointing to next data , so they can be linked together to form a list 
            // This is the basic formulation of linked list 


#include <iostream>
using namespace std;
class Node{      // since in a particular data entity , two members are tied , class/struct is needed to bind them 
    public:
    int data;
    Node *next;    // self referencing pointer which point the next data of same type 
    Node(int value){    
        data=value;
        next=nullptr;
    }
};
// Now we need a class which provides the operations to manage these different nodes into a list 
class LinkedList{
    Node * head;     // to mark the start of the data of a list and useful for traversal 
    Node * tail;     
    public:
    LinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertAtBeg(int value){
        Node *newNode=new Node(value);    
        if(head==nullptr){       // if the entered data is first one , head and  needs to be pointed to it 
            head=tail=newNode;
            //newNode->next=nullptr;   already done by constructor 
        }
        else{
            newNode->next=head;       // pointer to link the the newNode with existing head node 
            head=newNode;
        }
    }                                 // Time complexity:O(1)
    void deleteAtBeg(){
       if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
        else{
            Node *freeNode;  // to point to the data head is pointing 
            freeNode=head;
            head=head->next;  // after doing so , the intended deletion node is lost , so freeNode was created
            delete freeNode;
        }  
    }                                  // Time complexity:O(1)

    void insertAtEnd(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            //newNode->next=nullptr;
        }
        else{
            tail->next=newNode;
            tail=newNode;
           // newNode->next=nullptr;
        }
    }                                  // Time complexity:O(1)
    void deleteAtEnd(){
        if(head==nullptr){
            cout<<"linked list underflow!!!"<<endl;
            return;
        }
         if(head==tail){             // only one data 
             tail=nullptr;
             delete head;
             head=nullptr;
             return;
         }
         
         Node *temp;                     // We need to access the next last node which needs traversal
            temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }                           // temp points to 2nd last node 
            Node *freeNode;
            freeNode=temp->next;
            tail=temp;
            temp->next=nullptr;
            delete freeNode;
    }                                         // Time complexity:O(n)( worst case)
    void insertAtPos(int value,int n){ 
        if(n==1){
            this->insertAtBeg( value);     // head needs to be initialzed so general case fails here 
            return;
        }
        Node *newNode=new Node(value);
        Node *temp;
        temp=head;
        for(int i=0;i<n-2&&temp!=nullptr;i++){   // Traverse in a such a way that temp points to (n-1)th node
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"invalid position"<<endl;      // position exceeds the no of nodes +1
            return;
        if(temp->next==nullptr){       // tail needs to be updated so general case fails here 
            this->insertAtEnd(value);
            return;
        }
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }                                      // Time complexity:O(n) ( worst case)
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
        for(int i=0;i<n-2;i++){
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
        temp->next=temp->next->next;
        delete freeNode;
    }                                                  // Time complexity:O(n)( worst case)

    void display(){
        Node *temp;
        temp=head;
        if(head==nullptr){
            cout<<"linked list is empty"<<endl;
            return;
        }
        while(temp!=nullptr){
            cout<<temp->data<<"->"<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }                            // Time complexity:O(n)
};
int main() {
    LinkedList  ll;
    ll.insertAtBeg(20);
    ll.insertAtBeg(10);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    ll.deleteAtBeg();
    ll.deleteAtBeg();
    ll.deleteAtEnd();
    ll.deleteAtEnd();
    ll.deleteAtEnd();  // underflow condition
    ll.insertAtBeg(10);
    ll.insertAtEnd(40);
    ll.insertAtPos(20,2);
    ll.insertAtPos(30,3);
    ll.display();
    ll.insertAtPos(39,6);   // out of bound position
    return 0;
}

// ALWAYS REMEMBER !!! IF NO OF NODE IS 0 OR 1 , IT NEEDS SPECIAL ATTENTION SINCE HEAD AND TAIL POINTER ADDS
// ADDITIONAL RESPONSIBILITY 