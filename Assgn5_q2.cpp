#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head=NULL;

int main(){
    int arr[] = {1,2,1,2,1,3,1};
    for(int i=0;i<7;i++){
        Node *t=new Node();
        t->data=arr[i];
        t->next=head;
        head=t;
    }

    int key = 1;
    int count = 0;

    Node *p=head;
    Node *prev=NULL;

    while(p!=NULL){
        if(p->data==key){
            count++;
            if(prev==NULL){
                head=head->next;
                delete p;
                p=head;
            }else{
                prev->next=p->next;
                delete p;
                p=prev->next;
            }
        }else{
            prev=p;
            p=p->next;
        }
    }

    cout<<"Count: "<<count<<endl;

    Node *q=head;
    while(q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
    }

    return 0;
}
