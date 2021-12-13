#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void inserAthead(node* &head,int m){
    node* a=new node(m);
    a->next=head;
    if(head!=NULL){
    head->prev=a;

    }
    head=a;

}
void insertATtail(node* &head,int t){
    if(head==NULL){
        inserAthead(head,t);
        return;
    }
    node* m=new node(t);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=m;
}
void delAthead(node* &head){
    node* t=head;
    head=head->next;
    head->prev=NULL;
    delete t;

}
void deltion(node* &head,int pos){
    if(pos==1){
        delAthead(head);
        return;
    }
    node* temp=head;
    int cont=1;
    while(temp!=NULL&&cont!=pos){
        temp=temp->next;
        cont++;
    }
    if(temp->next!=NULL){
    temp->next->prev=temp->prev;

    }
    temp->prev->next=temp->next;
    delete temp;

}
void prin(node* head){
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data<<"->NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertATtail(head,1);
    insertATtail(head,2);
    insertATtail(head,3);
    inserAthead(head,10);
    // deltion(head,2);
    // delAthead(head);
    prin(head);
}