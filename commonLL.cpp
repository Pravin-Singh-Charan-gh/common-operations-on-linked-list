#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
};

void append(node**head,int data){
    node*newn=new node();
    newn->data=data;
    newn->next=NULL;
    
    if(*head==NULL){
    *head=newn;
    return ;
    }
    node*temp=*head;
    
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=newn;
}
void printLL(node**head){
    node*temp=*head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<"\n";
}

void delete_mid(node**head,int pos){
    if(*head==NULL)return;
    node*temp=*head;
    
    if(pos==0){
        *head=(*head)->next;
        delete temp;
        return;
    }
    
    for(int i=0;i<pos-1 && temp!=NULL;i++)
    temp=temp->next;
    
    if(temp==NULL || temp->next==NULL){
        cout<<"Node are less than position.\n";
        return;
    }
    
    node*next_node=temp->next->next;
    delete temp->next;
    temp->next=next_node;
}

bool search(node**head,int key){
    if(*head==NULL)return false;
    
    if((*head)->data==key)return true;

    return search(&(*head)->next,key);
}
int count_nodes(node** head)
{
    if (*head == NULL) 
        return 0;
        return 1 + count_nodes(&(*head)->next);
}
void reverseLL(node**head){
    node*curr=*head,*next=NULL,*prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
void helper(node**curr,node**prev,node**next){
    if(*curr==NULL)return;
    *next=(*curr)->next;
    (*curr)->next=*prev;
    *prev=*curr;
    *curr=*next;
    helper(curr,prev,next);
}
void reverse(node**head){
    node*curr=*head;
    node*prev=NULL,*next=NULL;
    helper(&curr,&prev,&next);
}

void deleteLL(node**h){
    node*temp,*head=*h;
    while(head!=NULL){
        temp=(head)->next;
        delete head;
        head=temp;
    }
}
int main(){
    node*head=NULL;
    for(int i=1;i<=9;i++)
    append(&head,i*2);
    printLL(&head);
    deleteLL(&head);
    printLL(&head);
    return 0;
}
