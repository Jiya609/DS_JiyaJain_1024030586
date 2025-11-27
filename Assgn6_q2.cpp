#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *last=NULL;

int main(){
    Node *a=new Node(); a->data=20;
    Node *b=new Node(); b->data=100;
    Node *c=new Node(); c->data=40;
    Node *d=new Node(); d->data=80;
    Node *e=new Node(); e->data=60;

    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a;
    last=e;

    Node *p=a;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=a);
    cout<<a->data;

    return 0;
}
