#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    int n = q.size();
    int half = n/2;

    queue<int> first;

    for(int i=0;i<half;i++){
        first.push(q.front());
        q.pop();
    }

    while(!first.empty()){
        cout<<first.front()<<" ";
        cout<<q.front()<<" ";
        first.pop();
        q.pop();
    }

    return 0;
}
