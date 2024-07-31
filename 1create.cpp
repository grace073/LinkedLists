#include<iostream>

using namespace std;

class Node{
    public:
    int data; //data stored in linked list
    Node*next; //pointer to next node (user-defined type:Node)
    Node(){ //constructor
        this->next==NULL;
        //non-paarameterized constructor used to initialise the pointer to the next node
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        //parameterized constructor which adds the data to the nodes
    }
};
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){
    Node a; //static allocation     
    Node*b=new Node(15); //dynamic allocation
    delete b; //dynamically allocated memory should be freed from heap
    Node*head=new Node(10);
    return 0;
}