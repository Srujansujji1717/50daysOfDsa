#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }

};
void addAtbig(node* &head,int t){
    node* n=new node(t);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
    

}
void insertAtend(node* &head,int x){
        node* n=new node(x);

    if(head==NULL){
        head=n;
        return;
    }
    node* t= head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=n;

}
void prin(node* head){
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data<<"->NULL";
    cout<<endl;
}
void delAThead(node* &head){
    node* t=head;
    head=head->next;
    delete t;
}
void deletion(node* &head,int k){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delAThead(head);
        return;
    }
    node* tem=head;
    while(tem->next->data!=k){
        tem=tem->next;
    }
    node* h=tem->next;
    tem->next=tem->next->next;
    delete h;

}

bool check(node* t,int m){
    while(t->next!=NULL){
        if(t->data==m){
            return true;
        }
        t=t->next;
    }
    return false;
}

node* recursiverever(node* head){
    if(head->next==NULL||head==NULL){
        return head;
    }
    node* newnod=recursiverever(head->next);
    head->next->next=head;
    head->next=NULL;
    return newnod;
}
void makecycle(node* &head,int pos){
    node* t=head;
    node* m;
    int count=1;
    while(t->next!=NULL){
        if(count==pos){
            m=t;
        }
        t=t->next;
        count++;
    }
    t->next=m;
}
void remcycle(node* &head){
node* t=head;
node* slow=head;
node* fast= head;
do{
slow=slow->next;
fast=fast->next->next;
}while(slow!=fast);
fast=t;
while(fast->next!=slow->next){
    slow=slow->next;
    fast=fast->next;
}
slow->next=NULL;

}
bool deccycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;

}
int main(){
   node* head=NULL;
   insertAtend(head,1);
   insertAtend(head,2);
   insertAtend(head,3);
   addAtbig(head,0);
   insertAtend(head,4);
   insertAtend(head,5);
   insertAtend(head,6);
//    makecycle(head,3);
//    remcycle(head);
//    cout<<deccycle(head)<<endl;
   prin(head);
//    deletion(head,2);
//    delAThead(head);
//node* r=recursiverever(head);
   //prin(r);


}