#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}


char pop() {
    if (top == -1) {
        return -1;  // empty
    } else {
        return stack[top--];
    }
}


int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, k = 0;
    char ch, temp;

    cout<<"Enter an infix expression "<<endl;
    cin>>infix;   

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        
        if ((ch >= 'A' && ch <= 'Z') || 
            (ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        
        else if (ch == '(') {
            push(ch);
        }
        
        else if (ch == ')') {
            while ((temp = pop()) != '(') {
                postfix[k++] = temp;
            }
        }
        
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';  

    cout<<"Postfix expression "<<postfix<<endl;
    return 0;
}
