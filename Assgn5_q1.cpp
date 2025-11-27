#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertBeg(int x){
    Node *t = new Node();
    t->data = x;
    t->next = head;
    head = t;
}

void insertEnd(int x){
    Node *t = new Node();
    t->data = x;
    t->next = NULL;

    if(head == NULL){
        head = t;
        return;
    }

    Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = t;
}

void insertAfter(int val, int x){
    Node *p = head;
    while(p!=NULL && p->data!=val){
        p = p->next;
    }
    if(p==NULL){
        cout<<"Value not found\n";
        return;
    }

    Node *t = new Node();
    t->data = x;
    t->next = p->next;
    p->next = t;
}

void insertBefore(int val, int x){
    if(head==NULL) return;

    if(head->data == val){
        insertBeg(x);
        return;
    }

    Node *p = head;
    Node *prev = NULL;

    while(p!=NULL && p->data!=val){
        prev = p;
        p = p->next;
    }

    if(p==NULL){
        cout<<"Value not found\n";
        return;
    }

    Node *t = new Node();
    t->data = x;
    prev->next = t;
    t->next = p;
}

void deleteBeg(){
    if(head==NULL) return;
    Node *t = head;
    head = head->next;
    delete t;
}

void deleteEnd(){
    if(head==NULL) return;

    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }

    Node *p=head;
    Node *q=NULL;

    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    q->next=NULL;
    delete p;
}

void deleteVal(int val){
    if(head==NULL) return;

    if(head->data==val){
        deleteBeg();
        return;
    }

    Node *p=head;
    Node *q=NULL;

    while(p!=NULL && p->data!=val){
        q=p;
        p=p->next;
    }

    if(p==NULL){
        cout<<"Not found\n";
        return;
    }

    q->next=p->next;
    delete p;
}

void search(int val){
    Node *p=head;
    int pos=1;
    while(p!=NULL){
        if(p->data==val){
            cout<<"Found at position "<<pos<<"\n";
            return;
        }
        p=p->next;
        pos++;
    }
    cout<<"Not found\n";
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
    int ch,a,b,val;

    while(1){
        cout<<"\n1 Insert Beg\n2 Insert End\n3 Insert Before\n4 Insert After\n5 Delete Beg\n6 Delete End\n7 Delete Value\n8 Search\n9 Display\n10 Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        if(ch==1){
            cout<<"Enter value: ";
            cin>>a;
            insertBeg(a);
        }
        else if(ch==2){
            cout<<"Enter value: ";
            cin>>a;
            insertEnd(a);
        }
        else if(ch==3){
            cout<<"Insert value and before which value: ";
            cin>>a>>val;
            insertBefore(val,a);
        }
        else if(ch==4){
            cout<<"Insert value and after which value: ";
            cin>>a>>val;
            insertAfter(val,a);
        }
        else if(ch==5){
            deleteBeg();
        }
        else if(ch==6){
            deleteEnd();
        }
        else if(ch==7){
            cout<<"Enter value to delete: ";
            cin>>val;
            deleteVal(val);
        }
        else if(ch==8){
            cout<<"Value to search: ";
            cin>>val;
            search(val);
        }
        else if(ch==9){
            display();
        }
        else{
            break;
        }
    }
    return 0;
}
