#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *last=NULL;

void insertFirst(int x){
    Node *t=new Node();
    t->data=x;
    if(last==NULL){
        last=t;
        t->next=t;
    }
    else{
        t->next=last->next;
        last->next=t;
    }
}

void insertLast(int x){
    Node *t=new Node();
    t->data=x;
    if(last==NULL){
        last=t;
        t->next=t;
    }
    else{
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void insertAfter(int v,int x){
    if(last==NULL) return;
    Node *p=last->next;
    do{
        if(p->data==v){
            Node *t=new Node();
            t->data=x;
            t->next=p->next;
            p->next=t;
            if(p==last) last=t;
            return;
        }
        p=p->next;
    }while(p!=last->next);
}

void insertBefore(int v,int x){
    if(last==NULL) return;
    Node *p=last->next;
    Node *q=last;
    do{
        if(p->data==v){
            Node *t=new Node();
            t->data=x;
            t->next=p;
            q->next=t;
            if(p==last->next) last->next=t;
            return;
        }
        q=p;
        p=p->next;
    }while(p!=last->next);
}

void deleteVal(int v){
    if(last==NULL) return;
    Node *p=last->next;
    Node *q=last;
    do{
        if(p->data==v){
            if(p==last && p->next==last){
                last=NULL;
            }
            else{
                q->next=p->next;
                if(p==last) last=q;
            }
            delete p;
            return;
        }
        q=p;
        p=p->next;
    }while(p!=last->next);
}

void search(int v){
    if(last==NULL){
        cout<<"-1\n";
        return;
    }
    Node *p=last->next;
    int pos=1;
    do{
        if(p->data==v){
            cout<<pos<<endl;
            return;
        }
        pos++;
        p=p->next;
    }while(p!=last->next);
    cout<<"-1\n";
}

void display(){
    if(last==NULL){
        cout<<endl;
        return;
    }
    Node *p=last->next;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=last->next);
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
