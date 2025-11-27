#include <iostream>
using namespace std;

#define SIZE 20

int q[SIZE];
int front = -1, rear = -1;

int isFull(){
    return rear == SIZE-1;
}

int isEmpty(){
    return front == -1;
}

void enqueue(int x){
    if(isFull()){
        cout<<"Queue is Full\n";
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        q[rear] = x;
    }
}

void dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty\n";
    }
    else{
        cout<<"Deleted: "<<q[front]<<endl;

        if(front == rear){
            front = rear = -1;  
        }
        else{
            front++;
        }
    }
}

void peek(){
    if(!isEmpty()){
        cout<<"Front element = "<<q[front]<<endl;
    }
}

void display(){
    if(isEmpty()){
        cout<<"Queue Empty\n";
    }
    else{
        for(int i=front; i<=rear; i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
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
