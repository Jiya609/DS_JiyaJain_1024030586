#include <iostream>
using namespace std;

#define SIZE 20

int cq[SIZE];
int front=-1, rear=-1;

int isFull(){
    return (front==0 && rear==SIZE-1) || (rear+1==front);
}

int isEmpty(){
    return front==-1;
}

void enqueue(int x){
    if(isFull()){
        cout<<"Full\n";
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
        cq[rear]=x;
    }
    else{
        rear = (rear+1)%SIZE;
        cq[rear]=x;
    }
}

void dequeue(){
    if(isEmpty()){
        cout<<"Empty\n";
        return;
    }
    cout<<"Deleted: "<<cq[front]<<endl;

    if(front==rear){
        front=rear=-1;
    }
    else{
        front = (front+1)%SIZE;
    }
}

void peek(){
    if(!isEmpty()){
        cout<<"Front = "<<cq[front]<<endl;
    }
}

void display(){
    if(isEmpty()){
        cout<<"Empty\n";
        return;
    }

    int i=front;
    while(i!=rear){
        cout<<cq[i]<<" ";
        i=(i+1)%SIZE;
    }
    cout<<cq[rear]<<endl;
}

int main(){
    int ch,x;

    while(1){
        cout<<"\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin>>ch;

        if(ch==1){
            cin>>x;
            enqueue(x);
        }
        else if(ch==2){
            dequeue();
        }
        else if(ch==3){
            peek();
        }
        else if(ch==4){
            display();
        }
        else{
            break;
        }
    }
    return 0;
}
