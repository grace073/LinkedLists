#include<iostream>

using namespace std;

class LinkedListNode{
    public:
    int data;
    LinkedListNode*next=NULL;
    LinkedListNode(){
        this->next=NULL;
    }
    LinkedListNode(int data){
        this->data=data;
        this->next=NULL;
    }
};

LinkedListNode* delete_node(LinkedListNode* &head, int key) {
 //TODO: Write - Your - Code
 if(head==NULL){
   return NULL;
 }
 LinkedListNode*prev=NULL;
 LinkedListNode*curr=head;
 while(curr!=NULL){
   //case 1: key is found at curr node:
   if(curr->data==key){
     //case 1: key is found at head
     if(curr==head){
       head=head->next;
       curr->next=NULL;
       delete curr;
       return head;
     }
     //case 2: key is at tail:
     else if(curr->next==NULL){
       prev->next=NULL;
       delete curr;
       return head;
     }
     //case 3: key is found in btwn head and tail:
     else{
       prev->next=curr->next;
       curr->next=NULL;
       delete curr;
       return head;
     }
   }
   else{
     //case 2: key is not in curr node:
    prev=curr;
    curr=curr->next;
   }
 }
  return head;
}

void printLL(LinkedListNode*head){
    LinkedListNode*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){
    LinkedListNode*head=new LinkedListNode(7);
    LinkedListNode*temp=head;
    int n=0;
    while(n<=5){
        int val;
        cout<<"Enter value for LL: ";
        cin>>val;
        LinkedListNode*newNode=new LinkedListNode(val);
        temp->next=newNode;
        temp=temp->next;
        n++;
    }
    cout<<"The entered LL is: ";
    printLL(head);
    int key;
    cout<<"Enter the key you want to delete in Linked List:"<<endl;
    cin>>key;
    delete_node(head, key);
    cout<<"LL after deletion: ";
    printLL(head);
    return 0;
}