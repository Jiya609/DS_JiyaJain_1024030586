#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch){
    if(top == MAX-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top ++;
        stack[top] = ch;
    }
}

char pop(){
    
    if(top == -1){
        cout<<"underflow"<< endl;
    }
    else{
       return stack[top--];
     }
}

int main(){
    char str[100];
    int i;

    cout<<"Enter a string "<<endl;
    cin>>str;

    for(i=0; i<strlen(str); i++){
        push(str[i]);
    }

    cout<<"The reversed string is "<<endl;
    while(top != -1){
       cout<< pop();
    }

    cout<< endl;

    return 0;
}