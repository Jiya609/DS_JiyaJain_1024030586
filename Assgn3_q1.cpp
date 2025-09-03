#include<iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(){
    int x;
    cout<<"Enter data "<<endl;
    cin >> x;
    if(top == -1) {
        cout<<"overflow" << endl;
    } 
    else{
        top ++;
        stack[top] = x;
    }

}

void pop(){
    int y;
    if(top == -1){
        cout<<"underflow"<< endl;
    }
    else{
        top --;
    }
}

void peek(){
    if(top == -1){
        cout<< "Stack is empty "<<endl;
    }
    else{
        cout<< stack[top]<<endl;
    }
}

void display(){
    int i;
    for(i=top; i>=0; i--){
        cout<<stack[i];
    }
}

bool isEmpty(){
    return (top == -1);
}

bool isFull(){
    return (top == MAX-1);
}

int main() {

    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:cout << "Enter value to push: ";
                
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                 break;
            case 4:
            isFull();
                    
            
                break;
                case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}