#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(){
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node*reverseLL(Node* head){
    Node*prev=NULL;
    Node*curr=head;
    while(curr!=NULL){
        Node*newNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newNode;
    }
    return prev;
}

Node *addOne(Node *head){
    //reverse the given LL:
    head=reverseLL(head);

    int carry=1;
    Node*temp=head;
    while(temp->next!=NULL){
        //process upto the last-but-one Node
        int totalSum=temp->data+carry;
        int digit=totalSum%10;
        carry=totalSum/10;

        temp->data=digit;
        temp=temp->next;
        if(carry==0){
            break;
        }
    }
    //process the last Node:
    if(carry!=0){
        int totalSum=temp->data+carry;
        int digit=totalSum%10;
        carry=totalSum/10;

        temp->data=digit;

        //if carry still remains:
        if(carry!=0){
            Node*newNode=new Node(carry);
            temp->next=newNode;
        }
    }
    head=reverseLL(head);
    return head;
}

void printLL(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){
    Node*head=new Node(7);
    Node*temp=head;
    int n=0;
    while(n<=5){
        int val;
        cout<<"Enter value for LL: ";
        cin>>val;
        Node*newNode=new Node(val);
        temp->next=newNode;
        temp=temp->next;
        n++;
    }
    cout<<"The entered LL is: ";
    printLL(head);
    cout<<endl;
    cout<<"The LL after adding ONE to it is: "<<endl;
    head=addOne(head);
    printLL(head);
    cout<<endl;
    return 0;
}
