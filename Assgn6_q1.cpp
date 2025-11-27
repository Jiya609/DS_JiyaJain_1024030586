#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node *head = NULL;

void insertFirst(int x){
    Node *t=new Node();
    t->data=x;
    t->prev=NULL;
    t->next=head;
    if(head!=NULL) head->prev=t;
    head=t;
}

void insertLast(int x){
    Node *t=new Node();
    t->data=x;
    t->next=NULL;
    if(head==NULL){
        t->prev=NULL;
        head=t;
        return;
    }
    Node *p=head;
    while(p->next!=NULL) p=p->next;
    p->next=t;
    t->prev=p;
}

void insertBefore(int v,int x){
    if(head==NULL) return;
    if(head->data==v){
        insertFirst(x);
        return;
    }
    Node *p=head;
    while(p!=NULL && p->data!=v) p=p->next;
    if(p==NULL) return;
    Node *t=new Node();
    t->data=x;
    t->next=p;
    t->prev=p->prev;
    p->prev->next=t;
    p->prev=t;
}

void insertAfter(int v,int x){
    Node *p=head;
    while(p!=NULL && p->data!=v) p=p->next;
    if(p==NULL) return;
    Node *t=new Node();
    t->data=x;
    t->prev=p;
    t->next=p->next;
    if(p->next!=NULL) p->next->prev=t;
    p->next=t;
}

void deleteVal(int v){
    if(head==NULL) return;
    Node *p=head;
    while(p!=NULL && p->data!=v) p=p->next;
    if(p==NULL) return;
    if(p->prev!=NULL) p->prev->next=p->next;
    else head=p->next;
    if(p->next!=NULL) p->next->prev=p->prev;
    delete p;
}

void search(int v){
    Node *p=head;
    int pos=1;
    while(p!=NULL){
        if(p->data==v){
            cout<<pos<<endl;
            return;
        }
        p=p->next;
        pos++;
    }
    cout<<"-1\n";
}

void display(){
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    int ch,a,b,v;
    while(1){
        cin>>ch;
        if(ch==1){ cin>>a; insertFirst(a); }
        else if(ch==2){ cin>>a; insertLast(a); }
        else if(ch==3){ cin>>a>>v; insertBefore(v,a); }
        else if(ch==4){ cin>>a>>v; insertAfter(v,a); }
        else if(ch==5){ cin>>v; deleteVal(v); }
        else if(ch==6){ cin>>v; search(v); }
        else if(ch==7){ display(); }
        else break;
    }
    return 0;
}
