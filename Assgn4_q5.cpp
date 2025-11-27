#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> t=q1;
    q1=q2;
    q2=t;
}

void pop(){
    if(q1.empty()){
        cout<<"Empty\n";
    }
    else{
        cout<<"Popped: "<<q1.front()<<endl;
        q1.pop();
    }
}

int main(){
    push(10);
    push(20);
    pop();
    return 0;
}
