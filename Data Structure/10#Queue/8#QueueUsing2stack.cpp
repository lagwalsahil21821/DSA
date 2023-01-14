#include<bits/stdc++.h>
using namespace std;
class Queue{
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x){
    stk1.push(x);
}

int Queue::dequeue(){
    int x = -1;
    if(stk2.empty()){
        if(stk1.empty()){       //if both stack empty
            cout<<"Queue Underflow\n";
            return x;
        }
        else{   //if stack 2 is empty but stack 1 has elements then push to stack 2
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
    x = stk2.top();
    stk2.pop();
    return x;
}

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"first element deleted: "<<q.dequeue()<<"\n";
    cout<<"Second element deleted: "<<q.dequeue()<<"\n";



    
}


